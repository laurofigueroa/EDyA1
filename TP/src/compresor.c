#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "trie.h"


void compresor(char *nombre) {

	char *cadena = calloc(100,sizeof(char));
	cadena[99] = '\0';
	char caracter[2];
	caracter[0] = 0;
	caracter[1] = '\0';
	int pos;
	char *cadena_mas_caracter = calloc(100,sizeof(char));
	cadena_mas_caracter[99] = '\0';
	uint8_t memoria = 0;
	int ocupado = 0;
	char *nombre_lzw = malloc(sizeof(char)*strlen(nombre)+5);
	strcpy(nombre_lzw, nombre);
	strcat(nombre_lzw, ".lzw");
	FILE *archivo_entrada = fopen(nombre, "r");
	FILE *archivo_salida = fopen(nombre_lzw, "wb");

	inicializar_diccionario();

	
	if(cadena[0] = fgetc(archivo_entrada));
	else printf ("ERROR - PRIMER CARACTER NO ENCOTRADO \n");

	while(!feof(archivo_entrada)) {
		
		caracter[0] = fgetc(archivo_entrada);
		if(caracter[0] == EOF)
			break;

		strcpy(cadena_mas_caracter,cadena);
		strcat(cadena_mas_caracter, caracter);

		if(-1 != esta_en_diccionario(cadena_mas_caracter)){
			strcpy(cadena , cadena_mas_caracter);
		}
		else {
			agregar_binario(esta_en_diccionario(cadena), arbol.nelem, archivo_salida, &memoria, &ocupado);
			agregar_al_diccionario(cadena_mas_caracter);
			strcpy(cadena, caracter);
		}
	}
	agregar_binario(esta_en_diccionario(cadena), arbol.nelem,  archivo_salida, &memoria, &ocupado);

	if(memoria != 0)
		fputc(memoria<<(8-ocupado),archivo_salida);	

	fclose(archivo_entrada);
	fclose(archivo_salida);
}
