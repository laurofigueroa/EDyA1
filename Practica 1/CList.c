#include <stdlib.h>
#include "CList.h"

int clist_length(CList *list)
{
    CList *firstnode = list;

    int i;
    
    if (firstnode == NULL) 
        return 0;
    else {
        list = clist_next(list);
        for(i = 1; firstnode != list; i++)
            list = clist_next(list);
    return i;
    }  
}

CList *clist_prepend(CList *list,int data) 
{	
	CList *newnode = malloc(sizeof(CList));
	CList *firstnode;
	int length;

	firstnode = list;

	if (list == NULL){
		clist_data(newnode) = data;
		clist_next(newnode) = newnode;	
		return newnode;
	} else {
		length = clist_length(list);
		
		while(length > 1){
			list = clist_next(list);
			--length;
		}
		clist_next(list) = newnode;
		clist_next(newnode) = firstnode;
		clist_data(newnode) = data;
		return newnode;
		}
}
CList *clist_append(CList *list,int data) {

	CList *newnode = malloc(sizeof(CList));
	CList *firstnode = list;
	int length;
		 
	if (list == NULL) {
		clist_next(newnode) = newnode;
		clist_data(newnode) = data;
		return newnode;
	}
	length = clist_length(list);
        
	while (length > 1) {
		list = clist_next(list);
		--length;
	}
	clist_next(newnode) = firstnode;
	clist_next(list) = newnode;
	clist_data(newnode) = data;
        
	return firstnode;
}

void clist_foreach(CList *list, VisitorFuncInt visit, void *extra_data)
{
	CList *node;
	int i,length;
	
	length = clist_length(list);
	node = list;

	for( i = 1; i <= length ; i++) {
		visit(clist_data(node),extra_data);
		node = clist_next(node);
	}
}

void clist_destroy(CList *list) 
{
	CList *nodetodelete;
	int length,i;

	length = clist_length(list);

	for( i = 1; i <= length ; i++) {
		nodetodelete = list;
		list = clist_next(list);
		free(nodetodelete);
	}
}

