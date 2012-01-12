#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "bplustree.h"


static bp_node*
bp_new_node(int leaf)
{
   bp_node *node;
   node = malloc(sizeof(bp_node));
   if (!node)
   {
      return NULL;
   }
   memset(node, 0, sizeof(bp_node));
   node->leaf = leaf;
   if (leaf)
   {
#ifdef BP_LEAF_LINEAR
      node->k = NULL;
#else
      node->k = malloc(sizeof(int)*BP_ORDER_LEAF);
#endif
      node->v = malloc(sizeof(void*)*BP_ORDER_LEAF);
      memset(node->v, 0, (sizeof(void*)*BP_ORDER_LEAF));
   }
   else
   {
      node->k = malloc(sizeof(int)*BP_ORDER_INNER);
      node->v = malloc(sizeof(bp_node*)*BP_ORDER_INNER+1);
      memset(node->v, 0, (sizeof(void*)*BP_ORDER_INNER+1));
   }
   return node;
}


bp_tree*
bp_new_tree()
{
   bp_tree *t = malloc(sizeof(bp_tree));
   if (!t)
      return 0;
   t->root = bp_new_node(1);
   if (!t->root)
   {
      free(t);
      return 0;
   }
   else
   {
      return t;
   }
}

int bp_node_low(bp_node *n)
{
   if (n->leaf)
   {
#ifdef BP_LEAF_LINEAR
      return n->low;
#else
      return n->k[0];
#endif
   }
   else
   {
      return n->k[0];
   }
}

bp_node *
bp_insert_leaf(bp_node *r, int i, void *d)
{
#ifdef BP_LEAF_LINEAR
   bp_node *n = r;
   assert(r->leaf);
   if (r->low + BP_ORDER_LEAF < i || r->low > i)
   {
      /* split leaf */
      n = bp_new_node(1); /* new leaf */
      if (r->low > i)
      {
	 r->next = n;
      }
      else
      {
	 n->next = r->next;
	 r->next = n;
      }
      n->low = i / BP_ORDER_LEAF * BP_ORDER_LEAF;
      bp_insert_leaf(n, i, d);
   }
   /* insert is easy */
   n->v[i-r->low].d = d;
   return n;
#else
   int k;
   assert(r->leaf);
   if (r->cnt >= BP_ORDER_LEAF)
   {
      /* split leaf */
   }
   for (k = 0; k < BP_ORDER_LEAF; k++)
   {
      if (i > r->k[k] && i <= r->k[k+1])
      {
	 /* insert */
	break;
      }
   }
   return r;
#endif
}

bp_node *
bp_insert_inner(bp_node *r, int i, void *d)
{
   bp_node *n;
   if (!r)
   {
      r = bp_new_node(1/* leaf */);
   }
   for (n = r;;)
   {
      int k = 0;
      for (; i > n->k[k] && k < BP_ORDER_INNER; k++);
      if (k != BP_ORDER_INNER && i <= n->k[k])
      {
	 if (n->leaf)
	 {
	    bp_node *t = bp_insert_leaf(n, i, d);
	    if (t != n)
	    {
	       /* maybe split */
	    }
	 }
	 else
	 {
	    bp_node *tt = n->v[k].n;
	    bp_node *t = bp_insert_inner(tt, i, d);
	    if (t != tt)
	    {
	       /* maybe split */
	    }
	 }
      }
   }
   return r;
}

bp_node*
bp_search(bp_tree *t, int i)
{
   if (!t)
   {
      return 0;
   }
   return 0;
}

int bp_upper(bp_node *n)
{
   if (n->leaf)
   {
#ifdef BP_LEAF_LINEAR
      return n->low+BP_ORDER_LEAF;
#else
      return n->k[n->cnt];
#endif
   }
   return n->k[n->cnt];
}

int
bp_insert(bp_tree *t, int i, void *d)
{
   bp_node *n;
   if (!t)
      return 0;
   if (!t->root)
      return 0;
   n = t->root;
   if (n->leaf)
   {
      bp_node *a;
      a = bp_insert_leaf(n, i, d);
      if (a!=n)
      {
	 /* has splitted, need a new root */
	 bp_node *b;
	 t->root = bp_new_node(0);
	 if (!t->root)
	    return 0;
	 b = t->root;
	 if (bp_upper(a) < bp_upper(n))
	 {
	    b->k[0] = bp_upper(a);
	    b->v[0].n = a;
	    b->v[1].n = n;
	 }
	 else
	 {
	    b->k[0] = bp_upper(n);
	    b->v[0].n = n;
	    b->v[1].n = a;
	 }
      }
   }
   else
   {
      bp_insert_inner(n, i, n);
   }
   return 0;
}

void
bp_destroy_leaf(bp_node *n)
{
#ifndef BP_LEAF_LINEAR
   free(n->k);
#endif
   free(n->v);
}

void
bp_destroy_inner(bp_node *n)
{
   int c = 0;
   for (; c < n->cnt; c++)
   {
      if (n->v[c].n->leaf)
	 bp_destroy_leaf(n->v[c].n);
      else
	 bp_destroy_inner(n->v[c].n);
   }
   free(n->k);
   free(n->v);
}

void
bp_destroy(bp_tree *t)
{
   if (!t)
      return;
   if (!t->root)
      return;
   if (t->root->leaf)
   {
      bp_destroy_leaf(t->root);
      return;
   }
   else
   {
      bp_destroy_inner(t->root);
   }
}
