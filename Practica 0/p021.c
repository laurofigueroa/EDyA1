#include <stdio.h>
typedef void (*VisitorFunc)(int);

void recorre(VisitorFunc,int s[], int n){ 

//int recorre2( int (*f)(int), int s[], int n) {
	int i;
	
	for(i = 0; i < n; i++) 		
		f(s[i]);
	
}
void suma2(int *a) {	
	*a++;
}
int suma1(int a) {
	
	return a+1	;
	
}

int main(void) {
	int i;
	int s[3]={1,2,3};
	recorre(&suma2,s,3);
	
	for(i = 0; i < 3; i++)
		printf("%d \n", s[i]);
	
}
