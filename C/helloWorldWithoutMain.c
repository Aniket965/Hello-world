// This Program uses a preprocessor directive that gives an impression that the program runs without main

#include<stdio.h> 
#define fun main 
int fun(void) 
{ 
    printf("Hello World without main function!");
    return 0; 
}

