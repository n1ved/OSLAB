#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct proc{
    int atime;
    int btime;
    int btime_cpy;
    int ftime;
    int wtime;
    int ttime;
};

void schedule(struct proc arr[] , int n , int q){
    int clock = 0;
    int tbursttime = 0;
    for(int i=0 ; i<n ; i++){
        tbursttime += arr[i].btime;
        arr[i].btime_cpy = arr[i].btime;
    }
    int i=0;
    int tcounter = 0 ;
    bool allexec(){
        for(int j=0 ; j<n ; j++){
            if(arr[i].btime != 0)
                return false;
        }
        return true;
    }
    while(allexec()){
        if((tcounter == q && clock!=0) || (arr[i].btime == 0 || arr[i].atime > clock)){
            i = (i+1)%n;
            tcounter = 0;
        }else{
            arr[i].btime--;
            tcounter++;
            clock++;
            if(arr[i].btime == 0)
                arr[i].ftime = clock;
        }
    }

    for(int i=0 ; i<n ; i++){
        arr[i].wtime = arr[i].ftime - arr[i].btime_cpy - arr[i].atime;
        arr[i].ttime = arr[i].btime+arr[i].wtime;
    }
}

void main(){
    int SIZE;
    printf("Enter number of process : ");
    scanf("%d" , &SIZE);
    struct proc data[SIZE];
    printf("Enter time quantum : ");
    int q;
    scanf("%d" , &q);

    for(int i=0 ; i<SIZE ; i++){
        printf("Enter Arrival Time , Burst Time of Process %d : ",i);
        scanf("%d%d",&data[i].atime,&data[i].btime);
    }

    for(int i=0 ; i<SIZE ; i++){
        struct proc temp;
        for(int j=0 ; j<SIZE-1 ;j++){
            if(data[j].atime>data[j+1].atime){
                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }   
        }
    }

    schedule(data , SIZE,q);

    for(int i=0 ; i<SIZE ; i++){
        printf("%d\t%d\t%d\t%d\t%d\n",i,data[i].atime,data[i].btime,data[i].wtime,data[i].ttime);
    }
}