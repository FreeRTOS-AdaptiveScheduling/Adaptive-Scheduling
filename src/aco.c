//implement swap template void *
//performance measure
//pass by refernce in c

#include <stdio.h>
#include <math.h>

//hValue:heuristic value
float alpha, beta;

float probabilityTask(int noOfTask,int taskNo ,float pheromone[50], float hueristicValue[50]){
	float probability;
	float sum=0;
	int i;
	for(i=0;i<noOfTask;i++){
		sum+=pow(pheromone[i],alpha)*pow(hueristicValue[i],beta);
	}

	probability=pow(pheromone[taskNo],alpha)*pow(hueristicValue[taskNo],beta);
    return probability;

}

/*void swap(int *a, int *b){
	int c;
	c=*a;
	*a=*b;
	*b=c;

}

void swap1(float *a, float *b){
	float c;
	c=*a;
	*a=*b;
	*b=*c;

}*/

void sort(int taskNo[50], float probability[50],int noOfTask){
	int i,j;
	float k;
	int p;
	for(i=0;i<noOfTask;i++){
		for(j=i+1;j<noOfTask;j++){
			if(probability[i]<probability[j]){
				//swap1(&probability[i],&probability[j]);
				//swap(&taskNo[i],&taskNo[j]);
				k=probability[i];
				probability[i]=probability[j];
				probability[j]=k;
				p=taskNo[i];
				taskNo[i]=taskNo[j];
				taskNo[j]=p;
			}
		}

	}
}

float CalculateHueristicValue(float constforHvalue,float deadline,float time){
	return constforHvalue/(deadline-time);
}

void findpaths(int noOfTask, int taskNo[50],int path[50][50]){
	int i,j;
	for(i=0;i<50;i++){
		path[i][0]=taskNo[i];
		int k=1;
		for(j=0;j<noOfTask;j++){
			if(j!=i){
				path[i][k++]=taskNo[j];
			}
		}
	}

}

void main(){

int noOfTask; //max 50
float pheromone[50];
float constforHvalue;
int deadline[50];
float hueristicValue[50];
int i;
float probability[50];
int taskNo[50];
int path[50][50];

for(i=0;i<noOfTask;i++){
	taskNo[i]=i;
}


float time=0;//find way to update time
for(i=0;i<noOfTask;i++){
	hueristicValue[i]=CalculateHueristicValue(constforHvalue,deadline[i],time);
	probability[i]=probabilityTask(noOfTask,i,pheromone,hueristicValue);

}

sort(taskNo,probability,noOfTask);

findpaths(noOfTask,taskNo,path);

//calculatePerformance(path);

}
