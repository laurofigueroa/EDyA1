#include<stdio.h>
#include<stdlib.h>


char *getnewline (){
	char *m = malloc (40);
	char c;
	int i=0;
	while (EOF!=(c=getchar()) && '\n' != c){
		*m = c;
		m++;
		i++;
	}
	m -= i;// m = m- i
	return m;
}

int main (){
	char *a= getnewline();
	printf ("%s\n",a);
	free (a);
}
