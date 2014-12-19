#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
        char k[100];
        pid_t pid;
        pid=fork();
        if(pid==0){
                printf("Child proccess.\n");
                printf("PID:%d\n",getpid());
                while(1){};
        }
	wait(NULL);
        printf("Parent proccess.\n");
        printf("PID:%d\n",getpid());
        printf("Has kill the child!\n");
        return 0;
}

