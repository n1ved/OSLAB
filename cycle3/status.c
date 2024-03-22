#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void main(){
	struct stat sfile;
	stat("forker.c",&sfile);
	printf("st_mode : %o\n",sfile.st_mode);
	printf("st_size : %d\n",sfile.st_size);
}
