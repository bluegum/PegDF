/*
 * A trie implementation, I call it tst_compact, I noticed the number of malloc's greatly reduced,
 * however, the total memory savings are negligible.
 * Node deletion is not implemented.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tst_compact.h"
#include "pdfmem.h"

typedef struct tnode
{
      char *s; // splitchar string
      char *k;
      void *v;
      Tptr sib, kid;
} Tnode;

Tptr tstc_new(char *k, char *s, void *val)
{
      Tptr p;
      p = (Tptr) pdf_malloc(sizeof(Tnode));
      memset(p, 0, sizeof(Tnode));
      p->s = s;
      p->k = k;
      p->v = val;
      return p;
}

Tptr tstc_sib_add(Tptr head, char *k, char *s, void *v)
{
      Tptr n = head;
      Tptr nn;
      while (n && n->sib && *n->sib->s < *s)
      {
	    n = n->sib;
      }
      nn = tstc_new(k, s, v);
      if (n == head && *head->s > *nn->s)
      {
	    nn->sib = head;
	    return nn;
      }
      if (n->sib)
      {
	    Tptr t = n->sib;
	    n->sib = nn;
	    n->sib->sib = t;
      }
      else
      {
	    n->sib = nn;
      }
      return head;
}

Tptr tstc_kid_add(Tptr head, char *k, char *s, void *v)
{
      Tptr p = head;
      while (!p->kid && *s++)
      {
	    p->kid = tstc_new(k, s, v);
	    p = p->kid;
      }
      p->s = 0;
      p->v = v;
      p->k = k;
      return p;
}

Tptr _tstc_insert(Tptr p, char *k, char *s, void *v)
{
      int i = 0;
      Tptr x, t = p, orig = p, last = p;
      if (p == 0)
      {
	    p = tstc_new(k, s, v);
	    return p;
      }
      // search siblings
      if (!p->sib && *p->s != *s)
      {
	    x = tstc_new(k, s, v);
	    if (*p->s < *s)
	    { // append
		  p->sib = x;
	    }
	    else
	    { // swap
		  x->sib = p;
		  p = x;
	    }
	    return p;
      }
      while (t && *t->s < *s) { last = t; t = t->sib; };
      if (!t)
      {
	    // append
	    last->sib = tstc_new(k, s, v);
      }
      else if (*last->s < *s && *t->s > *s)
      {
	    // insert
	    x = tstc_new(k, s, v);
	    x->sib = t;
	    last->sib = x;
      }
      else
      {	    // found head
	    x = t;
	    char *ts = t->s;
	    // iterate kid
	    while (t->kid && *ts && *s && *s==*t->s)
	    {
		  x = t;
		  t = t->kid;
		  ts++, s++;
	    }
	    // expand kid
	    if (!t->kid && *s == *ts)
	    {
		  while (!t->kid && *ts && *s && *s==*t->s)
		  {
			x = t;
			t->kid = tstc_new(t->k, ts+1, t->v);
			t = t->kid;
			s++;
			ts++;
		  }
		  // add sib
		  {
			Tptr y = tstc_sib_add(t, k, s, v);
			if (y != t)
			{ // update parent->kid
			      x->kid = y;
			}
		  }
	    }
	    else
	    { // add sib
		  Tptr y;
		  if (*t->s == *s)
		  {
			y = _tstc_insert(t, k, s, v);
		  }
		  else if (*s == 0)
		  {
			y = tstc_new(k, s, v);
			*y = *x;
			x->sib = y;
			x->kid = tstc_new(k, s, v);
			return p;
		  }
		  else
		  {
			y = tstc_sib_add(t, k, s, v);
		  }
		  if (y != t)
		  {
			if (p == t)
			      p = y;
			else
			      x->kid = y;
		  }
	    }
      }
      return p;
}

/* recursive search */
static
int
_tstc_rfind(Tptr n, char *s, void **v)
{
      int found = 0;
      *v = 0;

      if (!n)
	    return 0;
      while (n)
      {
	    if (*n->s == *s)
		  break;
	    n = n->sib;
      }
      if (!n)
	    return 0;

      if (*s == *n->s && n->kid)
      {
	    if (n->kid->s[0] == 0)
	    {
		  if (s[1] == 0)
		  {
			found = 1;
			*v = n->kid->v;
			return found;
		  }
		  else if (n->kid->sib)
			found = _tstc_rfind(n->kid->sib, s+1, v);
		  else
			found = _tstc_rfind(n->sib, s, v);
	    }
	    else
	    {
		  found = _tstc_rfind(n->kid, s+1, v);
	    }
      }
      else if (!n->kid && *n->s == *s)
      {
	    if (strcmp(n->s, s) == 0)
	    {
		  *v = n->v;
		  found = 1;
	    }
	    else
	    {
		  found = _tstc_rfind(n->sib, s, v);
	    }
      }
      else
      {
	    found = _tstc_rfind(n->kid, s+1, v);
      }
      return found;
}

