#include <stdio.h>
#include <stdlib.h>
#define MAX 50
struct contacto {
	char nombre[MAX];
	char telefono[MAX];
	unsigned int edad;
};

struct contacto crearcontacto(void) {
	struct contacto a;
	
	printf("ingrese el nombre\n");
	scanf("%s", a.nombre);
	printf("ingrese el numero de telefono\n");
	scanf("%s", a.telefono);
	printf("ingrese la edad\n");
	scanf("%u", &a.edad);

	printf("Nombre: %s \t Telefono: %s \t Edad: %u \n", a.nombre , a.telefono,a.edad );
	return a;
	
}



void main(void) {
	crearcontacto();
}  
