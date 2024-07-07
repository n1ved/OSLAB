#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    printf("Program to showcase fork\n");
    pid_t parent_pid = getpid();
    printf("Current parent is [%d]\n",parent_pid);
    pid_t child_pid = fork();
    pid_t child_c_pid = fork();
    if(getpid() < 0){
        printf("Error encounterd while creating a child for [%d]\n",getpid());
    }
    printf("EXEC [%d] \n",getpid());
}
