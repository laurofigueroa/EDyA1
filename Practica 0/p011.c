#include<stdio.h>

void setin(int *a)
{
	if(*a)
		*a=1;
}

int main(void)
{
	int b=0, *c;
	c=&b;
	setin (c);
	printf("%d\n", b);
	
	return 0;
}
			
