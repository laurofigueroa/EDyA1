#include <stdlib.h>
#include "LStack.h"


sNode *stack_create(void) {
	sNode *pila =  malloc(sizeof(sNode));
	pila->data = -9000;
	pila->next = NULL;
	return pila;
}

int stack_top(sNode *pila)
{
	if(pila == NULL || pila->data == -9000)
		return -9000;
	
	while(snode_next(pila) != NULL)
		pila = snode_next(pila);

	return snode_data(pila);
}

sNode *stack_push(sNode *pila, int data)
{
	sNode *firstnode = pila;
	sNode *newnode = stack_create();
	snode_data(newnode) = data;

	if(pila == NULL) {
		snode_next(pila) = NULL;
		return newnode;
	}
	if(pila->data == -9000) {
		pila->data = data;
		free(newnode);
		return pila;
	}

	while(snode_next(pila) != NULL)
		pila = snode_next(pila);

	snode_next(pila) = newnode;
	snode_next(newnode) = NULL;

	return firstnode;
}





