#ifndef __CBTREE_H__


#define MAX_LENGTH 100

typedef void (*VisitorFuncInt) (int data, void *extra_data);

typedef struct _CBTree {
	int *data;
	int nelements;
	int size;
} CBTree;

#define cbtree_data(l)	(l)->data
#define cbtree_nele(l)	(l)->nelements

CBTree *cbtree_new(int);

#endif
