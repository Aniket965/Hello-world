#include <stdio.h>
#define MAX_STRING_LEN 30

// Function definitions
int indexOf(char c, char*);
char * rmchar(char c, char*);

int main(void){
    //variable declarations
    char * new;
    char * lower = "abcdefghijklmnopqrstuvwxyz0123456789";
    char * caps = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    while(1){
        //get user input
        char string[MAX_STRING_LEN];
        printf("Enter a(nother) string to check: ");
        scanf("%[^\n]%*c", string);
        
        //remove non alpha-num chars
        //caps to lowercase
        new = string;
        int ptr = 0;
        int i = 0;
        while(string[ptr] != '\0' && ptr < MAX_STRING_LEN){
            if(indexOf(string[ptr], lower) == -1){
                if(indexOf(string[ptr], caps) != -1){
                    new[ptr - i] =  string[ptr] + 32;
                }
                else{
                    new = rmchar(string[ptr], new);
                    i++;
                }
            }
            ptr++;
        }
        
        //palindrome check
        int length =  ptr - i;
        int flag = 1;
        for(int i = 0; i < length / 2; i++){
            if(new[i] != new[length - 1 - i]){
                flag = 0;
                break;
            }
        }
        
        //print message
        switch(flag){
            case 0:
                printf("Not a palindrome! :(\n");
                break;
            case 1:
                printf("Is a palindrome! :)\n");
                break;
        }
    }
    return 0;
}

// Function declarations

// index of char
int indexOf(char c, char * a) {
	char * cpy = a;
	while (*cpy != '\0') {
		if (*cpy == c) {
			return cpy - a;
		}
		cpy++;
	}
	return -1;
}

// remove first instance of char
char * rmchar(char c, char * a) {
	char * ptr = a;
	char * i = a;
	int del = indexOf(c, ptr);
  static char result[( sizeof(a) / sizeof(*a) )];
	while (*ptr != '\0') {
		if (ptr != a + del) {
			result[i - a] = *ptr;
            i++;
		}
		ptr++;
	}
	result[i - a] = '\0';
	return result;
}
