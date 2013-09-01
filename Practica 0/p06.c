#include<stdio.h>

void zerozero (int *a)
{
	*a=0;
}	
int main(void)
{
	int b[5]={1,2,3,4,5};
	printf("el primer elemento de b es %d\n", b[0]);
	zerozero(b);
	printf("ahora el primer elemento es %d\n", b[0]);
}
