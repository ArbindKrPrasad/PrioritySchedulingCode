#include<stdio.h>
#include<stdlib.h>

int main(){
	int noOfProcess;
	int i, at, pr, bt;
	int t=0;
	
	int complete=0;
	
	int minPri, minPriIndex;
	
	
	printf("No of process: ");
	scanf("%d",&noOfProcess);
	int arr[7][noOfProcess];
	for(i=0; i<noOfProcess; i++){
		printf("\nFor P%d \n", i);
		printf("Priority: ");
		scanf("%d", &pr);
		printf("Arrival Time: ");
		scanf("%d", &at);
		printf("Burst Time: ");
		scanf("%d", &bt);
		arr[0][i]=i;
		arr[1][i]=at; //Arrival Time
		arr[2][i]=pr; //Priority
		arr[3][i]=bt; //Burst Time
		arr[4][i]=0;  //Wait Time
		arr[5][i]=0;  //State
		arr[6][i]=0;  //Turn Around Time
		arr[7][i]=0;  //WaitTime to incriment Priority
	}
	
	
	//Body
	int burstTime[noOfProcess];
	for(i=0; i<noOfProcess;i++){
		burstTime[i]=arr[3][i];
	}
	while(complete==0){
		for(i=0;i<noOfProcess; i++){
			if(arr[1][i]==t){
				arr[5][i]=2;
			}
		}
	
		t++;
		minPri = 100;
		minPriIndex = 0;
		for(i=0; i<noOfProcess; i++){
			if(arr[2][i]<minPri&&arr[5][i]==2){
				minPriIndex = i;
				minPri = arr[2][i];
			}
		}
		
		arr[3][minPriIndex] -=1;
		arr[4][minPriIndex] -=1;
		arr[7][minPriIndex] -=1;
		if(arr[3][minPriIndex]==0){
			arr[6][minPriIndex] = t;
			arr[5][minPriIndex] = -1;
			arr[7][minPriIndex] = 0;
		}
		
		for(i=0; i<noOfProcess;i++){
			if(arr[5][i]==2){
				arr[4][i] +=1;
				arr[7][i] +=1;
				if(arr[7][i]==2){
					arr[7][i]=0;
					arr[2][i] -=1;
				}
			}
		}
		
		//Checking the completion
		int temp=0;
		for(i=0; i<noOfProcess;i++){
			temp=temp+arr[5][i];
		}
		//printf("\n%d",temp);
		if((temp*(-1))==noOfProcess){
			complete=-1;
		}
		//printf("\n%d",(temp*(-1)));
	}
		
	printf("\nPNo:\t");
	for(i=0; i<noOfProcess; i++){
		printf("P%d\t", arr[0][i]);
	}
	
	printf("\nAT:\t");
	for(i=0; i<noOfProcess; i++){
		printf("%d\t", arr[1][i]);
	}
	
	printf("\nPri:\t");
	for(i=0; i<noOfProcess; i++){
		printf("%d\t", arr[2][i]);
	}
	
	
	printf("\nBT:\t");
	for(i=0; i<noOfProcess; i++){
		printf("%d\t", arr[3][i]);
	}
	
	printf("\nWT:\t");
	for(i=0; i<noOfProcess; i++){
		printf("%d\t", arr[6][i]-burstTime[i]);
	}
	
	printf("\nState:\t");
	for(i=0; i<noOfProcess; i++){
		printf("%d\t", arr[5][i]);
	}
	
	printf("\nTAT:\t");
	for(i=0; i<noOfProcess; i++){
		printf("%d\t", arr[6][i]);
	}
	
	printf("\nWIP:\t");
	for(i=0; i<noOfProcess; i++){
		printf("%d\t", arr[7][i]);
	}
	printf("\n\nTotal Time unit required: %d",t);
	
}
