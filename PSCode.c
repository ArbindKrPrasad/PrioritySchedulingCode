#include<stdio.h>
#include<stdlib.h>
					//Symbol for complexity:  n = Total no. of process
					//			  m = Turn Around Time
int main(){
	int noOfProcess;										//-- 1
	int i, at, pr, bt;										//-- 1
	int t=0;											//-- 1
	int complete=0;											//-- 1
	int minPriIndexC;										//-- 1
	int minPri, minPriIndex;									//-- 1

	//Taking User Input
	printf("No of process: ");									//-- 1
	scanf("%d",&noOfProcess);									//-- 1
	int arr[8][noOfProcess];									//-- 1
	for(i=0; i<noOfProcess; i++){									//-- 1
		printf("\nFor Process P%d \n", i);							//-- n
		printf("Priority: ");									//-- n
		scanf("%d", &pr);									//-- n
		printf("Arrival Time: ");								//-- n
		scanf("%d", &at);									//-- n
		printf("Burst Time: ");									//-- n	
		scanf("%d", &bt);									//-- n
		arr[0][i]=i;										//-- n
		arr[1][i]=at; //Arrival Time								//-- n
		arr[2][i]=pr; //Priority								//-- n	
		arr[3][i]=bt; //Burst Time								//-- n
		arr[4][i]=0;  //Wait Time								//-- n
		arr[5][i]=0;  //State									//-- n
		arr[6][i]=0;  //Turn Around Time							//-- n
		arr[7][i]=0;  //WaitTime to incriment Priority						//-- n
	}
	printf("\n-----------------------------------\n\n");
		
	//Saving the burst time of each process.
	int burstTime[noOfProcess];									//-- 1
	for(i=0; i<noOfProcess;i++){									//-- 1
		burstTime[i]=arr[3][i];									//-- n
	}
	
	int initialPri[noOfProcess];									//-- 1
	for(i=0; i<noOfProcess;i++){									//-- 1
		initialPri[i]=arr[2][i];								//-- n
	}
	
	
	//Checking initial minimum priority.
	for(i=0; i<noOfProcess; i++){									//-- 1
		if(arr[1][i]==0){									//-- n
			minPriIndexC = i;								//-- log(n)
			break;										//-- log(n)
		}
	}

	while(complete==0){										//-- 1     	
		//Checking for the arrival time
		for(i=0;i<noOfProcess; i++){								//-- m    
			if(arr[1][i]==t){								//-- nm
				arr[5][i]=2;								//-- mlog(n)
			}
		}
						
		minPri = 100000;									//-- m
		minPriIndex = 0;									//-- m
		//Finding the minimum priority
		for(i=0; i<noOfProcess; i++){								//-- m
			if(arr[2][i]<minPri&&arr[5][i]==2){						//-- mn
				minPriIndex = i;							//-- mlog(n)
				minPri = arr[2][i];							//-- mlog(n)
			}
		}
		
		t++;											//-- m
		if(minPriIndexC!=minPriIndex){								//-- m
			int time=2;									//-- m
			while(time!=0){									//-- m
				//Checking for the arrival time
				for(i=0;i<noOfProcess; i++){        					//-- 3m
					if(arr[1][i]==t){						//-- 3mn
						arr[5][i]=2;						//-- 3mlog(n)
					}
				}
				t++;									//-- 3m

				for(i=0; i<noOfProcess;i++){						//-- m
					if(arr[5][i]==2){						//-- m
						arr[4][i] +=1;						//-- m/3
						arr[7][i] +=1;						//-- m/3
						
						if(arr[7][i]==2){					//-- m/3
							arr[7][i]=0;					//-- m/9
							arr[2][i] -=1;					//-- m/9
						}														
					}	
				}	
				time--;									//-- 3m
			}
		}
				
		//Execution
		minPriIndexC = minPriIndex;								//-- m
		arr[3][minPriIndex] -=1;								//-- m
		arr[4][minPriIndex] -=1;								//-- m
		arr[7][minPriIndex] -=1;								//-- m
		if(arr[3][minPriIndex]==0){								//-- m
			arr[6][minPriIndex] = t;							//-- log(m)
			arr[5][minPriIndex] = -1;							//-- log(m)
			arr[7][minPriIndex] = 0;							//-- log(m)
		}
			
		//Checking for the completed process.
		for(i=0; i<noOfProcess;i++){								//-- m
			if(arr[5][i]==2){								//-- m
				arr[4][i] +=1;								//-- m/3
				arr[7][i] +=1;								//-- m/3
				if(arr[7][i]==2){							//-- m/3
					arr[7][i]=0;							//-- m/9
					arr[2][i] -=1;							//-- m/9
				}														
			}
		}
			
		//Checking the completion
		int temp=0;
		for(i=0; i<noOfProcess;i++){								//-- m
			temp=temp+arr[5][i];								//-- mn
		}
		
		if((temp*(-1))==noOfProcess){								//-- m
			complete=-1;									//-- mn
		}
	}
	/*End of the logic*/
	
	//Output
	printf("Priority Scheduling Table: \n");							//-- 1	
	printf("\nProcNo:   \t");									//-- 1
	for(i=0; i<noOfProcess; i++){									//-- 1	
		printf("P%d\t", arr[0][i]);								//-- n	
	}
	
	printf("\nArrT:     \t");									//-- 1	
	for(i=0; i<noOfProcess; i++){									//-- 1	
		printf("%d\t", arr[1][i]);								//-- n
	}
	
	printf("\nInitPri:    \t");									//-- 1
	for(i=0; i<noOfProcess; i++){									//-- 1
		printf("%d\t", initialPri[i]);								//-- n
	}
	
	printf("\nBurstT:   \t");									//-- 1
	for(i=0; i<noOfProcess; i++){									//-- 1
		printf("%d\t", burstTime[i]);								//-- n
	}
	
	printf("\nWaitT:    \t");									//-- 1
	for(i=0; i<noOfProcess; i++){									//-- 1
		printf("%d\t", (arr[6][i]-arr[1][i])-burstTime[i]);					//-- n
	}
	
	printf("\nCompT:    \t");									//-- 1
	for(i=0; i<noOfProcess; i++){									//-- 1
		printf("%d\t", arr[6][i]);								//-- n
	}
	
	printf("\nTAT:      \t");									//-- 1
	for(i=0; i<noOfProcess; i++){									//-- 1
		printf("%d\t", arr[6][i]-arr[1][i]);							//-- n
	}
	
	printf("\nFinalPri:    \t");									//-- 1
	for(i=0; i<noOfProcess; i++){									//-- 1
		printf("%d\t", arr[2][i]);								//-- n
	}
	
	printf("\n\n\nRequired Answers: ");								//-- 1
	printf("\n\nPNo: |\t");										//-- 1
	for(i=0; i<noOfProcess; i++){									//-- 1
		printf("   P%d", arr[0][i]);								//-- n
		printf("   |   ");									//-- n
	}
	
	printf("\n\nTAT: |\t");										//-- 1
	for(i=0; i<noOfProcess; i++){									//-- 1
		printf("%5d", arr[6][i]-arr[1][i]);							//-- n
		printf("   |   ");									//-- n
	}
	
	printf("\n\nWT:  |\t");										//-- 1
	int totalWaitTime=0;										//-- 1
	for(i=0; i<noOfProcess; i++){									//-- 1
		printf("%5d", (arr[6][i]-arr[1][i])-burstTime[i]);					//-- n
		totalWaitTime += (arr[6][i]-arr[1][i])-burstTime[i];					//-- n
		printf("   |   ");									//-- n
	}
	
	printf("\n\nTurn Around Time: %d second", t);							//-- 1
	printf("\n\nAverage Waiting Time  : %.2f second\n\n", totalWaitTime/(float)noOfProcess );	//-- 1												
}
