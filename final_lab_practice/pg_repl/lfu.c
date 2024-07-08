#include <stdio.h>

int main(){
    int pages , frames;
    int hit = 0 , fault = 0 ;
    printf("Enter the number of frames : ");
    scanf("%d",&frames);
    printf("Enter the size of sequence string : ");
    scanf("%d",&pages);
    int frame[frames] , page[pages] , frequency[frames] , index[frames];
    printf("Enter the sequence string : ");
    for(int i=0 ; i<pages ; i++)
        scanf("%d",&page[i]);

    for(int i=0 ; i<frames ; i++){
        frame[i] = -1;
        frequency[i] = -1;
        index[i] = 0;
    }

    for(int i=0 ; i<pages ; i++){
        int found = 0;
        for(int j=0 ; j<frames ; j++){
            if(frame[j] == page[i]){
                hit++;
                found = 1;
                frequency[j]++;
                index[j] = i;
                break;
            }
        }
        if(found != 1){
            fault++;
            int least_freq = 0;
            for(int j=0; j<frames;j++){
                if(
                    frequency[j] < frequency[least_freq] ||
                    (
                        frequency[j] == frequency[least_freq] &&
                        index[j] < index[least_freq]
                    )
                )
                    least_freq = j;
            }
            frame[least_freq] = page[i];
            frequency[least_freq] = 0;
            index[least_freq] = i;
        }

        for(int j=0 ; j<frames ;j++){
            printf("%d ",frame[j]);
        }

        printf("\n");
    }

    printf("HIT %d \nFAULT %d\n" , hit , fault);
}
