#include <stdlib.h>
#include "hashtable.h"
#include <stdio.h>

Hashtable *hashtable_new(int size, HashFunc hash,EqualsFunc igualdad) {
  unsigned int idx;
  Hashtable *ht = malloc(sizeof(Hashtable));
	
	ht->equal = igualdad;
  ht->hash = hash;
  ht->size = size;
  ht->table = malloc(sizeof(Hashbucket*)*size);
  ht->nelems = 0;

  for (idx = 0; idx < size; idx++) {
    ht->table[idx] = NULL;
	}

  return ht;
}


int isin(Hashtable *ht,Hashbucket *nodo,char *key) {
//	printf("key del nodo: %s \n",(char*)nodo->key);
	while(nodo != NULL){
		if(ht->equal((char *)nodo->key,key))
			return 1;
		nodo = nodo->next;
	}
	return 0;
}


void hashtable_insert(Hashtable *ht, void *key, void *data) {
 
	unsigned int idx = ht->hash(key,ht->size);
	
	Hashbucket *newbucket = malloc(sizeof(Hashbucket));
	newbucket->key = key;
	newbucket->data = data;
	newbucket->next = NULL;

//	printf("key a guardar:%s \n",(char*)(key));

  if (ht->table[idx]== NULL){
   	ht->table[idx] = newbucket;
		ht->nelems++;
		return;
	}

	Hashbucket *aux = ht->table[idx];
	Hashbucket *before = aux;

//	printf("isin key (%s) : %d \n",(char*)key,isin(ht,aux,(char*)key));

	if(isin(ht,aux,(char*)key)){
//	printf(" estoy en el if \n");
	//	printf("equal(aux->key,key) = %d \n",ht->equal(aux->key,key));
		while(!(ht->equal(aux->key,key))){
//			printf("key : %s \n",(char*)aux->key);
			aux = aux->next;
	}	
//	 printf("fuera del while\n");
//   printf("ultimo return: %s \n",(char*)(aux->key));
		aux->data = data;
		free(newbucket);
		return;
	}

//	printf(" es este ?%s \n",(char *)aux->key);

	while(aux != NULL) {
		before = aux;
		aux = aux->next;
	}
	before->next = newbucket;
	ht->nelems++;
	return;
}
void hashtable_insert2(Hashtable *ht, void *key, void *data) {
	unsigned int idx = ht->hash(key,ht->size);
	Hashbucket *node = ht->table[idx];

	while(node != NULL) {
		if(ht->equal(node->key,key)){
			node->data = data;
			return;
		}
		node = node->next;
	}

	if(node == NULL) {
		Hashbucket *hb = malloc(sizeof(Hashbucket));
		hb->key = key;
		hb->data = data;
		hb->next = ht->table[idx];
		ht->table[idx] = hb;
		ht->nelems++;
	}
}
void *hashtable_lookup2(Hashtable *ht, void *key) {
  unsigned int idx = ht->hash(key,ht->size);

  if (ht->table[idx] == NULL){
		printf("no esta \n");
    return NULL ;
	}
	
//	printf("antes del if key: %s \n",(char *)ht->table[idx]->key);

	Hashbucket *aux = ht->table[idx];

	if(isin(ht,aux,(char*)key)) {
		while(!ht->equal(aux->key,key)) {
//			printf("key: %s \n",(char *)aux->key);
			aux = aux->next;
		}
//	printf("key: %s \n",(char *)aux->key);		
  return aux->data;
	}
	return NULL;
}

void *hashtable_lookup(Hashtable *ht,void *key) {
	unsigned int idx = ht->hash(key,ht->size);
	Hashbucket *node = ht->table[idx];
	
	while(node != NULL) {
		if(ht->equal(node->key,key))
			return node->data;
		node = node->next;	
	}
	if(node == NULL)
		return NULL;
}

void hashtable_delete(Hashtable *ht, void *key) {
  unsigned int idx = ht->hash(key,ht->size);

  if (isin(ht,ht->table[idx],(char*)key)) {
  	ht->nelems--;
		
		Hashbucket *aux,*before;
		aux = ht->table[idx];
		before = aux;
		
  	while(!ht->equal(aux->key,key)) {
//			printf("key: %s \n",(char *)aux->key);
			before = aux;
			aux = aux->next;
			
		}
  	if(aux == before){
  		if(aux->next == NULL) {
  			free(aux);
  			ht->table[idx] = NULL;
  			return;
			}
			ht->table[idx] = aux->next;
			free(aux);
			return;
		}
		before->next = aux->next;
		free(aux);
		 return;
  }
}

void hashtable2_delete(Hashtable *ht, void *key) {
	unsigned int idx = ht->hash(key,ht->size);

	Hashbucket *node = ht->table[idx];
	Hashbucket *before;

	while (node != NULL) {
		before = node;
		if (ht->equal(node->key,key)) {
			before->next = node->next;
			free(node);
			return;
		}
	node = node->next;
	}
}


void hashtable_destroy(Hashtable *ht) {
  int i;
  Hashbucket *todelete,*aux;
  for(i = 0; i < ht->size ; i++) {
  	aux= ht->table[i];
  	while( aux != NULL ) {
  		todelete = aux;
  		aux = aux->next;
    	free(todelete);
  	}
  }
  free(ht->table);
  free(ht);
}

void hashtable_resize(Hashtable *ht) {

	Hashtable *newht = malloc(sizeof(Hashtable));
	newht->table = malloc(sizeof(Hashbucket*)*2*ht->size);
	newht->size = ht->size *2;
	newht->nelems = 0;
	newht->hash = ht->hash;
	newht->equal = ht->equal;
	
	Hashbucket *aux,**aux2;

	int i,j;
	for(i = 0; i < ht->size ; i++) {
			if(ht->table[i] != NULL) {
				aux = ht->table[i];
				while(aux != NULL) {
					hashtable_insert(newht,aux->key,aux->data);
					aux = aux->next;
				}
			}
	}
	aux2 = ht->table;
	ht->table = newht->table;
	newht->table = aux2;
	newht->size = ht->size;
	
	hashtable_destroy(newht);
}
