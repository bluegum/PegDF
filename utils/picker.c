#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include "pdf.h"

static void
usage()
{
      const char *msg = "\
Usage: picker [OPTIONS] -o ouput_dir inputfile\n\
OPTIONS:\n\
        -  :\n\
        -- :\n\
             to extract all pages\n\
        -x : page numbers to be extracted\n\
             [0-9]+ | [0-9]+, | [0-9]+-[0-9]+\n\
        -i : to inflate page contents\n\
        -p : user password\n\
        -o : output directory\n\
        --help : print this message\n\
";
      printf("%s", msg);
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
      int i = 0, p;
      int v = 1;
      int inflate = 0;
      char *in = 0, *out = 0, *passwd = 0;
      num_range nr[1024];
      char *range;
      char base_name[1024];
      char *odir = out;
      //
      pdf_err e;
      pdf_doc *doc;
      pdfcrypto *crypto;
      int version = 17; // for output files
      int write_flag = 0;

      if (argc < 2)
	    return 1;
      while (v < argc)
      {
	    if (argv[v][0] == '-')
	    {
		  if ((argv[v][1] == 0) || ((argv[v][1] == '-') && (argv[v][2] == 0)))
		  {
			nr[0].bgn = 1;
			nr[0].end = 100000;
			v++;
			i++;
			continue;
		  }
		  if ((argv[v][1] == '-') && strncmp(&argv[v][2], "help", 4) == 0)
		  {
			usage();
			return 0;
		  }
		  if (argv[v][1] == 'i')
		  {
			inflate = 1;
			if (argv[v][2] == 0)
			{
			      v++;
			      continue;
			}
			else
			{
			      // fall thru
			      argv[v][1] = argv[v][2];
			}
		  }
		  if (argv[v][1] == 'x')
		  {
			v++;
			range = argv[v];
			while (*range)
			{
			      range = parse_num_range(range, &nr[i]);
			      if (nr[i].bgn == -1)
				    break;
			      i++;
			      if (i >= 1024)
				    break;
			}
			v++;
		  }
		  else if (argv[v][1] == 'p')
		  {
			// password
			v++;
			passwd = argv[v];
		  }
		  else if (argv[v][1] == 'o')
		  {
			v++;
			out = argv[v];
			v++;
		  }
		  else
		  {
			printf("%s", "\nInvalid parameters!\n\n");
			usage();
			return 0;
		  }
	    }
	    else
	    {
		  in = argv[v];
		  break;
	    }
      } // while
      if (i == 0)
      {
	    printf("%s", "\nNo page number/ranges are specified!\n\n");
	    usage();
	    return 0;
      }
      if (!in)
      {
	    printf("%s\n", "need input file");
	    return 1;
      }
      if (!out)
      {
	    printf("%s\n", "need output file");
	    return 1;
      }
      //
      e = pdf_open(in, &doc);
      if (!doc || e != pdf_ok)
      {
	    printf("failed to open %s\n", in);
	    goto err;
      }
      if (!passwd && pdf_doc_need_passwd(doc) && pdf_doc_authenticate_user_password(doc, "") != 0)
      {
	    printf("%s\n", "Need user password, use -p option");
	    goto err;
      }
      if (passwd && pdf_doc_need_passwd(doc) && pdf_doc_authenticate_user_password(doc, passwd) != 0)
      {
	    printf("%s\n", "Wrong user password!");
	    goto err;
      }
      printf("writing to %s\n", out);
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
      if (crypto)
	    pdf_crypto_destroy(crypto);
      pdf_doc_done(doc);
      pdf_finish(doc);
     return 0;
  err:
      return 1;
}
