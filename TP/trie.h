#ifndef __TRIE_H__
#define __TRIE_H__

#define MAX_CHAR	256

typedef struct TrieNode_ {
	unsigned char letra;
	int pos;
	struct TrieNode_ *arr_letras[MAX_CHAR];
} TrieNodo;

typedef struct TrieRaiz_ {
	int nelem;
	TrieNodo *arr_letras[MAX_CHAR];
} TrieRaiz;

typedef struct _agre {
	unsigned char *palabra[100];
	int posicion;
} diccionario;
	
typedef struct raiz_ {
	diccionario *arr_global;
	int nelems;
} raiz; 

TrieRaiz arbol;



TrieNodo *crear_nodo(unsigned char caracter);
void inicializar_diccionario(void);
int esta_en_diccionario(unsigned char *palabra);
void agregar_al_diccionario(unsigned char *palabra);
unsigned char *binario(int numero, int tamanio);
FILE *comprimir(char *nombre);

#endif
