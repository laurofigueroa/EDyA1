#include <stdlib.h>
#include "BSTree.h"


void  bstree_destroy(BSTree *node)
{
        if (node != NULL) {
                bstree_destroy(bstree_left(node));
                bstree_destroy(bstree_right(node));
                free(node);
        }

}

void  bstree_foreach(BSTree *node, VisitorFuncInt visit, void *extra_data)
{
        if (node != NULL) {
                visit(bstree_data(node), extra_data);
                bstree_foreach(bstree_left(node), visit, extra_data);
                bstree_foreach(bstree_right(node), visit, extra_data);
        }
}


BSTree *bstree_insert(BSTree *node, int dato)
{

	if(node == NULL) {
		BSTree *node1 = malloc(sizeof(BSTree));
		bstree_data(node1) = dato;
		bstree_right(node1) = NULL;

		bstree_left(node1) = NULL;
		return node1;
	} 
	if(bstree_left(node) != NULL && dato <= bstree_data(node))

		 	bstree_left(node) = bstree_insert(bstree_left(node), dato);
	
	else if (bstree_left(node) == NULL && dato <= bstree_data(node))

			bstree_left(node) = bstree_insert(bstree_left(node),dato);

	else if (bstree_right(node) == NULL && dato > bstree_data(node))

			bstree_right(node) = bstree_insert(bstree_right(node),dato);
	else
		 	bstree_right(node) = bstree_insert(bstree_right(node) , dato);
	return node;
}

int bstree_contains(BSTree *node,int dato)
{
	if(node == NULL)
		return 0;
	
	if (bstree_data(node) == dato)
		return 1;

	int right = bstree_contains(bstree_left(node),dato);
	int left = bstree_contains(bstree_right(node),dato); 	
	
	return right + left - right * left;
}

int bstree_nelements(BSTree *node)
{
	if(node == NULL) 
		return 0;
	
	return 1+bstree_nelements(bstree_left(node)) + bstree_nelements(bstree_right(node));

}

