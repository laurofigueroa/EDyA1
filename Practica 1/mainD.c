#include <stdio.h>
#include <stdlib.h>
#include "DList.h"

static void print_int (int data, void *extra_data)
{
       printf("%d ", data);
}


int main(int argc, char *argv[]) 
{
	DList *list = NULL;
		
	list = dlist_prepend(list,1);
	list = dlist_prepend(list,2);
	list = dlist_prepend(list,3);
	list = dlist_append(list,4);
	
	dlist_foreach(list,print_int,DLIST_TRAVERSAL_ORDER_REWARD, NULL);
	printf("\n");
	
	dlist_destroy(list);

}