int
tstc_find(Tptr p, char *s, void **v)
{
      return _tstc_rfind(p, s, v);
}

void
tstc_free(Tptr n)
{
      if (!n)
	    return;
      while (n)
      {
	    if (!n->kid)
	    {
		  Tptr p = n->sib;
		  pdf_free(n);
		  n = p;
	    }
	    else
	    {
		  if (n->kid)
		  {
			Tptr p = n->sib;
			tstc_free(n->kid);
			pdf_free(n);
			n = p;
		  }
		  else
			n = n->sib;
	    }
      }
}

void
tstc_call(Tptr n, char *k, tstc_f f, void *a)
{
      if (!n)
	    return;
      while (n)
      {
	    if (!n->kid)
        {
		  f(n->k, n->v, a);
        }
	    else
	    {
		  if (k)
		  {
			*k++ = *n->s;
			*k = 0;
		  }
		  tstc_call(n->kid, k, f, a);
	    }
	    n = n->sib;
      }
}

void
tstc_print(Tptr n)
{
      if (!n)
	    return;
      while (n)
      {
	    if (!n->kid)
		  printf("%s:0x%x\n", n->k, (int)n->v);
	    else
		  tstc_print(n->kid);
	    n = n->sib;
      }
}

Tptr tstc_insert(Tptr p, char *k, void *v)
{
      return _tstc_insert(p, k, k, v);
}

#if 0
static
void
val_free(void *v, void *a)
{
      pdf_free(v);
}

int
main(int arc, char **argv)
{
      int i;
      Tptr p, t = 0;
      void *v;

      t = tstc_insert(t, "X0", (void*)10);
      t = tstc_insert(t, "X1", (void*)0);
      t = tstc_insert(t, "X2", (void*)101);
      t = tstc_insert(t, "F1", (void*)1);
      t = tstc_insert(t, "F3", (void*)3);
      t = tstc_insert(t, "F2", (void*)2);
      t = tstc_insert(t, "abca", (void*)4);
      t = tstc_insert(t, "abcef", (void*)14);
      t = tstc_insert(t, "xquis", (void*)13);
      t = tstc_insert(t, "quick", (void*)888);
      t = tstc_insert(t, "G0", (void*)113);
      t = tstc_insert(t, "Length", (void*)1113);
      t = tstc_insert(t, "Group", (void*)1888);

      i = (int)tstc_find(t, "F2", &v);
      i = (int)tstc_find(t, "abc", &v);
      i = (int)tstc_find(t, "abcefg", &v);
      i = (int)tstc_find(t, "abcef", &v);
      i = (int)tstc_find(t, "x", &v);

      tstc_print(t);
      tstc_free(t);

      t = 0;
      v = pdf_malloc(1024);
      t = tstc_insert(t, "dummy", v);
      tstc_print(t);
      tstc_call(t, val_free, 0);
      tstc_free(t);
      return 0;
}
#endif
