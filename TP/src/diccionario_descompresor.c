/*
#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

#define SIZE 320


diccionario *inicializar_diccionarioarr(void) {
	printf("asdasdasd");
	diccionario *nuevo_dic = malloc(sizeof(diccionario));
	int i;

	for(i = 0; i < SIZE; i++) {
		nuevo_dic->arr[i] = malloc(sizeof(char*)*100);
	}

	for(i = 0; i < 100; i++) {
			nuevo_dic->arr[0][i] = malloc(sizeof(char)); *((char *)nuevo_dic->arr[0][i]) = i;
			nuevo_dic->arr[1][i+100] = malloc(sizeof(char)); *((char *)nuevo_dic->arr[1][i+100]) = i+100;
	}

	for(i = 200; i < 256; i++) {
		nuevo_dic->arr[2][i] = malloc(sizeof(char)); *((char *)nuevo_dic->arr[2][i]) = i;
	}
	
	nuevo_dic->posicion = 255;

	return nuevo_dic;
}

int main(void) {
	diccionario *dic = inicializar_diccionarioarr();
	
	printf("%c - %d \n",dic->arr[0][65]);
	
}
*/


#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

#define SIZE 320




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

/*
int main() {

diccionario *dic = inicializar_diccionarioarr();
printf("%s \n", (char*)dic->arr[0][1]);
printf("%s \n", (char*)dic->arr[0][2]);
printf("%s %d \n", (char*)dic->arr[1][0], 'd');
printf("%s \n", (char*)dic->arr[2][0]);
printf("%s \n", (char*)dic->arr[2][1]);

	imprimir_diccionario(dic);



return 0;
}

*/







