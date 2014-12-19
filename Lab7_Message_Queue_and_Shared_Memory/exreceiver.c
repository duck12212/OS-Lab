#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "msg_gue.h"
#include <stdlib.h>

int main(){
	int msqid;
	struct oslab_msg_st msg_buffer;
	struct msqid_ds msq_id;
	//int c=1;
	msqid = msgget((key_t)0x1235,IPC_CREAT | 0666);
	do{
	msgrcv(msqid,(void *)&msg_buffer,sizeof(msg_buffer) - sizeof(long int),1,0);
	printf("%s\n",msg_buffer.msg_text);
	//c=c+1;
	}while(strcmp(msg_buffer.msg_text,"exit"));
	msgctl(msqid,IPC_RMID,&msq_id);
	return 0;
}

