#include <stdlib.h>
#include "MStack.h"


MStack *create(void)
{
	MStack *newstack = malloc(sizeof(MStack));
	mstack_data(newstack) = malloc(sizeof(int)*10);	
	mstack_back(newstack) = -1;
	mstack_size(newstack) = 10;
	return newstack;
}

int top(MStack *pila)
{
	return mstack_data(pila)[mstack_back(pila)];
}


MStack *push(MStack *pila,int data)
{
	if(++mstack_back(pila) < mstack_size(pila))
		mstack_data(pila)[mstack_back(pila)] = data;
	else	{
		mstack_data(pila) = realloc(mstack_data(pila) , sizeof(int)*(mstack_size(pila)*2));	
		mstack_data(pila)[mstack_back(pila)] = data;
	}
	return pila;
}
