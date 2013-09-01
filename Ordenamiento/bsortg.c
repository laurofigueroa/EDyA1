#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*CompFunc)(void *, void *);

void swap_ptr(void *d1,void *d2,size_t size){
	void *aux = malloc(size); 
	memmove(aux,d1,size);	
	memmove(d1,d2,size);	
	memmove(d2,aux,size);	
	free(aux);	
}


void bsortg(void **arr,int sz,CompFunc cmp) {

	int sorted, i;
	void *aux;
	do {
		sorted = 1;
		for (i = 0; i < sz - 1; i++)
			if (cmp(arr[i], arr[i+1]) > 0) {
				sorted = 0;
				aux = arr[i];
				arr[i] = arr[i+1];
     				arr[i+1] = aux;
     		}
  } while (sorted != 1);
}

/* TERMINA IMPLEMENTACION DE BSORTG */


int min_array(void *arr[], int sz,int pos,CompFunc cmp) {
	int i;
	
	if(pos >= sz) {
		printf("No existe tal posicion\n");
		return -1;
	}

	int min = pos;
	for(i = pos; i < sz-1; i++){
		if(cmp(arr[min],arr[i+1]) > 0){
			min = i;		
		}	
	}		
	return min;
}

void ssort(void **arr, int sz, CompFunc cmp) {
			
}



void print_array(int data[],int sz){
	int i;
	for(i  = 0; i < sz; i++)
    printf("%d ", data[i]);
 	puts("");
}
