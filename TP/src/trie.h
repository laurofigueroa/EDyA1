#ifndef __TRIE_H__
#define __TRIE_H__

#define MAX_CHAR	256
#define SIZE		660

typedef struct TrieNode_ {
	unsigned char letra;
	int pos;
	struct TrieNode_ *arr_letras[MAX_CHAR];
} TrieNodo;

typedef struct TrieRaiz_ {
	int nelem;
	TrieNodo *arr_letras[MAX_CHAR];
} TrieRaiz;

typedef struct _diccionario {
	char **arr[SIZE];
	int posicion;
} diccionario;
	

TrieRaiz arbol;

TrieNodo *crear_nodo(unsigned char caracter);
void inicializar_diccionario(void);
int esta_en_diccionario(unsigned char *palabra);
void agregar_al_diccionario(unsigned char *palabra);


#endif
