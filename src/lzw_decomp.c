#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include "lzw_decomp.h"

#define BITS       12                   /* Setting the number of bits to 12, 13*/
#define TABLE_SIZE (1<<BITS)
#define MAX_VALUE  (1<<BITS) - 1
#define MAX_CODE   MAX_VALUE - 1
#define BUF_SIZE   1024

#define CODE_CLEAR 256
#define CODE_EOF   257
#define CODE_NEW   258
typedef struct { short code; char c; } lzw_dict_entry;
struct lzw_decompress_t
{
    lzw_decomp_malloc _malloc;
    lzw_decomp_free   _free;
    lzw_decomp_src_read _read;
    void *src;
    lzw_dict_entry dict[TABLE_SIZE];
    /* state */
    int counter;
    unsigned char *buf;  /* input buffer */
    unsigned char scratch[256], *p, *e; /* output buffer */
    int bits, bit_position, last_bit, next_shift;
    int next_code, prev_code, last_c;
};

static const lzw_dict_entry lzw_dict_256[256] =
{
{0, 0},{1, 1},{2, 2},{3, 3},{4, 4},{5, 5},{6, 6},{7, 7},{8, 8},{9, 9},{10, 10},{11, 11},{12, 12},{13, 13},{14, 14},{15, 15},{16, 16},{17, 17},{18, 18},{19, 19},{20, 20},{21, 21},{22, 22},{23, 23},{24, 24},{25, 25},{26, 26},{27, 27},{28, 28},{29, 29},{30, 30},{31, 31},{32, 32},{33, 33},{34, 34},{35, 35},{36, 36},{37, 37},{38, 38},{39, 39},{40, 40},{41, 41},{42, 42},{43, 43},{44, 44},{45, 45},{46, 46},{47, 47},{48, 48},{49, 49},{50, 50},{51, 51},{52, 52},{53, 53},{54, 54},{55, 55},{56, 56},{57, 57},{58, 58},{59, 59},{60, 60},{61, 61},{62, 62},{63, 63},{64, 64},{65, 65},{66, 66},{67, 67},{68, 68},{69, 69},{70, 70},{71, 71},{72, 72},{73, 73},{74, 74},{75, 75},{76, 76},{77, 77},{78, 78},{79, 79},{80, 80},{81, 81},{82, 82},{83, 83},{84, 84},{85, 85},{86, 86},{87, 87},{88, 88},{89, 89},{90, 90},{91, 91},{92, 92},{93, 93},{94, 94},{95, 95},{96, 96},{97, 97},{98, 98},{99, 99},{100, 100},{101, 101},{102, 102},{103, 103},{104, 104},{105, 105},{106, 106},{107, 107},{108, 108},{109, 109},{110, 110},{111, 111},{112, 112},{113, 113},{114, 114},{115, 115},{116, 116},{117, 117},{118, 118},{119, 119},{120, 120},{121, 121},{122, 122},{123, 123},{124, 124},{125, 125},{126, 126},{127, 127},{128, 128},{129, 129},{130, 130},{131, 131},{132, 132},{133, 133},{134, 134},{135, 135},{136, 136},{137, 137},{138, 138},{139, 139},{140, 140},{141, 141},{142, 142},{143, 143},{144, 144},{145, 145},{146, 146},{147, 147},{148, 148},{149, 149},{150, 150},{151, 151},{152, 152},{153, 153},{154, 154},{155, 155},{156, 156},{157, 157},{158, 158},{159, 159},{160, 160},{161, 161},{162, 162},{163, 163},{164, 164},{165, 165},{166, 166},{167, 167},{168, 168},{169, 169},{170, 170},{171, 171},{172, 172},{173, 173},{174, 174},{175, 175},{176, 176},{177, 177},{178, 178},{179, 179},{180, 180},{181, 181},{182, 182},{183, 183},{184, 184},{185, 185},{186, 186},{187, 187},{188, 188},{189, 189},{190, 190},{191, 191},{192, 192},{193, 193},{194, 194},{195, 195},{196, 196},{197, 197},{198, 198},{199, 199},{200, 200},{201, 201},{202, 202},{203, 203},{204, 204},{205, 205},{206, 206},{207, 207},{208, 208},{209, 209},{210, 210},{211, 211},{212, 212},{213, 213},{214, 214},{215, 215},{216, 216},{217, 217},{218, 218},{219, 219},{220, 220},{221, 221},{222, 222},{223, 223},{224, 224},{225, 225},{226, 226},{227, 227},{228, 228},{229, 229},{230, 230},{231, 231},{232, 232},{233, 233},{234, 234},{235, 235},{236, 236},{237, 237},{238, 238},{239, 239},{240, 240},{241, 241},{242, 242},{243, 243},{244, 244},{245, 245},{246, 246},{247, 247},{248, 248},{249, 249},{250, 250},{251, 251},{252, 252},{253, 253},{254, 254},{255, 255}
};

static void
lzw_clear(lzw_decompress *d)
{
    d->next_code = CODE_NEW;
    d->bits = 9;
    d->next_shift = 512;
    d->counter = CODE_NEW;
}

