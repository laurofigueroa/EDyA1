#include <stdio.h>
#include <stdlib.h>
#include "SList.h"

static void print_int (int data, void *extra_data)
{
       printf("%d ", data);
}

int suma1(int a) {
	return (a + 1);
}


int cmp (const void *k, const void *l)      
{
        if (*(int*)k < *(int*)l)
                return 1;
        else if (*(int*)k == *(int*)l) 
                return 0;
        else 
                return -1;
}
int siguiente (int a, int b) 
{
	if (a + 1 == b)
		return 1;
	else 
		return 0;
}

int main(int argc, char *argv[])
{
	SList *list = NULL;
	SList *list2 = NULL;
	SList *list3 = NULL;
	SList *list4 = NULL;
	SList *list5 = NULL;
	
	
	list = slist_prepend(list, 1);
	list = slist_prepend(list, 2);
	list = slist_prepend(list, 3);
	list = slist_append(list, 4);

	list2 = slist_prepend(list2, 1);
	list2 = slist_prepend(list2, 2);
	list2 = slist_prepend(list2, 3);
	list2 = slist_append(list2, 4);
	
	list5 = slist_prepend(list5, 5);
        list5 = slist_prepend(list5, 5);
        list5 = slist_prepend(list5, 5);
        list5 = slist_append(list5, 5);

	printf("%d \n",slist_has_next(list));
	printf("%d\n",slist_length(list));

	slist_foreach(list, print_int, NULL);
	printf("\n");

	list2 = slist_concat(list,list3);
	slist_foreach(list2, print_int, NULL);
	puts("");
	
	slist_insert(list,4,2);
	slist_foreach(list, print_int, NULL);
        printf("\n");

	slist_remove(list,3);
        slist_foreach(list, print_int, NULL);
        printf("\n");

	printf("%d \n", slist_contains(list,4));

	printf("Posicion %d \n",slist_index(list,3));
	
	printf("Lista1:\t");
	slist_foreach(list, print_int, NULL);
	printf("\n");

	printf("Lista2:\t");
	slist_foreach(list2, print_int, NULL);
	printf("\n");
	
	printf("La interseccion de lis1 y list2: ");
       	list4 = slist_intersect(list,list2);
	slist_foreach(list4, print_int, NULL);

	printf("\n");
        printf("Lista1:\t");
        slist_foreach(list, print_int, NULL);
        printf("\n");

        printf("Lista2:\t");
        slist_foreach(list2, print_int, NULL);
        printf("\n");
	
	
        printf("La interseccion custom con suma1  de lis1 y list2: ");
        list4 = slist_intersect_custom(list,list2,siguiente);
        slist_foreach(list4, print_int, NULL);
        printf("\n");

	slist_sort(list,cmp);
	printf("Lista1 ordenada de menor a mayor:\t");
        slist_foreach(list, print_int, NULL);
        printf("\n");


	
	slist_destroy(list);
	slist_destroy(list2);
	slist_destroy(list3);
	slist_destroy(list4);
	slist_destroy(list5);
    return 0;
}
