#ifndef __CLIST_H__
#define __CLIST_H__

typedef void (*VisitorFuncInt) (int data, void *extra_data);
typedef int  (*CompareFunc) (const void *, const void *);
typedef int  (*CompareFuncInt) (int , int); 

typedef struct _CList{
        int data;
        struct _CList *next;
} CList;

#define clist_data(l)       (l)->data
#define clist_next(l)       (l)->next


int clist_length(CList *);

CList *clist_append(CList *,int);

CList *clist_prepend(CList *,int);

void clist_foreach(CList *,VisitorFuncInt,void *);

void clist_destroy(CList *);


#endif /* __CLIST_H__ */
