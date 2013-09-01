#include <stdio.h> 
#include <math.h>

#define USER 	"lauro"
#define PASSWORD  "holas"
#define MAXLENGTH 50

float abs2(float x) {
	if (x >= 0.0)
		return x;
	else {
		x= -x;	
		return x;
	}
}


float eval(float a, float b, float c, float x) {

	float res;

	res= a*x*x+b*x+c;
	return res;

}

int hasroot(float a, float b, float c) {
	
	float raiz;
	
	raiz= (b*b)-(4*a*c);
	
	if (raiz < 0) 
		return 0;
	else 
		if (raiz == 0) 
			return 1;
		else 
			return 2;
}	
	
	
int sum(int n) {
	
	int sum;
	
	for(sum = 0; n > 0; n--)
			sum=sum+n;
	return sum;
}



int factorial(int n) {
	
	int fac = 0;
	
	for(fac = 1; n > 0; n--)
		fac=fac*n;
	
	return fac;
}

int factorial2(int n) {

	if (n== 0) 
		return 1;
	else
		return n*factorial2(n-1);
} 

int factorial3(int n,int fac) {
	if (n!=0 ) 
        factorial3(n-1,fac*n);
	else
		return fac;
} 


int fib(int n) {
	
	int ant,fib,res,i;
	
	fib= 0;
	ant= 1;
	res= 0;
	
	if (n == 0)
		return n;
	else
		for(i = 1; i <= n; i++) {
		
			res= fib + ant;
			ant= fib;
			fib= res;
		}
	return fib;
}


int fib2(int n) {
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else 
		return fib2(n-1)+fib2(n-2);
}	


int bisiesto(int n) {

	if (n%400 == 0)
		return 1;
	else if (n%100 == 0)
		return 0;
	else if (n%4 == 0)
		return 1;
}

int bisiesto2(int n) {

	if((n%4 == 0 && !(n%100 == 0)) || (n%400 == 0))
		return 1;
	else 
		return 0;
}

int isprime(int n) {

	int i;
		 
	for (i=2; (i*i)<n; i++)
		if (n%i == 0)
			return 0;
	return 1;
}

void hola(void) {
	
	putchar('h');
	putchar('o');
	putchar('l');
	putchar('a');
	putchar(' ');
	putchar('m');
	putchar('u');
	putchar('n');
	putchar('d');
	putchar('o');
	putchar('.');
	putchar('\n');
}

int lc() {
	
	char c;
	int nl= 0;
	
	while((c=getchar()) != EOF)
		if (c == '\n')
			nl++;
	return nl;
}

void echo() {

	char c;
	
	while((c=getchar()) != EOF)
		putchar(c);
	
}
void simplecaesar() {
	
	char c;
	
	while ((c=getchar()) != EOF) {
		if (c == 'a')
			c='u';
		else if (c == 'e')
			c='o';
		else if (c == 'o')
			c='e';
		else if (c == 'u')
			c='a';
	
		putchar(c);
	}
}


int euclides(int a, int b) {

	if (a==0)
		return b;
	else if (b==0)
		return a;
	else 
		return euclides(b, a%b);
}

int euclides2(int a, int b) {
	
	int res;
	
	if (a==0)
		return b;
	else if (b==0)
		return a;
	else while(res != 0)
		if (a==0)
			return b;
		else if (b==0)
			return a;	
		else
			res=a%b;
			a=b;
			b=res;
			
	return b;
}


float prom(int s[],int a) {
	
	int i,acum;
	acum=0;
	
	for(i=0; i < a; i++)
		acum=acum + s[i];
		
	return ((float)acum/(float)a);
}

void printint(int s[], int n) {
	
	int i;
	
	for(i=0;i < n;i++)
		printf("%d \t",s[i]);
		
	putchar('\n');	
}

int isin(int s[],int n,int a) {
	
	int i;
	
	for(i=0; i < n; i++)
		if (a==s[i])
			return 1;
			
	return 0;
	
}

