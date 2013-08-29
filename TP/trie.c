#include <stdio.h>
#include <stdlib.h>
#include "trie.h"


TrieNodo *crear_nodo(unsigned char caracter) {
	int i;
	TrieNodo *nuevo_nodo = malloc(sizeof(TrieNodo));
	nuevo_nodo->letra = caracter;
	nuevo_nodo->pos = arbol.nelem++;
	
	for(i = 0; i < MAX_CHAR; i++)
		nuevo_nodo->arr_letras[i] = NULL;
	return nuevo_nodo;
}

void inicializar_diccionario(void) {
	int i;
	arbol.nelem = 0;
	
	for(i = 0; i < MAX_CHAR; i++)  
		arbol.arr_letras[i] = crear_nodo(i);
}


int esta_en_diccionario(unsigned char*palabra) {
	TrieNodo *ptr_nodo;
	unsigned char*l = palabra;

	ptr_nodo = arbol.arr_letras[(int)*((unsigned char*)l)];

	while(*(++l) != '\0') {
		if(ptr_nodo->arr_letras[(int)*((unsigned char*)l)] == NULL)
			return -1;
		ptr_nodo = ptr_nodo->arr_letras[(int)*((unsigned char*)l)];
	}
	return ptr_nodo->pos;
}


void agregar_al_diccionario(unsigned char*palabra) {
	unsigned char*l = palabra;	
	TrieNodo *ptr_nodo = arbol.arr_letras[(int)*(unsigned char*)l];

	if(esta_en_diccionario(palabra) >= 0)
		return;

	
	while(*l != '\0' && ptr_nodo->arr_letras[(int)*(unsigned char*)(++l)] != NULL) 
		ptr_nodo = ptr_nodo->arr_letras[(int)*(unsigned char*)l];
	
	while(*l != '\0') { 
		ptr_nodo->arr_letras[(int)*(unsigned char*)l] = crear_nodo(*l);
		ptr_nodo = ptr_nodo->arr_letras[(int)*(unsigned char*)l];
		l++;
	}
	return;
}





