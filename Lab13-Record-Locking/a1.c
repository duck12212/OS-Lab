#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
struct flock*file_lock(short type,short whence)
{
        static struct flock ret;
        ret.l_type=type;
        ret.l_start=0;
        ret.l_whence=whence;
        ret.l_len=0;
        return &ret;
};

int main(){
        int i;
        int fd=open("b.txt",O_RDWR|O_APPEND);
        printf("1. exclusive lock(write lock).  2. share lock(read lock).\n");
        scanf("%d",&i);
        if(i==1) {
        fcntl(fd,F_SETLK,file_lock(F_WRLCK,SEEK_SET));
        printf("Locking file with 'WRLCK' success,enter integer to unlock：\n");
        scanf("%d",&i);
        fcntl(fd,F_SETLKW,file_lock(F_UNLCK,SEEK_SET));
        }
        else if(i==2){
        fcntl(fd,F_SETLK,file_lock(F_RDLCK,SEEK_SET));
        printf("Locking file with 'RDLCK' success,enter integer to unlock：\n");
        scanf("%d",&i);
        fcntl(fd,F_SETLKW,file_lock(F_UNLCK,SEEK_SET));
        }
        else
        printf("error input\n");
        close(fd);
}
