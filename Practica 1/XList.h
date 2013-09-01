#ifndef __XLIST_H__
#define __XLIST_H__

typedef void (*VisitorFuncInt) (int,void *);
	

typedef struct XList_ {
	int data;
	intptr_t next;

} XList;

#define xlist_next(l) 	(l)->next
#define xlist_data(l) 	(l)->data

XList *xlist_prepend(XList *,int);

XList *xlist_append(XList *,int);

void xlist_foreach(XList *,VisitorFuncInt,void *);

void xlist_destroy(XList *);




#endif /*__XLIST_H__ */
