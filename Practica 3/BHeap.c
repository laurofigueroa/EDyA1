#include <stdlib.h>
#include "BHeap.h"
#include <stdio.h>

BHeap *bheap_create(void)
{
	return malloc(sizeof(BHeap));
}

int bheap_minimum(BHeap *heap)
{
	if(heap == NULL)
		return 5000;
	else if(bheap_nelems(heap) == 0)
		return 5000;
	return bheap_data(heap)[0];
}

int bheap_nivel(int data){
	int i;
	for(i = 0;((2^i)-1) < data; i++){
	//	printf("Nivel %d - 2^%d-1 = %d \n",i,i,((2^i)-1) );
	}
	return i;
}

BHeap *bheap_erase_minimum2(BHeap *heap)
{
	if(heap == NULL)
		return heap;
	else if(bheap_nelems(heap) == 0)
		return heap;

	bheap_data(heap)[0]=bheap_data(heap)[--bheap_nelems(heap)];

	int i,minimo,aux,nivel;
	nivel = bheap_nivel(bheap_nelems(heap));
	printf("Nivel %d \n",nivel);
	
	for(i = 0;(bheap_data(heap)[i] >= bheap_data(heap)[hijoI(i)] || bheap_data(heap)[i] >= bheap_data(heap)[hijoD(i)]) && i < bheap_nelems(heap);) {
		printf("Nodo padre %d - hijoI %d - hijoD %d \n",bheap_data(heap)[i], bheap_data(heap)[hijoI(i)],bheap_data(heap)[hijoD(i)]);
		if(hijoI(i) >= bheap_nelems(heap) ) /*((i > (2^(nivel-1))) && (i < (2^(nivel))))*/
			return heap;

		minimo = bheap_data(heap)[hijoD(i)] > bheap_data(heap)[hijoI(i)] ? hijoI(i) : hijoD(i) ;
		if(bheap_data(heap)[i] > bheap_data(heap)[minimo]) {
			aux = bheap_data(heap)[minimo];
			bheap_data(heap)[minimo] = bheap_data(heap)[i];
			bheap_data(heap)[i] = aux;
		}
		i = minimo;
	}
	return heap;
}

BHeap *bheap_erase_minimum(BHeap *heap)
{
	if(heap == NULL || bheap_nelems(heap) == 0)
		return heap;

	if(bheap_nelems(heap) == 1) {
		bheap_nelems(heap) = 0;
		return heap;
	}
	bheap_data(heap)[0] = bheap_data(heap)[bheap_nelems(heap)-1];
	bheap_nelems(heap)--;
	int i,minimo,aux;
	for(i = 0; bheap_nelems(heap) > hijoI(i);) {
	/*	printf("Nodo padre %d - hijoI %d - hijoD %d \n",
			bheap_data(heap)[i], bheap_data(heap)[hijoI(i)],
			bheap_data(heap)[hijoD(i)]);*/

		if( hijoD(i) < bheap_nelems(heap) )
			minimo = bheap_data(heap)[hijoD(i)] > bheap_data(heap)[hijoI(i)] ? hijoI(i) : hijoD(i) ;
		else
			minimo = hijoI(i);

		if(bheap_data(heap)[i] > bheap_data(heap)[minimo]){
			aux = bheap_data(heap)[i];
			bheap_data(heap)[i] = bheap_data(heap)[minimo];
			bheap_data(heap)[minimo] = aux;
		}else{ 
			return heap;
		}
		
		i = minimo;
	}
	return heap;	
}

void bheap_print(BHeap *heap)
{
	int i;
	for(i = 0; i < bheap_nelems(heap) ; i++)
		printf("%d ",bheap_data(heap)[i]);
	puts("");
}


BHeap *bheap_insert(BHeap *heap,int data)
{	
	printf("1 \n");
	if(heap == NULL){
		BHeap *newheap = bheap_create();
		bheap_data(newheap)[0] = data;
		bheap_nelems(newheap) = 1;
		return newheap;
	}
	if(bheap_nelems(heap) == 0) {
		bheap_data(heap)[0] = data;
		bheap_nelems(heap) = 1;
		return heap;
	}
	int i,aux;
	bheap_data(heap)[bheap_nelems(heap)] = data;
	bheap_nelems(heap)++;

	for(i = bheap_nelems(heap)-1; bheap_data(heap)[i] < bheap_data(heap)[padre(i)];){
		//printf("Hijo %d - Padre %d\n",bheap_data(heap)[i],bheap_data(heap)[padre(i)]);
		aux = bheap_data(heap)[i];
		bheap_data(heap)[i] = bheap_data(heap)[padre(i)];
		bheap_data(heap)[padre(i)] = aux;
		i = padre(i);
	}
	return heap;
} 

void bheap_destroy(BHeap *heap)
{
	free(heap);
}

