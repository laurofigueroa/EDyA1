#ifndef __RTREE_H__

typedef struct _RTree {
	void *data;
	struct _RTree *left,*right;
} RTree;

#define rtree_data(l)	(l)->data
#define rtree_left(l)	(l)->left
#define rtree_right(l)	(l)->right


#endif
