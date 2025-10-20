#include <stdio.h>
#include <string.h>

#define maxreg 10
#define msglargo 100

int ids[maxreg];
char mensajes[maxreg][msglargo];
int tipos[maxreg];
int cantidad = 0;

void agregarRegistro() {
    if (cantidad >= maxreg) {
        printf("No se pueden agregar más registros.\n");
        return;
    }

    printf("Ingrese ID ");
    scanf("%d", &ids[cantidad]);

    printf("Ingrese Mensaje: ");
    scanf(" %[^\n]", mensajes[cantidad]);

    printf("Ingrese Tipo: ");
    scanf("%d", &tipos[cantidad]);

    cantidad++;
    printf("Registro agregado\n");
}

void mostrarRegistros() {
    if (cantidad == 0) {
        printf("No hay registros para mostrar.\n");
        return;
    }

    printf("\n--- Lista de registros ---\n");
    for (int i = 0; i < cantidad; i++) {
        printf("Registro %d: ID=%d, Mensaje=\"%s\", Tipo=%d\n", i+1, ids[i], mensajes[i], tipos[i]);
    }
}

void eliminarRegistro() {
    if (cantidad == 0) {
        printf("No hay registros para eliminar.\n");
        return;
    }

    int idEliminar;
    printf("Ingrese el ID del registro a eliminar: ");
    scanf("%d", &idEliminar);

    int encontrado = 0;
    for (int i = 0; i < cantidad; i++) {
        if (ids[i] == idEliminar) {
            encontrado = 1;
            for (int j = i; j < cantidad - 1; j++) {
                ids[j] = ids[j + 1];
                strcpy(mensajes[j], mensajes[j + 1]);
                tipos[j] = tipos[j + 1];
            }
            cantidad--;
            printf("Registro eliminado\n");
            break;
        }
    }

    if (!encontrado) {
        printf("No se encontró un registro con ID %d.\n", idEliminar);
    }
}

int main() {
    int opcion;

    do {
        printf("\n---- Menu ----\n");
        printf("1. Agregar registro\n");
        printf("2. Mostrar registros\n");
        printf("3. Eliminar registro\n");
        printf("0. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarRegistro();
                break;
            case 2:
                mostrarRegistros();
                break;
            case 3:
                eliminarRegistro();
                break;
            case 0:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida.\n");
        }

    } while (opcion != 0);

    return 0;
}
