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
    int qid_envio, qid_respuesta, ret;
    int i;
    qid_envio = msgget(1001, IPC_CREAT | 0660);
    if (qid_envio == -1) {
        perror("msgget 1001");
        exit(1);
    }
    qid_respuesta = msgget(1003, IPC_CREAT | 0660);
    if (qid_respuesta == -1) {
        perror("msgget 1003");
        exit(1);
    }
    printf("Cliente: Qenvio=%d, Qresp=%d\n", qid_envio, qid_respuesta);
    for (i = 1; i <= 3; i++) {
        mensaje.mtype = 1;
        snprintf(mensaje.mtext, MSGSZ, "Mensaje cliente #%d", i);
        ret = msgsnd(qid_envio, &mensaje, MSGSZ, 0);
        if (ret == -1) {
            perror("msgsnd cliente");
            exit(1);
        }
        printf("[Cliente] Enviado: %s\n", mensaje.mtext);
    }
    for (i = 1; i <= 3; i++) {
        ret = msgrcv(qid_respuesta, &mensaje, MSGSZ, 1, MSG_NOERROR);
        if (ret == -1) {
            perror("msgrcv cliente");
            exit(1);
        }
        printf("[Cliente] Respuesta: %s\n", mensaje.mtext);
    }
    return 0;
}
