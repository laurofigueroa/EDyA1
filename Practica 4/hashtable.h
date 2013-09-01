#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

//typedef unsigned int (*HashFunc)(void *);
typedef unsigned int (*HashFunc)(void *, unsigned int);
typedef int (*EqualsFunc)(void *, void *);
#define BASE 128

typedef struct _Hashbucket {
  void *key;
  void *data;
	struct _Hashbucket *next;
} Hashbucket;

typedef struct _Hashtable {
  Hashbucket **table;
  int nelems, size;
  HashFunc hash;
  EqualsFunc equal;
} Hashtable;

Hashtable *hashtable_new(int, HashFunc,EqualsFunc);
void hashtable_insert(Hashtable *, void *, void *);
void *hashtable_lookup(Hashtable *, void *);
void hashtable_delete(Hashtable *, void *);
void hashtable_destroy(Hashtable *);
int isin(Hashtable *,Hashbucket *nodo,char *key); 

#endif /* __HASHTABLE_H__ */
