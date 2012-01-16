#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "bplustree.h"

typedef struct
{
   int split;
   int n;
   bpt_node *left;
   bpt_node *right;
} bpt_split;

bpt_split bpt_insert_leaf(bpt_node *r, int i, void *d);
int bpt_upper(bpt_node *n);
int bpt_lower(bpt_node *n);

static bpt_node*
bpt_new_node(int leaf)
{
   bpt_node *node;
   node = malloc(sizeof(bpt_node));
   if (!node)
   {
      return NULL;
   }
   memset(node, 0, sizeof(bpt_node));
   node->leaf = leaf;
   if (leaf)
   {
#ifdef BPT_LEAF_LINEAR
      node->k = NULL;
#else
      node->k = malloc(sizeof(int)*BPT_ORDER_LEAF);
#endif
      node->v = malloc(sizeof(void*)*BPT_ORDER_LEAF);
      memset(node->v, 0, (sizeof(void*)*BPT_ORDER_LEAF));
   }
   else
   {
      node->k = malloc(sizeof(int)*BPT_ORDER_INNER);
      node->v = malloc(sizeof(bpt_node*)*BPT_ORDER_INNER+1);
      memset(node->v, 0, (sizeof(void*)*BPT_ORDER_INNER+1));
   }
   return node;
}

