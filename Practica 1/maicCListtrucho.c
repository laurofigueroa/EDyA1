#include <stdio.h>
#include <stdlib.h>
#include "SList.h"


int main(int argc, char *argv[]) 
{
	SList *list = malloc(sizeof(SList));
	
	slist_next(list) = list;
	slist_data(list) = 5;
	
	free(list);

	return 0;
}
