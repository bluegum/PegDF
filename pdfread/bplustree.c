#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "bplustree.h"
#include "pdfmem.h"

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

bpt_node*
bpt_new_node(int leaf)
{
      bpt_node *node;
      node = pdf_malloc(sizeof(bpt_node));
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
            node->k = pdf_malloc(sizeof(int)*BPT_ORDER_LEAF);
            memset(node->k, 0, (sizeof(int)*BPT_ORDER_LEAF));
#endif
            node->v = pdf_malloc(sizeof(void*)*BPT_ORDER_LEAF);
            memset(node->v, 0, (sizeof(void*)*BPT_ORDER_LEAF));
      }
      else
      {
            node->k = pdf_malloc(sizeof(int)*BPT_ORDER_INNER);
            memset(node->k, 0, (sizeof(int)*BPT_ORDER_INNER));
            node->v = pdf_malloc(sizeof(bpt_node*)*(BPT_ORDER_INNER+1));
            memset(node->v, 0, (sizeof(void*)*(BPT_ORDER_INNER+1)));
      }
      return node;
}

bpt_tree*
bpt_new_tree(int n)
{
      bpt_tree *t = (bpt_tree*)pdf_malloc(sizeof(bpt_tree));
      if (!t)
            return 0;
      t->root = bpt_new_node(1);
      if (!t->root)
      {
            pdf_free(t);
            return 0;
      }
      else
      {
            if (t->root->leaf)
                  t->root->low = n/BPT_ORDER_LEAF*BPT_ORDER_LEAF;
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
      if (r->low + BPT_ORDER_LEAF <= i || r->low > i)
      {
            /* split leaf */
            n = bpt_new_node(1); /* new leaf */
            if (r->low < i)
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
            if (r->low > n->low)
            {
                  s.left = n;
                  s.right = r;
                  s.n = r->low;
            }
            else
            {
                  s.left = r;
                  s.right = n;
                  s.n = n->low;
            }
            s.split = 1;
      }
      else
      {
            /* insert is easy */
	    if (!n->v[i-r->low].d)
	    {
		  n->cnt += 1;
	    }
            n->v[i-r->low].d = d;
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
      int i, j;
      bpt_node *n, *n1 = 0;
      int mid = (r->cnt)/2;
      bpt_split s;
      bpt_node *left, *right;

      s.split = 1;
      n = bpt_new_node(0);

      for (i = mid; i < r->cnt; i++)
      {
            if (k->n > r->k[i])
            {
                  mid += 1;
            }
            else
                  break;
      }

      if (bpt_upper(r) <= k->n)
      {
            s.n = k->n;
            s.left = r;
            s.right = n;
            n->k[0] = bpt_upper(k->right);
            n->v[0].n = k->right;
            n->cnt += 1;
            return s;
      }
      /* shuffle half into new node */
      for(j=mid, i = 0; j < BPT_ORDER_INNER; j++, i++)
      {
            n->k[i] = r->k[j];
            n->v[i] = r->v[j];
      }
      n->cnt = i;
      n->v[i] = r->v[j];
      n->v[j].n = r->v[i].n;
      r->cnt -= i;
      /* find k belongs to n1 */
      if (k->n < n->k[0])
      {
            n1 = r;
      }
      else
      {
            n1 = n;
      }
      /* find k in n1 */
      for (i = 0; i < n1->cnt; i++)
      {
            if (k->n < n1->k[i])
            {
                  break;
            }
      }
      /* shuffle the rest of n1 by 1 */
      for (j = BPT_ORDER_INNER-1; j > i; j--)
      {
            n1->k[j] = n1->k[j-1];
            n1->v[j+1].n = n1->v[j].n;
      }
      /* insert */
      n1->k[i] = k->n;
      n1->v[i].n = k->left;
      n1->v[i+1].n = k->right;
      n1->cnt += 1;
      /* pluck out a key from n1 */
      n = (n1==n)?(r):(n);
      if (bpt_lower(n1) < bpt_lower(n))
      {
            left = n1;
            right = n;
      }
      else
      {
            left = n;
            right = n1;
      }
      if (left->cnt > right->cnt)
      {
            s.n = left->k[left->cnt-1];
            right->v[0] = left->v[left->cnt];
            left->cnt -= 1;
      }
      else
      {
            s.n = right->k[0];
            /* right shuffle back by 1 element */
            for (i = 0; i < right->cnt-1; i++)
            {
                  right->k[i] = right->k[i+1];
                  right->v[i].n = right->v[i+1].n;
            }
            right->v[i] = right->v[i+1];
            right->cnt -= 1;
      }
      s.left = left;
      s.right = right;
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
      else
      {
            if (r->cnt == 0)
            {
                  bpt_node *l = bpt_new_node(1);
                  s = bpt_insert_leaf(l, i, d);
                  r->k[0] = bpt_upper(l);
                  r->v[0].n = l;
                  r->cnt += 1;
                  return s;
            }
      }
      for (k = 0; k < r->cnt && (i > n->k[k]); k++);

      if (k == BPT_ORDER_INNER)
            n = n->v[k].n;
      else if (n->k[k] == i)
            n = n->v[k+1].n;
      else
            n = n->v[k].n;

      if (!n)
      {
            n = bpt_new_node(1);
            n->low = i/BPT_ORDER_LEAF*BPT_ORDER_LEAF;
            if (k < BPT_ORDER_INNER)
            {
                  if (r->k[k] == i)
                        r->v[k+1].n = n;
                  else
                        r->v[k].n = n;
            }
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
                  if (s.right->leaf)
                  {
                        bpt_node *ni; // inner node
                        ni = bpt_new_node(0);
                        ni->k[0] = bpt_upper(s.right);
                        ni->v[0].n = s.right;
                        ni->cnt += 1;
                        s.right = ni;
                  }
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
                        /* insert into the last slot */
                        r->k[m] = s.n;
                        r->v[m].n = s.left;
                        r->v[m+1].n = s.right;
                  }
                  s.split = 0;
                  r->cnt += 1;
            }
      }

      return s;
}

