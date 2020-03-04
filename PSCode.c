#include<stdio.h>
#include<stdlib.h>

int main(){
	int noOfProcess;
	int i, at, pr, bt;
	int t=0;
	printf("No of process: ");
	scanf("%d",&noOfProcess);
	int arr[7][noOfProcess];
	for(i=0; i<noOfProcess; i++){
		arr[7][i]=i;
	}
	for(i=0; i<noOfProcess; i++){
		printf("For P%d \n", i);
		printf("Arrival Time: ");
		scanf("%d", &at);
		printf("Priority: ");
		scanf("%d", &pr);
		printf("Burst Time: ");
		scanf("%d", &bt);
		arr[1][i]=at; //Arrival Time
		arr[2][i]=pr; //Priority
		arr[3][i]=bt; //Burst Time
		arr[4][i]=0;  //Wait Time
		arr[5][i]=0;  //State
		arr[6][i]=0;  //Turn Around Time
		arr[7][i]=0;  //WaitTime to incriment Priority
	}	
}
