#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "pdfmem.h"
#include "pdfname.h"


/*
  The 'name' in PDF specification are the PDF language's identifier.
  The 'name' specifically refered here are the 'identifier's that are
  not in the large collection of PDF keywords.

  By using a hash table to store all the names, we introduce a centralized
  storage that "intern" the names.

  Prior to this, the 'names' are free heap memorys, managed by the life cycle
  of the object that it belongs.
*/

#define DEBUG_HASH

#ifdef DEBUG_HASH
#define P_HASH(var, ...) printf(var, ##__VA_ARGS__)
#else
#define P_HASH(var, ...)
#endif

#if (HASHTABLE_INITIAL_SIZE % 16)
#error "HASHTABLE_INITIAL_SIZE must be power to twos"
#endif

static void hashtable_resize(hashtable *ht);

static unsigned long
shxor_hash(unsigned char *p, int len)
{
    unsigned long val = 0;//1234567890;

    do
    {
        val <<= 3; // 3 is the golden number, found by the TCL hacker
        val += *p++;
    }
    while(--len);

    return val;
}

unsigned long
nvh1a_hash(unsigned char *string, int len)
{
    unsigned result = 0x811c9dc5, ch;
#define FNV_32_PRIME    ((unsigned) 0x01000193)
    for (ch=*string++ ; ch ; ch=*string++) {
        result = (result ^ ch) * FNV_32_PRIME;
    }
    return (unsigned long)result;
}

hashtable *
hashtable_create(int size)
{
    hashtable *ht = pdf_malloc(sizeof(hashtable));

    if (ht)
    {
        ht->n = 0;
        ht->n_buckets = size;
        ht->resize_buckets = size * HASHTABLE_RESIZE_RATIO;
        ht->buckets = (hashtable_entry**)pdf_malloc(sizeof(hashtable_entry*) * ht->n_buckets);
        if (ht->buckets)
        {
            memset(ht->buckets, 0, sizeof(hashtable_entry*) * ht->n_buckets);
        }
        else
        {
            pdf_free(ht);
            ht = NULL;
        }
        ht->replace_entry = 0;
    }
    return ht;
}

hashtable *
hashtable_new()
{
    return hashtable_create(HASHTABLE_INITIAL_SIZE);
}

void
hashtable_free(hashtable *ht)
{
    if (ht)
    {
        int i;
        for (i = 0; i < ht->n_buckets; i++)
        {
            hashtable_entry *e = ht->buckets[i];
            while (e)
            {
                hashtable_entry *next = e->next;
                pdf_free(e);
                e = next;
            }
        }
        pdf_free(ht->buckets);
        pdf_free(ht);
    }
}

static
hashtable_entry *
hashtable_entry_create(unsigned char *k, int len)
{
    hashtable_entry *e = NULL;
    unsigned char *buf;
    e = pdf_malloc(sizeof(hashtable_entry) + (len + 1));
    memset(e, 0, sizeof(hashtable_entry) + (len + 1));
    buf = (unsigned char*)e + sizeof(hashtable_entry);
    memcpy(buf, k, len);
    buf[len] = 0;
    e->str = buf;
    return e;
}

/*
 * Insert new or return an existing entry
 *
 */
hashtable_entry *
hashtable_search(hashtable *ht, hashtable_entry *search)
{
    if (!search)
    {
        return NULL;
    }
    else
    {
        unsigned char *k;
        int len;
        unsigned long h;
        hashtable_entry *e;
        hashtable_entry **pe, **ppe;
        hashtable_entry *ne = NULL;
        int x;

        k = search->str;
        len = strlen((char*)search->str);
        h = nvh1a_hash(k, len);
        x = h%ht->n_buckets;
        pe = &ht->buckets[x];
        ppe = pe;
        e = *pe;

        while (e)
        {
            if (strlen((char*)e->str) == len &&
                strncmp((const char*)e->str, (const char*)k, len) == 0)
            {
                break;
            }
            pe = ppe;
            ppe = &(e->next);
            e = e->next;
        }

        if (e)
        {
            return e;
        }
        else
        {
            /* Insert a new entry and return it. */
            if (ht->replace_entry)
            {
                ne = search;
                ne->next = NULL;
            }
            else
            {
                ne = hashtable_entry_create(k, len);
            }
            if (!ne)
                return NULL;
            if (*pe)
                (*pe)->next = ne;
            else
                *pe = ne;
        }
        /* maybe grow it */
        if (++ht->n > ht->resize_buckets)
        {
            hashtable_resize(ht);
        }

        return ne;
    }
}

