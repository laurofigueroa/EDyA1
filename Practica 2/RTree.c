#include <stdlib.h>
#include "RTree.h"

RTree *rtree_create(void *data,RTree *leftson,RTree *rightson)
{
	RTree *newnode = malloc(sizeof(RTree));
	
	rtree_data = data;
	rtree_
