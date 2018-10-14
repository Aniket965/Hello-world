/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Mathematics;

/**
 *
 * @author sohai
 */
public class SubsetCalculation {

    
    public static int power(int num, int pow)
    {
     int result=1;
    while(pow !=0)
    { 
        result *=num;
        --pow;
    }
    return result;
}
    
    
    public  static int subsetCalculation(int n) {
        if(n>1)
           return (n*(n+1)/2)* power(2,n-1);
        else
            return 0;
    }
    
//(n*(n-1)/2)2^n-1
    public static void main(String[] args) {
        System.out.print(subsetCalculation(3));
        System.out.print(power(3,2));
    }
    
    
}