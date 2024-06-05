#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>

void main(){
    struct dirent *dirent_ptr;
    DIR *dir_ptr;

    dir_ptr = opendir("/home/n1ved/");

    if(dir_ptr == NULL){
        printf("Failed to open directory \n");
        return;
    }

    while((dirent_ptr = readdir(dir_ptr)) != NULL){
        printf("%s\n",dirent_ptr->d_name);
    }

    closedir(dir_ptr);
    return;
}