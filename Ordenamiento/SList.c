#include <stdlib.h>
#include "SList.h"

SList *slist_append(SList *list, int data)
{
      SList *newNode = malloc(sizeof(SList));
      SList *node;
      slist_data(newNode) = data;
      slist_next(newNode) = NULL;
      if (list == NULL) {
         return newNode;
      }
      node = list;
      while (slist_next(node) != NULL) {
            node = slist_next(node);
      }
      /* ahora 'node' apunta al ultimo nodo en la lista */
      slist_next(node) = newNode;
      return list;
}

SList *slist_prepend(SList *list, int data)
{
      SList *newNode = malloc(sizeof(SList));
      slist_next(newNode) = list;
      slist_data(newNode) = data;
      return newNode;
}

SList *add_sorted(SList *l,int data) {
	
	SList *newnode = malloc(sizeof(SList));
	newnode->data = data;
	
	if(l == NULL) {
		newnode->next = NULL;
		return newnode;
	}
	SList *firstnode,*nodebefore;
	firstnode = l;
	nodebefore = l;

	while(l != NULL && l->data < data) {
		nodebefore = l;
		l = l->next;
	}
	
	if(nodebefore == firstnode) {
		newnode->next = firstnode;
		return newnode;
	}

	if(l == NULL) {
		newnode->next = NULL;
		nodebefore->next = newnode;
		return firstnode;
	}
	nodebefore->next = newnode;
	newnode->next = l;
	return firstnode;

}

void  slist_destroy(SList *list)
{
      SList *nodeToDelete;
 
      while (list != NULL) {
            nodeToDelete = list;
            list = slist_next(list);
            free(nodeToDelete);
      }
}

void  slist_foreach(SList *list, VisitorFuncInt visit, void *extra_data)
{
      SList *node = list;

      while (node != NULL) {
            visit(slist_data(node), extra_data);
            node = slist_next(node);
      }
}

int slist_has_next(SList *list)
{
	if (slist_next(list) != NULL)
		return 1;
	else
		return 0;
}

int slist_length(SList *list)
{
	int i = 0;

	while( list != NULL) {
		i++;
		list = slist_next(list);		
	}
	return i;
}

void copy(SList *list1, SList *list2) {

	while (list1 != NULL) {
		list2 = slist_append(list2,slist_data(list1));
		list1 = slist_next(list1) ;	
	}
}

SList *slist_concat(SList *list1, SList *list2)
{

	SList *newlist = malloc(sizeof(SList));
	newlist = NULL;

	 while (list1 != NULL) {
                newlist = slist_append(newlist,slist_data(list1));
		list1 = slist_next(list1);
	}	
	while (list2 != NULL) {
		newlist = slist_append(newlist,slist_data(list2));
                list2 = slist_next(list2);

	}
	
	return newlist;
}

void slist_insert (SList *list,int data, int posicion) 
{	
	int i = 1;
	SList *newnode = malloc(sizeof(SList));
	SList *auxnode;
	
	while ( i <  posicion ){
		auxnode = list;
		list = slist_next(list);
		i++;
	}
	if ( posicion == 1){
		slist_next(newnode) = slist_next(list);
	        slist_data(newnode) = slist_data(list);
	
	        slist_data(list) = data;
	        slist_next(list) = newnode;
		}

	else	{
		slist_data(newnode) = data;
		slist_next(newnode) = list;
		slist_next(auxnode) = newnode;
		}
	
}

void slist_remove(SList *list, int posicion) 
{
	
	int i = 1;
	SList *nodebefore;
	SList *nodeafter;

	while (i < posicion) {
		nodebefore = list;
		list = slist_next(list);
		i++;
	} 
	if (posicion == 1){
		nodeafter = slist_next(list);
		slist_next(list) = slist_next(slist_next(list));
		slist_data(list) = slist_data(nodeafter);
		free(nodeafter);
	} else {
		slist_next(nodebefore) = slist_next(slist_next(nodebefore));
		free(list);
	}
}
SList *slist_remove2(SList *list, int posicion) 
{
	
	int i = 1;
	SList *nodebefore;
	SList *nodeafter;
	SList *fst = list;

	while (i < posicion) {
		nodebefore = list;
		list = slist_next(list);
		i++;
	} 
	if (posicion == 1){
		if(slist_next(list) != NULL) {
			nodeafter = slist_next(list);
			slist_next(list) = slist_next(slist_next(list));
			slist_data(list) = slist_data(nodeafter);
			free(nodeafter);
		} else {
			free(list);
			return NULL;
		}
	} else {
		slist_next(nodebefore) = slist_next(slist_next(nodebefore));
		free(list);
	}
	return fst;
}

int slist_contains(SList *list, int data)
{
	while (list != NULL) {
		if (slist_data(list) == data)
			return 1;
		list = slist_next(list);
	}
	return 0;
}

int slist_index(SList *list, const int data)
{	
	int i;

	if (slist_contains(list, data)){
		for (i = 1; list != NULL; i++) {
			if (slist_data(list) == data)
				return i;
			list = slist_next(list);
		 }
	}
	/*else {
		return -1;
	}*/
	return -1;
}

/*
SList *slist_intersect (SList *list1, SList *list2)
{
	SList *newlist = malloc(sizeof(SList));
	newlist = NULL;
	SList *auxnode;
	int i = 1;
	int index;
	
	while (list1 != NULL) {
		if (slist_contains(list2,slist_data(list1))) {
			
			auxnode = list2;
			index = slist_index(list2,slist_data(list1));					
			while( i < index ) {
				list2 = slist_next(list2);
			}
			
			newlist = slist_prepend(newlist,slist_data(list2));
			list2 = auxnode;
		}
		list1 = slist_next(list1);
		
	}	
	return newlist;
}
*/

SList *slist_intersect (SList *list1, SList *list2)
{
	SList *newnode = malloc(sizeof(SList));
	newnode = NULL;

	while( list1 != NULL ) {
		if ( slist_contains(list2,slist_data(list1)) && !slist_contains(newnode, slist_data(list1)) )
			newnode = slist_append(newnode, slist_data(list1));
	
		list1 = slist_next(list1);
	}
	return newnode;
}

SList *slist_intersect_custom (SList *list1, SList *list2, CompareFuncInt cmp)
{
	SList *newnode = malloc(sizeof(SList));
	SList *firstnode;
	newnode = NULL;

	while (list1 != NULL) {
		firstnode = list2;
		while (list2 != NULL) {
			if (cmp(slist_data(list1),slist_data(list2)))
				if( !slist_contains(newnode, slist_data(list1))) 
					newnode = slist_append(newnode,slist_data(list1));
			
			list2 = slist_next(list2);
		}
		list2 = firstnode;
		list1 = slist_next(list1);
	
	}
	return newnode;
}
SList *slist_sort (SList *list, CompareFunc cmp) //version Guido
// void slist_sort (SList *list, CompareFunc cmp)
{
	int *acomodar; // int acomodar[size] MALL
	int size,i;

	size = slist_length(list);
	acomodar = malloc(sizeof(int)*size);
	SList *firstnode;
	firstnode = list;

	for( i = 0; i < size ; i++) {
		acomodar[i] = slist_data(list);
		list = slist_next(list); 
	}
	qsort(acomodar,size,sizeof(int),cmp);

	list = firstnode;
	for( i = 0; i < size ; i++) {
		slist_data(list) = acomodar[i];
		list = slist_next(list);

	}
	free(acomodar);
	return firstnode;
}
