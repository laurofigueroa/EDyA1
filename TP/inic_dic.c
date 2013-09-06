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


/* Cambie la estructura, palabra realmente me confundia asi que fui con el tradicional arr :p */

/*
typedef struct _agre {
        unsigned char **arr[SIZE];
        int posicion;
} diccionario;
*/


diccionario *inicializar_diccionarioarr(void) {
	diccionario *nuevo_dic = malloc(sizeof(diccionario));
	int i;

	for(i = 0; i < SIZE; i++) {
	/* Este malloc lo hacias para alocar 100 char pero queremos poner punteros a char*/
		nuevo_dic->arr[i] = malloc(sizeof(char*)*100);

	/* antes aca le asignabas una string a la diagonal de el arreglo bidimensional
	* porque las pos [i][i] son los elem diagonales.
	*/
	}

//inicializarlo con el ascii
	for(i = 0; i < 100; i++) {
	/* Primero guardamos en arr[0][i] guardamos la direccion de memora reservada para
	* un char
	*/
		nuevo_dic->arr[0][i] = malloc(sizeof(char));
	
	/* Despues en la direcion de memoria le guardamos EL char */
		*((char *)nuevo_dic->arr[0][i]) = i;

	/* Asi quedaria todo junto */
		nuevo_dic->arr[1][i] = malloc(sizeof(char)); *((char *)nuevo_dic->arr[1][i]) = i+100;
	/* La idea parece complica porque tenemos q asegurarle a cada char q cuando
	* salgamos de esta funcion no se borre, va a ser distinto cuando desconprimanos
	* porque va a ser todo dentro de la misma funcion y cuando salgamos las
	* constanes no las necesitamos mas pero aca si.
	*/
	}
	for(i = 0; i < 56; i++) {
		nuevo_dic->arr[2][i] = malloc(sizeof(char)); *((char *)nuevo_dic->arr[2][i]) = i+200;
	}
	
	nuevo_dic->posicion = 255; //ya se que va a haber hasta esta posicion

	return nuevo_dic;
}
/*
int main() {

diccionario *dic = inic_dic();
printf("%c \n", *(char*)dic->arr[0][65]);
printf("%c \n", *(char*)dic->arr[0][67]);
printf("%c %d \n", *(char*)dic->arr[1][0], 'd');
printf("%c \n", *(char*)dic->arr[2][40]);

return 0;
}*/
