#ifndef __HSORT_H__
#define __HSORT_H__
#include "BHeap.h"

int *hsort(int data[],int sz);
void array_to_heap(BHeap *heap,int *data,int sz);
void heapify(int *data,int sz);

#endif
