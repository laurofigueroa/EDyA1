#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MASDE8BITS(a)	(a >> 8) 
#define ULTIMOS8BITS(a)	(a >> 8)
#define SOBRANTE(a)	(a >> 8)
#define MEM_LLENA(a)	(a & (0x0001 << 15))
#define PRIMER_BIT(a)	(a & 0x0001)
#define ULTIMO_BIT(a)	(a >> 7)
#define N_BIT(a, n)	PRIMER_BIT(a >> n-1)



void agregar_binario(uint16_t codigo_entrada, int nelems_dic, FILE *salida, uint8_t *memoria, int *ocupado) {
	
	uint8_t codigo_salida;
	uint16_t nbits = 0;

//	printf("COD_ENTRADA  %%c = %c, %%d = %d \n", codigo_entrada, codigo_entrada);

	while((1 << ++nbits) <= nelems_dic); 
		
	while(nbits != 0) {
//		printf("nbits = %d\n", nbits);
		if(*ocupado != 8) {
			*memoria <<= 1;
			*memoria |= N_BIT(codigo_entrada, nbits);
			(*ocupado)++;
			nbits--;
//		printf("memoriaaa = %d --- ocupado = %d \n", *memoria, *ocupado);
		}
		else {
			fputc(*memoria, salida);
//			printf("# ESCRIBIENDO ---------------------->  %d \n", *memoria);
			*ocupado = 0;
		}
		if((nbits == 0) && (*ocupado == 8)){
			fputc(*memoria, salida);
//			printf("########## ESCRIBIENDO ########  %d \n", *memoria);
			*ocupado = 0;	
		}
		
	}
}

uint16_t leer_binario(FILE *entrada, int nelems_dic, uint16_t *memoria, int *ocupado) {

	uint8_t codigo;
	uint16_t salida = ((*memoria << (16 - *ocupado)) >> (16 - *ocupado));
	int nbits = 0;
	int bits_disponibles = 0;
	printf("###### PRINCIPIO: salida = %d , memoria = %d , ocupado = %d\n",salida, *memoria, *ocupado);

	
	while((1 << ++nbits) <= nelems_dic+1);
	
	printf("A nbits = %d\n", nbits);
	nbits -= *ocupado;
//	printf("D nbits = %d\n", nbits);

	while(nbits != 0) {
//		printf("entre al while de leer binario\n");
		if(bits_disponibles != 0) {
//			printf("1 - salida previa  %d\n", salida);
			salida <<= 1;
//			printf("2 - salida <<1 %d\n", salida);
			salida |= ULTIMO_BIT(codigo);
//			printf("3 - salida |ultimo bit %d\n",salida);
//			printf("codigo ultimo bit = %d\n", ULTIMO_BIT(codigo));
			codigo <<= 1;
//			printf("4 - codigo << = %d\n", codigo);
			nbits--;
			bits_disponibles--;
//	printf("salgo del if, nbits = %d , bits_disponibles = %d, codigo = %d \n", nbits, bits_disponibles, codigo);
		}
		else {
			codigo = fgetc(entrada);
			bits_disponibles = 8;
			printf("###### CODIGO LEIDO = %d \n", codigo);
		}

	}
	*memoria = codigo >> (8 - bits_disponibles);
	*ocupado = bits_disponibles;

//	printf("# SALIENDO ---------------------->  %d \n", salida);
		
	return salida;
}
