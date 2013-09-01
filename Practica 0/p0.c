#include <stdio.h>
#include <stdlib.h>


void zerozero (int *a) // Ejercicio 6
{
	*a=0;
}	


/* Ejercicio 7: La funcion malloc devuelve una direccion de memoria, 
en caso de no encontrar suficiente espacio, retorna NULL. */


struct contacto {	// Ejercicio 8
	char nombre[50];
	char numero[50];
	unsigned int edad;
};

struct contacto crearcontacto(void) {	// Ejercicio 9
	int i;
	char c;
	struct contacto tipo;

	printf("ingrese el nombre\n");
	for(i=0;EOF!=(c=getchar()) && '\n'!=c;i++)
		tipo.nombre[i]=c;
	tipo.nombre[++i]='\0';
	
	printf("ingrese el telefono\n");
	for(i=0;EOF!=(c=getchar()) && '\n'!=c;i++)
			tipo.numero[i]=c;
	tipo.numero[i+1]='\0';		
	printf("ingrese la edad\n");
	scanf("%d",&tipo.edad);
	
	printf("El contacto creado es : %s\t %s\t %d \n", tipo.nombre, tipo.numero, tipo.edad);
	return tipo;
}


struct pto	{	// Ejercicio 10-a
	float x;
	float y;
};

struct pto medio(struct pto p1, struct pto p2) {	// Ejercicio 10-b
	struct pto m;
	m.x=((p1.x+p2.x)/2);
	m.y=((p1.y+p2.y)/2);
	return m;
}

void setin(int *a) {	// Ejercicio 11
	if(*a)
		*a=1;
}

void swap(int *a, int *b) { // Ejercicio 12
	
	int c;  // si a c lo hago int * violacion de segmento xq??
	c=*b;
	*b=*a;
	*a=c;
}


char *getnewline () {	// Ejercicio 14
	char *m = malloc (40);
	char c;
	int i=0;
	while (EOF!=(c=getchar()) && '\n' != c){
		*m = c;
		m++;
		i++;
	}
	m -= i;// m = m- i
	return m;
}

void actualizaredad(struct contacto *k) {	// Ejercicio 15

		scanf("%u",&((*k).edad));

}

int prom(struct contacto *p, int n) { // Ejercicio 16

	int res = 0;
	int i;

	for(i = 0; i < n ; i++) {
		res=res+(*p).edad;
		p++;
	}
	return res/n;
	
		/* Ejercicio 16
	struct contacto *p,s[3];
 	
 	s[0].edad= 4;
 	s[1].edad= 50;
 	s[2].edad= 60;
	p=&s[0];
	
	printf("La edad promedio es %d \n",prom(p,3));
	*/
}

// Ejercicio 17 echo en otro archivo






struct agenda {
	
	struct contacto contactos[100];
	int cantcont;
};


void agregarcontacto(struct agenda *a) {
	
	int i;
	
	i= (*a).cantcont + 1;
	
	(*a).contactos[i]=crearcontacto();
	
	(*a).cantcont++;
}

void mostrarcontactos(struct agenda *a) {
	
	int i;
	
	for(i=0; i < (*a).cantcont ; i++) {
		
		printf("1- %s \n", &((*a).contactos[i].nombre[0]));
	}
	
}


int main(void) {
	
	
	struct agenda ag;
	agregarcontacto(&ag);
	
	mostrarcontactos(&ag);
	printf("%d \n",ag.cantcont);
	return 0;
}
	
