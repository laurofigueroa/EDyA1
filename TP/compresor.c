#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "trie.h"
#include <stdint.h>

#define NELEMS(a)	(sizeof(a))/(sizeof(unsigned char))

static unsigned char byte[1]; 
static int cant = 1;

unsigned char *binario(int numero, int tamanio) {
	unsigned char *arr = malloc(sizeof(unsigned char)*tamanio);
	int i;
	
	for( i = tamanio-1; i >= 0; i--) {
		arr[i] = numero%2;
		numero = numero/2;
	}
	return arr;
}

void concatenar(char *arr, char c) {
	int i;
	for(i = 0; arr[i] != '\0'; i++);
	arr[i] = c;
	arr[++i] = '\0';
	return;
}

void ultimo_elemento(char *arr) {
	int i;
	for(i = 0; arr[i] != '\0'; i++);
	if(i != 0)
		arr[i-1] = '\0';
}


void agregar_binario(char *arr, int bits, FILE *salida) {
	int pos,x,i;
	unsigned char *bin;
	if(0 > (pos = esta_en_diccionario(arr)))
		return;
//	printf("agregando %d bits \n",bits);	
	bin = binario(pos, bits);
	for(i = 0; i < bits; i++) {
		if(cant < 8) {
			byte[0] = byte[0] << 1;
			byte[0] = byte[0] | bin[i];
			cant++;
		} else {
			cant = 0;
			fwrite(byte,sizeof(unsigned char),1,salida);
			byte[0] = 0;
			byte[0] = byte[0] << 1;
			byte[0] = byte[0] | bin[i];
			cant++;
		}
	}

	if(cant == 8) {
	cant = 0;
	fwrite(byte,sizeof(unsigned char),1,salida);
	byte[0] = 0;
	}	
}

void primer_elemento(char *arr, char c) {
	int i;
	arr[0] = c;
	arr[1] = '\0';	
}



void concatenacion_strcat(char *s1, char *s2) {
	if(s2[0] == '\0')
		return;
	char *resultado_inutil = strcat(s1,s2);
	return;
}

void compresor(char *archivo) {
        unsigned char c;
        unsigned char caracter[1];
		int bits = 9;
        unsigned char *cadena = malloc(sizeof(unsigned char)*32);
        unsigned char *cadena_original = malloc(sizeof(unsigned char)*32);
	FILE *archivo_binario = fopen("Archivo_comprimido","wb");
        FILE *archivo_fuente = fopen(archivo,"r");

	cadena[0] = '\0';

	int i;
	for(i = 0; i < 32; i++) {
		cadena[i] = '\0';
		cadena_original[i] = '\0';
	}

	char hola[11] = "hola";
	char chau[4] = "chau";
	printf("%s \n",strcat(hola,chau));

	while(((c = getc(archivo_fuente)) != EOF)) {
		//printf("Caracter c = %d \n",c);
		caracter[0] = c;
		//printf("caracter[0] = (%c) \t",caracter[0]);
		//printf("cadena_original = (%s) \t",cadena);
		//printf("cadena = (%s) \t",cadena);
                cadena_original = (unsigned char *)strcpy(cadena_original,cadena);
		//printf("Ncadena_original = (%s) \n",cadena);

		concatenar(cadena,c);
		//printf("cadena++caracter = (%s) \n",cadena);
		if(arbol.nelem >= pow(2, bits)) {
			bits++;
		}
		if(c == 255) {
			agregar_binario(cadena_original, bits,archivo_binario);
			break;
		}
		if(esta_en_diccionario(cadena) == -1) {
                        //printf("Dentro del if \n");
			agregar_binario(cadena_original, bits,archivo_binario);
                       // putc('\n',archivo_binario);
			agregar_al_diccionario(cadena);
                        cadena[0] = c;
			cadena[1] = '\0'; 
			//printf("En el if : cadena = (%s) \n",cadena);
		}
	}
        return;
}

