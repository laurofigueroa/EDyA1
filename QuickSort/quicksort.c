#include <stdlib.h>
#include <time.h>
#include "QuickSort.h"
#include <stdio.h>

void swap(int *p, int *q) {
  int t = *p;
  *p = *q;
  *q = t;
}

int particionar(int data[],int init,int last){
	int pivot = data[init],l = init,r = last;

	while(l < r){
		while(data[l] <= pivot && l < r)
			l++;
		while(data[r] > pivot)
			r--;
		if(l < r)
			swap(&data[l],&data[r]);
	}
	swap(&data[init],&data[r]);
	return r;
}

void qsort_(int data[],int init,int last){
	int pivot;

	if(init < last){
		pivot = particionar(data,init,last);
		qsort_(data,init, pivot-1);
		qsort_(data,pivot+1,last);
	}
}

int colocar(int *v, int b, int t)
{
        int i;
        int pivote, valor_pivote;
        int temp;
 
        pivote = b;
        valor_pivote = v[pivote];
		for (i=b+1; i<=t; i++){
				if (v[i] < valor_pivote){
                    pivote++;    
                    temp=v[i];
                    v[i]=v[pivote];
                    v[pivote]=temp;
 
            
				}
        
		}
        temp=v[b];
        v[b]=v[pivote];
        v[pivote]=temp;
        return pivote;
    
} 
 
void Quicksort(int* v, int b, int t)
{
         int pivote;
		 if(b < t){
            pivote=colocar(v, b, t);
            Quicksort(v, b, pivote-1);
            Quicksort(v, pivote+1, t);
         
		 }  
    
}

int particionar_random(int data[],int init,int last){
	
	int random = (rand()%(last-init)+1)+init;
	srand(time(NULL));
	swap(&data[random],&data[init]);

	int pivot = data[init],l = init,r = last;

	while(l < r){
		while(data[l] <= pivot && l < r)
			l++;
		while(data[r] > pivot)
			r--;
		if(l < r)
			swap(&data[l],&data[r]);
	}
	swap(&data[init],&data[r]);
	return r;
}


int particionar_last(int data[],int init,int last){
	
	swap(&data[last],&data[init]);

	int pivot = data[init],l = init,r = last;

	while(l < r){
		while(data[l] <= pivot && l < r)
			l++;
		while(data[r] > pivot)
			r--;
		if(l < r)
			swap(&data[l],&data[r]);
	}
	swap(&data[init],&data[r]);
	return r;
}

int particionar_mid(int data[],int init,int last){
	
	swap(&data[(last+init)/2],&data[init]);

	int pivot = data[init],l = init,r = last;

	while(l < r){
		while(data[l] <= pivot && l < r)
			l++;
		while(data[r] > pivot)
			r--;
		if(l < r)
			swap(&data[l],&data[r]);
	}
	swap(&data[init],&data[r]);
	return r;
}

int particionar_mediana(int data[],int init,int last){
	
	int mid = (last+init)/2;
	if(data[init] >= data[last] && data[last] <= data[mid] )
		swap(&data[last],&data[init]);
	else if(data[init] >= data[mid] && data[last] >= data[mid] )
		swap(&data[mid],&data[init]);
	

	int pivot = data[init],l = init,r = last;

	while(l < r){
		while(data[l] <= pivot && l < r)
			l++;
		while(data[r] > pivot)
			r--;
		if(l < r)
			swap(&data[l],&data[r]);
	}
	swap(&data[init],&data[r]);
	return r;
}

void qsort_op(int data[],int init,int last,CLASE_DE_PIVOTE opcion){
	int pivot;

	if(init < last){
		switch (opcion) {
			case ALEATOREO:
				pivot = particionar_random(data,init,last);
				qsort_op(data,init, pivot-1,opcion);
				qsort_op(data,pivot+1,last,opcion);
				break;
			case ULTIMO:
				pivot = particionar_last(data,init,last);
				qsort_op(data,init, pivot-1,opcion);
				qsort_op(data,pivot+1,last,opcion);
				break;
			case MEDIO:
				pivot = particionar_mid(data,init,last);
				qsort_op(data,init, pivot-1,opcion);
				qsort_op(data,pivot+1,last,opcion);
				break;
			case MEDIANA:
				pivot = particionar_mediana(data,init,last);
				qsort_op(data,init, pivot-1,opcion);
				qsort_op(data,pivot+1,last,opcion);
				break;				
			default:
				pivot = particionar(data,init,last);
				qsort_op(data,init, pivot-1,opcion);
				qsort_op(data,pivot+1,last,opcion);
				break;
		}
	}
}



void qsort_op_contadora(int data[],int init,int last,CLASE_DE_PIVOTE opcion,int *iteracion){
	int pivot;

	(*iteracion)++;

	if(init < last){
		switch (opcion) {
			case ALEATOREO:
				pivot = particionar_random(data,init,last);
				qsort_op_contadora(data,init, pivot-1,opcion,iteracion);
				qsort_op_contadora(data,pivot+1,last,opcion,iteracion);
				break;
			case ULTIMO:
				pivot = particionar_last(data,init,last);
				qsort_op_contadora(data,init, pivot-1,opcion,iteracion);
				qsort_op_contadora(data,pivot+1,last,opcion,iteracion);
				break;
			case MEDIO:
				pivot = particionar_mid(data,init,last);
				qsort_op_contadora(data,init, pivot-1,opcion,iteracion);
				qsort_op_contadora(data,pivot+1,last,opcion,iteracion);
				break;
			case MEDIANA:
				pivot = particionar_mediana(data,init,last);
				qsort_op_contadora(data,init, pivot-1,opcion,iteracion);
				qsort_op_contadora(data,pivot+1,last,opcion,iteracion);
				break;				
			default:
				pivot = particionar(data,init,last);
				qsort_op_contadora(data,init, pivot-1,opcion,iteracion);
				qsort_op_contadora(data,pivot+1,last,opcion,iteracion);
				break;
		}
	}
}

int *copy(int *data,int sz){
	int *arr = malloc(sizeof(int)*sz);
	int i;
	for(i = 0; i <= sz ; i++)
		arr[i] = data[i];
	return arr;
}
void iteraciones_qsort(int *data,int sz){
	
	int contador[] = {0,0,0,0,0};
	int i;
	printf("ALEATOREO 0 \t ULTIMO 1 \t MEDIO 2 \t MEDIANA 3 \t PRIMERO 4 \n");	
	for(i = 0; i <= 4 ; i++) {
		int *data1 = copy(data,sz);	
		qsort_op_contadora(data1,0,sz-1,i,&contador[i]);
		printf("Iteraciones necesarias con %d :\t %d \n",i,contador[i]);
		free(data1);
	}
//	qsort_(data,0,sz-1);
//	print_array(data,sz);
}
