#include <stdio.h>

void nombre(char *a) {
	
	printf("Ingrese el nombre: \n");
	scanf("%s",a);
}

int main(void) {
	
	char a[10];
	nombre(a);	
	printf("%s \n",a);
}
