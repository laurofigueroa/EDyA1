#include <stdio.h>

void swap(int *a, int *b) { // si a c lo hago int * violacion de segmento xq??
	
	int c;
	c=*b;
	*b=*a;
	*a=c;
}


int main (void) {
	
	int *b,*c,x,y;
	
	x=6;
	y=5;	
	b=&x;
	c=&y;
	
	printf("%d %d \n", *b,*c);
	swap(b,c);	
	printf("%d %d \n", *b,*c);

	return 0;
}
