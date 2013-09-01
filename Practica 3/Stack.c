#include <stdlib.h>
#include "Stack.h"

Stack *stack_create(void) 
{
	Stack *nuevapila = malloc(sizeof(Stack));
	stack_back(nuevapila) = -1;
	return nuevapila;
}

int stack_top(Stack *pila) 
{
	if(stack_back(pila) < 0)
		return -9000;
	return stack_data(pila)[stack_back(pila)];
}

Stack *stack_push(Stack *pila,int data)
{
	if(stack_back(pila) < MAX_STACK) {
		stack_back(pila)++;	
		stack_data(pila)[stack_back(pila)] = data;
	}
	return pila;
}

Stack *stack_pop(Stack *pila)
{
	if(stack_back(pila) > -1)
		stack_back(pila)--;
	return pila;
}

Stack *stack_reverse(Stack *pila)
{
	int i,pilaoriginal;
	Stack *pilan = stack_create();
	pilaoriginal = stack_back(pila);

	for(i = 0; i <= pilaoriginal; i++) {
		pilan = stack_push(pilan,stack_top(pila));
		stack_back(pila)--;
	}
	stack_back(pila) = pilaoriginal;
	stack_back(pilan) = pilaoriginal;

	return pilan;
}

void stack_print(Stack *pila) 
{
	int i;
	for (i = 0; i <= stack_back(pila) ; i++)
		printf("%d ", stack_data(pila)[i]);
	puts("");
}

void stack_destroy(Stack *pila)
{
	free(pila);
}










