#include <stdio.h>
#include "bsort.h"
#include "SList.h"

#define NELEMS(a) (sizeof((a))/sizeof(int))

static void print_int (int data, void *extra_data)
{
       printf("%d ", data);
}

void print_array(int data[],int sz){
	int i;
	for(i  = 0; i < sz; i++)
    printf("%d ", data[i]);
 	puts("");
}

int menor(void *data1,void *data2){

return (*((int*)data1) - *((int*)data2));
}	

int mayor(void *data1,void *data2){

return (*((int*)data2) - *((int*)data1));
}	

int main(void) {
	int arr[]  = { 2, 4, 1, 3, 7, 8, 6 };
	int arr2[] = { 2, 4, 1, 3, 7, 8, 6 };
	int arr3[] = { 2, 4, 1, 3, 7, 8, 6 };
	int arr4[] = { 2, 4, 1, 3, 7, 8, 6 };
	int arr5[] = { 2, 4, 1, 3, 7, 8, 6 };
	int arr6[] = { 2, 4, 1, 3, 7, 8, 6 };
	int arr7[] = { 2, 4, 1, 3, 7, 8, 6 };
	int arr8[] = { 2, 4, 1, 3, 7, 8, 6 };
	
	int i;
	
	SList *list = NULL;
	list = slist_prepend(list, 1);
	list = slist_prepend(list, 2);
	list = slist_prepend(list, 3);
	list = slist_append(list, 4);
	list = slist_append(list, 123);
	list = slist_append(list, 43);
	list = slist_append(list, 23);
	list = slist_append(list, 12);
	list = slist_append(list, 0);

	SList *list2 = NULL;
	list2 = slist_prepend(list2, 1);
	list2 = slist_prepend(list2, 2);
	list2 = slist_prepend(list2, 3);
	list2 = slist_append(list2, 4);
	list2 = slist_append(list2, 123);
	list2 = slist_append(list2, 43);
	list2 = slist_append(list2, 23);
	list2 = slist_append(list2, 12);
	list2 = slist_append(list2, 0);


	printf("##### Aca empieza bsort ##### \n");

	bsort(arr, NELEMS(arr));

	print_array(arr,NELEMS(arr));

/*	printf("Min array \n");
	for(i  = 0; i < NELEMS(arr); i++)
    printf("%d ", min_array(arr,NELEMS(arr),i));
  	puts("");
*/	

	printf("##### Aca empieza ssort ##### \n");

	printf("Arreglo ordenado:\t");
	ssort(arr2,NELEMS(arr2));
	print_array(arr2,NELEMS(arr2));

	printf("Lista ordenada: \t");

	list = ssortl(list);

	slist_foreach(list, print_int, NULL);
    printf("\n");

	printf("##### Aca empieza isort ##### \n");

	printf("Arreglo ordenado:\t");
	isort(arr3,NELEMS(arr3));
	print_array(arr3,NELEMS(arr3));


	printf("Lista ordenada: \t");

	list2 = isortl(list2);
	slist_foreach(list2, print_int, NULL);
    printf("\n");

	printf("##### Aca empieza ssort_recursive ##### \n");
	
	printf("Arreglo ordenado:\t");
	ssort_recursive(arr4,NELEMS(arr4));
	print_array(arr4,NELEMS(arr4));
	
	printf("##### Aca empieza bsortg  ##### \n");
	bsortg(arr5,NELEMS(arr5),mayor);
	print_array(arr5,NELEMS(arr5));


return 0;
}
