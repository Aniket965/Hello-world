#include <stdio.h>

int main(){

    float hra,da,ta,gs,sal;
    printf("Enter Your Basic Salary ");
    scanf("%f",&sal);

    hra = sal*0.20;
    da = sal*0.10;
    ta = sal*0.10;
    gs = sal+hra+da+ta;

    printf("Your Gross Salary is %f",gs);


    printf("\n");
    return 0;

}