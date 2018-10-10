/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Mathematics;
import Prime.*;
/**
 *
 * @author sohai
 */

// LemoilsConjecutive(n) = odd prime + even 
public class LemoilsConjecutive {
    
   static boolean isPrime(int n)
   {
        if(n==1)
            return false;
        for(int i=2 ; i*i<=n ; i++)
            if(n%i==0)
                return false;
        return true;
   }
    
   static void checklc(int n)
   {    
      for(int i=1 ; i<=n/2; i++)
      {
          int var =n-i*2;
          if(isPrime(i)&&isPrime(var))
              System.out.println( "2*" +  i + "+" + var);
      }
       
   }
            public static void main(String[] args) {
        
                checklc(7);
                
    }
    
   
   
   
}
