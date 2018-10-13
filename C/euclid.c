#include<stdio.h>

int gcd(int x, int y){
	if(x == 0)
		return y;
	return gcd(y % x, x);
}

void main(){
	int hcf, a, b;
	printf("Enter the 2 numbers: ");
	scanf("%d%d",&a, &b);
	hcf = gcd(a, b);
	printf("The HCF is: %d\n",hcf);
}