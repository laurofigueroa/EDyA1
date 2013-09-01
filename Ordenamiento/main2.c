#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hsort.h"

#define NELEMS(arr)		((sizeof(arr))/sizeof(int))
#define MAX 20

void print_array(int data[],int sz){
	int i;
	for(i  = 0; i < sz; i++)
    printf("%d ", data[i]);
 	puts("");
}

int main(void){
	
	
	int arr4[] = {-1,-9,0,-4,1,7,2,10,0};
	int arr5[] = {-9,-4,-1,0,0,1,2,7,10};
	int arr6[] = {10,7,2,1,0,0,-1,-4,-9};
	int arr7[] = {-9,-4,-1,0,0,1};
	int arr8[] = {10,7,2,1,0,0,-1,-4,-9};
	int *arr;
	printf("arr 4 \t");
	arr = hsort(arr4,NELEMS(arr4));
	print_array(arr,NELEMS(arr4));		
	free(arr);
	
	printf("arr 5 \t");
	arr = hsort(arr5,NELEMS(arr5));
	print_array(arr,NELEMS(arr5));		
	free(arr);

	printf("arr 6 \t");
	arr = hsort(arr6,NELEMS(arr6));
	print_array(arr,NELEMS(arr6));		
	free(arr);
	
	printf("heapify arr 4 \t");
	heapify(arr4,NELEMS(arr4));	
	print_array(arr4,NELEMS(arr4));		

	printf("heapify arr 5 \t");
	heapify(arr5,NELEMS(arr5));	
	print_array(arr5,NELEMS(arr5));		

	printf("heapify arr 6 \t");
	heapify(arr6,NELEMS(arr6));	
	print_array(arr6,NELEMS(arr6));		

	swapift(arr7,NELEMS(arr7));
	print_array(arr7,NELEMS(arr7));		

	swapift(arr6,NELEMS(arr6));
	print_array(arr6,NELEMS(arr6));		

	hsort_mod(arr8,NELEMS(arr8));
	print_array(arr8,NELEMS(arr8));

	printf("### \tISERTION SORT \t ###\n");
	int arr9[MAX];
	int i;
	for(i = 0; i < MAX; i++) {
		arr9[i]=rand()%21;
		srand(time(NULL));
	}
	
	print_array(arr9,MAX);
	introsort(arr9,0,MAX-1);	
	print_array(arr9,MAX);

	introsort(arr6,NELEMS(arr6)-1);
	print_array(arr6,NELEMS(arr6));		

	return 0;

}

