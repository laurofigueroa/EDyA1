#ifndef __BSORT_H__
#define __BSORT_H__

#include "SList.h"

typedef int (*CmpFunc)(void *,void *);

void bsort(int [], int);
int min_array(int data[],int sz,int pos);
void ssort(int data[], int sz);
SList *ssortl(SList *);
void isort(int *data,int);
SList *isortl(SList *);
void ssort_recursive(int data[],int sz);
#endif /* __BSORT_H__ */