FILE *comprimir(char *nombre) {
	int bits = 8;
	int i,x;
	unsigned int c = 3;
	int *bin;
	char cadena[1000];
	char cadena_temp[1000];
	char *primer_elem;
	FILE *salida = fopen("archbin.dat", "wb");
	FILE *fuente = fopen(nombre, "rb");

	cadena[0] = '\0';
	for(i = 0; (c = fgetc(fuente)) != EOF; i++) {
		strcpy(cadena_temp,cadena);
		concatenar(cadena, c);
		//printf("Cadena (%s) antes del if \n",cadena);
		if (arbol.nelem > pow(2,bits)) 
			bits++;
		/*if (c == '/') {
			agregar_binario(cadena, bits,salida);
		}*/
		printf("bits %d - nelems %d \n",bits, arbol.nelem);
		if(esta_en_diccionario(cadena) == -1) {
			//printf("Agregar cadena %s al diccionario\n",cadena);	
			agregar_al_diccionario(cadena);
			//printf("Esta %s pos dic %d \n",cadena,esta_en_diccionario(cadena));
			ultimo_elemento(cadena);
			//printf("Agregar cadena (%s) al binario \n",cadena);	
			agregar_binario(cadena, bits, salida);
			//putc('\n',salida);
			primer_elemento(cadena, c);
		}
	}
	printf("Agregar cadena (%s) al binario \n",cadena);	
	printf("afuera del for \n");
	if (c == EOF)
		agregar_binario(cadena, bits,salida);
	
	if(cant != 0) {
		while(cant++ != 8){
			byte[0] = byte[0] << 1;
		}
		fwrite(byte, sizeof(unsigned char), 1, salida);	
	}
	
	return salida;
}

#define ESTADO_INICIAL		3	

raiz *inicializar_dic(void) {
	raiz nuevo_diccionario = malloc(sizeof(raiz));
	nuevo_diccionario.nelems = 0;
	int i;
	diccionario nodo;
	nodo.pos = 0;
	
	for(i = 0; i < ESTADO_INICIAL; i++) {
		nuevo_diccionario.arr_global[i] = malloc(sizeof(diccionario));
		nuevo_diccionario.arr_global[i] = nodo;
	}

	for(i = 0; i < 100; i++) {
		nuevo_diccionario.arr_global[0].palabra[i] = i;
	}
	for(i = 100; i < 200; i++) {
		nuevo_diccionario.arr_global[1].palabra[i] = i;
	}
	for(i = 200; i < 256; i++) {
		nuevo_diccionario.arr_global[2].palabra[i] = i;
	}
	return nuevo_diccionario;
}

#define traduccion_codigo(codigo)	dic->arr_global[codigo/100].palabra[codigo%100]

void descompresor(char *archivo_entrada) {

	int estado;
	raiz *dic = inicializar_dic();

	FILE *entrada = fopen(archivo_entrada,"rb");
	FILE *salida = fopen("descomprimido","wb");

	char *cadena;	
	char caracter[1];
	uint8_t *codigo_antiguo;
	uint8_t *aux;
	char *nuevo_codigo;

	estado = fread(codigo_antiguo,sizeof(uint8_t),1,entrada);
	if (estado) 
		estado = fwrite(codigo_antiguo,sizeof(uint8_t),1,salida);
	else
		printf("ERROR - ARCHIVO VACIO\n");

	while(fread(nuevo_codigo,sizeof(uint8_t), 1, salida)) {
		cadena = traduccion_codigo(*nuevo_codigo);
		fwrite(cadena, sizeof(uint8_t), 1, salida);
		*caracter = cadena[0];
		aux = malloc(sizeof(uint8_t)+strlen(cadena)+strlen(caracter)-1);
		aux = strcat(aux, codigo_antiguo);
		aux	= strcat(aux, nuevo_codigo);
		codigo_antiguo = nuevo_codigo;
	}
	

}
