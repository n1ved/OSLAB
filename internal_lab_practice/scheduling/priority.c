#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct proc{
    int atime;
    int prior;
    int btime;
    int wtime;
    int ttime;
};

void schedule(struct proc arr[] , int n){
    int clock = 0;
    for(int i=0 ; i<n ; i++){
        while(true){
            if(arr[i].atime <= clock){
                arr[i].wtime = clock - arr[i].atime;
                arr[i].ttime = arr[i].btime + arr[i].wtime;
                clock += arr[i].btime;
                break;
            }else{
                clock++;
            }
        }
    }
}

void main(){
    int SIZE;
    printf("Enter number of process : ");
    scanf("%d" , &SIZE);
    struct proc data[SIZE];

    for(int i=0 ; i<SIZE ; i++){
        printf("Enter Arrival Time , Burst Time , Priority of Process %d : ",i);
        scanf("%d%d%d",&data[i].atime,&data[i].btime,&data[i].prior);
    }

    for(int i=0 ; i<SIZE ; i++){
        struct proc temp;
        for(int j=0 ; j<SIZE-1 ;j++){
            if(data[j].prior>data[j+1].prior){
                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }   
        }
    }

    schedule(data , SIZE);

    for(int i=0 ; i<SIZE ; i++){
        printf("%d\t%d\t%d\t%d\t%d\n",data[i].prior,data[i].atime,data[i].btime,data[i].wtime,data[i].ttime);
    }
}