#include <stdio.h>
#include "Alist.h"


static void print_int(int data,void *extra_data)
{
	printf("%d ",data);
}

int main(int argc, char *argv[])
{

	AList list;

	gp(list,0,NULL);

	append(list,2);

	printf("%d \n",alist_data(list,0);

	return 0;

}

