#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
int main()
{
	const int size = 4096;
	const char *name = "OS";
	char *message = malloc(128);
	int shm_fd;
	void *ptr;
	shm_fd = shm_open(name,O_CREAT|O_RDWR,0666);
	ftruncate(shm_fd,size);
	ptr = mmap(0,size,PROT_WRITE,MAP_SHARED,shm_fd,0);
	do
	{
		printf("Input some text:\n");
		gets(message);
	if(strcmp(message,"exit")){
		sprintf(ptr,"%s\n",message);	
		ptr += (strlen(message)+1);
	}
	else{
		sprintf(ptr,"%s",message);
		ptr += strlen(message);
	}
	}while(strcmp(message,"exit"));
	return 0;
}
