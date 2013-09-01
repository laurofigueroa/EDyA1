#include <stdlib.h>
#include "AList.h"


int alist_length(AList *list)
{
	int i;

	for(i = 0; list != NULL; i++)
		;
	return i;		
}

void gp (AList *l,int posicion,int *lugar) // guarda en la lista order en la posicion  una direccion de un entero en la lista data
{
//	alist_order(l,posicion) = lugar;
	l->order[posicion] = lugar;
}

int alist_full(AList *list) 
{
	return (alist_length(list) - MAXLENGTH);
}
void alist_append(AList *list,int data)
{
	int posicion;

	if(alist_full(list)) {
		posicion = alist_length(list);
		gp(list,posicion,alist_&data(list,posicion));
		alist_data(list,posicion) = data;
		gp(list,posicion+1,NULL);
	}

 
