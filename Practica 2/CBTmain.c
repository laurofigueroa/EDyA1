#include <stdio.h>
#include "CBTree.h"

int main(void) {


	CBTree *arbol = cbtree_new(3);
	cbtree_print_caracteristicas(arbol);
	cbtree_insert(arbol,1);	
	cbtree_insert(arbol,2);
	cbtree_insert(arbol,3);
	cbtree_insert(arbol,4);
	cbtree_insert(arbol,5);
	cbtree_insert(arbol,6);
	cbtree_insert(arbol,7);
	cbtree_insert(arbol,8);
	cbtree_print_caracteristicas(arbol);
	cbtree_print(arbol);	
	cbtree_destroy(arbol);
	
	/* Arbol fibonacci */
	
	int x = 4;
	printf("## Arbol fibonacci de %d ## \n",x);
	CBTree *arbol2 = fibonaccitree(x);
	cbtree_print_caracteristicas(arbol2);
	cbtree_print(arbol2);	

	printf("Aplicando la fc fibonacci al los nodos del arbol");
	fibtoarbol(arbol2);
	cbtree_print(arbol2);	

	cbtree_destroy(arbol2);
	
	return 0;
}
