#ifndef PDFNAME_H
#define PDFNAME_H

typedef struct hashtable_s hashtable;
typedef struct hashtable_entry_s hashtable_entry;

struct hashtable_entry_s
{
    unsigned char *str;
    hashtable_entry *next;
};

struct hashtable_s
{
    hashtable_entry **buckets;
    int n_buckets;
    int resize_buckets;
    int n;
    // flag only for resizing, entries are inserted instead of
    // being allocated fresh.
    int replace_entry;
};


#define HASHTABLE_INITIAL_SIZE 16
#define HASHTABLE_RESIZE_RATIO 4

extern hashtable *hashtable_new();
extern void hashtable_free(hashtable *ht);
extern hashtable_entry *hashtable_search(hashtable*, hashtable_entry *);
extern hashtable_entry* hashtable_delete_entry(hashtable *ht, hashtable_entry*);

extern void hashtable_stat(hashtable *ht);
extern hashtable *pdfname_new();
extern char* pdfname_search(char *string);
extern void pdfname_free();


#endif
