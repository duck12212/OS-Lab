#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include 

<sys/msg.h>
#include "msg_gue.h"
#include <stdlib.h>

 int main(){
	key_t key= 0x1235;
	int msqid;
	struct 

oslab_msg_st msg_buffer;
	msqid = msgget(key,IPC_CREAT | 0666 );
	//int c=1;
	do{
	printf("input message:

\n");
	gets(msg_buffer.msg_text);
	msg_buffer.oslab_msg_type=1;
	//printf("%s\n",msg_buffer.msg_text);	
	

printf("%d\n",msgsnd(msqid,(void *)&msg_buffer,sizeof(msg_buffer) - sizeof(long int),0));
	//c=c+1;
	}while

(strcmp(msg_buffer.msg_text,"exit"));
	
	return 0;
}

