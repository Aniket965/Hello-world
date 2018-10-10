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
public class ModularExponent {

static int fun(int b, int e, int p)
{
 int res = 1;
 b = b % p;
 while(e > 1){
     if((e & 1)==1)
         res = (res * b) %p;
     e= e>>1;
     b=(b*b)%p;
 }
 return res;
}

    public static void main(String[] args) {
       System.out.print(fun(2,2,1)); 
    }

}