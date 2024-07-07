#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

int main(){
    struct dirent *dirent;
    DIR *dir;

    dir = opendir(".");

    if(dir == NULL){
        printf("Failed to open directory\n");
        return 1;
    }

    while((dirent = readdir(dir)) != NULL){
        struct stat sfile;
        stat(dirent->d_name,&sfile);
        printf("[ %s ]\t[ %o ]\t[ %ld ]\n",dirent->d_name,sfile.st_mode,sfile.st_size);
    }

    closedir(dir);
    return 0;
}
