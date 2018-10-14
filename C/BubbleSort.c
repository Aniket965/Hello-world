#include <stdio.h>
#include <stdlib.h>
#define  Length 100 //Define your array length here


//Decreasing Bubble Sort

int main()
{

    int array[Length];
    int i;
    int j;
    int aux;

    printf("Give program the numbers\n");

    //Feeding our array
    for(i=0; i<Length; i++)
        scanf("%i", &array[i]);
        system("clear");

    //Giving user the outpot that was entered
    printf("\nYour array in order of input is:\n");
    for(i=0; i<Length; i++)
        printf("%i ", array[i]);

    //Bubble Sort Algorithm
    for(j=0; j<Length; j++){
        for(i=j+1; i<Length; i++){
            if(array[j] < array[i]){
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
    }

    //Sorted Array
    printf("\n\nDecreasing order:\n");
    for(i=0; i<Length; i++)
        printf("%i ", array[i]);

    printf("\n");


    return 0;
}

