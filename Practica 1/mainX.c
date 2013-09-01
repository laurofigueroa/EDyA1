#include <stdio.h>
#include <stdlib.h>
#include "XList.h"


static void print_int(int data, void *extra_data)
{
	printf("%d ",data);
}


int main(int argc, char **argv) 
{
	XList *list = NULL;

	list = xlist_append(list, 4); 

	print_int(xlist_data(list),NULL);
	
	return 0;
}
