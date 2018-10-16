#include <stdio.h>

//Method to solve this problem in constant time
int main(){

    int num,i=1,sum=0,sum1=0,sum2=0;
    // +1-2+3-4+5-6+7-8+9-n
    printf("Enter the Last value ");
    scanf("%d",&num);

    //Printing needs to be done using a loop only
    while(i<=num)
      (i%2)?printf("+%d",i++):printf("-%d",i++);

    //n1 is the number of odd terms
    int n1 = (num-1)/2 +1;
    // n2 is the number of even terms
    int n2;

    //If num is an odd number
    if(num%2)
    {
      n2 = n1-1;
      //sum1 is the sum of odd terms
      sum1 = (n1 * (1+num))/2;
      //sum2 is the sum of even terms
      sum2 = (n2 * (2+(num-1)))/2;
      sum = sum1 - sum2;
    }
    else
    {
      n2 = n1;
      sum1 = (n1 * (1+(num-1)))/2;
      sum2 = (n2 * (2+num))/2;
      sum = sum1 - sum2;
    }

    printf("\nSum is %d",sum);

    printf("\n");
    return 0;
}
