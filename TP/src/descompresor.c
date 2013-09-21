#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "trie.h"
#include <string.h>

#define traduccion_codigo(codigo)       (dic->arr[codigo/100][codigo%100])

void agregar_palabra(char *cadena_leida, char *caracter, diccionario *dic) {

	char *nueva_palabra = malloc(sizeof(char)*strlen(cadena_leida)+2);
	int pos = ++dic->posicion;

	strcpy(nueva_palabra, cadena_leida);
	strcat(nueva_palabra, caracter);

	dic->arr[pos/100][pos%100] = nueva_palabra;

}

void descompresor(char *nombre) {
	diccionario *dic = inicializar_diccionarioarr();

	uint16_t memoria = 0;
	int ocupado = 0;

	char *cadena_leida;

	char *caracter = malloc(sizeof(char)*2);
	caracter[1] = '\0';
	
	uint16_t codigo_antiguo, nuevo_codigo;
	char *cadena;
	int traduccion;
	char *temp;

	char *entrada_lzw = malloc(sizeof(char)*strlen(nombre)+5);
	char *salida_out = malloc(sizeof(char)*strlen(nombre)+5);
	strcpy(entrada_lzw, nombre);
	strcat(entrada_lzw, ".lzw");
	strcpy(salida_out, nombre);
	strcat(salida_out, ".out");
	
	FILE *archivo_entrada = fopen(entrada_lzw, "rb");
	FILE *archivo_salida = fopen(salida_out, "w");

	codigo_antiguo = leer_binario(archivo_entrada, dic->posicion+1, &memoria, &ocupado);
	cadena_leida = traduccion_codigo(codigo_antiguo);
	fputc(*cadena_leida,archivo_salida);



	while(!feof(archivo_entrada)) {
		nuevo_codigo = leer_binario(archivo_entrada, dic->posicion+1, &memoria, &ocupado);
		cadena = traduccion_codigo(nuevo_codigo);

		if(cadena == NULL) {
			temp = cadena_leida; 
			cadena = malloc(sizeof(char)*(strlen(cadena_leida)+3));
			strcpy(cadena, temp);
			strcat(cadena, caracter);
		}
	
		fwrite(cadena, sizeof(char),strlen(cadena), archivo_salida);
		*caracter = *cadena;
		agregar_palabra(cadena_leida, caracter, dic);
		cadena_leida = cadena;		
	}

}
