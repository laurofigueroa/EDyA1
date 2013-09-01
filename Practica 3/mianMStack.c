#include <stdio.h>
#include <stdlib.h>
#include "MStack.h"

int main(void){


	MStack *pila = create();

	pila = push(pila, 44);
	
	printf("%d \n",top(pila));
	return 0;

}
