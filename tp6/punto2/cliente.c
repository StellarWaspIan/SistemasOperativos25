#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSGSZ 100

struct s_msgbuf {
    long mtype;
    char mtext[MSGSZ+1];
} mensaje;

int main(int argc, char *argv[]) {
    int qid, ret;
    int tipo;

    if (argc != 2) {
        fprintf(stderr, "Uso: %s <tipo_cliente: 1 o 2>\n", argv[0]);
        exit(1);
    }

    tipo = atoi(argv[1]);
    if (tipo != 1 && tipo != 2) {
        fprintf(stderr, "Tipo de cliente invalido (use 1 o 2)\n");
        exit(1);
    }

    qid = msgget(1001, IPC_CREAT | 0660);
    if (qid == -1) {
        perror("msgget");
        exit(1);
    }
    printf("Cliente tipo %d, cola id = %d\n", tipo, qid);

    mensaje.mtype = tipo;  // tipo 1 o tipo 2 según el cliente

    snprintf(mensaje.mtext, MSGSZ, "Mensaje del cliente tipo %d - 1", tipo);
    ret = msgsnd(qid, &mensaje, MSGSZ, IPC_NOWAIT);
    printf("send 1 = %d\n", ret);

    snprintf(mensaje.mtext, MSGSZ, "Mensaje del cliente tipo %d - 2", tipo);
    ret = msgsnd(qid, &mensaje, MSGSZ, IPC_NOWAIT);
    printf("send 2 = %d\n", ret);

    return 0;
}
