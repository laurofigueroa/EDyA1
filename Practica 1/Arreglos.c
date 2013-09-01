#include <stdio.h>

#define MAXLENGTH 100

#define l_p(l,i) (l->punteros[i])
#define l_d(l,i) (l->datos[i])

typedef struct _AList {

	int datos[MAXLENGTH-1];
	int *punteros[MAXLENGTH];
} AList;


void gp(AList *l,int posicion,int *p)
{
	l->punteros[posicion] = p;
}

int length(AList *l)
{
	int i;
	for(i = 0; l_p(l,i) != NULL; i++)
		;
	return i;
}

void append(AList *l,int data)
{
	int celem  = length(l); // cantidad de elementos l
	if (celem < MAXLENGTH){
		l_p(l,celem) = &(l_d(l,celem));
		l_d(l,celem) = data;
		l_p(l,++celem) = NULL;
	}
}

int hacerlugar(AList *l,int posicion)
{
	int cantelem = length(l);
	int movimientos = cantelem - posicion + 2 ;
	int i;
	if(cantelem == MAXLENGTH-1)
		return 0;
	
	for( i = 0; i < movimientos; i++) {
		l_p(l,cantelem+1) = l_p(l,cantelem);
		cantelem--;
	}
	return 1;
}
void prepend(AList *l,int data)
{
	int cantelem = length(l);
	if(cantelem == 0){
		l_p(l,0) = &(l_d(l,0));
		l_p(l,1) = NULL;
		l_d(l,0) = data;
	} else {
		
		if(hacerlugar(l,1)){
			l_p(l,0) = &(l_d(l,cantelem));
			l_d(l,cantelem) = data;
		}
	}	

}

void insertar(AList *l,int posicion,int data)
{
	int cantelem;

	if( hacerlugar(l,posicion) ) {

		cantelem = length(l);
		gp(l,posicion-1,&(l_d(l,cantelem)));
		l_d(l,cantelem) = data;

	}
}


int main(int argc, char *argv[])
{
	AList list;
	AList *l;
	int celem,i;

	l = &list;

	gp(l,0,NULL);


	append(l,4);
	prepend(l,5);
	append(l,7);
	append(l,8);
	prepend(l,10);

	

	celem = length(l);	
	printf("Cantidad de elementos %d \n", celem);
	
	for(i = 0; i < celem; i++)
		printf("%d ", *l_p(l,i));
	puts(" "); 

	insertar(l,3,9);
	celem = length(l);
	for(i = 0; i < celem; i++)
                printf("%d ", *l_p(l,i));
        puts(" ");


	
	return 0;
}
