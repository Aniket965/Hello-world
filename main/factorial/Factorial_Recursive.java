import java.util.*;
class Factorial_Recursive{  
 static int factorial(int n){    
  if (n == 0)
    return 1; /*Base case*/
  else
    return(n * factorial(n-1)); /*Recursive Function call*/
 }    
 public static void main(String args[]){  
  int i,fact=1;  
  int number;
  Scanner sc=new Scanner(System.in);
  number=sc.nextInt();  /*Taking number input*/
  fact = factorial(number); /*calling function to calculate factorial*/   
  System.out.println("Factorial of " + number + " is: " + fact);    
 }  
}
