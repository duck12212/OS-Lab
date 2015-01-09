#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/select.h>
#include<limits.h>
int main(){
        char buffer[PIPE_BUF];
        fd_set tmpset;
        int ready,b;
        struct timeval tv;
        int fd1=open("fifo1",O_RDWR);
        int fd2=open("fifo2",O_RDWR);
        if(fd1>fd2)
        b=fd1;
        else
        b=fd2;
        while(1){
        FD_ZERO(&tmpset);
        FD_SET(fd1,&tmpset);
        FD_SET(fd2,&tmpset);
        tv.tv_sec=(2);
        tv.tv_usec=(2000);
        memset(&buffer,0,PIPE_BUF);
        if((ready=select(b+1,&tmpset,NULL,NULL,&tv))<0){
        printf("Failure sorry~~~~~QQ.\n");
        }else if(ready==0){
        printf("Timeout.Try another select().\n");
        }else{
                if(FD_ISSET(fd1,&tmpset)){
                        printf("Device 1 can read.\n");
                        read(fd1,&buffer,PIPE_BUF);
                        printf("%s\n",buffer);
                }
                if(FD_ISSET(fd2,&tmpset)){
                        printf("Device 2 can read.\n");
                        read(fd2,&buffer,PIPE_BUF);
                        printf("%s\n",buffer);
                }

        }





        }

        return 0;







}
