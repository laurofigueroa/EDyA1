#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "QuickSort.h"

#define NELEMS(arr)		((sizeof(arr))/sizeof(int))

void print_array(int data[],int sz){
	int i;
	for(i  = 0; i < sz; i++)
    printf("%d ", data[i]);
 	puts("");
}

int main(void) {

	int arr[] =  {-1,-9,0,-4,1,7,2,10,0};
	int arr2[] = {-1,-9,0,-4,1,7,2,10,0};
	int arr3[] = {-1,-9,0,-4,1,7,2,10,0};
	int arr4[] = {-1,-9,0,-4,1,7,2,10,0};
	int arr5[] = {-9,-4,-1,0,0,1,2,7,10};
	int arr6[] = {10,7,2,1,0,0,-1,-4,-9};
	int *data1;

	qsort_(arr,0,NELEMS(arr)-1);
	print_array(arr,NELEMS(arr));

	Quicksort(arr2,0,NELEMS(arr2)-1);	
	print_array(arr2,NELEMS(arr2));
	
	qsort_op(arr3,0,NELEMS(arr3)-1,MEDIANA);	
	print_array(arr3,NELEMS(arr3));
	

	printf("Arreglo a ordenar: \t");
	print_array(arr4,NELEMS(arr4));
	printf("Contador de iteraciones \n");
	iteraciones_qsort(arr4,NELEMS(arr4));
		
	printf("Arreglo a ordenar: \t");
	print_array(arr5,NELEMS(arr5));
	printf("Contador de iteraciones \n");
	iteraciones_qsort(arr5,NELEMS(arr5));

	printf("Arreglo a ordenar: \t");
	print_array(arr6,NELEMS(arr6));
	printf("Contador de iteraciones \n");
	iteraciones_qsort(arr6,NELEMS(arr6));

	return 0;
}
