
public class modularExponentiation {
		
		  static int power(int x, int y, int p) 
		    {  
		        int res = 1;      
		          
		        x = x % p;  
		      
		        while (y > 0) 
		        { 
		            if((y & 1)==1) 
		                res = (res * x) % p; 
		            y = y >> 1;  
		            x = (x * x) % p;  
		        } 
		        return res; 
		    } 
		  
		    public static void main(String args[]) 
		    { 
		        int x = 10; 
		        int y = 100000; 
		        int m = 1000000007; 
		        // Gives ans as x^y%m
		        System.out.println("Power is " + power(x, y, m)); 
		    } 
		

	}