bpt_tree*
bpt_new_tree()
{
   bpt_tree *t = (bpt_tree*)malloc(sizeof(bpt_tree));
   if (!t)
      return 0;
   t->root = bpt_new_node(1);
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

int bpt_node_low(bpt_node *n)
{
   if (n->leaf)
   {
#ifdef BPT_LEAF_LINEAR
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

bpt_split
bpt_insert_leaf(bpt_node *r, int i, void *d)
{
   bpt_split s;
#ifdef BPT_LEAF_LINEAR
   bpt_node *n = r;
   assert(r->leaf);

   s.split = 0;
   if (r->low + BPT_ORDER_LEAF < i || r->low > i)
   {
      /* split leaf */
      n = bpt_new_node(1); /* new leaf */
      if (r->low > i)
      {
	 r->next = n;
      }
      else
      {
	 n->next = r->next;
	 r->next = n;
      }
      n->low = i / BPT_ORDER_LEAF * BPT_ORDER_LEAF;
      bpt_insert_leaf(n, i, d);
      s.left = r;
      s.right = n;
      s.n = n->low;
      s.split = 1;
   }
   else
   {
      /* insert is easy */
      n->v[i-r->low].d = d;
      n->cnt += 1;
   }
   return s;
#else
   int k;
   assert(r->leaf);
   if (r->cnt >= BPT_ORDER_LEAF)
   {
      /* split leaf */
   }
   for (k = 0; k < BPT_ORDER_LEAF; k++)
   {
      if (i > r->k[k] && i <= r->k[k+1])
      {
	 /* insert */
	 break;
      }
   }
   return s;
#endif
}

bpt_split
bpt_split_inner(bpt_node *r, bpt_split *k)
{
   int i, j, m;
   bpt_node *n, *n1 = 0;
   int mid = (r->cnt+1)/2;
   bpt_split s;
   s.split = 1;
   n = bpt_new_node(0);
   for (i = 0, j = 0; i < r->cnt; i++, j++)
   {
      if (i > mid)
      {
	 break;
      }
      if (k->n < r->k[i])
      {
	 n1 = r;
      }
   }
   if (!n1)
   {
      n1 = n;
   }
   n->v[j].n = r->v[i].n;
   n->cnt = mid;
   r->cnt -= mid;
   /* find k belongs to which into n1 */
   for (i = 0; i < n1->cnt; i++)
   {
      if (k->n > n1->k[i])
      {
	 break;
      }
   }
   if (i == n1->cnt)
   {
      /* insert into the first */
      i = 0;
   }
   n1->cnt = mid;
   /* shuffle half into new node */
   for(j=mid, m = 1; j > 0; j--, m++)
   {
      n->k[n->cnt-m] = r->k[r->cnt-m-1];
      n->v[n->cnt-m+1].n = r->v[r->cnt-m].n;
   }
   n->v[0].n = r->v[i+1].n;
   /* insert k into n1 */
   for (i = 0; i < n1->cnt; i++)
   {
      if (k->n > n1->k[i])
      {
	 break;
      }
   }
   if (i == n1->cnt)
   {
      /* insert into the first */
      i = 0;
   }
   for (j = n1->cnt-1; j >= i; j--)
   {
      n1->k[j+1] = n1->k[0];
      n1->v[j+2].n = n1->v[j+1].n;
   }
   n1->k[i] = k->n;
   n1->v[i].n = k->left;
   n1->cnt += 1;
   /* pluck out a key from n1 */
   if (bpt_lower(n1) < bpt_lower(n))
   {
      s.n = n1->k[n1->cnt-1];
      s.left = n1;
      s.right = n;
      n->v[0].n = n1->v[n1->cnt].n;
   }
   else
   {
      s.n = n1->k[0];
      s.left = n;
      s.right = n1;
      n->v[n->cnt].n = n1->v[0].n;
      /* n1 shuffle back by 1 element */
      for (i = 0; i < n1->cnt-1; i++)
      {
	 n1->k[i] = n1->k[i+1];
	 n1->v[i].n = n1->v[i+1].n;
      }
   }
   n1->cnt -= 1;
   s.split = 1;
   return s;
}

bpt_split
bpt_insert_inner(bpt_node *r, int i, void *d)
{
   bpt_split s;
   bpt_node *n = r;
   int k = 0;

   s.split = 0;

   if (!r)
   {
      r = bpt_new_node(1/* leaf */);
   }

   for (k = 0; i > n->k[k] && k < r->cnt; k++);

   if (k <= BPT_ORDER_INNER && k < r->cnt && k > 0)
   {
      n = n->v[k-1].n;
   }
   else
   {
      n = n->v[k].n;
   }
   if (n->leaf)
   {
      s = bpt_insert_leaf(n, i, d);
   }
   else
   {
      s = bpt_insert_inner(n, i, d);
   }
   if (s.split)
   {
      if (r->cnt >= BPT_ORDER_INNER)
      {
	 s = bpt_split_inner(r, &s);
      }
      else
      {
	 int m;
	 /* insert split */
	 for (m=0;m<r->cnt;m++)
	 {
	    if (r->k[m] > i)
	       break;
	 }
	 if (m != r->cnt)
	 {
	    int c;
	    c = r->cnt;
	    for (; m < c; c--)
	    {
	       r->k[c] = r->k[c-1];
	       r->v[c+1] = r->v[c];
	    }
	    /* insert new node */
	    r->k[m] = s.n;
	    r->v[m].n = s.left;
	    r->v[m+1].n = s.right;
	 }
	 else
	 {
	    if (s.n > r->k[m-1])
	    {
	       if (s.n < bpt_lower(r->v[m].n))
	       {
		  r->k[m] = s.n;
		  r->v[m+1].n = r->v[m].n;
		  r->v[m].n = s.left;
	       }
	       else
	       {
		  r->k[m] = s.n;
		  r->v[m+1].n = s.right;
	       }
	    }
	    else
	    {
	       r->k[m] = s.n;
	       r->v[m+1].n = r->v[m].n;
	       r->v[m].n = s.left;
	    }
	 }
	 s.split = 0;
	 r->cnt += 1;
      }
   }

   return s;
}

bpt_node*
bpt_search(bpt_tree *t, int i)
{
   if (!t)
   {
      return 0;
   }
   return 0;
}

int bpt_upper(bpt_node *n)
{
   if (n->leaf)
   {
#ifdef BPT_LEAF_LINEAR
      return n->low+BPT_ORDER_LEAF;
#else
      return n->k[n->cnt];
#endif
   }
   return n->k[n->cnt];
}

int bpt_lower(bpt_node *n)
{
   if (n->leaf)
   {
#ifdef BPT_LEAF_LINEAR
      return n->low;
#else
      return n->k[0];
#endif
   }
   return n->k[0];
}

int
bpt_insert(bpt_tree *t, int i, void *d)
{
   bpt_node *n;
   if (!t)
      return 0;
   if (!t->root)
      return 0;
   n = t->root;
   if (n->leaf)
   {
      bpt_split s;
      s = bpt_insert_leaf(n, i, d);
      if (s.split)
      {
	 /* has splitted, need a new root */
	 bpt_node *b;
	 t->root = bpt_new_node(0);
	 if (!t->root)
	    return 0;
	 b = t->root;
	 b->k[0] = s.n;
	 b->v[0].n = s.left;
	 b->v[1].n = s.right;
	 b->cnt += 1;
      }
   }
   else
   {
      bpt_split s = bpt_insert_inner(n, i, d);
      if (s.split)
      {
	 /* create a new super node */
	 t->root = bpt_new_node(0);
	 t->root->k[0] = s.n;
	 t->root->v[0].n = s.left;
	 t->root->v[1].n = s.right;
	 t->root->cnt = 1;
      }
   }
   return 0;
}

void
bpt_destroy_leaf(bpt_node *n)
{
#ifndef BPT_LEAF_LINEAR
   free(n->k);
#endif
   free(n->v);
}

void
bpt_destroy_inner(bpt_node *n)
{
   int c = 0;
   for (; c < n->cnt; c++)
   {
      if (n->v[c].n->leaf)
	 bpt_destroy_leaf(n->v[c].n);
      else
	 bpt_destroy_inner(n->v[c].n);
   }
   free(n->k);
   free(n->v);
}

void
bpt_destroy(bpt_tree *t)
{
   if (!t)
      return;
   if (!t->root)
      return;
   if (t->root->leaf)
   {
      bpt_destroy_leaf(t->root);
      return;
   }
   else
   {
      bpt_destroy_inner(t->root);
   }
}

static void
bpt_walk_node(bpt_node* n)
{
   int i;
   if (!n)
      return;
   if (n->leaf)
   {
      printf("leaf:  ");
#ifdef BPT_LEAF_LINEAR
      for (i = 0; i < BPT_ORDER_LEAF; i++)
      {
	 if (n->v[i].n)
	    printf("%d..", n->low + i);
      }
#else
      for (i = 0; i < n->cnt; i++)
      {
	 printf("%d..", n->k[i]);
      }
#endif
      printf("\n");
   }
   else
   {
      for (i = 0; i < n->cnt; i++)
      {
	 printf("inner:  %d\n", n->k[i]);
	 bpt_walk_node(n->v[i].n);
      }
      bpt_walk_node(n->v[i].n);
   }
}
void
bpt_walk(bpt_tree* t)
{
   if (!t)
      return;
   bpt_walk_node(t->root);
}
