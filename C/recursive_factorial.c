#include<stdio.h>

void main()
{
	int Input;
	long Factorial;
	printf("Enter a number from 0 to 12 : ");
	scanf("%ld", &Input);
	Factorial = RecursiveFactorial(Input);
	if(Factorial == 0)
	{
		printf("Invalid Input");
	}
	else
	{
		printf("The factorial of %d is %ld", Input, RecursiveFactorial(Input));
	}
}

long int RecursiveFactorial(long int Num)
{
	if (Num == 1 || Num == 0)
	{
		return 1;
	}
	if (Num < 0 || Num > 12)
	{
		return 0;
	}
	return RecursiveFactorial(Num - 1);
}
