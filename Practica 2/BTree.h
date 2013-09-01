#ifndef __BTREE_H__
#define __BTREE_H__

typedef void (*VisitorFuncInt) (int data, void *extra_data);

typedef enum {
	BTREE_TRAVERSAL_ORDER_IN,
	BTREE_TRAVERSAL_ORDER_PRE,
	BTREE_TRAVERSAL_ORDER_POST
} BTreeTraversalOrder;

/**
 * Los campos son privados, y no deberian ser accedidos
 * desde el código cliente.
 */
typedef struct _BTNode {
	int    data;
	struct _BTNode *left;
	struct _BTNode *right;
} BTree;

#define btree_data(l)       (l)->data
#define btree_left(l)       (l)->left
#define btree_right(l)      (l)->right

typedef struct _BSTnode {
	int data;
	struct _BSTnode *left;
	struct _BSTnode *right;
} BSTree;

#define bstree_data(l)       (l)->data
#define bstree_left(l)       (l)->left
#define bstree_right(l)      (l)->right


/**
 * Crea un nuevo nodo, en complejidad O(1).
 *
 * Nota: el árbol vacio se representa con un (BTree *) NULL.
 */
BTree *btree_create(int data, BTree *left, BTree *right);

/**
 * Destruccion del árbol.
 */
void  btree_destroy(BTree *root);

/**
 * Recorrido del árbol, utilizando la funcion pasada.
 */
void  btree_foreach(BTree *list, VisitorFuncInt visit, void *extra_data);

BTree *mirror(BTree *);

BTree *copy(BTree*);
#endif /* __BTREE_H__ */

