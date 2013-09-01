#include <stdio.h>
#include <stdlib.h>
#include "BTree.h"

static void print_int (int data, void *extra_data)
{
	printf("%d ", data);
}

int main(int argc, char *argv[])
{
	int suma,length = 0;
	int i;
	BTree *ll = btree_create(1, NULL, NULL);
	BTree *l = btree_create(2, ll, NULL);
	BTree *r = btree_create(3, NULL, NULL);
	BTree *root = btree_create(4, l, r);

	suma = btree_sum2(root);
	printf("La suma de los elementos del arbol es: %d \n",suma);

	length = btree_length2(root);
	printf("La cantidad de elementos del arbol es: %d \n",length);

	length = btree_altura(root);
        print_int(length,NULL);
        puts("");
	
/*
	for(i = 0; i < 3 ;i++){
		btree_foreach22(root,print_int,i,NULL);
		puts("");
	}
*/
	length = btree_min(root);
	print_int(length,NULL);
	puts("");

	btree_replace(root,length);
	
	btree_foreach(root, print_int, NULL);
	puts("");
	

	BTree *pp = btree_create(8,NULL,NULL);
	BTree *pd = btree_create(9,NULL,NULL);
	BTree *p = btree_create(6,pp,pd);
	BTree *dd = btree_create(2,NULL,NULL);
	//BTree *di = btree_create(1,NULL,NULL);
	BTree *d = btree_create(7, NULL, dd);	
	BTree *raiz = btree_create(5,p,d);

	printf("arbol original \n");
	btree_foreach(raiz, print_int, NULL);
	puts("");
	
	raiz = mirror(raiz);
	printf("arbol espejo \n");
	btree_foreach(raiz, print_int, NULL);
	puts("");

	btree_destroy(root);
	btree_destroy(raiz);


	return 0;
}

