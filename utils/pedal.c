#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pdf.h"

static void
usage()
{
      const char *msg = "\
Usage: pedal [OPTIONS] -o ouput_file input_file\n\
OPTIONS:\n\
        -p : user password\n\
        -o : output directory\n\
        -d : DEVICE\n\
        --help : print this message\n\
DEVICES:\n\
        html text\n\
";
      printf("%s", msg);
}

static int
valid_device(char *dev)
{
      if (!dev)
	    return 0;
      if (strcmp(dev, "text") == 0)
	    return 1;
      else if (strcmp(dev, "html") == 0)
	    return 1;
      else
	    return 0;
}

int
main(int argc, char* argv[])
{
      int v = 1;
      char *in = 0, *out = 0, *passwd = 0, *device = 0;
      FILE *outf = 0;
      //
      pdf_err e;
      pdf_doc *doc;
      pdfcrypto *crypto = 0;

      if (argc < 4)
      {
	    usage();
	    return 1;
      }
      while (v < argc)
      {
	    if (argv[v][0] == '-')
	    {
		  if ((argv[v][1] == '-') && strncmp(&argv[v][2], "help", 4) == 0)
		  {
			usage();
			return 0;
		  }
		  if (argv[v][1] == 'd')
		  {
			// password
			v++;
			device = argv[v];
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
		  }
		  else
		  {
			printf("%s", "\nInvalid parameters!\n\n");
			usage();
			return 0;
		  }
		  v++;
	    }
	    else
	    {
		  in = argv[v];
		  break;
	    }
      } // while
      if (!(in && out && device))
      {
	    usage();
	    return 1;
      }
      if (!valid_device(device))
      {
	    printf("Invalid device: %s\nDefault to \"text\"\n", device);
	    device = "text";
      }
#ifdef DEBUG
      printf("convert %s to %s as %s\n", in, out, device);
#endif
      outf = fopen(out, "wb");
      if (!outf)
      {
	    fprintf(stderr, "Can not open %s.\n", out);
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
	    goto err1;
      }
      if (passwd && pdf_doc_need_passwd(doc) && pdf_doc_authenticate_user_password(doc, passwd) != 0)
      {
	    printf("%s\n", "Wrong user password!");
	    goto err1;
      }
      // push all pages to device
      pdf_doc_process_all(doc, device, outf, passwd);
      fclose(outf);
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
