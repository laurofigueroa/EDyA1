#include <stdlib.h>
#include <stdint.h>
#include "XList.h"


XList *xlist_append (XList *list,int data) 
{
	XList *newnode = malloc(sizeof(XList));
	XList *fnode = list;
	XList *nodebef;
	if (list == NULL) {
		xlist_data(newnode) = data;
		xlist_next(newnode) = NULL;
		return newnode;
	}

	nodebef = list;
	while(xlist_next(list)^nodebef != NULL) {
		nodebef = list;
		list = xlist_next(list)^nodebef;
	}
	
	xlist_next(list) = nodebef ^ newnode;
	xlist_next(newnode) = list ^ NULL;
	xlist_data(newnode) = data;

	return fnode;

}	
/*
XList *xlist_prepend (XList *list,int data)
{
	XList *newnode = malloc(sizeof(XList));

	if (list == NULL) {
		xlist_data(newnode) = data;
		xlist_next(newnode) = NULL;
	}
	
	xlist_next(newnode) = newnode ^ list;
	xlist_data(newnode) = data;
	return newnode;
}

*/	
