#include <stdio.h>
#include <stdlib.h>

void allocate(int mem[] , int mem_s , int proc[] , int proc_s){
    for(int i=0 ; i<proc_s ; i++){
        int wfit_index = -1;
        int wfit_dif = 0;
        for(int j=0 ; j<mem_s ; j++){
            if(proc[i] < mem[j] && (mem[j] - proc[i]) > wfit_dif){
                wfit_dif = mem[j] - proc[i];
                wfit_index = j;
            }
        }
        if(wfit_index != -1){
            printf("ALLOCATED PROCESS_%d[%d] in MEMORY_BLOCK_%d[%d]\n",i,proc[i],wfit_index,mem[wfit_index]);
            mem[wfit_index] -= proc[i];
            proc[i] = 0;
        }
        else{
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