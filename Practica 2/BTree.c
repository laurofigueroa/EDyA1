#include <stdlib.h>
#include "BTree.h"

BTree *btree_create(int data, BTree *left, BTree *right)
{
	BTree *newNode = malloc(sizeof(BTree));
	btree_data(newNode) = data;
	btree_left(newNode) = left;
	btree_right(newNode) = right;
	return newNode;
}

void  btree_destroy(BTree *node)
{
	if (node != NULL) {
		btree_destroy(btree_left(node));
		btree_destroy(btree_right(node));
		free(node);
	}

}

void  btree_foreach(BTree *node, VisitorFuncInt visit, void *extra_data)
{
	if (node != NULL) {
		visit(btree_data(node), extra_data);
		btree_foreach(btree_left(node), visit, extra_data);
		btree_foreach(btree_right(node), visit, extra_data);
	}
}

int btree_sum(BTree *node) 
{
	int total = 0;
	if (node != NULL) {
	 total += btree_data(node) + btree_sum(btree_left(node))+btree_sum(btree_right(node));
	}
	return total;

}
void sumatoria(int data,void *extra_data) {
		
	*((int *)extra_data) += data;
	return;
}

int btree_sum2(BTree *node) {
	int *suma;
	int resultado = 0;
	if(node == NULL)
		return resultado;

	suma = &resultado;
	(*suma)++;
	btree_foreach(btree_left(node),sumatoria,(int *)suma);
	btree_foreach(btree_left(node),sumatoria,(int *)suma);
	return resultado;
}
void altura_aux(int data,void *extra_data) {
	(*((int *)extra_data))++;
}

int btree_length2(BTree *node) {
	int *alt_aux;
	int resultado = 0;
	if(node == NULL)
		return resultado;
	alt_aux = &resultado;
	(*alt_aux)++;
	btree_foreach(btree_left(node),altura_aux,alt_aux);
	btree_foreach(btree_right(node),altura_aux,alt_aux);

	return resultado;
}

int btree_length(BTree *node)
{
	int length = 0;
	if(node != NULL)
		length += 1 + btree_length(btree_left(node)) + btree_length(btree_right(node));
	return length;
}


int btree_altura(BTree *node)
{
	int left = 0;
	int right = 0;
	
	if(node != NULL){
		left = btree_altura(btree_left(node));
		right = btree_altura(btree_right(node));
	}
	return (left > right ? ++left : ++right);

}

void btree_foreach22(BTree *node,VisitorFuncInt visit,BTreeTraversalOrder dir,void *extra_data)
{
	if(node != NULL) { 
		if(dir == BTREE_TRAVERSAL_ORDER_POST) {
			btree_foreach22(btree_left(node),visit,dir,NULL);
			btree_foreach22(btree_right(node),visit,dir,NULL);
			visit(btree_data(node),extra_data);
		} else if(dir == BTREE_TRAVERSAL_ORDER_IN) {
			btree_foreach22(btree_left(node),visit,dir,NULL);
			visit(btree_data(node),extra_data);
			btree_foreach22(btree_right(node),visit,dir,NULL);
		} else {
			visit(btree_data(node),extra_data);
			btree_foreach22(btree_left(node),visit,dir,NULL);
			btree_foreach22(btree_right(node),visit,dir,NULL);
		}
	}
}

int btree_min(BTree *node) 
{
	int minimo;
	
	if(node != NULL) {
//		minimo = (btree_data(node) < btree_left(node)) ? btree_data(node) : btree_left(node);
//		minimo = (minimo < btree_data(right) ? minimo : btree_right(node);
	
		minimo = btree_data(node);
		if(btree_left(node) != NULL)
			minimo = btree_min(btree_left(node)) < minimo ? btree_min(btree_left(node)) : minimo;
		if(btree_right(node) != NULL)
			minimo = (btree_min(btree_right(node)) < minimo) ? btree_min(btree_right(node)) : minimo;
	} else
		return 90000;
		
	return minimo;
}

void btree_replace(BTree *node,int replace)
{
		
	if(node != NULL) {
//		printf("%d \n",btree_data(node));
		btree_data(node) = replace;
		btree_replace(btree_left(node),replace);
		btree_replace(btree_right(node),replace);
	}
}


void local_min(int data, void *extradata) {
  int *p = extradata;
  if (data < *p) {
    *p = data;
  }
}

int btree_min2(BTree *root) {
  int min = -1;
  if (root != NULL) {
    min = btree_data(root);
    btree_foreach(root, local_min, &min);
  }
  return min;
}

BTree *copy(BTree *node) 
{
	if(node == NULL) {
		return node;
	}
	BTree *newnode = malloc(sizeof(BTree));
	newnode =  btree_create(btree_data(node),copy(btree_left(node)), copy(btree_right(node))); 
	return newnode; 
	
}

BTree *mirror2(BTree *node)
{	
	BTree *mirrortree = copy(node);

	if(mirrortree == NULL) {
		return mirrortree;
	}

	BTree *aux = btree_left(mirrortree);
	btree_left(mirrortree) = btree_right(mirrortree);
	btree_right(mirrortree) = aux;

	return mirrortree;
}


BTree *mirror(BTree *node) {

	if(node == NULL)
		return node;
	
	BTree *aux = btree_left(node);
	btree_left(node) = btree_right(node);
	btree_right(node) = aux;

	if(btree_left(node) != NULL) 
		btree_left(node) = mirror(btree_left(node));		
	if(btree_right(node) != NULL)
		btree_right(node) = mirror(btree_right(node));

	return node;
}
