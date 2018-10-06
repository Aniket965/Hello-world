#include<bits/stdc++.h> 
#define ASCII_SIZE 256 
using namespace std; 
  
char getMaxOccuringChar(char* str) 
{ 
    // Create array to keep the count of individual 
    // characters and initialize the array as 0 
    int count[ASCII_SIZE] = {0}; 
  
    // Construct character count array from the input 
    // string. 
    int len = strlen(str); 
    for (int i=0; i<len; i++) 
        count[str[i]]++; 
  
    int max = -1;  // Initialize max count 
    char result;   // Initialize result 
  
    // Traversing through the string and maintaining 
    // the count of each character 
    for (int i = 0; i < len; i++) { 
        if (max < count[str[i]]) { 
            max = count[str[i]]; 
            result = str[i]; 
        } 
    } 
  
    return result; 
} 
  
// Driver program to test the above function 
int main() 
{ 
    char str[] = "sample string"; 
    cout << "Max occurring character is "
         << getMaxOccuringChar(str); 
} 