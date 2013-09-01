#ifndef __BHEAP_H__

#define MAX_HEAP 100

typedef struct _BHeap{
	int data[MAX_HEAP];
	int nelems;
} BHeap;

#define bheap_data(l)	(l)->data
#define bheap_nelems(l)	(l)->nelems
#define hijoI(l)	(2*(l)+1)
#define hijoD(l)	(2*(l)+2)
#define padre(l)	(((l)-1)/2)


BHeap *bheap_create(void);
int bheapr_minimum(BHeap);
BHeap *bheap_erase_minimum(BHeap *);
BHeap *bheap_insert(BHeap * , int);
void bheap_print(BHeap *);
void bheap_destroy(BHeap *);

#endif

