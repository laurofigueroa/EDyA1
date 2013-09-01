#include <stdio.h>

void applyin(int (*f)(int),int *a) {
	
	*a = f(*a);
	
}

int suma1(int a) {
	
	return a+1	;
	
}

int main(void) {
	
	int a=21;
	applyin(suma1,&a);
	
	printf("%d \n", a);
	
}
