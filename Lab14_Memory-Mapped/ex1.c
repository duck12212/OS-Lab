#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#define FILE_LENGTH 0x50

int main(int argc,char *argv[])
{
    int fd,count=0,tmp;
    char *map_memory,*ca,ch[100];

    fd = open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);

    lseek(fd,0, SEEK_SET);
    write(fd, "", FILE_LENGTH);
    map_memory =(char*) mmap(0, FILE_LENGTH, PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);


    ca = map_memory;
    tmp = strlen(ca);
    printf("Input any characters continuously:\n");
    gets(ch);
    for(count=0;count<strlen(ch);count++){
        sprintf((char*)map_memory+tmp,"%c",ch[count]);
        tmp++;
    }
    while(1){
        printf("countinue input:\n");
        gets(ch);
        for(count=0;count<strlen(ch);count++){
                sprintf((char*)map_memory+tmp,"%c",ch[count]);
                tmp++;
        }
    }


    munmap(map_memory, FILE_LENGTH);
    return 0;
}
