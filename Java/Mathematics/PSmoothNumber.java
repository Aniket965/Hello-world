/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Mathematics;

import java.util.Scanner;

/**
 *
 * @author sohai
 */
public class PSmoothNumber {
    
    
    static boolean[] smooth = new boolean[1000];

static int maxPrime(int n)
{
    int max=0;
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

static void checkSmooth(int n,int p)
{
    for(int i= 1; i<=n ;i++)
        if(maxPrime(i) <= p)
            smooth[i]=true;           
}

static void printsmooth( int start , int end)
{
    for(int i = start ; i<= end ; i++)
    {
        if(smooth[i])
            System.out.print(i + " ");
    }
}
 public static void main(String[] args) {
        
        checkSmooth(100, 8);
        printsmooth(20, 30);
        printsmooth(40, 60);
         
        
    }
    
}
