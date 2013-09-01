#include <stdio.h>
#include "BSTree.h"

static void print_int(int data,void *extra_data) {
	printf("%d ",data);
}

int main (int argc, char *argv[])
{
	BSTree *raiz = NULL;

        raiz = bstree_insert(raiz,10);
        raiz = bstree_insert(raiz,4);
        raiz = bstree_insert(raiz,4);
        raiz = bstree_insert(raiz,2);
        raiz = bstree_insert(raiz,15);
        raiz = bstree_insert(raiz,40);


	bstree_foreach(raiz,print_int,NULL);
	puts("");

	int dato = 2;
	printf("Esta el %d en el arbol? : %d \n", dato,bstree_contains((raiz),dato));

	dato = bstree_nelements(raiz);
	print_int(dato,NULL);
	puts("");

	bstree_destroy(raiz);
	
	return 0;
}
