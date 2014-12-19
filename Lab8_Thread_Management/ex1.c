#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
int count=0;
pthread_mutex_t mutex1=PTHREAD_MUTEX_INITIALIZER;
void *add(void *arg)
{	
	int j;
	pthread_mutex_lock(&mutex1);
	for(j=0;j<250000;j++){
		 count++;
	}
	

pthread_mutex_unlock(&mutex1);
	printf("Thread:%d ID %lu Completed.\n",(int)arg,pthread_self());
	pthread_exit

(NULL);
}
int main(){
	int i,k,rc;
	pthread_t thread[4];
	for(i=0;i<4;i++){
	rc=pthread_create(&thread

[i],NULL,add,(void *)i);
	if(rc){
	printf("ERROR;return code from pthread_create() is %d\n",rc);
	exit(-1);
	

}
	}
	for(k=0;k<4;k++){
        rc=pthread_join(thread[k],NULL);
        if(rc){
        printf("ERROR;return 

code from pthread_join() is %d\n",rc);
        exit(-1);
        }
        }
	printf("Value=%d\n",count);
	return 0;
}


	
