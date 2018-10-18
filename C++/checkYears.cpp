#include <iostream>

using namespace std;



main(){
    short thisyear,year,age;
    cout << "Wprowadz biezacy rok:";
    cin >> thisyear;
    cout << "Wprowadz wiek urodzenia";
    cin >> year;
    age = thisyear - year;
    if (year > thisyear){
        cout << "wiek gracza nie moze byc ujemny! ;)";
    }
    else{
        
        if (age < 3){
        cout << "za mlody";
        }
        else if (age >= 3  && age <= 6){
            cout << "przedszkolaki";
        }
        else if (age >= 7  && age <= 8){
            cout << "";
        }
        else if (age >= 9  && age <= 10){
            cout << "orliki";
        }
        else if (age >= 11  && age <= 12){
            cout << "mlodzicy";
        }
        else if (age >= 13  && age <= 14){
            cout << "trampkarze";
        }
        else if (age >= 15  && age <= 16){
            cout << "juniorzy mlodszy";
        }
        else if (age >= 17  && age <= 18){
            cout << "juniorzy starsi";
        }
        else if (age > 18){
            cout << "seniorzy";
        }
    }

  
    
}
