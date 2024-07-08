#include <stdio.h>

void allocate(int memloc[] , int proclist[] , int memloc_size , int proclist_size){
    for(int i=0 ; i<proclist_size ; i++){
        int min_diff = -1;
        for(int j=0 ; j<memloc_size ; j++){
            if(proclist[i] <= memloc[j]){
                if(min_diff == -1)
                    min_diff = j;
                if((memloc[i] - proclist[j]) < (memloc[min_diff] - proclist[j])){
                    min_diff =j;
                }
            }
        }
        if(min_diff != -1){
            memloc[min_diff] -= proclist[i];
            printf("Allocated PROC%d into MEM%d\n" , i , min_diff);
        }
        else{
            printf("Unable to allocate PROC%d \n" , i);
        }
    }
}

int main(){
    int memloc_size , proclist_size;
    printf("Enter number of memory locations : ");
    scanf("%d",&memloc_size);
    printf("Enter number of process : ");
    scanf("%d",&proclist_size);

    int memloc[memloc_size] , proclist[proclist_size];

    printf("Enter memory block sizes : ");
    for(int i=0 ; i<memloc_size ; i++)
        scanf("%d",&memloc[i]);

    printf("Enter process sizes : ");
    for(int i=0 ; i<proclist_size ; i++)
        scanf("%d",&proclist[i]);

    allocate(memloc, proclist, memloc_size, proclist_size);

    printf("Remaining Memory locations : ");
    for(int i=0 ; i<memloc_size ; i++)
            printf("%d ",memloc[i]);
    printf("\n");
}
