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
    qid_in = msgget(1001, IPC_CREAT | 0660);
    if (qid_in == -1) {
        perror("msgget 1001");
        exit(1);
    }
    qid_out = msgget(1002, IPC_CREAT | 0660);
    if (qid_out == -1) {
        perror("msgget 1002");
        exit(1);
    }
    printf("ServidorA: cola_in = %d, cola_out = %d\n", qid_in, qid_out);
    while (1) {
        ret = msgrcv(qid_in, &mensaje, MSGSZ, 0, MSG_NOERROR);
        if (ret == -1) {
            perror("msgrcv servidorA");
            exit(1);
        }
        contador++;
        printf("[ServidorA] Recibido del cliente: %s\n", mensaje.mtext);
        struct s_msgbuf msg_out;
        msg_out.mtype = 1; 
        snprintf(msg_out.mtext, MSGSZ,"mensaje del proceso cliente del tipo %ld (nro %d)",mensaje.mtype, contador);
        ret = msgsnd(qid_out, &msg_out, MSGSZ, 0);
        if (ret == -1) {
            perror("msgsnd servidorA -> servidorB");
            exit(1);
        }
    }

    return 0;
}

