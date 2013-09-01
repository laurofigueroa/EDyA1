#include <stdio.h>
#include <stdlib.h>
#include "CList.h"

static void print_int(int data, void *extra_data)
{
	printf("%d ", data);
}


int main(int argc, char *argv[]) 
{
	CList *list = NULL;
	CList *list2 = NULL;	

	list = clist_prepend(list,1);
	list = clist_prepend(list,2);
	list = clist_prepend(list,3);
	list = clist_prepend(list,4);
	list = clist_prepend(list,5);
	list = clist_prepend(list,6);
	list = clist_prepend(list,7);
	list = clist_prepend(list,8);
	
	list2 = clist_append(list2,1);
	list2 = clist_append(list2,2);
	list2 = clist_append(list2,3);
	list2 = clist_append(list2,4);
	list2 = clist_append(list2,5);
	list2 = clist_append(list2,6);
	list2 = clist_append(list2,7);
	list2 = clist_append(list2,8);
	
		
	printf("La longitud de la lista 1:\t%d \n",clist_length(list));
	clist_foreach(list,print_int, NULL);
	puts(" ");

	
	printf("La longitud de la lista 2:\t%d \n",clist_length(list2));
	clist_foreach(list2,print_int, NULL);
	puts(" ");
	
	clist_destroy(list);
	clist_destroy(list2);
	return 0;
}
