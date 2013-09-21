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

	while((1 << ++nbits) <= nelems_dic); 
		
	while(nbits != 0) {
		if(*ocupado != 8) {
			*memoria <<= 1;
			*memoria |= N_BIT(codigo_entrada, nbits);
			(*ocupado)++;
			nbits--;
		}
		else {
			fputc(*memoria, salida);
			*ocupado = 0;
		}
		if((nbits == 0) && (*ocupado == 8)){
			fputc(*memoria, salida);
			*ocupado = 0;	
		}
		
	}
}

uint16_t leer_binario(FILE *entrada, int nelems_dic, uint16_t *memoria, int *ocupado) {

	uint8_t codigo;
	uint16_t salida = ((*memoria << (16 - *ocupado)) >> (16 - *ocupado));
	int nbits = 0;
	int bits_disponibles = 0;

	
	while((1 << ++nbits) <= nelems_dic+1);
	
	nbits -= *ocupado;

	while(nbits != 0) {
		if(bits_disponibles != 0) {
			salida <<= 1;
			salida |= ULTIMO_BIT(codigo);
			codigo <<= 1;
			nbits--;
			bits_disponibles--;
		}
		else {
			codigo = fgetc(entrada);
			bits_disponibles = 8;
		}

	}
	*memoria = codigo >> (8 - bits_disponibles);
	*ocupado = bits_disponibles;

	return salida;
}
