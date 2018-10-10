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
public class JaggedNumber {


 static int smallestPrime(int n)
 {
  for(int p=2; p*p <=n ; p++)
      if(n % p == 0)
          return  p;
      return n;
 }
 
 
 static void findJagged(int n)
 {
     int i=1;
     int count = 1;
     while(count <= n)
     {
     if(smallestPrime(i)>=i*2)
         System.out.print(i + " ");
         count+=1;
     i+=1;
    }
 }

 public static void main(String args[])
 {
     findJagged(100);
 }
}

    

