#ifndef __STACK_H__
#define __STACK_H__

#define MAX_STACK 50

typedef struct _Stack{
	int data[MAX_STACK];
	int back;
} Stack;


#define stack_data(l)	(l)->data
#define stack_back(l)	(l)->back




Stack *stack_create(void);
int stack_top(Stack *pila);
Stack *stack_push(Stack *pila,int data);
Stack *stack_pop(Stack *pila);

#endif 