/**
 * expand table to the size of : original_size * HASHTABLE_RESIZE_RATIO
 */
static void
hashtable_resize(hashtable *ht)
{
    int new_n_buckets = (ht->n_buckets) * HASHTABLE_RESIZE_RATIO;
    hashtable *new_ht = hashtable_create(new_n_buckets);

    if (new_ht)
    {
        int i;
        P_HASH("Resizing hash table, to %d\n", new_n_buckets);
        new_ht->replace_entry = 1;
        for (i = 0; i < ht->n_buckets; i++)
        {
            hashtable_entry **pe = &ht->buckets[i];
            hashtable_entry *e = *pe;
            while (e)
            {
                hashtable_entry *ne = e->next;
                hashtable_search(new_ht, e);
                *pe = ne;
                e = *pe;
            }
        }

        new_ht->replace_entry = 0;
        pdf_free(ht->buckets);
        *ht = *new_ht;
        pdf_free(new_ht);
    }
}

/**
 *  Unplug an entry from hash table, and return it.
 *  The entry disappeared from hash table, but not freed
 *  The caller of this function decides what to do about the entry
 */
hashtable_entry*
hashtable_delete_entry(hashtable *ht, hashtable_entry *ent)
{
    unsigned char *k = ent->str;
    int len = strlen(k);
    unsigned long h = nvh1a_hash(k, len);
    hashtable_entry **pe = &ht->buckets[h%ht->n_buckets];
    hashtable_entry *e = *pe;

    while (e->next)
    {
        if (strlen((char*)e->str) == len &&
            strncmp((const char*)e->str, (const char*)k, len) == 0)
        {
            break;
        }
        pe = &((*pe)->next);
        e = *pe;
    }

    if (e)
    {
        *pe = e->next;
    }
    return e;
}

void
hashtable_print(hashtable *ht)
{
    int i;
    int x = 0;
    int zeros = 0;
    int histogram[128];

    memset(histogram, 0, sizeof(histogram));

    P_HASH("Hash table stat:-------------\n");
    for (i = 0; i < ht->n_buckets; i++)
    {
        if (ht->buckets[i])
        {
            int j = 0;
            hashtable_entry *e = ht->buckets[i];

            P_HASH("Entry[%d]: ", i);
            for (; e; j++)
            {
                P_HASH("%s ", e->str);
                e = e->next;
            }
            P_HASH(" : %d entries\n", j);
            x += j;
            histogram[j]++;
        }
        else
        {
            histogram[0]++;
            zeros++;
        }
    }
    P_HASH("\nBuckets=%d, Total %d entries\n", ht->n_buckets, x);
    P_HASH("0s=%d, 1s=%d, 2s=%d, 3s=%d, 4s=%d, 5s=%d, 6s=%d, 7s=%d, 8s=%d, 9s=%d, 10s=%d\n",
           histogram[0], histogram[1], histogram[2], histogram[3], histogram[4],
           histogram[5], histogram[6], histogram[7], histogram[8], histogram[9], histogram[10]);
}

/*****************************************************************************
 *
 *  PDF Name Implementation. the names are ids outside of PDF keywords.
 *
 *****************************************************************************/

/*
 * PDF names are user defined identifiers that can be used as ids in
 * dictionaries, content streams, etc., and associate with resources.
 * The resources are things
 * like font dictionary and data, image data and structure, a graphics state,
 * a metadata dictionary, an encryption dictionary, a page structure dictionary,
 * etc.
 *
 * PDF names are used by both document structure as references to other resources
 * as well as content streams to access some particular resource as needed.
 *
 */

hashtable *
pdfname_new()
{
    return hashtable_new();
}

char*
pdfname_search(hashtable *ht, char *string)
{
    hashtable_entry e, *p;
    e.str = (unsigned char*)string;
    e.next = NULL;
    p = hashtable_search(ht, &e);
    assert(p);
    return (char*)(p->str);
}

void
pdfname_free(hashtable *ht)
{
    hashtable_free(ht);
}
