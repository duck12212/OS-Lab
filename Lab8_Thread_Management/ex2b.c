#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "msg_gue.h"
#include <stdlib.h>
#include <pthread.h>
struct oslab_msg_st msg_buffer;
void *send(void *arg){
        int msqid;
        msqid = msgget((key_t)0x1235,IPC_CREAT | 0666 );
        do{
        printf("input message:\n");
        gets(msg_buffer.msg_text);
        msg_buffer.oslab_msg_type=2;
        msgsnd(msqid,(void *)&msg_buffer,sizeof(msg_buffer) - sizeof(long int),0);
        }while(strcmp(msg_buffer.msg_text,"exit"));
        pthread_exit(NULL);
}
void *receiver(void *arg){
        int msqid;
        struct msqid_ds msq_id;
        msqid = msgget((key_t)0x1235,IPC_CREAT | 0666);
        do{
        msgrcv(msqid,(void *)&msg_buffer,sizeof(msg_buffer) - sizeof(long int),1,0);
        printf("receiver message:\n%s\n",msg_buffer.msg_text);
        }while(strcmp(msg_buffer.msg_text,"exit"));
        msgctl(msqid,IPC_RMID,&msq_id);
        pthread_exit(NULL);
}
 int main(){
        pthread_t sendthread,receiverthread;
        pthread_create(&sendthread,NULL,send,NULL);
        pthread_create(&receiverthread,NULL,receiver,NULL);
        pthread_join(sendthread,NULL);
        pthread_join(receiverthread,NULL);
        return 0;
}

