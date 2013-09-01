#include <stdio.h>


int apply(int(*f)(int), int n) {
	
	return ((*f)(n));	// cambiando los parentesis funciona igual ¿?
	
}

int suma1(int a) {
	
	return a+1	;
	
}

int main (void) {
	
	int a = 21;
	
	printf("%d \n", apply(suma1,a));
	return 0;
	
}
