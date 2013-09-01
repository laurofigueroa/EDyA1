#ifndef __ALIST_H__
#define __ALIST_H__

#define MAXLENGTH 100


typedef void (*VisitorFuncInt) (int, void *);

typedef struct AList_ {

	int data[MAXLENGTH-1];
	int *order[MAXLENGTH];
} AList;


#define alist_order(a,i)	(a->(order[i]))
#define alist_data(a,i)		(a->data[i])
#define alist_&data(a,i)	(&(a->data[i]))





#endif /* __ALIST_H__ */