lzw_decompress* lzw_decomp_init(lzw_decomp_malloc _malloc, lzw_decomp_free _free, lzw_decomp_src_read _read, void *src)
{
    lzw_decompress *d = _malloc(sizeof(lzw_decompress));
    if (!d)
        return d;
    d->buf = _malloc(BUF_SIZE+1); // +1 to suppress bogus read in lzw_get_code()
    if (!d->buf)
    {
        _free(d);
        return 0;
    }
    d->_malloc = _malloc;
    d->_free = _free;
    d->_read = _read;
    d->src = src;
    d->p = d->e = d->scratch;
    d->counter = 0;
    d->bit_position = (BUF_SIZE) * 8 + 1;
    d->last_bit = 0;
    lzw_clear(d);
    memcpy(d->dict, lzw_dict_256, sizeof(lzw_dict_entry)*256);
    return d;
}

static unsigned char*
code_to_string(lzw_dict_entry *dict, unsigned int code, unsigned char *buf)
{
    if (code < 256)
    {
        *buf = code;
        return buf;
    }
    else
    {
        *buf = dict[code].c;
        code = dict[code].code;
        return code_to_string(dict, code,++buf);
    }
}

static inline unsigned int
lzw_get_code(lzw_decompress *d)
{
    unsigned int code;

    code = d->buf[d->bit_position/8]<<16;
    code |=  d->buf[1+d->bit_position/8]<<8;
    code |=  d->buf[2+d->bit_position/8];
    code <<= (d->bit_position%8);
    code &= 0xffffff;
    code >>= (24-d->bits);
    d->bit_position += d->bits;
    return code;
}

int
lzw_decomp_read(lzw_decompress *d, unsigned char *buf, int len)
{
    unsigned int code;
    unsigned char *p;
    int dec_len, i;

    if (len <= 0)
        return 0;
    if (d->p < d->e)
    {
        *buf++ = *--d->e;
        return 1;
    }

    if (d->last_bit < (d->bit_position + d->bits))
    {
        int rd;
        int last = (d->last_bit/8 - d->bit_position/8);

        if (last < 0)
            last = 0;

        if (last)
            memcpy(d->buf, d->buf+d->bit_position/8, last);
        if (last)
            rd = (d->_read)((int)d->src, d->buf+last, BUF_SIZE-last);
        else
            rd = (d->_read)((int)d->src, d->buf, BUF_SIZE);
        if (!rd)
            return 0;
        if (last)
        {
            d->bit_position %= 8;
            d->last_bit = (last + rd)*8;
        }
        else
        {
            d->bit_position = 0;
            d->last_bit = rd * 8;
        }
    }
    if (d->bit_position >= d->last_bit)
    {
        return 0;
    }
    code = lzw_get_code(d);

    if (code == MAX_VALUE)
        return 0;
    if (code == CODE_EOF)
        return 0;
    if (code == CODE_CLEAR)
    {
        lzw_clear(d);
        code = lzw_get_code(d);
        d->prev_code = code;
        d->last_c = code;
        *buf = code;
        d->counter++;
        return 1;
    }
    if (d->counter == CODE_NEW)
    {
        d->counter++;
        d->prev_code = code;
        d->last_c = code;
        *buf = code;
        return 1;
    }
    d->counter++;
    if (d->counter >= d->next_shift)
    {
        d->bits += 1;
        d->next_shift *= 2;
    }
    /*
    ** This code checks for the special STRING+CHARACTER+STRING+CHARACTER+STRING
    ** case which generates an undefined code.  It handles it by decoding
    ** the last code, and adding a single character to the end of the decode string.
    */
    if (code >= d->next_code)
    {
        *d->scratch = d->last_c;
        p = code_to_string(d->dict, d->prev_code, d->scratch+1);
    }
    else
    {
        p = code_to_string(d->dict, code, d->scratch);
    }
    d->last_c = *p;
    dec_len = p - d->scratch + 1;
    /*
    ** Finally, if possible, add a new code to the string table.
    */
    if (d->next_code <= MAX_CODE)
    {
        //fprintf(stderr, "%d: %d, %c\n", d->next_code, d->prev_code, d->last_c);
        d->dict[d->next_code].code = d->prev_code;
        d->dict[d->next_code].c = d->last_c;
        d->next_code++;
    }
    d->prev_code = code;
    /* write out */
    if (len >= dec_len)
    {
        len = dec_len;
        for (i = 0; i < len; i++)
        {
            //putchar(*p);
            *buf++ = *p--;
        }
        d->p = d->e = d->scratch;
    }
    else
    {
        for (i = 0; i < len; i++)
        {
            //putchar(*p);
            *buf++ = *p--;
        }
        d->p = d->scratch;
        d->e = p+1;
    }
    return len;
}

void lzw_decomp_close(lzw_decompress *d)
{
    if (d)
    {
        if (d->buf)
        {
            (d->_free)(d->buf);
        }
        (d->_free)(d);
    }
}

#if 0

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int
main(int argc, char *argv[])
{
    int lzw_file;
    lzw_decompress *d;
    unsigned char buf[256];
    int len;
/*
** Now open the files for the expansion.
*/
    lzw_file = open("test.lzw",0);
    if (lzw_file==-1)
    {
        printf("Fatal error opening files.\n");
        exit(-2);
    };
/*
** Expand the file.
*/
    d = lzw_decomp_init(malloc, free, read, (void*)lzw_file);
    while ( len = lzw_decomp_read(d, buf, 10) ) {
        int i;
        for (i = 0; i < len; i++)
        {
            putchar(buf[i]);
        }
    }
    lzw_decomp_close(d);
    close(lzw_file);
}
#endif
