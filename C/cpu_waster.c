#include <stdlib.h>

void waste_cpu(){
    int x = 2;
    while(1){
      malloc(x);
      x*=2;
    }
}

int main(){
    waste_cpu();
    return 0;
}
