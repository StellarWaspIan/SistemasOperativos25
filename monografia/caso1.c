#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int Dato = 100;      // Valor inicial compartido
int variableA = 20;  // Proceso A suma 20
int variableB = 35;  // Proceso B resta 35

void OperacionA() {
    int temp = Dato;           // Lee
    printf("[A] Lee Dato = %d\n", temp);
    temp = temp + variableA;   // Calcula
    printf("[A] Calcula Dato + %d = %d\n", variableA, temp);
    Dato = temp;               // Escribe
    printf("[A] Escribe Dato = %d\n", Dato);
}

void OperacionB() {
    int temp = Dato;           // Lee
    printf("[B] Lee Dato = %d\n", temp);
    temp = temp - variableB;   // Calcula
    printf("[B] Calcula Dato - %d = %d\n", variableB, temp);
    Dato = temp;               // Escribe
    printf("[B] Escribe Dato = %d\n", Dato);
}

int main() {
    pid_t pidA, pidB;

    printf("Dato inicial = %d\n\n", Dato);

    pidA = fork();
    if (pidA == 0) {
        OperacionA();
        exit(0);
    }

    pidB = fork();
    if (pidB == 0) {
        OperacionB();
        exit(0);
    }

    waitpid(pidA, NULL, 0);
    waitpid(pidB, NULL, 0);

    printf("\nDato final (no determinista) = %d\n", Dato);

    return 0;
}
