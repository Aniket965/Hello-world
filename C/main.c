//
//  main.c
//  helloWorldC
//
//  Created by João Laranjo on 13/10/18.
//  Copyright © 2018 João Laranjo. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    printf("Hello World!\n");
    
    char *ptr = "Hello World!";
    
    int i = 0;
    while( ptr[i] != '\0' ){
        
        printf("%c \n", ptr[i]);
        i++;
    }
    
    return 0;
}
