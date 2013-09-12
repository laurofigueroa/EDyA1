#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "trie.h"
#include <string.h>

#define traduccion_codigo(codigo)       (dic->arr[codigo/100][codigo%100])

void agregar_palabra2(uint16_t codigo_antiguo, uint16_t caracter, diccionario *dic) {
	char *nueva_palabra = malloc(sizeof(uint16_t)*2+1);
	int pos = ++dic->posicion;
	
	nueva_palabra[0] = codigo_antiguo;
	nueva_palabra[1] = caracter;
	nueva_palabra[2] = '\0';

	dic->arr[pos/100][pos%100] = nueva_palabra;
}

void agregar_palabra(char *cadena_leida, char *caracter, diccionario *dic) {

	char *nueva_palabra = malloc(sizeof(char)*strlen(cadena_leida)+1);
	int pos = ++dic->posicion;

	strcpy(nueva_palabra, cadena_leida);
	strcat(nueva_palabra, caracter);

	dic->arr[pos/100][pos%100] = nueva_palabra;

//	printf("CADENA ESCRITA CORRECTAMENTE....................... (%s) \n",nueva_palabra);

}

void descompresor(char *nombre) {
	printf("------------> DESCOMPRESOR <-------------------- \n");
	diccionario *dic = inicializar_diccionarioarr();

//	imprimir_diccionario(dic);



	uint16_t memoria = 0;
	int ocupado = 0;
	char *cadena_leida;// = malloc(sizeof(char)*100);

	char *caracter = malloc(sizeof(char)*2);
	caracter[1] = '\0';
	
	uint16_t codigo_antiguo, nuevo_codigo;
	char *cadena;
	int traduccion;
	char *temp;
	
	FILE *archivo_entrada = fopen(nombre, "rb");
	FILE *archivo_salida = fopen("descomprimido", "w");

	codigo_antiguo = leer_binario(archivo_entrada, dic->posicion+1, &memoria, &ocupado);
//	printf("codigo antiguo = %d\n", codigo_antiguo);
	cadena_leida = traduccion_codigo(codigo_antiguo);
	fputc(*cadena_leida,archivo_salida);
//	printf("CADENA LEIDA = %s\n",cadena_leida);

//	fwrite(cadena_leida, sizeof(char),strlen(cadena_leida),archivo_salida);


	while(!feof(archivo_entrada)) {
		nuevo_codigo = leer_binario(archivo_entrada, dic->posicion+1, &memoria, &ocupado);
//		printf("      CODIGO LEIDO: %d\n", nuevo_codigo);
		cadena = traduccion_codigo(nuevo_codigo);
//		printf("  CADENA TRADUCIDA %s de CODIGO LEIDO: %d\n",cadena, nuevo_codigo);
		if(cadena == NULL) {
			temp = cadena_leida; 
			cadena = malloc(sizeof(char)*(strlen(cadena_leida)+3));
			strcpy(cadena, temp);
			strcat(cadena, caracter);
		}
	
//		printf("cadena hacia archivo salida %s \n", cadena);
		fwrite(cadena, sizeof(char),strlen(cadena), archivo_salida);
		*caracter = *cadena;
//		printf("caracter %s + %s \n",cadena_leida,caracter);
		agregar_palabra(cadena_leida, caracter, dic);
		//printf("concatenado = %s \n", cadena);
		cadena_leida = cadena;		
	}

/*	if(fread(&codigo_antiguo, sizeof(uint16_t), 1, archivo_entrada)) { 
		fwrite(&codigo_antiguo, sizeof(uint16_t), 1, archivo_salida);	
	}
	while(fread(&nuevo_codigo, sizeof(uint16_t), 1, archivo_entrada)) {
		cadena = traduccion_codigo(nuevo_codigo);
		fwrite(cadena, sizeof(char),strlen(cadena), archivo_salida);
		*caracter = *cadena;
		agregar_palabra(codigo_antiguo, caracter, dic);
		codigo_antiguo = nuevo_codigo;
	}
*/
}
