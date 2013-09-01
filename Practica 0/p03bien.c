#include <stdio.h>
#include <stdlib.h>

#define MAX 48

enum palo { ORO , BASTO , ESPADA , COPA};

struct carta {
	enum palo tipo;
	int num;
	};

int main(void) {
	struct carta mazo[MAX];
	int pos;
	int random = 0;

	for( pos = 1 ; pos <= MAX ; pos++) {
		if (pos <= 12) {
			mazo[pos].tipo = ORO;
			mazo[pos].num = pos;
		}
		else if ( 12 < pos && pos <= 24) {
			mazo[pos].tipo = BASTO;
			mazo[pos].num = (pos-12);
		}
		else if ( 24 < pos && pos <= 36) {
			mazo[pos].tipo = ESPADA;
			mazo[pos].num = (pos-24);
		}
		else if ( 36 < pos && pos <= 48) {
			mazo[pos].tipo = COPA;
			mazo[pos].num = (pos-36);
		}
	}

	srand(time(NULL));
	random = rand() % 49;
	printf("%d \t %d \n",mazo[random].tipo , mazo[random].num);

	return 0;

}
