/* Edit Distance : Given two strings A of length m and B of length n, transform A into B with a minimum number of operations of the following types:
 * Delete a character from A
 * Insert a character into A
 * Change some character in A into a new character.
 * The minimal number of such operations required to transform A into B is called the edit distance between A and B.
 * */

//Solution : if i have to transform A -> B then we need A number of Rows and B number of Columns

import java.util.*;

public class EditDistance {

	public EditDistance() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		Scanner s =  new Scanner(System.in);
		
		System.out.println("Enter the first String A : ");
		String s1 = s.next();
		char s11[] = s1.toCharArray();
		char A[] = new char[s11.length + 1];
		
		A[0] = '0';
		for(int i = 1 ; i < A.length ; i++)
		{
			A[i] = s11[i-1];
		}
		
		
		System.out.println("Enter the second String B :");
		String s2 = s.next();
		char s22[] = s2.toCharArray();
		char B[] = new char[s22.length + 1];
		
		B[0] = '0';
		for(int i = 1 ; i < B.length ; i++)
		{
			B[i] = s22[i-1];
		}
		
		int DPgrid[][] = new int[A.length+1][B.length+1];
		
		//Initial conditions
		DPgrid[0][0] = 0;
		for(int i = 1 ; i <= A.length ; i++)
		{
			DPgrid[i][0] = DPgrid[i-1][0] + 1;
		}
		for(int j = 1 ; j <= B.length ; j++)
		{
			DPgrid[0][j] = DPgrid[0][j-1] + 1;
		}
		
		int maxval=0;
		
		for(int i = 1 ; i < A.length ; i++)
		{
			for(int j = 1 ; j < B.length ; j++)
			{
				if(A[i] == B[j])
				{
					DPgrid[i][j] = DPgrid[i-1][j-1]; 
				}
				else
				{
					maxval = findmin(DPgrid[i-1][j] , DPgrid[i][j-1] , DPgrid[i-1][j-1]);
					DPgrid[i][j] = maxval+1;
					
				}
			}
		}
		System.out.println("the number of edit operations required = " + DPgrid[A.length-1][B.length-1]);
		
	}
	
	public static int findmin(int a , int b ,  int c)
	{
		return (a<b) ? ((a<c) ? a : c) : ((b<c) ? b : c);
	}

}
