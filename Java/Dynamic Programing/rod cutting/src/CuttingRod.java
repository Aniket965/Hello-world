/*
 * Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. 
 * Determine the maximum value obtainable by cutting up the rod and selling the pieces. 
 * For example, if length of the rod is 8 and the values of different pieces are given as following, 
 * then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)


length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 1   5   8   9  10  17  17  20
And if the prices are as following, then the maximum obtainable value is 24 (by cutting in eight pieces of length 1)

length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 3   5   8   9  10  17  17  20

 *
 * solution
 * 
 * 
 * */
import java.util.*;
public class CuttingRod {

	public CuttingRod() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner s =  new Scanner(System.in);
		
		System.out.println("Enter the Size of rod ");
		int n = s.nextInt();
		
		int price[] = new int[n];
		
		for(int i = 0 ; i < n ; i++)
		{
			price[i] = s.nextInt();
		}
		
		int val[] = new int[n];
		int tempval = 0;
		val[0] = price[0];
		for(int i = 1 ; i < n ; i++)
		{
			val[i] = price[i];
			for(int j = 0 ; j < i ; j++)
			{
				tempval = val[j] + val[i-j-1];
				
				if(tempval > val[i])
				{
					val[i] = tempval;
				}
			}
		}
		
		for(int i = 0 ; i < n ; i++)
		{
			System.out.print(" " + val[i]);
		}
		
		System.out.println("The maximum price by cutting the rod is  = " + val[n-1]);
	}
/*
	private static int max(int i, int j) {
		// TODO Auto-generated method stub
		return (i>j ? i : j);
	}
*/
}