int lenstr(char s[]) {
	
	int i;
	
	for(i = 0; s[i] != '\0'; i++)
		;
	return i;
}

int cmpstr(char s[],char t[]) {
	
	int i;
	
	for(i = 0; s[i] != '\0' || t[i] != '\0' ; i++)
		if (s[i] != t[i])
			return 0;
	return 1;
	
}

void login() {
	
	char c;
	char user[]= USER ;
	char pass[]= PASSWORD ;
	char aux[MAXLENGTH];
	int i;
	
	printf("Ingrese el usuario: ");
	
	for(i = 0; i < MAXLENGTH && (c=getchar()) != EOF && c != '\n' ; i++)
			aux[i]=c;
	
	aux[i]='\0';
	
	
	if( cmpstr(aux,user) != 0 )
		printf("El usuario ingresado es correcto\n");
	else{
		printf("El usuario ingresado es incorrecto \n");
		printf("Vuelva a ingresar el usuario: " );
		
		while(cmpstr(aux,user) == 0) {
	
			for(i = 0; i < MAXLENGTH && (c=getchar()) != EOF && c != '\n' ; i++)
				aux[i]=c;
	
			aux[i]='\0';
			
			if( cmpstr(aux,user) != 0 )
				printf("El usuario ingresado es correcto\n");
			else{
			printf("El usuario ingresado es incorrecto \n");
			printf("Vuelva a ingresar el usuario: " );
		
			}
		}
	}
	
	printf("Ingrese la contraseña: ");
	
	for(i = 0; i < MAXLENGTH && (c=getchar()) != EOF && c != '\n' ; i++)
		aux[i]= c;
	
	aux[i] = '\0';
		
	if (cmpstr(aux,pass) != 0) 
		printf("La contraseña ingresada es correcta \n");
	else {
		printf("La contraseña ingresada es incorrecta \n");
		printf("Vuelva a ingresar la contraseña: " );
		
		while (cmpstr(aux,pass) == 0) {
		
			for(i = 0; i < MAXLENGTH && (c=getchar()) != EOF && c != '\n' ; i++)
				aux[i]= c;
	
			aux[i] = '\0';
	
			if( cmpstr(aux,pass) != 0 )
				printf("La contraseña ingresada es correcta\n");
			else {
				printf("La contraseña ingresada es incorrecta \n");
				printf("\nVuelva a ingresar la contraseña \n");
			}		
		}	
	}
}

int invertir(int a) {
		int c = 0;
		if ( a/10 == 0)
			return a;
		else 
			while (a/10 != 0) {
				c = c*10 + a%10;
				a = a/10;
			}
			return c*10 + a;
			

}

void vocal(void) {
	int i;
	char c;
	int a[] = {0,0,0,0,0};
	for (i = 0 ; (c=getchar()) != EOF && c != '\n'; i++) {
		if (c == 'a')
			a[0]++;
		else if (c == 'e')
			a[1]++;
		else if (c == 'i')
			a[2]++;
		else if (c == 'o')
			a[3]++;
		else if (c == 'u')
			a[4]++;
	}
	
	for (i=0; i < 5; i++)
		printf(" %d \t", a[i]);
	
	printf("\n");
	
}

void fcom() {
	
	char c;
	
	while( ((c=getchar()) != EOF) || ( c == '*' ) )
		if (c == '*')
			if (((c=getchar()) != EOF) && (c == '/') )
				return;
	
}

void deletecom() {

	char c,d;
		
	while((c=getchar()) != EOF) {
		if (c == '/')
			if ((d=getchar()) == '*' && (d != EOF) ) {
				fcom();
				c='\0';
			}
			else {
				putchar(c);
				c=d;
			}
		if (c != EOF)
			putchar(c); /* aca hay un comentario */
		
	}
}


	/*hola*/
int main(void) {
	/*hola*//*hola*/
	//deletecom(); /*hola*/ 
	/*hola*/
	char s[]="hola";
	char t[]="hola";
	printf("%d \n", cmpstr(s,t));	
	printt();
return 0;
}
