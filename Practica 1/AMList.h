#ifndef __H_AMLIST__
#define __H_AMLIST__

#define INTSIZE	4




typedef struct arrelgo_{
	int *p;
	int  size;
} AList;


#define alist_start(l) (l)->p
#define alist_size(l)  (l)->size


#endif /*__H_AMLIST__*/
