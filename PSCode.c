#include<stdio.h>
#include<stdlib.h>

int main(){
	int noOfProcess;
	int i, at, pr, bt;
	int t=0;
	int waitTime=0;
	int complete=0;
	int minPriIndexC;
	
	int minPri, minPriIndex;
	noOfProcess=4;
	int arr[8][4] = {{0 ,1, 2, 3},  //process no
					 {0 ,1 ,2 ,4},  //arr time
					 {40,30,20,10}, //priority
					 {5, 4, 2, 10}, //burst time
					 {0, 0, 0, 0},  //wait time
					 {0, 0, 0, 0},  //state 0 - idle, 1-running, (-1)-completed, 2-queue
					 {0, 0, 0, 0},  //tat
					 {0, 0, 0, 0}}; //wtIncPri
	
	//Saving the burst time of each process.
	int burstTime[noOfProcess];
	for(i=0; i<noOfProcess;i++){
		burstTime[i]=arr[3][i];
	}
	
	//Checking initial minimum priority.
	for(i=0; i<noOfProcess; i++){
		if(arr[1][i]==0){
			minPriIndexC = i;
			break;
		}
	}
	
	
	while(complete==0){
		//Checking for the arrival time
		for(i=0;i<noOfProcess; i++){
			if(arr[1][i]==t){
				arr[5][i]=2;
			}
		}
		
			
		t++;  
		minPri = 100;
		minPriIndex = 0;
		///Finding the minimum priority
		for(i=0; i<noOfProcess; i++){
			if(arr[2][i]<minPri&&arr[5][i]==2){
				minPriIndex = i;
				minPri = arr[2][i];
				
			}
		}
		
		if(minPriIndexC!=minPriIndex){
			int time=2;
			while(time!=0){
				//Checking for the arrival time
				for(i=0;i<noOfProcess; i++){
					if(arr[1][i]==t){
						arr[5][i]=2;
					}
				}
				t++;
				
				
				for(i=0; i<noOfProcess; i++){
					arr[4][i] +=1;
					arr[7][i] +=1;
					if(arr[7][i]==2){
						arr[7][i]=0;
						arr[2][i] -=1;
					}	
				}
				
				time--;
			}
		}
		
		
		//Execution
		minPriIndexC = minPriIndex;
		arr[3][minPriIndex] -=1;
		arr[4][minPriIndex] -=1;
		arr[7][minPriIndex] -=1;
		if(arr[3][minPriIndex]==0){
			arr[6][minPriIndex] = t;
			arr[5][minPriIndex] = -1;
			arr[7][minPriIndex] = 0;
		}
			
		//Checking for the completed process.
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
