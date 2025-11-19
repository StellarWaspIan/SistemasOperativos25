#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RUTA 260
#define MAX_LINEA 1024

void visualizarArchivo(FILE *archivo) {
    char linea[MAX_LINEA];

    rewind(archivo); // Ir al principio del archivo
    printf("\n--- Contenido del archivo ---\n");
    while (fgets(linea, MAX_LINEA, archivo) != NULL) {
        printf("%s", linea);
    }
    printf("\n--- Fin del archivo ---\n");
}

void agregarTexto(FILE *archivo) {
    char texto[MAX_LINEA];
    printf("Ingrese el texto que desea agregar al final: ");
    getchar(); // Limpiar el buffer
    fgets(texto, MAX_LINEA, stdin);

    fseek(archivo, 0, SEEK_END); // Ir al final del archivo
    fprintf(archivo, "%s", texto);

    printf("✅ Texto agregado con éxito.\n");
}

int main() {
    char ruta[MAX_RUTA];
    FILE *archivo;
    int opcion;

    printf("Ingrese la ruta del archivo de texto: ");
    scanf("%s", ruta);

    archivo = fopen(ruta, "r+");

    if (archivo == NULL) {
        printf("❌ No se pudo abrir el archivo en modo lectura/escritura.\n");

        // Intentar crear el archivo si no existe
        archivo = fopen(ruta, "w+");
        if (archivo == NULL) {
            perror("❌ Error al crear el archivo");
            return 1;
        } else {
            printf("📄 Archivo no existía. Se creó uno nuevo: %s\n", ruta);
        }
    }

    do {
        printf("\n==== Menú ====\n");
        printf("1. Visualizar archivo\n");
        printf("2. Agregar texto al final\n");
        printf("0. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                visualizarArchivo(archivo);
                break;
            case 2:
                agregarTexto(archivo);
                break;
            case 0:
                printf("👋 Finalizando el programa...\n");
                break;
            default:
                printf("❌ Opción no válida.\n");
        }

    } while (opcion != 0);

    fclose(archivo);
    return 0;
}
