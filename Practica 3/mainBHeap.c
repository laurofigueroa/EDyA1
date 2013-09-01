#include <stdio.h>
#include "BHeap.h"


int main(int argc, char *argv[])
{
	BHeap *heap = bheap_create();

	bheap_data(heap)[0] = 1;
	bheap_data(heap)[1] = 2;
	bheap_data(heap)[2] = 3;
	bheap_data(heap)[3] = 4;
	bheap_data(heap)[4] = 5;
	bheap_data(heap)[5] = 6;
	bheap_data(heap)[6] = 7;

	bheap_nelems(heap) = 7;
	
	printf("%d \n",bheap_data(heap)[0]);

	heap = bheap_erase_minimum(heap);

	bheap_print(heap);

	heap = bheap_insert(heap,1);

	bheap_print(heap);

	bheap_destroy(heap);
	
	return 0; 
} 
