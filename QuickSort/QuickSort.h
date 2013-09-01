#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

enum piv {ALEATOREO,ULTIMO,MEDIO,MEDIANA};
typedef enum piv CLASE_DE_PIVOTE;

void qsort_(int data[],int init,int last);
int particionar(int data[],int init,int last);
int particionar_mediana(int data[],int init,int last);
void swap(int *p, int *q);


#endif
