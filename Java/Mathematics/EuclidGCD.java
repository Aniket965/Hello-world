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
public class EuclidGCD {

    public static int gcd(int a , int b) {
        if(b>0)
        {
            return gcd(b,a%b);
        }
        else
        {
            return a;
        }
    }
    
    
    
    public static int extended_euclid(int a, int b ,int x ,int y)
    {
       if(a==0)
       {
           x=0;
           y=1;
           return b;
       }
       int x1=1, y1=1  ;
       int gcd  = extended_euclid(b%a, a, x1, y1);
       x= y1-(b/a)*x1;
       y=x1;
       return gcd;
    }
    
    
    
    public static void main(String[] args) {
        System.out.println(gcd(14,12));
        System.out.println(extended_euclid(14, 12, 1, 1));
     //   System.out.println( x + " " +  y );
    }
    
}
