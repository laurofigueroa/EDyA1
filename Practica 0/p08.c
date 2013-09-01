#include<stdio.h>

struct contacto{
	char nombre[50];
	char numero[50];
	unsigned int edad;
};

struct contacto crearcontacto(void)
{
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
	scanf("%u",&tipo.edad);
	
	printf("%s\t %s\t %d\n", tipo.nombre, tipo.numero, tipo.edad);
	return tipo;
}



int main(void)
{
	struct contacto a;
	a= crearcontacto();

	return 0;
}		
				
	
