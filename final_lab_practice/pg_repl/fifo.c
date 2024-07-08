#include <stdio.h>
#include <unistd.h>

int main(){
    int frames , pages ;
    int hit = 0 , fault = 0 , curser = 0;

    printf("Enter size of frames :");
    scanf("%d" , &frames);

    printf("Enter page sequence size : ");
    scanf("%d",&pages);

    int frame[frames] , page[pages], recency[frames];

    printf("Enter page sequence : ");
    for(int i=0 ; i<pages ; i++)
        scanf("%d", &page[i]);

    for(int i=0 ; i<pages ; i++){
        int found = 0;
        for(int j=0 ; j<frames ; j++){
            if(frame[j] == page[i]){
                hit++;
                found = 1;
                break;
            }
        }
        if(found != 1){
            fault++;
            frame[curser] = page[i];
            curser = (curser + 1)%frames;
        }
    }

    printf("%d MISS\n%d HIT\n",fault,hit);

}
