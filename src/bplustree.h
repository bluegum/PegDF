#ifndef BPLUSTREE_H
#define BPLUSTREE_H

#define BPT_LEAF_LINEAR
#define BPT_ORDER_INNER 32
#define BPT_ORDER_LEAF 32

typedef void(*leaf_action)(void *);
typedef struct s_bpt_node bpt_node;
struct s_bpt_node
{
      int leaf;
      int *k;
#ifdef BPT_LEAF_LINEAR
      int low;
#endif
      int cnt;
      union {
            bpt_node * n;
            void *d;
      } *v;
      bpt_node *next;
} ;

typedef struct
{
      bpt_node *root;
} bpt_tree;

typedef int (*bpt_callback)(bpt_node *n, leaf_action);

extern void bpt_destroy(bpt_tree *t);
extern int bpt_insert(bpt_tree *t, int i, void *d);
extern bpt_node* bpt_search(bpt_tree *t, int i);
extern bpt_tree* bpt_new_tree();
extern void bpt_walk(bpt_tree* t, leaf_action a);
extern void bpt_delete_node(bpt_tree* t, leaf_action a);
extern int bpt_count_leaf(bpt_tree* t);
extern bpt_node* bpt_new_node(int leaf);
extern void bpt_node_free(bpt_node *n);

#endif
