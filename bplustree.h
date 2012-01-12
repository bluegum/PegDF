#ifndef BPLUSTREE_H
#define BPLUSTREE_H

#define BP_LEAF_LINEAR
#define BP_ORDER_INNER 20
#define BP_ORDER_LEAF 200

typedef struct s_bp_node bp_node;
struct s_bp_node
{
   int leaf;
   int *k;
#ifdef BP_LEAF_LINEAR
   int low;
#endif
   int cnt;
   union {
      bp_node * n;
      void *d;
   } *v;
   bp_node *next;
} ;

typedef struct
{
   bp_node *root;
} bp_tree;
extern bp_node *bp_insert_leaf(bp_node *r, int i, void *d);
extern bp_node *bp_insert_leaf_linear(bp_node *r, int i, void *d);
extern void bp_destroy(bp_tree *t);
extern int bp_insert(bp_tree *t, int i, void *d);
extern bp_node* bp_search(bp_tree *t, int i);
extern bp_tree* bp_new_tree();

#endif
