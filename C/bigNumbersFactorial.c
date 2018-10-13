#include<stdio.h>
#define max_size 456569 //I did a research in https://www.wolframalpha.com/ and concluded that the size of 99999! is this. Is the biggest number that this algorithm can calculate

void print_number(int result[], int size){
	int i;
	printf("Result: ");
    for (i=size-1; i>=0; i--){
    	//the number is stored on array backwards
        printf("%d",result[i]);
    }

    putchar('\n');
}

int multiplyVector(int number, int array[], int size){
    int carry_out=0;
    int mult, i;

    for(i=0;i<size;i++){
        mult = array[i]*number+carry_out;
        array[i] = mult%10;
        carry_out=mult/10;
    }
    while(carry_out != 0){
        array[size] = carry_out%10;
        carry_out/=10;
        size++;
    }
    return size;
}



void factorial(int num, int result[]){
    int size, factor;
    result[0]=1;
    size=1;
    for(factor=1;factor<=num;factor++){
        size = multiplyVector(factor,result,size);
    }
    print_number(result,size);
}



int main(){
    int num;
    int result[max_size];
    printf("Type in an integer value: ");
    scanf("%d",&num);
    factorial(num,result);
    return 0;
}