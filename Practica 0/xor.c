#include <stdio.h>


void swap(int *a,int *b) {
	
	*b=	*a ^ *b;
	*a= *a ^ *b;
	*b= *a ^ *b;
	
}
	
int main (void) {

	int a,b;	
	a=23;
	b=29;
	swap(&a,&b);
	
	printf("%d %d \n", a,b);
	return 0;
	
}

