#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    execl("ls" ," -l", NULL);
    return 0;
}
