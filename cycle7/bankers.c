#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main(){
    int X , Y;
    printf("Enter number of resources   : ");
    scanf("%d" , &X);

    printf("Enter number of process     : ");
    scanf("%d" , &Y);

    int avail[X] , max[Y][X] , aloc[Y][X] , need[Y][X] ;
    bool exec[Y] ;

    for(int i=0 ; i<Y ; i++){
        exec[i] = false;
    }

    printf("Enter availabilty of %d resources : ",X);
    for(int i=0 ; i<X ; i++)
        scanf("%d" , &avail[i]);

    for(int i=0 ; i<Y ; i++){
        printf("Enter ALLOCATION values of PROCESS %d : ",i);
        for(int j=0 ; j<X ; j++)
            scanf("%d" , &aloc[i][j]);
        printf("Enter MAXIMUM values of PROCESS %d : ",i);
        for(int j=0 ; j<X ; j++)
            scanf("%d" , &max[i][j]);
    }

    int X_cpy = X;
    int Y_cpy = Y;

    for(int i=0 ; i<Y ; i++){
        for(int j=0 ; j<X ; j++){
            need[i][j] = max[i][j] - aloc[i][j] ;
        }
    }

    while(Y_cpy -- ){
        for(int i=0 ; i<Y ; i++){
            bool readyToExec = true;
            for(int j=0 ; j<X ; j++){
                if(need[i][j] > avail[j]){
                    readyToExec = false;
                }
            }
            if(readyToExec && !exec[i]){
                printf("EXEC %d\n" , i);
                exec[i] = true;
                for(int j=0 ; j<X ; j++){
                    avail[j] += aloc[i][j] ;
                }
            }
        }
        bool quit = true;

        for(int i=0 ; i<Y ; i++)
            if(!exec[i])
                quit = false;

        if(quit)
            exit(0);
    }
    


}