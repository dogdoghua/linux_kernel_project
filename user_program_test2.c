#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void main(){
        int result[1024];
        int status;
        //printf("in main\n");
        if(fork() == 0){
                printf("in child process, pid = %d \n ", getpid());                             
                syscall(355,768,1023,result);
                exit(0);
        }
        else{
                printf("in parent process, pid = %d \n ", getpid());
                syscall(355,768,1023,result);
                wait(&status);
        }
}
