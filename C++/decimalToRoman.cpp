Program to convert Decimal number to Roman number.


#include <bits/stdc++.h> 
using namespace std; 
  
// Function to calculate roman equivalent 
string decimalToRoman(int num)  
{    
     string m[] = {"", "M", "MM", "MMM"}; 
     string c[] = {"", "C", "CC", "CCC", "CD", "D",  
                        "DC", "DCC", "DCCC", "CM"}; 
     string x[] = {"", "X", "XX", "XXX", "XL", "L",  
                        "LX", "LXX", "LXXX", "XC"}; 
     string i[] = {"", "I", "II", "III", "IV", "V",  
                        "VI", "VII", "VIII", "IX"}; 
          
     // Converting to roman 
     string thousands = m[num/1000]; 
     string hundereds = c[(num%1000)/100]; 
     string tens =  x[(num%100)/10]; 
     string ones = i[num%10]; 
          
     string ans = thousands + hundereds + tens + ones; 
          
     return ans; 
} 
  
int main() 
{ 
      int num = 699; 
      cout << decimalToRoman(num); 
      return 0; 
}
