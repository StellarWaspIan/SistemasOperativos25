#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const int SEGMENTO_VALIDO = 0;
    const int BASE   = 1000;
    const int LIMITE = 500;  
    int seg;
    int desplazamiento;
    int direccion_fisica;
    printf("Segmentacion basica (un solo segmento)\n");
    printf("Segmento valido: %d, BASE = %d, LIMITE = %d\n\n", SEGMENTO_VALIDO, BASE, LIMITE);
    while (1) {
        printf("Ingrese direccion logica <segmento desplazamiento> (negativo para salir): ");
        if (scanf("%d %d", &seg, &desplazamiento) != 2) {
            printf("Entrada invalida.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }
        if (seg < 0 || desplazamiento < 0) {
            printf("Fin.\n");
            break;
        }
        if (seg != SEGMENTO_VALIDO) {
            printf("Error: numero de segmento invalido (%d). Solo se acepta %d.\n",seg, SEGMENTO_VALIDO);
            continue;
        }
        if (desplazamiento >= LIMITE) {
            printf("Error: desplazamiento %d fuera de limite (max = %d).\n",desplazamiento, LIMITE - 1);
            continue;
        }
        direccion_fisica = BASE + desplazamiento;
        printf("Direccion logica <%d, %d> -> direccion fisica = %d\n\n",seg, desplazamiento, direccion_fisica);
    }
    return 0;
}
