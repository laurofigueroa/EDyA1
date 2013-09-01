#include <stdlib.h>
#include "BHeap.h"
#include "hsort.h"
//#include "QuickSort.h"
int *hsort2(int data[],int sz){

	int i;
	int *s = malloc(sizeof(int)*sz);
	BHeap *heap = bheap_create();

	for(i = 0; i < sz ; i++)
		heap = bheap_insert(heap,data[i]);	
	
	bheap_print(heap);	
/*	for(i = 0; i < sz ; i++){
		s[i]= bheap_minimum(heap);
		heap = bheap_erase_minimum(heap)
	}	
*/
	for(i = 0; heap->nelems != 0; i++) {
		s[i] = bheap_minimum(heap);
		heap = bheap_erase_minimum(heap);
	}
	bheap_destroy(heap);
	
	return s;
}
int *hsort(int data[],int sz){

        int i;
        int *s = malloc(sizeof(int)*sz);
        BHeap *heap = bheap_create();

        for(i = 0; i < sz ; i++)
                heap = bheap_insert(heap,data[i]);
//	bheap_print(heap);
        i = 0;
	while(!bheap_is_empty(heap)) {
                s[i++] = bheap_minimum(heap);
                heap = bheap_erase_minimum(heap);
        
	}
        bheap_destroy(heap);

        return s;
}



void array_to_heap(BHeap *heap,int *data,int sz){
	
	int i;
	for(i = 0; i < sz ; i++)
		heap = bheap_insert(heap,data[i]);
}

void heapify(int *data,int sz){
  int i;
  int sorted = 1;
  do {
    sorted = 1;
    for(i = 0; i < sz; i++) {
      if(hijoI(i) < sz && data[i] < data[hijoI(i)]) {
	swap(&data[i], &data[hijoI(i)]);
	sorted = 0;
      }
      if(hijoD(i) < sz && data[i] < data[hijoD(i)]) {
	swap(&data[i], &data[hijoD(i)]);
	sorted = 0;
      }
    }
    
  } while (sorted != 1);
	
}

void swap(int *d1,int *d2){
	int aux = *d1;
	*d1 = *d2;
	*d2 = aux;
}

void swapift(int *data,int sz){
	int i;

	swap(&data[0],&data[sz-1]);

	for(i = 0; i < sz-2; i++)
		swap(&data[i],&data[i+1]);

}


void hsort_mod(int *data, int sz) {
	
	heapify(data,sz);
	while(sz != 0) {
//		printf("Arreglo a ordenar:\t");
//		print_array(data,sz);
		swapift(data,sz--);
	}	
}

/*void introsort_loop(int *data, int init,int last,int depth_limit){
	const int size_threshold = 10;
	int p;
	while(last - init > size_threshold){
		if(depth_limit == 0)
			hsort2(data,init,last);
		depth_limit--;
		p = particionar_mediana(data,init,last);
		introsort_loop(data,p,last,depth_limit);	
	}
}

long double log2(int x){
	return (log(x)/log(2));
}

void introsort(int *data,int init,int last){

	introsort_loop(data,init,last,2*log2(last-init));
	isort(data,init,last);

}
*/
