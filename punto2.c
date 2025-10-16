#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	//funcion de comparacion para el ordenamiento
	int compararChar(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
	}
	char cadena1[30];
    char cadena2[30];
	printf("Ingrese la palabra 1: ");
	scanf("%s", cadena1);
	printf("Ingrese el palabra 2: ");
	scanf("%s", cadena2);
	
	qsort(cadena1, strlen(cadena1), sizeof(char), compararChar);
	qsort(cadena2, strlen(cadena2), sizeof(char), compararChar);

	printf("Palabras Ordenadas: ");
    printf("\n");
	printf("Palabra 1: %s",cadena1);
    printf("\n");
	printf("Palabra 2: %s",cadena2);
    printf("\n");
	
	return 0;
}


