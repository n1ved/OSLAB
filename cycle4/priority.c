#include <stdio.h>

struct process{
	int pid;
	int wtime;
	int ttime;
	int btime;
	int prior;
};

void main(){
	int totaltime = 0;
	float twaittime = 0;
	int n;
	printf("Enter number of process : ");
	scanf("%d",&n);
	struct process p[n];

	for(int i=0 ; i<n ; i++){
		printf("Process %d data\n" , i+1);
		printf("Enter burst time : ");
		scanf("%d",&p[i].btime);
		printf("Enter priority : ");
		scanf("%d",&p[i].prior);
		p[i].pid = i+1;
	}
	
      struct process temp;
      
      for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                  if(p[i].prior > p[j].prior){
                        temp = p[i];
                        p[i] = p[j];
                        p[j] = temp;
                  }
            }
      }
      
	for(int i=n-1 ; i>=0 ; i--){
		p[i].wtime = totaltime ;
		totaltime += p[i].btime;
		twaittime += p[i].wtime;
		p[i].ttime = p[i].wtime + p[i].btime;
	}
	printf("----------------------------------------------------------------------------------------------\n");
	printf("PID \t PRIORITY \t BURST_TIME \t WAIT_TIME \t TURNAROUND_TIME\n");
	for(int i=n-1 ; i>=0 ; i--){
		printf("%d \t %d \t\t %d \t\t %d \t\t %d\n" , p[i].pid ,p[i].prior, p[i].btime , p[i].wtime , p[i].ttime);
	}
	printf("----------------------------------------------------------------------------------------------\n");
	printf("Total time required for execution : %d\n" , totaltime);
	//printf("Average wait time : %d\n", twaittime/n );
}

