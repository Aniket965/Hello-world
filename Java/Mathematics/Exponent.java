
package Mathematics;

public class Exponent {

public static int fastExponent(int base , int exponent)
{
    int x;
    
    if(exponent == 0)
    {
        return 1;
    }
    
    else if(exponent == 1 )
    {
        return base;
    }
    else 
    {
       x=fastExponent(base ,exponent/2);
       if(exponent%2==0)
       {
           return x*x;
       }
       else
           return x*base*x;
    }
}

public static int iterativeExponent(int base , int exponent)
{
    int res=1;
    
    while(exponent > 0)
    {
        if((exponent & 1) == 1)
            res=res*base;
        exponent = exponent >> 1;
        base= base * base;
    }
    return res;
}
    

public static void main(String args[])
{
   System.out.println(fastExponent(3, 5));
   System.out.println(iterativeExponent(3, 5));
}


}
