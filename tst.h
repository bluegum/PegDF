/* TERNARY SEARCH TREE ALGS */
#ifndef TST_H
#define TST_H

typedef struct tnode *Tptr;
typedef void (*tst_hook)(char *, void* val);

extern Tptr tst_insert(Tptr p, char *s, void *val);
extern Tptr tst_search(Tptr p, char *s);
extern int tst_rsearch(Tptr p, char *s);
extern void * tst_delete(Tptr p, char *s);
extern void tst_cleanup(Tptr p);
extern void tst_traverse(Tptr p, tst_hook f);

/* user data */
extern Tptr tst_init();
extern int tst_attach(Tptr, void *val);
extern void* tst_retrieve(Tptr);

#endif
