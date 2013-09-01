#ifndef __LSTACK_H__

typedef struct _node{
	int data;
	struct _node *next;
} Node;

typedef Node sNode;

#define snode_data(l)	(l)->data
#define snode_next(l)	(l)->next

sNode *stack_create(void);
int stack_top(sNode *);
sNode *stack_push(sNode *, int);
sNode *stack_pop(sNode *);
sNode *stack_reverse(sNode *);
void stack_print(sNode *);
void stack_destroy(sNode *);

#endif
