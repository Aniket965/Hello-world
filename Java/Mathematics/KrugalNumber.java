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
public class KrugalNumber {
    
    boolean isFrugal(int n)
    {
       int t=n;
       int s=0,k=0,p;
       
        for(int i = 2; i * i <=n; i++)
        {
             k=0;p=0;
            if(n%i==0)
            {
                p=i;
                while(n>0 && n%i==0)
                {
                    k++;
                    n=n/i;
                }
            }
            s=s+digitcount(p);
            if(k>1)
                s+=digitcount(k);
        }
        
        return digitcount(t)>s;
    }
    
    
    int digitcount(int n)
    {
        int c=0;
        while(n>0)
        {
            c++;
            n/=10;
        }
        return c;
    }
            
    
    
    
}
