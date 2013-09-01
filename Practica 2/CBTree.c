#include <stdlib.h>
#include "CBTree.h"
#include <math.h>
#include <stdio.h>

CBTree *cbtree_new(int niveles)
{
	CBTree *new = malloc(sizeof(CBTree));
	
	new->size = pow(2,niveles)-1;

	new->data = malloc(sizeof(int)*new->size);
	new->nelements = 0;
	
	return new;

}

void cbtree_destroy(CBTree *arbol)
{
	free(arbol->data);
	free(arbol);
}

CBTree *cbtree_insert(CBTree *arbol,int data)
{
	if(arbol->nelements < arbol->size){
	arbol->data[arbol->nelements] = data;
	arbol->nelements++;
	return arbol;	
	}

	int *tmp_data = realloc(arbol->data,sizeof(int)*2*arbol->size);
	
	if(tmp_data == NULL) {
		printf("No se puede redimencionar el arreglo. \n");
		return arbol;
	}
	arbol->data = tmp_data;
	arbol->size = 2*arbol->size;
	cbtree_data(arbol)[cbtree_nele(arbol)] = data;
	cbtree_nele(arbol)++;
		
	return arbol;


}
/*
int cbtree_nelemenst(CBTree *arbol)
{
	return cbtree_nele(arbol);
}
*/
void cbtree_foreach(CBTree *arbol, VisitorFuncInt visit,void *extra_data)
{
	int i;
	for(i = 0; i < cbtree_nele(arbol) ; i++)
		visit(cbtree_data(arbol)[i],NULL);
}

void cbtree_print(CBTree *arbol) {

	int i;
	for(i = 0; i < arbol->nelements ; i++)
		printf("%d ",arbol->data[i]);
	puts("");
}

void cbtree_print_caracteristicas(CBTree *arbol) {
	printf("Caracteristicas del arbol: \n");	
	printf("\tTamaño: %d \n",arbol->size);	
	printf("\tCantidad de elementos: %d \n",arbol->nelements);	
}
	
int fib(int n) {
	int ant,fib,res,i;
	fib= 0;
	ant= 1;
	res= 0;
	if (n == 0)
		return n;
	else
		for(i = 1; i <= n; i++) {
		
			res= fib + ant;
			ant= fib;
			fib= res;
		}
	return fib;
}

CBTree *fibonaccitree(int data) 
{
	CBTree *arbol = cbtree_new(3);
	cbtree_insert(arbol,data);
	int i;
	
	for(i = 0; (data != 1 && data != 0) ; ) {
		arbol = cbtree_insert(arbol,data-1);
		arbol = cbtree_insert(arbol,data-2);
		data = arbol->data[++i];
	}

	return arbol;
}
void fibtoarbol(CBTree *arbol) {
	if(arbol == NULL)
		return;
	int i;
	for(i = 0; i < arbol->nelements ; i++)
		arbol->data[i] = fib(arbol->data[i]);


}
