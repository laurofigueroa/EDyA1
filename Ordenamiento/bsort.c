#include <stdio.h>
#include "SList.h"
#include "bsort.h"

#define minimo(a,b)		((a)<=(b) ? (a) : (b))

void swap(int *p, int *q) {
  int t = *p;
  *p = *q;
  *q = t;
}

void bsort(int data[], int sz) {
  int sorted, i;

  do {
    sorted = 1;
    for (i = 0; i < sz - 1; i++)
      if (data[i] > data[i+1]) {
	sorted = 0;
	swap(&data[i], &data[i+1]);
      }
  } while (sorted != 1);
}

int min_array(int data[],int sz,int pos) {
	int min,i,j;

	if(pos < sz)
		min = data[pos];

	j=pos;

	for(i = pos ; i < sz ; i++) {
		min = minimo(min,data[i]);
		if(min == data[i])
			j = i;
	}
	return j;
}

void ssort(int data[], int sz) {
	
	int i,j;

	for(i = 0; i < sz; i++) {
		j = min_array(data,sz,i);
		swap(&data[j],&data[i]);
	}
}

int slist_min(SList *l) {
	
	if( l == NULL) {
		printf("Lista vacia \n");
		return -9000;
	}

	int min = l->data;
	
	while(l->next != NULL) {
		min = minimo(min,l->next->data);
		l = l->next;
	}
	return min;
}

SList *ssortl(SList *l) {

	SList *newlist = NULL;
	int minimo;
	while(l != NULL) {
		minimo = slist_min(l);
		newlist = slist_append(newlist,minimo);
		l = slist_remove2(l,slist_index(l,minimo));
	}
	return newlist;
}

void acomodar(int data[],int sz,int pos){
	if(!(pos < sz))
		return;
	if( pos == 0 )
		return;
	int i;
	for(i = pos; 0 <= i && data[i] <  data[i-1] ; i--) {
//			printf("posicion %d, datos a cambiar %d - %d \n",i,data[i],data[i-1]);
			swap(&data[i],&data[i-1]);

		}
}
void isort(int data[], int sz) {
	int i;
	
	for(i = 0; i < sz ; i++) 
		acomodar(data,sz,i);

}

SList *isortl(SList *l) {

	SList *newlist = NULL;	
	
	while(l != NULL) {
		newlist = add_sorted(newlist,l->data);
		l = slist_remove2(l,1);
	}
	slist_destroy(l);
	
	return newlist;	
	
}

void ssort_recursive(int data[], int sz) {
	
	if(sz == 0)
		return;

	swap(&data[0],&data[min_array(data,sz,0)]);
	ssort_recursive(&data[1],--sz);
}


void bsortg(int data[], int sz,CmpFunc cmp) {
  int sorted, i,j;

  do {
    sorted = 1;
    for (i = 0; i < sz - 1; i++)
      if (cmp(&data[i],&data[i+1]) > 0) {
	sorted = 0;
	swap(&data[i], &data[i+1]);
		}
  } while (sorted != 1);
}
