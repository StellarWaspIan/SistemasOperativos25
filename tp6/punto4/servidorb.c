#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MSGSZ 100

struct s_msgbuf {
    long mtype;
    char mtext[MSGSZ+1];
} mensaje;
int main(void) {
    int qid_in, qid_out, ret;
    int contador = 0;
    qid_in = msgget(1002, IPC_CREAT | 0660);
    if (qid_in == -1) {
        perror("msgget 1002");
        exit(1);
    }
    qid_out = msgget(1003, IPC_CREAT | 0660);
    if (qid_out == -1) {
        perror("msgget 1003");
        exit(1);
    }
    printf("ServidorB: Qin=%d, Qout=%d\n", qid_in, qid_out);
    while (1) {
        ret = msgrcv(qid_in, &mensaje, MSGSZ, 0, MSG_NOERROR);
        if (ret == -1) {
            perror("msgrcv servidorB");
            exit(1);
        }
        contador++;
        printf("[ServidorB] Recibido de ServidorA: %s\n", mensaje.mtext);

        struct s_msgbuf resp;
        resp.mtype = 1;
        snprintf(resp.mtext, MSGSZ,"recibido el mensaje numero %d", contador);
        ret = msgsnd(qid_out, &resp, MSGSZ, 0);
        if (ret == -1) {
            perror("msgsnd servidorB -> cliente");
            exit(1);
        }
    }
    return 0;
}

