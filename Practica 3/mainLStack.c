#include <stdio.h>
#include "LStack.h"

int main(int argc, char *argv[])
{
	sNode *pila = stack_create();

	pila = stack_push(pila,4);
	pila = stack_push(pila,6);

	printf("%d \n",stack_top(pila));
	int i;
	for(i = 0; pila != NULL ; i++){
		printf("%d elemento ", i+1);
		printf("%d \n",pila->data);
		pila = pila->next;
	}
	return 0;

}
