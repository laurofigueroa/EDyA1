#ifndef __MSTACK_H__


typedef struct _MStack{
	int *data;
	int back,size;
} MStack;


#define mstack_data(l)	(l)->data
#define mstack_back(l)	(l)->back
#define mstack_size(l)  (l)->size

MStack *create(void);
MStack *push(MStack *pila,int data);

#endif
