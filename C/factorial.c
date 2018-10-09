#include <stdio.h>

int facto(int n){
	if(n==0 || n==1)
		return 1;
	else{
		return n*facto(n-1);
	}
}

int main()
{
    // Factorial of a number 5= 5*4*3*2*1
    int fact=1;
    int i=0;
    int n;
    printf("Enter the number for which you want to calculate factorial ()");
	while(1){
		scanf("%d",&n);
		if(n>-1 && n<16)
			break;
		printf("the number should be more than -1 and less than 16\n\nReason : the size of int is 4 byte, it cant handle numbers more than 2 147 483 647 (for signed int), which is less than 16 factorial.\nplease enter once more, a number >-1 and <16\n\n ");
	}
    

    i=n;

    fact = facto(i);
    printf("Factorial of %d is %d",n,fact);

    printf("\n");
    return 0;
}
