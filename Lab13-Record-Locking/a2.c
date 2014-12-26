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
        printf("Choosing lock:\n");
        printf("1. exclusive lock(write lock).  2. share lock(read lock). 3. not use lock\n");
        scanf("%d",&i);
 if(i==1) {
        if(fcntl(fd,F_SETLK,file_lock(F_WRLCK,SEEK_SET))==0){
          printf("Locking file with 'WRLCK' success.\n");
        }
        else{
          printf("Locking file with 'WRLCK' fail, another process lock it.\n");
        }
        }
        else if(i==2){
          if(fcntl(fd,F_SETLK,file_lock(F_RDLCK,SEEK_SET))==0){
          printf("Locking file with 'RDLCK' success.\n");
          char ca[10000];
          if(read(fd, ca, 10000)<0)printf("Can't read file.\n");
          else
          {
            printf("Read file:\n");
            puts(ca);
          }

        }
        else{
          printf("Locking file with 'RDLCK' fail, another process lock it.\n");
        }
        }
        else if(i==3){
          char ca[10000];
          if(read(fd, ca, 10000)<0)printf("Can't read file.\n");
          else
          {
            printf("Read file:\n");
            puts(ca);
          }
        }
         fcntl(fd, F_SETLK, file_lock(F_UNLCK, SEEK_SET));
        close(fd);

}

