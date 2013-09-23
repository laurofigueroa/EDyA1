#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

#define SIZE 660




diccionario *inicializar_diccionarioarr(void) {
	diccionario *nuevo_dic = malloc(sizeof(diccionario));
	int i,j;

	for(i = 0; i < SIZE; i++) {
		nuevo_dic->arr[i] = malloc(sizeof(char*)*100);

	}

	for(i = 0; i < 100; i++) {
		nuevo_dic->arr[0][i] = malloc(sizeof(char)*2);
	
		*(nuevo_dic->arr[0][i]) = i;
		nuevo_dic->arr[0][i][1] = '\0';

		nuevo_dic->arr[1][i] = malloc(sizeof(char)*2); 

		*(nuevo_dic->arr[1][i]) = (i+100);
		nuevo_dic->arr[1][i][1] = '\0';
	}
	for(i = 0; i < 56; i++) {
		nuevo_dic->arr[2][i] = malloc(sizeof(char)*2); 

		*((char *)nuevo_dic->arr[2][i]) = (i+200);
		nuevo_dic->arr[2][i][1] = '\0';
	}
	
	nuevo_dic->posicion = 255; 

	for(i = 56; i < 100; i++) {
		nuevo_dic->arr[2][i] = NULL;
	}

	for(i = 3; i < SIZE; i++) {
		for(j = 0; j < 100; j++) {
			nuevo_dic->arr[i][j] = NULL;
		}
	}



	return nuevo_dic;
}

void imprimir_diccionario(diccionario *dic) { 

	int i,j;
	for(j = 0; j < 7; j++) {
		for(i = 0; i < 100; i++) {
			printf("fila: %d - col: %d - pos: %d cadena: %s \n", j, i, i+j*100, (char*)dic->arr[j][i]);
		}

	}
}

void liberar_diccionario(diccionario *dic) {
	int i,j;
	for(i = 0; i < SIZE; i++) {
		for(j = 0; j < 100; j++) {
			if(dic->arr[i][j] != NULL)
				free(dic->arr[i][j]);
			else 
				return;
		}
		free(dic->arr[i]);
	}
	free(dic);
}







