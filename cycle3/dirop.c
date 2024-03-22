#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

void main(){
	struct dirent *direntPointer;
	DIR *dirPointer;

	dirPointer = opendir("/home/mec/");

	if(dirPointer == NULL){
		printf("Failed open dir\n");
		return;
	}

	while((direntPointer = readdir(dirPointer)) != NULL ){
		printf("[%s]\n",direntPointer->d_name);
	}

	closedir(dirPointer);
	return;
}
