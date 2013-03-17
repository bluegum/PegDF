#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tst_compact.h"
#include "pdfmem.h"

typedef struct tnode {
      unsigned char splitchar;
      Tptr lokid, eqkid, hikid;
      int leaf;
      char *k;
} Tnode;

static
Tptr
tstc_inner_new(char *k, int i, Tptr eqkid)
{
      Tptr n = (Tptr) pdf_malloc(sizeof(Tnode));
      n->splitchar = k[i];
      n->lokid = n->hikid = 0;
      n->k = k;
      n->eqkid = eqkid;
      return n;
}

Tptr _tstc_insert(Tptr p, char *k, int i, void *val)
{
      if (p == 0)
      {
	    Tptr n;
            n = (Tptr) pdf_malloc(sizeof(Tnode));
	    n->leaf = 1;
	    n->splitchar = 0;
            n->lokid = n->eqkid = n->hikid = 0;
	    n->eqkid = val;
	    n->k = k;
	    p = tstc_inner_new(k, i, n);
	    return p;
      }

      if (!p->splitchar)
      {
	    if (k[i] >= p->k[i])
	    {
		  p->hikid = _tstc_insert(p->hikid, k, i, val);
	    }
	    else
	    {
		  p->eqkid = _tstc_insert(p->lokid, k, i, val);
	    }
      }
      else if (k[i] < p->splitchar)
      {
            p->lokid = _tstc_insert(p->lokid, k, i, val);
      }
      else if (k[i] > p->splitchar)
      {
            p->hikid = _tstc_insert(p->hikid, k, i, val);
      }
      else
      {
            if (k[i] == 0)
	    {
                  p->eqkid = (Tptr)val;
	    }
	    else if (p->splitchar)
	    {
		  Tptr t;
		  t = p->eqkid;
		  if (t->leaf)
		  {
			int eq = strcmp(k, t->k);
			if (eq > 0)
			{
			      t->hikid = _tstc_insert(t->hikid, k, i+1, val);
			}
			else if (eq < 0)
			{
			      t->lokid = _tstc_insert(t->lokid, k, i+1, val);
			}
			else
			{
			      // replace value
			      t->eqkid = val;
			}
		  }
		  else
		  {
			p->eqkid = _tstc_insert(t->eqkid, k, i+1, val);
		  }
	    }
	    else
	    {
		  p = _tstc_insert(p->eqkid, k, i+1, val);
	    }
      }
      return p;
}

Tptr
tstc_insert(Tptr p, char *k, void *val)
{
      return _tstc_insert(p, k, 0, val);
}

/* recursive search */
static
void*
_tstc_rfind(Tptr p, char *s, int i)
{
      if (!p) return 0;
      if (!p->splitchar)
      {
	    int eq = strcmp(s, &p->k[i]);
	    if (eq == 0)
	    {
		  return p->eqkid;
	    }
	    else if (eq > 0)
	    {
		  return _tstc_rfind(p->hikid, s, i);
	    }
	    else
	    {
		  return _tstc_rfind(p->lokid, s, i);
	    }
      }
      if (*s < p->splitchar)
      {
            return _tstc_rfind(p->lokid, s, i);
      }
      else if (*s > p->splitchar)
            return _tstc_rfind(p->hikid, s, i);
      else
      {
            return _tstc_rfind(p->eqkid, ++s, ++i);
      }
}

void*
tstc_find(Tptr p, char *s)
{
      return _tstc_rfind(p, s, 0);
}

Tptr tstc_init()
{
      return  _tstc_insert(0, 0, 0, 0);
}

void
tstc_free(Tptr n)
{
      if (!n)
      {
	    return;
      }
      if (!n->splitchar)
      {
	    tstc_free(n->lokid);
	    tstc_free(n->hikid);
	    pdf_free(n);
      }
      else
      {
	    tstc_free(n->lokid);
	    tstc_free(n->eqkid);
	    tstc_free(n->hikid);
	    pdf_free(n);
      }
}

void
tstc_call(Tptr n, tstc_f f)
{
      if (!n)
      {
	    return;
      }
      if (!n->splitchar)
      {
	    tstc_call(n->lokid, f);
	    tstc_call(n->hikid, f);
	    f(n->eqkid);
      }
      else
      {
	    tstc_call(n->lokid, f);
	    tstc_call(n->eqkid, f);
	    tstc_call(n->hikid, f);
      }
}

void
tstc_print(Tptr n)
{
      if (!n)
      {
	    return;
      }
      if (!n->splitchar)
      {
	    printf("%s:0x%08x\n", n->k, (int)n->eqkid);
	    if (n->hikid)
	    {
		  tstc_print(n->hikid);
	    }
	    else
	    {
		  tstc_print(n->lokid);
	    }
      }
      else
      {
	    tstc_print(n->lokid);
	    tstc_print(n->eqkid);
	    tstc_print(n->hikid);
      }
}

#if 1
static
void
val_free(void *v)
{
      pdf_free(v);
}

int
main(int arc, char **argv)
{
      int i;
      Tptr p, t = 0;
      void *v;

      t = tstc_insert(t, "quick", 888);
      t = tstc_insert(t, "a", (void*)11);
      t = tstc_insert(t, "a0", 21);
      t = tstc_insert(t, "a1", 22);
      t = tstc_insert(t, "a2", 23);
      t = tstc_insert(t, "b", 12);
      t = tstc_insert(t, "abc", 1);
      t = tstc_insert(t, "abcd", 2);
      t = tstc_insert(t, "abce", 3);
      t = tstc_insert(t, "abcef", 4);
      t = tstc_insert(t, "x", 13);

      i = tstc_find(t, "abcd");
      i = tstc_find(t, "abc");
      i = tstc_find(t, "abcefg");
      i = tstc_find(t, "abcef");
      i = tstc_find(t, "x");

      tstc_print(t);
      tstc_free(t);

      t = 0;
      v = pdf_malloc(1024);
      t = tstc_insert(t, "dummy", v);
      tstc_print(t);
      tstc_call(t, val_free);
      tstc_free(t);
      return 0;
}
#endif
