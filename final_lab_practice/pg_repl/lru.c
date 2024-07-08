#include <stdio.h>

int main(){
    int frames , pages ;
    int hit = 0 , fault = 0;

    printf("Enter size of frames :");
    scanf("%d" , &frames);

    printf("Enter page sequence size : ");
    scanf("%d",&pages);

    int frame[frames] , page[pages], recency[frames];

    printf("Enter page sequence : ");
    for(int i=0 ; i<pages ; i++)
        scanf("%d", &page[i]);

    for(int i=0 ; i<frames ; i++){
        frame[i] = -1;
        recency[i] = 0;
    }

    for(int i=0 ; i<pages ; i++){

        for(int k=0 ; k<frames ; k++)
            recency[k]++;

        int found = 0;
        for(int j=0 ; j<frames ; j++){
            if(page[i] == frame[j]){
                found = 1;
                recency[j] = 0;
                break;
            }
        }
        if(found != 1){
            fault++;
            int high = 0;
            for(int k=0 ; k<frames ; k++){
                if(recency[high] < recency[k])
                    high = k;
            }
            frame[high] = page[i];
            recency[high] = 0;
        }
        else{
            hit++;
        }
        for(int k=0 ; k<frames ; k++)
            printf("\t%d",frame[k]);

        printf("\n");

        for(int k=0 ; k<frames ; k++)
            printf("\t%d",recency[k]);

        printf("\n");
    }

    printf("%d MISS\n%d HIT\n",fault,hit);
}
