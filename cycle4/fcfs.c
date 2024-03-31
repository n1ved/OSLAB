#include <stdio.h>

struct process{
	int pid;
	int wtime;
	int ttime;
	int btime;
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
		printf("Enter burst time :");
		scanf("%d",&p[i].btime);
		p[i].pid = i+1;
	}

	for(int i=0 ; i<n ; i++){
		p[i].wtime = totaltime ;
		totaltime += p[i].btime;
		twaittime += p[i].wtime;
		p[i].ttime = p[i].wtime + p[i].btime;
	}
	printf("----------------------------------------------------------------------------------------------\n");
	printf("PID \t BURST_TIME \t WAIT_TIME \t TURNAROUND_TIME\n");
	for(int i=0 ; i<n ; i++){
		printf("%d \t %d \t\t %d \t\t %d\n" , p[i].pid , p[i].btime , p[i].wtime , p[i].ttime);
	}
	printf("----------------------------------------------------------------------------------------------\n");
	printf("Total time required for execution : %d\n" , totaltime);
	printf("Average wait time : %f\n", twaittime/n );
}
