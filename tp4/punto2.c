#include <stdio.h>
#include <stdlib.h>
#define N 10 

int main(void) {
    int X[N]; 
    int Y[N]; 

    int i;
    int pag, desp, dato;
    int opcion;
    for (i = 0; i < N; i++) {
        X[i] = -1;
        Y[i] = -1;
    }
    while (1) {
        printf("\n=== Sistema de paginacion basico ===\n");
        printf("1) Ingresar dato <pagina, desplazamiento, dato>\n");
        printf("2) Visualizar paginas\n");
        printf("0) Salir\n");
        printf("Opcion: ");
        if (scanf("%d", &opcion) != 1) {
            printf("Entrada invalida.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }
        if (opcion == 0) {
            printf("Fin.\n");
            break;
        }
        switch (opcion) {
            case 1:
                printf("Ingrese <pagina desplazamiento dato>: ");
                if (scanf("%d %d %d", &pag, &desp, &dato) != 3) {
                    printf("Entrada invalida.\n");
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF);
                    continue;
                }
                if (pag != 0 && pag != 1) {
                    printf("Error: numero de pagina invalido (%d). Solo 0 o 1.\n", pag);
                    break;
                }
                if (desp < 0 || desp >= N) {
                    printf("Error: desplazamiento fuera de rango (0..%d).\n", N - 1);
                    break;
                }
                if (pag == 0) {
                    X[desp] = dato;
                    printf("Se guardo %d en pagina 0 (X[%d]).\n", dato, desp);
                } else {
                    Y[desp] = dato;
                    printf("Se guardo %d en pagina 1 (Y[%d]).\n", dato, desp);
                }
                break;
            case 2:
                printf("\nPagina 0 (vector X):\n");
                for (i = 0; i < N; i++) {
                    printf("X[%d] = %d\n", i, X[i]);
                }
                printf("\nPagina 1 (vector Y):\n");
                for (i = 0; i < N; i++) {
                    printf("Y[%d] = %d\n", i, Y[i]);
                }
                break;
            default:
                printf("Opcion invalida.\n");
                break;
        }
    }
    return 0;
}





