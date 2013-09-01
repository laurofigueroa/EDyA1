#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main() {
	Stack *pila1;
	pila1 = stack_create();
	
	stack_data(pila1)[0] = 2;
	stack_data(pila1)[1] = 8;
	stack_data(pila1)[2] = 14;
	stack_back(pila1) = 2;

	pila1 = stack_push(pila1,4);



	pila1 = stack_pop(pila1);
	stack_print(pila1);	

	int i;
	for(i = 0; i<=stack_back(pila1) && stack_back(pila1) != stack_maxstack(pila1) ; i++)
				stack_data(pila)[i] = 3;



	pila1 = stack_reverse(pila1);
	stack_print(pila1);

	stack_destroy(pila1);
	


}