bpt_node*
bpt_search_node(bpt_node *n, int i)
{
      if (n->leaf)
      {
            return n->v[i-n->low].d;
      }
      else
      {
            int k;
            for (k = 0; k < n->cnt; k++)
            {
                  if (i < n->k[k])
                  {
                        return bpt_search_node(n->v[k].d, i);
                  }
            }
            return bpt_search_node(n->v[k].d, i);
      }
}
bpt_node*
bpt_search(bpt_tree *t, int i)
{
      if (!t || t->root == NULL)
      {
            return 0;
      }
      return bpt_search_node(t->root, i);
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
      else
      {
            return bpt_upper(n->v[n->cnt].n);
      }
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
      int i;
      for (i = 0; i < BPT_ORDER_LEAF; i++)
      {
            if (n->v[i].d)
            {
                  pdf_free(n->v[i].d);
            }
      }
#ifndef BPT_LEAF_LINEAR
      pdf_free(n->k);
#endif
      pdf_free(n->v);
}

void
bpt_destroy_inner(bpt_node *n)
{
      int c = 0;
      for (; c <= n->cnt && n->v[c].n; c++)
      {
            if (n->v[c].n->leaf)
                  bpt_destroy_leaf(n->v[c].n);
            else
                  bpt_destroy_inner(n->v[c].n);
            pdf_free(n->v[c].n);
      }
      pdf_free(n->k);
      pdf_free(n->v);
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
      }
      else
      {
            bpt_destroy_inner(t->root);
      }
      pdf_free(t->root);
      t->root = NULL;
}

// bpt_free() frees bpt's nodes only, and leaves user data in leaf nodes alone.
void
bpt_node_free(bpt_node *n)
{
      if (n->leaf)
      {
	    pdf_free(n->v);
            pdf_free(n);
      }
      else
      {
	    int c = 0;
	    for (; c <= n->cnt && n->v[c].n; c++)
	    {
		  if (n->v[c].n->leaf)
		  {
			pdf_free(n->v[c].n);
			pdf_free(n->v[c].n->v);
		  }
		  else
			bpt_node_free(n->v[c].n);
	    }
	    pdf_free(n->k);
	    pdf_free(n->v);
            pdf_free(n);
      }
}

static int
bpt_walk_node(bpt_node* n, bpt_callback c, leaf_action a)
{
      int i, cnt;
      if (!n)
            return 0;
      cnt = c(n, a);
      if (!n->leaf)
      {
            for (i = 0; i <= n->cnt; i++)
            {
                  cnt += bpt_walk_node(n->v[i].n, c, a);
            }
      }
      return cnt;
}

static int
bpt_print_node(bpt_node *n, leaf_action a)
{
      int i;
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
            printf("inner: \n");
      }
      return 0;
}

static int
bpt_delete_leaf(bpt_node *n, leaf_action a)
{
      int i;
      if (n->leaf)
      {
#ifdef BPT_LEAF_LINEAR
            for (i = 0; i < BPT_ORDER_LEAF; i++)
            {
                  if (n->v[i].n)
		  {
#if 0
			printf("%d..", n->low+i);
#endif
                        (a)((void*)(n->v[i].d));
		  }
            }
#else
            for (i = 0; i < n->cnt; i++)
            {
                  printf("%d..", n->k[i]);
            }
#endif
      }
      return 0;
}

void
bpt_walk(bpt_tree* t, leaf_action a)
{
      if (!t)
            return;
      bpt_walk_node(t->root, bpt_print_node, a);
}


void
bpt_delete_node(bpt_tree* t, leaf_action a)
{
      if (!t)
            return;
      bpt_walk_node(t->root, bpt_delete_leaf, a);
}

static
int
bpt_return_leaf_cnt(bpt_node *n, leaf_action a)
{
      if (n && n->leaf)
	    return n->cnt;
      else
	    return 0;
}

int
bpt_count_leaf(bpt_tree* t)
{
      if (!t)
            return 0;
      return bpt_walk_node(t->root, bpt_return_leaf_cnt, NULL);
}
