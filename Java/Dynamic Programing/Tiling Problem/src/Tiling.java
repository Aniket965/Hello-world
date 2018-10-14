//--------------------------------------Problem------------------------------------
/*Tiling : Assume that we use dominoes measuring 2x1 to tile an infinite strip of height 2. 
How many ways can one tile a 2xn strip of square cells with 1x2 dominoes ?

Solution : It's a similar problem like a fibonacci series .*/


import java.util.*;
public class Tiling {

	public Tiling() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		
		Scanner s = new Scanner(System.in);
		
		System.out.println("Enter the size of strip : ");
		int n = s.nextInt();
		
		int a = 1;
		int b = 2;
		int sum = 0;
		for(int i = 2 ; i < n ; i++)
		{
			sum = a+b;
			a = b;
			b = sum; 
		}
		
		System.out.println(sum);
	}

}
