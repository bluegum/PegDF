/*
Copyright (c) 2014 Dakai Liu

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/



#ifndef RADIX_TRIE_H
#define RADIX_TRIE_H



#ifdef _MSC_VER

typedef __int32 int32_t;
typedef unsigned __int32 uint32_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;


#define INLINE __inline
#else
#include <stdint.h>
#define INLINE inline
#endif






typedef struct node nod;


#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC extern
#endif

EXTERNC nod* radix_trie_insert(nod *r, uint32_t key, int length, void *value);

EXTERNC void radix_trie_walk(nod *root, void (*fn)(uint32_t key, int bit, void *v));


EXTERNC int radix_trie_find(nod *root, uint32_t key, int len, void **val);

EXTERNC int radix_trie_delete(nod *n, uint32_t key, int len);

EXTERNC void radix_trie_delete_all(nod *root);



// Helpers



static void
trie_node_print(uint32_t key, int bit, void *v)
{
    int i = 0;

    printf("key = 0x");
    for (i = 4; i <= bit; i += 4)
    {
        printf("%01X", (key >> (32 - i)) & 0xf);
    }
    printf(", value = %p\n", v);

}


#endif
