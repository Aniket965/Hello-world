//
//  main.cpp
//  helloWorld
//
//  Created by João Laranjo on 13/10/18.
//  Copyright © 2018 João Laranjo. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    cout << "Hello World!" << endl;
    
    string name = "Hello World!";
    int i = 0;
    
    while (i != name.size()){
        cout << name[i] << endl;
        i++;
    }
    return 0;
}
