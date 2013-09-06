#include <stdio.h>
#include "trie.h"


int main(void) {
	int i,c;
	char palabra[] = "hola";
	char palabra2[] = "pepe";
	char palabra3[] = "hol";
	char palabra4[] = "hols";
	char palabra5[] = "h";
	char palabra6[] = "ho";
	
//	FILE *fichero = fopen("hola.txt","r");
	FILE *archivo_comprimido;	
/*	inicializar_diccionario();
	for(i = 0; i < MAX_CHAR; i++)  
		printf("caracter %c - posicion %d  \n ",arbol.arr_letras[i]->letra,
								 esta_en_diccionario(&(arbol.arr_letras[i]->letra)));
	puts("");
	//agregar_al_diccionario(palabra);
	/*printf("Esta %s en el diccionario? %d \n",palabra,esta_en_diccionario(palabra));
	printf("Esta %s en el diccionario? %d \n",palabra2,esta_en_diccionario(palabra2));
	printf("Esta %s en el diccionario? %d \n",palabra3,esta_en_diccionario(palabra3));
	printf("Esta %s en el diccionario? %d \n",palabra4,esta_en_diccionario(palabra4));
	printf("Esta %s en el diccionario? %d \n",palabra5,esta_en_diccionario(palabra5));
	printf("Esta %s en el diccionario? %d \n",palabra6,esta_en_diccionario(palabra6));
	

	for(i = 0;  0 <= (c = fgetc(fichero)); i++)
	  printf("%c",c);

	
	puts("");
	
	int *arr = binario(256,9);
	for(i = 0; i < 9; i++)  
		printf("%d",arr[i]);
	puts("");
*/
//	1P
//	1S
//	1R
//	printf("%d \n", arbol.nelem);
	archivo_comprimido = compresor("hola.txt");
	printf("pruuuuuuuuummmmmm \n");
	//descompresor("FACIL");
	
//	printf("%d \n",'ÿ');
//	printf("%d \n",'A');
/*	printf("Esta %c en el diccionario? %d \n",'h',esta_en_diccionario("h"));
	printf("Esta %c en el diccionario? %d \n",'o',esta_en_diccionario("o"));
	printf("Esta %c en el diccionario? %d \n",'l',esta_en_diccionario("l"));
	printf("Esta %c en el diccionario? %d \n",'a',esta_en_diccionario("a"));
	printf("Esta %s en el diccionario? %d \n","la",esta_en_diccionario("la"));
	printf("Esta %s en el diccionario? %d \n",palabra6,esta_en_diccionario(palabra6));
	printf("Esta %s en el diccionario? %d \n",palabra3,esta_en_diccionario(palabra3));
	printf("Esta %c en el diccionario? %d \n",47,esta_en_diccionario(palabra3));

	printf("Esta %s en el diccionario? %d \n","ol",esta_en_diccionario("ol"));
	printf("Esta %s en el diccionario? %d \n","ho",esta_en_diccionario("ho"));*/
	//compresor("compresor.c");

	return 0;
}
