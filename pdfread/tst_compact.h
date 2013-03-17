/* TERNARY SEARCH TREE ALGS */
#ifndef TST_COMPACT_H
#define TST_COMPACT_H

typedef struct tnode *Tptr;
typedef void (*tstc_f)(void *val);

extern Tptr tstc_insert(Tptr p, char *k, void *val);
extern void* tstc_find(Tptr p, char *s);
extern void tstc_free(Tptr p);
extern void tstc_print(Tptr n);
extern void tstc_call(Tptr n, tstc_f f);

/* user data */
extern Tptr tstc_init();

#endif
