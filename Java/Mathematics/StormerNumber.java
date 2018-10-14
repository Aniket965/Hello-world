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
public class StormerNumber {
    
   
  static   int maxPrime(int n)
    {
        int max = 0;
    
       for(int p = 2; p * p <=n ; p++)
           while(n % p == 0){
               if(p > max)
                   max=p;
                n = n / p;
       }
       if( n > 1 && n > max)
           max = n;
       return max;
    }
    
    
    
    static void sm(int n)
    {
       int i=1,lhs;
       int count = 0;
      while(count <=14)
      {
        lhs=i*i+1;
        if(maxPrime(lhs)>=2*i)
            System.out.print(i + " ");
            count+=1;
        i+=1;
        }
    }
    
    
    public static void main(String args[])
    {
        sm(14);
    }
    
    
}
