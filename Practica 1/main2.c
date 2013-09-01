#include <stdio.h>
#include <stdlib.h>
#include "SList.h"

static void print_int (int data, void *extra_data)
{
       printf("%d ", data);
}






int main(int argc,char *argv[]) 
{
	enum ordenc {
		"create",	 // 1
		"destroy",	 // 2
		"print", 	 // 3
		"add_end",	 // 4
		"add_beg",	 // 5
		"add_pos",	 // 6
		"lenght", 	 // 7
		"concat", 	 // 8
		"contains",	 // 9
		"index", 	// 10
		"intersect", 	// 11
		"sort",		// 13
		"terminar"};	// 14
	

	const char *comandos[]={
		"create",        // 1
                "destroy",       // 2
                "print",         // 3
                "add_end",       // 4
                "add_beg",       // 5
                "add_pos",       // 6
                "lenght",        // 7
                "concat",        // 8
                "contains",      // 9
                "index",        // 10
                "intersect",    // 11
                "sort",         // 13
                "terminar"};    // 14

	char *entrada(char *b){
		int i;
		for( i = 1 ; EOF != c=getchar() ; i++)
			b[i]= c;
		b[++i]='\0';
		return b;
	}

	int cmpstr(char s[],char t[]) {
	
		int i;
	
		for(i = 0; s[i] != '\0' || t[i] != '\0' ; i++)
			if (s[i] != t[i])
				return 0;
		return 1;	

	int  comando(char *b) {
		int i;
		char s[15];
		for( i = 0; b[i] != ' '; i++)	
			s[i] = b[i];
		s[++i] = '\0';
		for (i = 0; !(cmpstr(s,comandos[i])); i++)
		return i;
	}

	int arg1(char *b) {
		int i;
		for( i = 0; b[i] != ' '; i++);
		return (b[++i] - '0');			// corregir
	}

	int arg2(char *b) {
		int i,j = 0;
		char s[10];
		for( i = 0; b[i] != ' '; i++) // va hasta el primer espacio
		for( ++i; b[i] != ' '; i++,j++) // arranca en dsp del primer espacio
			s[j] = b[i];
		s[++j] = '\0';	
		return atof(s); 
	}
	
	int arg3(char *b) {
		int i,j = 0;
		char s[15];
		for( i = 0; b[i] != ' '; i++); // va hasta el primer espacio
		for( ++i; b[i] != ' '; i++); // va hasta el segundo espacio
		for( ++i; b[i] != ' ' && b[i] != '\n' ; i++,j++)
			s[j] = s[i];
		return atof (s);
	}



