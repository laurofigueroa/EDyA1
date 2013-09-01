#ifndef __DLIST_H__
#define __DLIST_H__

typedef void (*VisitorFuncInt) (int data, void *extra_data);
typedef int  (*CompareFunc) (const void *, const void *);
typedef int  (*CompareFuncInt) (int , int);
typedef enum {
		DLIST_TRAVERSAL_ORDER_FOWARD,
		DLIST_TRAVERSAL_ORDER_REWARD
} DListTraversalOrder;

typedef struct _DList {
	int	data;
	struct _DList *next;
	struct _DList *bfore;
} DList;

#define dlist_data(l)	(l)->data
#define dlist_next(l)	(l)->next
#define dlist_bfore(l)	(l)->bfore

DList *dlist_append(DList *list,int data);

DList *dlist_prepend(DList *list,int data);

void  dlist_destroy(DList *list);

void  dlist_foreach(DList *list,VisitorFuncInt visit,DListTraversalOrder direccion,void *extra_data);


#endif /*__DLIST_H__ */
