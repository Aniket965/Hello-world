#include <iostream>
using namespace std;

int main(void){
    char arr[13] = {'W', 'A', 'S', 'S', 'U', 'P', '\n', 'W', 'O', 'R', 'L', 'D', '!' };
    
    for(int i = 0; i < sizeof(arr)/sizeof(*arr); i++){
        printf("%c\n", arr[i]);
    }
    return 0;
}