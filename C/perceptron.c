#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.>

/* PS: DONT REMEMBER TO CHANGE THE loadTrainingSet TO YOUR SPECIFICATIONS!! */

float training[30][5];
float weights[4];
float sample[4];

void loadTrainingSet();
void randomizeWeights();
void networkTraining();
void perceptronOperation();

int main(int argc, char** argv){
	
	int i, j=1, choice;
	
	printf(" ---------------------------------------\n");
	printf("|Artificial Neural Networks-Percepetron|\n");
	printf(" ---------------------------------------\n\n");
	printf("-> Do you wish to train the network or enter your private weights? 1 - Training | 2 - Operation | 0 - Exit\n");
	printf("-> ");
	scanf("%d", &choice);
	printf("\n\n");
	
	while(choice=1||choice==2){
		switch(choice){
		case 1:{
			do{
			printf("-> Press enter to begin loading the training set\n\n");
			system("pause");
			loadTrainingSet();
			randomizeWeights();
			networkTraining();
			printf("\n-> You just ran %d training(s)\n", j);
			printf("-> Do you want to do other network training? 1 - Yes | 0 - No\n");
			printf("-> ");
			scanf("%d", &i);
			printf("\n\n");
			j++;
		    }while(i==1);
 		    printf("-> Do you want to go to the operation? 1 - Yes | 0 - No\n");
			printf("-> ");
			scanf("%d", &i);
			printf("\n\n");
			if(i==1){
				perceptronOperation(1);
			    break;
			}else{
				 break;
			}
		}
		case 2:{
			do{
			perceptronOperation(2);
			printf("-> Do you want to enter other set of weights and pessoal samples?? 1 - Yes | 0 - No\n");
			printf("-> ");
			scanf("%d", &i);
			printf("\n\n");
			}while(i==1);
			break;
		}
		}
		printf("-> Do you wish to train the network or enter your private weights? 1 - Training | 2 - Operation | 0 - Exit\n");
		printf("-> ");
		scanf("%d", &choice);
		printf("\n\n");
	}
	
	printf("-> We hope that you enjoyed it. Thanks!\n");
	return 0;
}

void perceptronOperation(int choice){
	
	int j, i;
	float out;
	
	if(choice!=1){
		for(j = 0; j < 4; j++){
			if(j==0){
				printf("-> Enter the activation threshold\n");
				printf("-> ");
				scanf("%f", &weights[j]);
			}else{
				printf("-> Enter the weight x%d\n", j);			
				printf("-> ");
				scanf("%f", &weights[j]);
			}
			
		}
		printf("\n");
	}
	
	printf("-> Lets start typing the entries . ");
	system("pause");
	printf("\n\n");
	do{	
		float sum = 0;
			
		for(j=0; j<4; j++){
		
		   	if(j==0){
  			sample[j] = -1.0000;
		}else{
			printf("->Enter the entrie x%d\n", j);
			printf("-> ");
			scanf("%f", &sample[j]);
		}
	   	sum += weights[j]*sample[j];
	    }
	    
  		
		printf("\n");
		printf("-> Sum = %.4f\n\n", sum);	
			
			
		if(sum>=0){
			out = 1.0000;
			printf("-> Sum >= 0, out = %.4f\n\n", out);
			system("pause");
		}else{
			out = -1.0000;
			printf("-> Sum < 0, out = %.4f\n\n", out);
			system("pause");
		}
		
		printf("\n-> Do you want to enter another sample set?? 1 - Yes | 0 - no\n");
			printf("-> ");
			scanf("%d", &i);
			printf("\n\n");
	}while(i==1);
	
}

void networkTraining(){
	
	float lR = 0.01, sum, out;
	int nT = 0, i = 0, j;
	int error;
	
	do{
		
		error = 0;
		
		for(i = 0; i<30; i++){
			
			sum = 0;
			
			for(j=0; j<4; j++){
				sum += weights[j]*training[i][j];
			}
			
			if(sum>=0){
				out = 1.0000;
			}else{
				out = -1.0000;
			}
			
			if(out != training[i][4]){
				
				for(j = 0 ; j<4; j++){
					weights[j] = weights[j] + (lR * (training[i][4] - out) * training[i][j]);
				}
				
				error = 1;
				
			}
			
		}
		
		nT = nT+1;			
		
	}while(error != 0);
	
	printf("\n      Updated weights      \n");
	
	printf(" ----------------------------\n");
	for(i=0; i<4; i++){
		if(i==0){
			printf("|Activation threshold = %.4f|\n", weights[i]);
		}else{
			if(weights[i]<0){
				printf("|Entry x%d weight = %.4f|\n", i, weights[i]);
			}else{
				printf("|Entry x%d weight = %.4f |\n", i, weights[i]);
			}
		}
	}
	
	printf(" ----------------------------\n\n");
	
	printf("\n-> Training finished with sucess\n");
	printf("-> Number of times counted = %d\n\n", nT);
	
	system("pause");
	
}


void randomizeWeights(){
	
	int i=0;
	
	srand((unsigned)time(NULL));
	
	printf("\n");
	
	printf("                Weights Randomization               \n");
	
	printf(" ----------------------------------------------------\n");
	
	do{
		
		weights[i] = rand()%100001;
		
		weights[i] = weights[i]/100000;
		
		if(i == 0){
			printf("|Activation threshold randomly chosen = %.4f|\n", weights[i]);
		}else{
			printf("|Entry x%d weight randomly chosen = %.4f|\n", i, weights[i]);
		}
		
		i++;
		
	}while(i<4);
	
	printf(" ----------------------------------------------------\n\n");
	
	printf("-> Weights randomized with sucess!\n");
	printf("-> Press enter to start the network training\n\n");
	
	system("pause");
	
	return;
	
}

void loadTrainingSet(){
	
	char url[]="";
	
	int i = 0;
	
	FILE *arch;
	
	arch = fopen(url, "r");
	if(arch == NULL)
		printf("Could not open the file");
	else{
			printf("\n-- Training set loaded from the file --\n\n");
			printf("Obs: Entry x0 corresponds to the weight w0 (activation threshold), by convention always gonna be -1\n\n");
			while(((fscanf(arch,"%f %f %f %f\n", &training[i][1], &training[i][2], &training[i][3], &training[i][4]))!=EOF)&&i<31){
				training[i][0] = -1.0000;
				printf("x0 = %.4f, x1 = %.4f, x2 = %.4f, x3 = %.4f, d = %.4f\n", training[i][0], training[i][1], training[i][2], training[i][3], training[i][4]);
				i++;	
	  	    }
			printf("\n\n");	
	}
	
	fclose(arch);
	
	printf("-> Data loaded from the file with success\n");
	printf("-> Press enter to start the randomization of the weights\n\n");
	
	system("pause");
	
	return;
	
}
