#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FRAME_SIZE 3

int frames[FRAME_SIZE];
int curser = 0;
float hitCount = 0;
int fault = 0;

void init(){
    for(int i=0 ; i<FRAME_SIZE ; i++){
        frames[i] = -1;
    }
}

bool checkPage(int data){
    for(int i=0 ; i<FRAME_SIZE ; i++){
        if(frames[i] == data)
            return true;
    }
    return false;
}

int main(){
    init();
    int PAGES;
    printf("Enter number of pages : ");
    scanf("%d" , &PAGES);
    int pages[PAGES];
    printf("Enter page referance sequence : ");
    for(int i=0 ; i<PAGES ; i++){
        scanf("%d" , &pages[i]);
    }

    for(int i=0 ; i<PAGES ; i++){
        bool hit = checkPage(pages[i]);
        if(hit){
            printf("HIT !\n");
            hitCount++;
        }else{
            printf("MISS !\n");
            fault++;
            frames[curser] = pages[i];
            curser = (curser + 1)%FRAME_SIZE;
        }
    }

    printf("Total page faults %d\n" , fault);
    printf("Hit ratio : %f %\n" , hitCount/(float)PAGES);
}

