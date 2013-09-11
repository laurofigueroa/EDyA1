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
	int i;

	for(i = 0; i < SIZE; i++) {
		nuevo_dic->arr[i] = malloc(sizeof(char*)*100);

	}

	for(i = 0; i < 100; i++) {
		nuevo_dic->arr[0][i] = malloc(sizeof(char));
	
		*((char *)nuevo_dic->arr[0][i]) = i;

		nuevo_dic->arr[1][i] = malloc(sizeof(char)); 

		*((char *)nuevo_dic->arr[1][i]) = (i+100);
	}
	for(i = 0; i < 56; i++) {
		nuevo_dic->arr[2][i] = malloc(sizeof(char)); *((char *)nuevo_dic->arr[2][i]) = (i+200);
	}
	
	nuevo_dic->posicion = 255; 

	return nuevo_dic;
}

void imprimir_diccionario(diccionario *dic) { 

	int i,j;
	for(i = 0; i < 100; i++) {
		printf("pos: %d cadena: %s \n", i, (char*)dic->arr[0][i]);
		printf("pos: %d cadena: %s \n", i+100, (char*)dic->arr[1][i]);
	}
	for(i = 0; i < 56; i++) {
		printf("pos: %d cadena: %s \n",i+200, (char*)dic->arr[2][i]);
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








