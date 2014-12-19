#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void how(int a){
printf("how are you?\n");
}
void good(int a){
printf("I'm so good.\n");
}
void ctwo(int a){
        signal(SIGINT,SIG_DFL);
}
void cone(int a){
        signal(SIGINT,good);
        signal(SIGALRM,ctwo);
        alarm(3);
}
int main()
{
	signal(SIGINT,how);
	signal(SIGALRM,cone);
	alarm(3);
	for(;;);
	return 0;
}
