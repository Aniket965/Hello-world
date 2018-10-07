    import java.util.*;
    class FactorialExample{  
     public static void main(String args[]){  
      Scanner s= new Scanner(System.in);
      int n = s.nextInt();
      System.out.println("Factorial of "+n+" is: "+factorialIterative(n));    

     }

     public static int factorialIterative(int n){
     	int fact=1;
     	for(int i=1;i<=n;i++){    
          fact=fact*i;    
      }
      return fact;	
     }

    }  
