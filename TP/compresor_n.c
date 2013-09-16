#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "trie.h"

//	printf("XFILES _ caracter = int  %d - caracter[0] = %c -  caracter[1] =  %c - caracter = %s\n",caracter[0],caracter[0],  caracter[1], caracter);

void compresor(char *nombre) {

	printf("DENTRO DEL COMPRESOR \n");
	
	char *cadena = calloc(100,sizeof(char));
	cadena[99] = '\0';
	char caracter[2];
	caracter[0] = 0;
	caracter[1] = '\0';
//	caracter[2] = '\0';
	int pos;
	char *cadena_mas_caracter = calloc(100,sizeof(char));
	cadena_mas_caracter[99] = '\0';
	uint8_t memoria = 0;
	int ocupado = 0;
	FILE *archivo_entrada = fopen(nombre, "r");
	FILE *archivo_salida = fopen("FACIL", "wb");

	inicializar_diccionario();

//	printf("DICCIONARIO INICIALIZADO - nelems = %d \n", arbol.nelem);
	
	if(cadena[0] = fgetc(archivo_entrada));
	else printf ("ERROR - PRIMER CARACTER NO ENCOTRADO \n");

	while(!feof(archivo_entrada)) {
		
		caracter[0] = fgetc(archivo_entrada);
		if(caracter[0] == EOF)
			break;

		/* Ver que hay en caracter */
/*		
		printf("EOF =  %d ",EOF);
		printf("caracter =  %d \n",caracter[0]);
*/		
		/* Concatenamos */
		strcpy(cadena_mas_caracter,cadena);
		strcat(cadena_mas_caracter, caracter);
/*
		printf("%s + ",cadena);
		printf("%s = ", caracter);
		printf(" %s \n", cadena_mas_caracter);
*/
		if(-1 != esta_en_diccionario(cadena_mas_caracter)){
			strcpy(cadena , cadena_mas_caracter);
		}
		else {
//			printf("ANTES DE BINARIO :$ \n");
//			printf("CODIGO: %d ---- %s\n", esta_en_diccionario(cadena), cadena);
			agregar_binario(esta_en_diccionario(cadena), arbol.nelem, archivo_salida, &memoria, &ocupado);
			agregar_al_diccionario(cadena_mas_caracter);
			strcpy(cadena, caracter);
		}
	}
	agregar_binario(esta_en_diccionario(cadena), arbol.nelem,  archivo_salida, &memoria, &ocupado);
//	printf("CODIGO: %d ---- %s\n", esta_en_diccionario(cadena), cadena);

	if(memoria != 0)
		fputc(memoria<<(8-ocupado),archivo_salida);	

//	printf("ultima memoria : %d",memoria<<ocupado);

/*	printf("pos %s -- %d \n", "ho", esta_en_diccionario("ho"));
	printf("pos %s -- %d \n", "ol", esta_en_diccionario("ol"));
	printf("pos %s -- %d \n", "la", esta_en_diccionario("la"));
	printf("pos %s -- %d \n", "al", esta_en_diccionario("al"));
	printf("pos %s -- %d \n", "la", esta_en_diccionario("la"));
*/
	fclose(archivo_entrada);
	fclose(archivo_salida);
}
