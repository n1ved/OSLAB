#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){
    pid_t parent = getpid();
    pid_t child = fork();
    if(child < 0){
        printf("Fork Failed \n");
        exit(1);
    } else {
        printf("Child created : %d\n" , child);
    }
    wait(NULL);
    execlp("ls" , NULL);
    exit(0);
}