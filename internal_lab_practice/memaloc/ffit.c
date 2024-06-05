#include <stdio.h>
#include <stdlib.h>

void allocate(int mem[] , int mem_s , int proc[] , int proc_s){
    for(int i=0 ; i<proc_s ; i++){
        for(int j=0 ; j<mem_s ; j++){
            if(proc[i] < mem[j]){
                printf("ALLOCATED PROCESS_%d[%d] in MEMORY_BLOCK_%d[%d]\n",i,proc[i],j,mem[j]);
                mem[j] -= proc[i];
                proc[i] = 0;
                break;
            }
        }
        if(proc[i] != 0 ){
            printf("COULD NOT ALLOCATE PROCESS_%d\n",i);
        }
    }
}


int main(){
    int BLOCK_NUM , PROC_NUM;
    printf("Enter number of blocks : ");
    scanf("%d" , &BLOCK_NUM);
    printf("Enter number of process : ");
    scanf("%d" , &PROC_NUM);

    int mem_blocks[BLOCK_NUM];
    int proc[PROC_NUM];

    printf("Enter size %d memory blocks : ",BLOCK_NUM);
    for(int i=0 ; i<BLOCK_NUM ; i++)
        scanf("%d" , &mem_blocks[i]);

    printf("Enter size %d processes : ",PROC_NUM);
    for(int i=0 ; i<PROC_NUM ; i++)
        scanf("%d" , &proc[i]);

    printf("BLOCKS---\n");
    for(int i=0 ; i<BLOCK_NUM ; i++){
        printf("BLOCK %d\t %d\n" , i , mem_blocks[i]);
    }

    printf("PROCESS---\n");
    for(int i=0 ; i<PROC_NUM ; i++){
        printf("PROCESS %d\t %d\n",i,proc[i]);
    }

    allocate(mem_blocks,BLOCK_NUM,proc,PROC_NUM);

    printf("BLOCKS AFTER ALOCATION---\n");
    for(int i=0 ; i<BLOCK_NUM ; i++){
        printf("BLOCK %d\t %d\n",i,mem_blocks[i]);
    }


}