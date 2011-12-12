#include <stdio.h>
#include <stdlib.h>
#include "tst.h"

typedef struct tnode {
   unsigned char splitchar;
   Tptr lokid, eqkid, hikid;
} Tnode;


Tptr tst_insert(Tptr p, char *s, void *val)
{
   if (p == 0) {
      p = (Tptr) malloc(sizeof(Tnode));
      if (s)
      {
	 p->splitchar = *s;
      }
      else
      {
	 p->splitchar = 0;
      }
      p->lokid = p->eqkid = p->hikid = 0;
      if (!s)
	 return p;
   }
   if (*s < p->splitchar)
      p->lokid = tst_insert(p->lokid, s, val);
   else if (*s == p->splitchar) {
      if (*s == 0)
	 p->eqkid = (Tptr)val;
      else
	 p->eqkid = tst_insert(p->eqkid, ++s, val);
   } else
      p->hikid = tst_insert(p->hikid, s, val);
   return p;
}

void tst_cleanup(Tptr p)
{   if (p) {
      tst_cleanup(p->lokid);
      if (p->splitchar) tst_cleanup(p->eqkid);
      tst_cleanup(p->hikid);
      free(p);
   }
}

/* iterative search */
Tptr tst_search(Tptr root, char *s)
{
   Tptr p;
   p = root;
   while (p) {
      if (*s < p->splitchar)
	 p = p->lokid;
      else if (*s == p->splitchar)  {
	 if (*s++ == 0)
	    return p;
	 p = p->eqkid;
      } else
	 p = p->hikid;
   }
   return 0;
}

/* recursive search */
int tst_rsearch(Tptr p, char *s)
{   if (!p) return 0;
   if (*s < p->splitchar)
      return tst_rsearch(p->lokid, s);
   else if (*s > p->splitchar)
      return tst_rsearch(p->hikid, s);
   else {
      if (*s == 0) return 1;
      return tst_rsearch(p->eqkid, ++s);
   }
}

void * tst_delete(Tptr p, char *s)
{
   Tptr last_p = p;
   void * val= 0;
   char *last_s = s;

   if (!s)
   {
      return NULL;
   }
   while (p)
   {
      if (*s == p->splitchar)
      {
	 if (*s++ == 0)
	 {
	    val = (void*)(p->eqkid);
	    break;
	 }
	 p = p->eqkid;
      }
      else
      {
	 last_s = s;
	 if (*s < p->splitchar)
	    p = p->lokid;
	 else
	    p = p->hikid;
	 if (p->lokid || p->hikid)
	 {
	    last_p = p;
	 }
      }
   }
   if (last_p && p) /* the node holds common prefix */
   {
      if (last_p->splitchar == *last_s)
      {
	 if (last_p->eqkid)
	 {
	    if (last_p->eqkid->hikid)
	    {
	       Tptr tt = last_p->eqkid;
	       last_p->eqkid = last_p->eqkid->hikid;
	       free(tt);
	    }
	    else
	    {
	       tst_cleanup(last_p->eqkid);
	       last_p->eqkid = NULL;
	    }
	 }
      }
      else if (last_p->hikid)
      {
	 if (last_p->hikid->splitchar == *last_s)
	 {
	    tst_cleanup(last_p->hikid);
	    last_p->hikid = NULL;
	 }
	 else if ((last_p->lokid) && (last_p->lokid->splitchar == *last_s))
	 {
	    tst_cleanup(last_p->lokid);
	    last_p->lokid = NULL;
	 }
	 else if (last_p->eqkid)
	 {
	    goto eqkid;
	 }
      }
      else if (last_p->lokid)
      {
	 if (last_p->lokid->splitchar == *last_s)
	 {
	    tst_cleanup(last_p->lokid);
	    last_p->lokid = NULL;
	 }
      }
      else if (last_p->eqkid)
      {
	 Tptr tt;
	eqkid:
	 tt = last_p->eqkid;
	 if (tt->splitchar == 0)
	 {
	    if (tt->hikid && tt->hikid->splitchar == *last_s)
	    {
	       tst_cleanup(tt->hikid);
	       tt->hikid = NULL;
	    }
	 }
      }
   }
   return val;
}
#if 0
void pmsearch(Tptr p, char *s)
{   if (!p) return;
   if (*s == '.' || *s < p->splitchar)
      pmsearch(p->lokid, s);
   if (*s == '.' || *s == p->splitchar)
      if (p->splitchar && *s)
	 pmsearch(p->eqkid, s+1);
   if (*s == 0 && p->splitchar == 0)
      srcharr[srchtop++] =
	 (char *) p->eqkid;
   if (*s == '.' || *s > p->splitchar)
      pmsearch(p->hikid, s);
}


void nearsearch(Tptr p, char *s, int d)
{   if (!p || d < 0) return;
   if (d > 0 || *s < p->splitchar)
      nearsearch(p->lokid, s, d);
   if (p->splitchar == 0) {
      if ((int) strlen(s) <= d)
	 srcharr[srchtop++] = (char *) p->eqkid;
   } else
      nearsearch(p->eqkid, *s ? s+1:s,
		 (*s == p->splitchar) ? d:d-1);
   if (d > 0 || *s > p->splitchar)
      nearsearch(p->hikid, s, d);
}
#endif

static char frame[1024];
static char *f = frame;
void tst_traverse(Tptr p, tst_hook callback)
{
   if (!p) {return;}
   tst_traverse(p->lokid, callback);
   if (p->splitchar)
   {
      *f++ = p->splitchar;
      tst_traverse(p->eqkid, callback);
      f--;
   }
   else
   {
      char *t = frame;
      *f = 0;
      callback(t, p->eqkid);
   }
   tst_traverse(p->hikid, callback);
}

Tptr tst_init()
{
   return  tst_insert(0, 0, 0);
}
int tst_attach(Tptr p, void *val)
{
   if (!p->splitchar)
   {
      p->eqkid = (Tptr)val;
      return 0;
   }
   return 1;
}
void* tst_retrieve(Tptr p)
{
   if (!p->splitchar)
   {
      return (void*)(p->eqkid);
   }
   else
   {
      return 0;
   }
}
