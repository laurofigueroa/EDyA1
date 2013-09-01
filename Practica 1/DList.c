#include <stdlib.h>
#include "DList.h"


DList *dlist_append(DList *list,int data) 
{
	DList *newnode = malloc(sizeof(DList));
	DList *fnode;
	if (list == NULL) {
		dlist_data(newnode) = data;
		dlist_next(newnode) = NULL;
		dlist_bfore(newnode) = NULL;
		return newnode;
	} else {
		fnode = list;
		while(dlist_next(list) != NULL)
			list = dlist_next(list);
		dlist_next(list) = newnode;
		dlist_bfore(newnode) = list;
		dlist_data(newnode) = data;
		dlist_next(newnode) = NULL;
		return fnode;
	}
}


DList *dlist_prepend(DList *list,int data)
{
	DList *newnode = malloc(sizeof(DList));

	if(list == NULL) {
		dlist_bfore(newnode) = NULL;
		dlist_data(newnode) = data;
		dlist_next(newnode) = NULL;
		return newnode;
	} else {
		dlist_bfore(list) = newnode;
		dlist_next(newnode) = list;
		dlist_data(newnode) = data;
		dlist_bfore(newnode) = NULL;
		return newnode;
	}
}

void dlist_destroy(DList *list) 
{
	DList *nodetodelete;
	while(list != NULL) {
		nodetodelete = list;
		list = dlist_next(list);
		free(nodetodelete);
	}
}

void dlist_foreach(DList *list,VisitorFuncInt visit,DListTraversalOrder direccion,void *extra_data) 
{
	DList *node = list; 
	if( DLIST_TRAVERSAL_ORDER_FOWARD == direccion )
		while(node != NULL) {
			visit(dlist_data(node),extra_data);
			node = dlist_next(node);
		} 
	else {
	
		while(node != NULL) {
			visit(dlist_data(node),extra_data);
			node = dlist_bfore(node);
		}
   }
}
