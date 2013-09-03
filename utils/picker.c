#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <getopt.h>
#include "pdf.h"

static int show_help;

static struct option const long_options[] =
{
    {"help", no_argument, &show_help, 1},
    {0, 0, 0, 0}
};

static void
usage(int status)
{
    const char *msg = "\
Usage: picker [OPTIONS] -o ouput_dir inputfile\n\
OPTIONS:\n\
 -x : page numbers to be extracted\n\
 [0-9]+ | [0-9]+, | [0-9]+-[0-9]+\n\
 -i : to inflate page contents\n\
 -p : user password\n\
 -o : output directory\n\
 --help : print this message\n\
\n\
example:\n\
\n\
 picker -io DIR in.pdf \n\
 extracts every single page into directory \"DIR\" \n\
";
    printf("%s", msg);
    exit (status);
}

typedef struct num_range_s
{
    int bgn;
    int end;
} num_range;

static int
parse_num(char *bgn, char *end)
{
    int i = 0;
    while (bgn <= end)
    {
	    i *= 10;
	    i += (*bgn++) - '0';
    }
    return i;
}

static char *
parse_num_range(char *s, num_range *nr)
{
    char *beg = s;
    int bgn = -1, end = -1;

    while (*s)
    {
	    if (*s && (*s >= '0' && *s <= '9'))
	    {
            s++;
	    }
	    else if (*s == '-')
	    {
            bgn = parse_num(beg, s-1);
            beg = ++s;
            while (*s)
            {
                if (*s == ',')
                {
                    end = parse_num(beg, s-1);
                    break;
                }
                else
                {
                    s++;
                }
            }
            if (!(*s) || (*s == ','))
            {
                end = parse_num(beg, s-1);
                nr->bgn = bgn;
                nr->end = end;
                if (*s == ',')
                    s++;
                return s;
            }
            else
                return 0;
	    }
	    else if (*s == ',')
	    {
            bgn = end = parse_num(beg, s-1);
            s++;
            break;
	    }
	    else
            break;
    }
    if (*s == 0 && s > beg)
    {
	    bgn = end = parse_num(beg, s-1);
    }
    nr->bgn = bgn;
    nr->end = end;
    return s;
}

int
main(int argc, char* argv[])
{
    int i = 0, p, c, option_index;
    int inflate = 0;
    char in[1024], out[1024], passwd[1024];
    num_range nr[1024];
    char *range;
    char base_name[1024];
    char *odir = out;
    //
    pdf_err e;
    pdf_doc *doc;
    pdfcrypto *crypto = 0;
    int version = 17; // for output files
    int write_flag = 0;

    in[0] = 0;
    out[0] = 0;
    passwd[0] = 0;
    nr[0].bgn = 1;
    nr[0].end = 100000;

    if (argc < 2)
	    usage(EXIT_SUCCESS);

    while (1)
    {
        c = getopt_long(argc, argv, "io:p:x:",
                        long_options, &option_index);
        if (c == -1)
            break;
        switch (c)
        {
            case 'i':
                inflate = 1;
                break;
            case 'o':
                strncpy(out, optarg, 1023);
                break;
            case 'x':
                range = optarg;
                if (range[0] < '0' || range[0] > '9')
                {
                    usage(EXIT_SUCCESS);
                    break;
                }
                while (range)
                {
                    range = parse_num_range(range, &nr[i]);
                    if (nr[i].bgn == -1)
                        break;
                    i++;
                    if (i >= 1024)
                        break;
                }
                break;
            case 'p':
                // password
                strncpy(passwd, optarg, 1023);
                break;
            case 0:
                // long option
                break;
            default:
                usage(EXIT_SUCCESS);
                break;
        }
    } // while

    if (show_help)
        usage (EXIT_SUCCESS);

    if (optind < argc)
    {
        strncpy(in, argv[optind], 1023);
    }

    if (!in[0])
        usage (EXIT_SUCCESS);

    if (!out[0])
        usage (EXIT_SUCCESS);

    if (i == 0)
    {
        i = 1;
    }
    //
    e = pdf_open(in, &doc);
    if (!doc || e != pdf_ok)
    {
	    printf("failed to open %s\n", in);
	    goto err;
    }
    if (!passwd[0] && pdf_doc_need_passwd(doc) && pdf_doc_authenticate_user_password(doc, "") != 0)
    {
	    printf("%s\n", "Need user password, use -p option");
	    goto err1;
    }
    if (passwd[0] && pdf_doc_need_passwd(doc) && pdf_doc_authenticate_user_password(doc, passwd) != 0)
    {
	    printf("%s\n", "Wrong user password!");
	    goto err1;
    }
#ifdef DEBUG
    printf("writing to %s\n", out);
#endif
    if (inflate)
	    write_flag |= WRITE_PDF_CONTENT_INFLATE;
    if (pdf_doc_need_passwd(doc))
    {
	    crypto = pdf_crypto_load(doc, passwd);
    }
    // make output directory
    {
	    struct stat s;
	    int err;
	    odir = out;
	    if ((err = stat(odir, &s)) == 0)
	    {
            if ((!(S_ISDIR(s.st_mode))) && (S_ISREG(s.st_mode)))
            {
                e = pdf_file_err;
                goto err;
            }
	    }
	    if (err || (!S_ISDIR(s.st_mode)))
	    {
            err = mkdir(odir, S_IRWXU | S_IRWXG);
            if (err != 0)
            {
                e = pdf_file_err;
                goto err;
            }

	    }
	    else if (err == 0 && (!S_ISDIR(s.st_mode)))
	    {
            e = pdf_file_err;
            goto err;
	    }

    }
    strcpy(base_name, basename(in));
    {
	    char *base_stem =
            strchr(base_name, '.');
	    if (base_stem)
            *base_stem = 0;
    }
    for (p = 0; p < i; p++)
    {
	    int x = nr[p].bgn;
	    int y = nr[p].end;
	    for (; x<=y; x++)
	    {
            char buf[1024];
            sprintf(buf, "%s/%s-%d.pdf", odir, base_name, x);
            if (x <= pdf_doc_page_count(doc))
            {
#ifdef DEBUG
                printf("writing page %d to %s\n", x, buf);
#endif
                // page start at 1 for user
                pdf_page_write(doc, x-1, write_flag, crypto, version, buf);
            }
	    }
    }
    // done
  err1:
    if (crypto)
	    pdf_crypto_destroy(crypto);
    pdf_doc_done(doc);
    pdf_finish(doc);
    return 0;
  err:
    return 1;
}
