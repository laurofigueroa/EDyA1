#include <stdio.h>
#include "trie.h"


int main(int argc, char **argv) {
	
	compresor(argv[1]);

	descompresor(argv[1]);
	
	return 0;
}
