#include <stdio.h>


struct contacto {
	
	char nombre[30];
	char numero[20];
	unsigned int edad;
};

typedef struct contacto Contacto;

struct agenda {
	
	Contacto persona[100];
	int cantcont;
};

typedef struct agenda Agenda;

void wstr(char *a) {
	
	printf("Ingrese el dato: ");
	scanf("%s",a);
		
}
void wuint(unsigned int *a) {
	
	printf("Ingrese el dato: ");
	scanf("%u",a);
		
}

void crearcontacto (Contacto *c) {
	
	printf("Ingrese el nombre: ");
	scanf("%s",(*c).nombre);
	
	printf("Ingrese el tel: ");
	scanf("%s",(*c).numero);
	
	printf("Ingrese la edad: ");
	scanf("%u",&(*c).edad);
	
}

void crearcontacto2 (Contacto *c) {

	printf("Ingrese el nombre");
	scanf("%s",c->nombre);
	
	printf("Ingrese el tel: ");
        scanf("%s",c->numero);

        printf("Ingrese la edad: ");
        scanf("%u",&(c->edad));


}

void agregarcontacto(Agenda *a) {
	
	int i;
	i= (*a).cantcont + 1;
	
	crearcontacto(&((*a).persona[i]));
	
	(*a).cantcont++;
	
}

void agregarcontacto2(Agenda *a) {

	a->cantcont ++;
	crearcontacto2(&(a->persona[a->cantcont]));
}


void mostrarcontactos(Agenda *a) {
	
	int i;
	
	for(i=1; i <= (*a).cantcont ; i++) {
		
		printf("%d-\n\tNombre:\t%s \n\tTel:\t%s \n\tEdad:\t%u \n\n",i, ((((*a).persona[i]).nombre)),((((*a).persona[i]).numero)),((((*a).persona[i]).edad)));
	}
	
}


int main(void) {
	
	Agenda ag;
	
	/*wstr(ag.persona[0].nombre); 
	wstr(ag.persona[0].numero);
	ag.persona[0].edad= 4 */;
	ag.cantcont=0;
	
	
	agregarcontacto2(&ag);
	mostrarcontactos(&ag);
	
	// Contacto juan;
	
	// crearcontacto(&juan);
	
	// printf("Nombre:\t%s \nTel:\t%s \nEdad\t%u \n", juan.nombre,juan.numero,juan.edad);
	
	
	
	return 0;
	
}

