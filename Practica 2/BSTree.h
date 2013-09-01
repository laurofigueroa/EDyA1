#ifndef __BSTREE_H__
#define __BSTREE_H__

typedef void (*VisitorFuncInt) (int data, void *extra_data);

typedef struct _BSTnode {
	int data;
	struct _BSTnode *left;
	struct _BSTnode *right;
} BSTree;


#define bstree_data(l)       (l)->data
#define bstree_left(l)       (l)->left
#define bstree_right(l)      (l)->right


void bstree_foreach(BSTree *,VisitorFuncInt,void *);

void bstree_destroy(BSTree *);

BSTree *bstree_insert(BSTree *,int);

int bstree_contains(BSTree *,int);

int bstree_nelements(BSTree *);


#endif /*__BSTREE_H__*/
