#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct hash_map_s hash_map;
typedef struct hash_map_entry hash_map_entry;
typedef struct hash_map_iterator_s hash_map_iterator;

struct hash_map_entry
{
        void *k;
        void *v;
        struct hash_map_entry *next;
};

typedef void (*free_hash_map_entry)(void*);

extern hash_map* hash_map_insert(hash_map *h, unsigned char *k, int k_len, void *v);
extern void* hash_map_find(hash_map *h, unsigned char *k, int key_len);
extern void hash_map_delete(hash_map *h);
extern void *hash_map_delete_entry(hash_map *h, unsigned char *k, int key_len);

extern void hash_map_iterator_reset(hash_map_iterator* itr);
extern void hash_map_iterator_next(hash_map_iterator* itr);
extern int hash_map_iterator_at_end(hash_map_iterator* itr);
extern struct hash_map_entry *hash_map_iterator_get(hash_map_iterator* itr);
extern hash_map_iterator *hash_map_front(hash_map *h);
extern void hash_map_iterator_free(hash_map_iterator *itr);


#endif
