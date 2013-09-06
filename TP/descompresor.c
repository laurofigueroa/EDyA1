#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "trie.h"
#include <string.h>

#define traduccion_codigo(codigo)       (dic->arr[codigo/100][codigo%100])

void agregar_palabra(uint16_t codigo_antiguo, uint16_t caracter, diccionario *dic) {
	char *nueva_palabra = malloc(sizeof(uint16_t)*2+1);
	int pos = ++dic->posicion;
	
	nueva_palabra[0] = codigo_antiguo;
	nueva_palabra[1] = caracter;
	nueva_palabra[2] = '\0';

	dic->arr[pos/100][pos%100] = nueva_palabra;
}

void descompresor(char *nombre) {
	printf("asdasda");
	diccionario *dic = inicializar_diccionarioarr();
	
	uint16_t codigo_antiguo, nuevo_codigo, caracter;
	unsigned char *cadena;
	int traduccion;
	
	FILE *archivo_entrada = fopen(nombre, "rb");
	FILE *archivo_salida = fopen("descomprimido", "wb");

	if(fread(&codigo_antiguo, sizeof(uint16_t), 1, archivo_entrada)) { 
		fwrite(&codigo_antiguo, sizeof(uint16_t), 1, archivo_salida);	
	}
	while(fread(&nuevo_codigo, sizeof(uint16_t), 1, archivo_entrada)) {
		cadena = traduccion_codigo(nuevo_codigo);
		fwrite(cadena, sizeof(char),strlen(cadena), archivo_salida);
		caracter = *cadena;
		agregar_palabra(codigo_antiguo, caracter, dic);
		codigo_antiguo = nuevo_codigo;
	}
}
