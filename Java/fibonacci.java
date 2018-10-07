package day4;

import java.util.Scanner;


public class Fibonacci {

	 static Scanner userInput = new Scanner(System.in); 
	
	public static void main(String[] args) {
        
		System.out.println("Enter number of terms :");
		
		int n = userInput.nextInt();
		
		int[] fibonacci = new int[n];
		
		fibonacci[0] = 1;
		
		fibonacci[1] = 1;
		
		for(int i=2;i<n;i++)
		{
			fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
			
		}
		
		System.out.println("The series is:");
		
		for(int j=0;j<n;j++)
			System.out.print(fibonacci[j] + " , ");
	}

}
