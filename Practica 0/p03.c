#include<stdio.h>
#include<stdlib.h>

enum palos { ORO = 1, BASTO, ESPADA, COPA};

typedef enum palos Palo;

struct carta{
	int num;
	Palo palo;

};

struct carta azar(struct carta mazo1[], int num)//elije una carta al azar
{
	srand (time(NULL));
	int p=rand()%num;
	
	return mazo1[p];
}
	
int main(void)
{	
	
//	struct carta *mazo = (struct carta *) malloc(48*sizeof(struct carta));	// castear puntero a void?
	struct carta mazo[48];
	int i;

	for(i = 0; i < 48 ; i++) {
		if(i <= 11){
			mazo[i].num = i+1;
			mazo[i].palo = ORO;
		}else if (11 < i <= 23) {
			 mazo[i].num = (i-11);
                       	 mazo[i].palo = BASTO;
		}else if (23 < i <= 35) {
			 mazo[i].num = (i-23);
	                 mazo[i].palo = ESPADA;
		}else if (35 < i <= 47) {
			 mazo[i].num = (i-35);
	                 mazo[i].palo = COPA;
		}
	}


	
	for(i=0; i< 48; i++)
		printf("%d	%d  \n", mazo[i].num,mazo[i].palo);
	
/*	struct carta n=azar(mazo, 48);
	printf("%d-%d\n", mazo[n].num ,mazo[n].palo);
*/	

	return 0;
}
			
	
	
	
	

	
	
