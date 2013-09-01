#include <stdio.h>
#include <stdlib.h>
#include "SList.h"
#include <string.h>

static void print_int (int data, void *extra_data)
{
       printf("%d ", data);
}

enum ordenc {
	CREATE,		 // 1
	DESTROY,	 // 2
	PRINT,	 	 // 3
	ADD_END,	 // 4
	ADD_BEG,	 // 5
	ADD_POS,	 // 6
	LENGHT, 	 // 7
	CONCAT, 	 // 8
	CONTAINS,	 // 9
	IDEX, 		// 10
	INTERSECT, 	// 11
	SORT,		// 12
	TERMINAR};	// 13

int cmpstr(char s[],char t[]) {
	
	int i;
	
	for(i = 0; s[i] != '\0' || t[i] != '\0' ; i++)
		if (s[i] != t[i])
			return 0;
	return 1;
}	



int main(int argc,char *argv[]) 
{
	int posicion,arg1,arg2,arg3,i,cantlistas;
	char comando[15];
	SList *listas[10];

	char *comandos[]={
		"create",        // 0 
                "destroy",       // 1
                "print",         // 2
                "add_end",       // 3
                "add_beg",       // 4
                "add_pos",       // 5
                "lenght",        // 6
                "concat",        // 7
                "contains",      // 8
                "index",        //  9
                "intersect",    // 10
                "sort",         // 11
                "terminar"};    // 12


	printf("Ingrese un comando: ");
	scanf("%s",comando);

	for(posicion = 0; 1 != cmpstr(comando,comandos[posicion]) ; ++posicion)
			;
	
	/*printf("%d \n",posicion);*/
	while(posicion != TERMINAR) {
	
		switch(posicion) {
			case CREATE :
					printf("lleguee create");
					scanf("%d",&arg1);
					cantlistas = arg1;
					for(i = 0; i < arg1 ; i++)
						listas[i] = malloc(sizeof(SList));
					break;
			case DESTROY :
					printf("llegue destroy");
					for( i = 0; i < cantlistas; i++)
						slist_destroy(listas[i]);
					break;
			case PRINT :
					printf("llegue prtin");
					scanf("%d", &arg1);
					slist_foreach( listas[arg1-1] , print_int , NULL);
					break;
			case ADD_END : 
					printf("llegue add");
					scanf("%d", &arg1);
					scanf("%d", &arg2);
					slist_append(listas[arg1-1], arg2);
					break;
		}
	printf("Ingrese un comando: ");
        scanf("%s",comando);
	
	for(posicion = 1; cmpstr(comando,comandos[posicion]) ; posicion++)
              ;


	}

	return 0;

}	
