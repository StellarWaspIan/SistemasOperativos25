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

int main(void) {
    int qid, ret;

    qid = msgget(1001, IPC_CREAT | 0660);
    if (qid == -1) {
        perror("msgget");
        exit(1);
    }
    printf("Servidor: cola id = %d\n", qid);

    while (1) {
        ret = msgrcv(qid, &mensaje, MSGSZ, 0, MSG_NOERROR);
        if (ret == -1) {
            perror("msgrcv");
            exit(1);
        }

        if (mensaje.mtype == 1) {
            printf("[Servidor] Recibido mensaje del proceso 1: %s\n", mensaje.mtext);
        } else if (mensaje.mtype == 2) {
            printf("[Servidor] Recibido mensaje del proceso 2: %s\n", mensaje.mtext);
        } else {
            printf("[Servidor] Recibido mensaje de tipo desconocido (%ld): %s\n",
                   mensaje.mtype, mensaje.mtext);
        }
    }

    return 0;
}
