#include <stdio.h>
#define z 50

//This program for determine the runs and print them on a separate line



int input(int A[z],int y)    //Input & store the array
{
	int i;

	for(i=0;i<y;++i)
		{
		printf("input %d number: ",i+1);
		scanf("%d",&A[i]);
		}



}


int process(int A[z],int x)	//process: Determine the runs
{
	int i;

	printf("\n\nYour runs is:\n");

	for(i=0;i<x;i++)
	{
		if(A[i] <= A[i+1])
			printf("%d\t",A[i]);

		else
			printf("%d\n",A[i]);

	}
}



void main()
{

	int B[z],n;
	int input(int*,int);	//declaration function
	int process(int*,int);	//declaration function

	printf("How many numbers are there: ");   //determine how many elements are in the array
	scanf("%d",&n);

	input(B,n);	//call the input function
	process(B,n);	//call the process function
}
