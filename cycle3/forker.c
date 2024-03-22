#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>	
void main(){
	pid_t parent = getpid();
	pid_t procid = fork();
	if(procid < 0 ){
		perror("fork failed !");
		exit(1);
	}
	else{
		printf("Child Created for parent %d\n",parent);
	}
	wait(NULL);
	printf("Executed Process %d\n",getpid());
	execlp("ls",NULL);
	return;
}
