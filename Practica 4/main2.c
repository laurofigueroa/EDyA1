#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include <math.h>

int equals(void *key1, void *key2) {
  int *p = key1;
  int *q = key2;

  return *p == *q;
}

int equalstr(void *string1,void *string2) {
	char *s = string1;
	char *t = string2;
	int i;
	
	for(i = 0; s[i] != '\0' || t[i] != '\0' ; i++)
		if (s[i] != t[i])
			return 0;
	return 1;
}


unsigned int hash2(void *key) {
  int *p = key;
  return *p % 10;
}
int stringlength(char *s) {
	int i;
	for(i = 0; s[i] != '\0'; i++)
		;
	return i;
}

int hashnat(int k, int size) {
	float a = 0.7;
	return (int)(size *(k*a-((int)(k*a))));
}

int stringtonat(char *s) {
	int length = stringlength(s);
	int i,res = 0;
	for(i = 0; i < length ; i++)
		res += s[i]*(pow(BASE,i));
	return res;
}

unsigned int hash(void *key, unsigned int size) {
	return hashnat(stringtonat((char *)key),size);
}

int main(void) {
  int x = 42, y = 42, z = 3,w = 4;
	char *k="lauro";
	char *u="hoa";
  Hashtable *ht = hashtable_new(10, hash, equalstr);

//	printf("funcion hash de %s : %d \n",k,hash(k,ht->size));

  hashtable_insert2(ht, k, &z);
  printf("z : %d\n", *((int *)hashtable_lookup(ht, k)));
	
	printf("### segundo insert ###	\n");

	hashtable_insert2(ht, u, &w);

	printf("### segundo lookup ###	\n");

  printf("z : %d\n", *((int *)hashtable_lookup(ht,u )));

	printf("### antes del resize ###	\n");

	
	hashtable_resize(ht);
	
	printf("z : %d\n", *((int *)hashtable_lookup(ht, k)));
	printf("w : %d\n", *((int *)hashtable_lookup(ht,u )));


  hashtable2_delete(ht, u);
  hashtable2_delete(ht, k);
	
  hashtable_destroy(ht);

	return 0;

}
