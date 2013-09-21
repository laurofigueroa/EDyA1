#include <stdio.h>
#include <stdint.h>

#define MASDE8BITS(a)	(a >> 8) 
#define ULTIMOS8BITS(a)	(a & 0x00ff)
#define SOBRANTE(a)	(a >> 8)
#define MEM_LLENA(a)	(a & (0x0001 << 15))
#define MAS_SIG(a)	(a & (0x0001 << 15))
#define PRIMER_BIT(a)   (a & 0x0001)
#define N_BIT(a, n)     PRIMER_BIT(a >> n-1)
#define ULTIMO_BIT(a)   ((a >> 8) & 0x0001)




int main() {
	FILE *salida = fopen("hacer_binario", "wb+r");
/*
	uint16_t cad[12];
	cad[0] = '/';
	cad[1] = 'W';
	cad[2] = 'E'; 
	cad[3] = 'D'; 
	cad[4] = 256; 
	cad[5] = 'E'; 
	cad[6] = 260; 
	cad[7] = 261; 
	cad[8] = 257; 
	cad[9] = 'B'; 
	cad[10] = 260; 
	cad[11] = 'T'; 

	int i;	
	for(i = 0; i < 12; i++)
		printf("cad[%d] = %d - ",i,cad[i]);	 

	fwrite(cad, sizeof(uint16_t), 12, archivo_binario);
*/
//	uint16_t cod = 23;
/*	printf("ULTIMOS8BITS = %d \n",0x00ff);
	printf("SOBRANTE = %d\n \n", 0xff00);
	printf("%d \n", cod);
	printf("MASDE8BITS(%d) = %d \n",cod,MASDE8BITS(cod));
	printf("SOBRANTE(%d) = %d \n",cod,SOBRANTE(cod));
	printf("ULTIMOS8BITS(%d) = %d \n",cod,ULTIMOS8BITS(cod));
	printf("SOBRANTE(%d) = %d \n",cod,SOBRANTE(cod));
*/	
/*	printf("%d (9) ",N_BIT(cod,9));
	printf("%d ",N_BIT(cod,8));
	printf("%d ",N_BIT(cod,7));
	printf("%d ",N_BIT(cod,6));
	printf("%d ",N_BIT(cod,5));
	printf("%d (4)",N_BIT(cod,4));
	printf("%d ",N_BIT(cod,3));
	printf("%d ",N_BIT(cod,2));
	printf("%d (1)\n",N_BIT(cod,1));
*/
//	printf("%d \n", 0x0001);
/*	
	printf("%d ", ULTIMO_BIT(cod));	
	printf("%d ", ULTIMO_BIT(cod<<9));	
	printf("%d ", ULTIMO_BIT(cod<<10));	
	printf("%d ", ULTIMO_BIT(cod<<11));	
	printf("%d ", ULTIMO_BIT(cod<<12));	
	printf("%d ", ULTIMO_BIT(cod<<13));	
	printf("%d ", ULTIMO_BIT(cod<<14));	
	printf("%d \n", ULTIMO_BIT(cod<<15));	
*/

	uint16_t x = 517, y = 289, z = 1056;
	uint8_t memoria = 0;
	int ocupado = 0;

	agregar_binario(y, 288, salida, &memoria, &ocupado);
	agregar_binario(x, 516, salida, &memoria, &ocupado);
	agregar_binario(z, 1055, salida, &memoria, &ocupado);
	fputc(memoria<<(8-ocupado), salida);

/*	fclose(salida);
	FILE *entrada = fopen("hacer_binario", "rb");
*/
//	printf("abriiiiiiiiiii\n");
	uint16_t memoria1 = 0;
	ocupado = 0;

	y = leer_binario(salida, 287, &memoria1, &ocupado);
	
	x = leer_binario(salida, 515, &memoria1, &ocupado);
	z = leer_binario(salida, 1054, &memoria1, &ocupado);

	printf("%d \n", y);
	printf("%d \n", x);
	printf("%d \n", z);


	return 0;
}
