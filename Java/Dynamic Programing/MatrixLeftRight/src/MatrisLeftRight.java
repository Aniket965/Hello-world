/*Problem 
 * Give a matrix with n rows and n columns. In each cell there are a number of apples.
 * we start from the upper-left corner of the matrix. We can go down or right one cell.
 * Finally, we need to arrive at the bottom right corner. 
 * Find the maximum number of apples that we can collect. When we pass through a cell, we collect all the apples left there.
 * */

import java.util.*;

public class MatrisLeftRight {

	public MatrisLeftRight() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		
		Scanner s = new Scanner(System.in);
		System.out.println("Enter the size of nxn matrix : ");
		int n = s.nextInt();
		
		int DPMatrix[][] = new int[n][n];
		System.out.println("Enter the values in matrix in increasing order from left to right and top to bottom : ");
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < n ; j++)
			{
				DPMatrix[i][j] =  s.nextInt();
			}
		}
		
		
		
		int DPgrid[][] = new int[n+1][n+1];
		
		for(int i = 0 ; i <= n ; i++)
		{
			for(int j = 0 ; j <= n ; j++)
			{
				if(i == 0 && j != 0)
					DPgrid[i][j] = 0;
				else if(i != 0 && j == 0)
					DPgrid[i][j] = 0;
				else if(i == 0 &&  j == 0)
					DPgrid[i][j] = 0;
				else
					DPgrid[i][j] = DPMatrix[i-1][j-1];
			}
		}
		
		for(int i = 1 ; i <= n ; i++)
		{
			for(int j = 1 ; j <= n ; j++)
			{
				if(DPgrid[i][j-1] > DPgrid[i-1][j])
					DPgrid[i][j] = DPgrid[i][j-1] + DPgrid[i][j];
				else
					DPgrid[i][j] = DPgrid[i-1][j] + DPgrid[i][j];
				
			}
		}
		

		for(int i = 0 ; i <= n ; i++)
		{
			System.out.println();
			for(int j = 0 ; j <= n ; j++)
			{
				System.out.print(DPgrid[i][j] + "\t");
			}
		}
			
		System.out.println("The maximum apple we can pick up are = " + DPgrid[n][n]);
	}
}

/*Similar Problem can be done if we can select the diagonal element as well.*/


