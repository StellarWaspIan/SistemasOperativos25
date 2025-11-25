#include <stdio.h>
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

    qid = msgget(1002, IPC_CREAT | 0660);
    if (qid == -1) {
        perror("msgget 1002");
        exit(1);
    }

    printf("ServidorB: cola = %d\n", qid);

    while (1) {
        ret = msgrcv(qid, &mensaje, MSGSZ, 0, MSG_NOERROR);
        if (ret == -1) {
            perror("msgrcv servidorB");
            exit(1);
        }

        printf("[ServidorB] Recibido de ServidorA: %s\n", mensaje.mtext);
    }

    return 0;
}
