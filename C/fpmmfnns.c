#include<stdio.h>

int main(){
    
    int m[3][5], i, j;
    
    for(i=0; i<3; i++){
    for(j=0; j<5; j++){
        scanf("%i", &m[i][j]);
    }
    }
        printf("\n\n");
        
    for(i=0; i<3; i++){
    for(j=0; j<5; j++){
        printf("%i ", m[i][j]);
    }
        printf("\n");
    }
}
