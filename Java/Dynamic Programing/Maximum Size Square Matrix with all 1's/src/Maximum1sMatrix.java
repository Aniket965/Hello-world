/*Problem : Maximum size square sub-matrix with all 1's
 * Given a matrix with 0's and 1's, give an algorith for finding the maximum size square sub-matrix with all 1s.
 * For Example consider the binary matrix below
 * 		
 * 		0	1	1	0	1
 * 		1	1	0	1	0
 * 		0	1	1	1	0
 * 		1	1	1	1	0
 * 		1	1	1	1	1
 * 		0	0	0	0	0
 * 
 * SubMatrix
 * 
 * 		1	1	1
 * 		1	1	1
 * 		1	1	1
 * 		
 * */

import java.util.*;
public class Maximum1sMatrix {

	public Maximum1sMatrix() {
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
		
		int DPgrid[][] = new int[n][n];	
		
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < n ; j++)
			{
				if(i == 0 && j != 0 )
					DPgrid[i][j] = DPMatrix[i][j];
				else if(i != 0 && j == 0)
					DPgrid[i][j] = DPMatrix[i][j];
				else if( i == 0 && j == 0)
					DPgrid[i][j] = DPMatrix[i][j];
				else if(DPMatrix[i][j] != 0)
				{
					DPgrid[i][j] = minValue(DPgrid[i-1][j-1] , DPgrid[i-1][j] , DPgrid[i][j-1]) + 1;
				}
				else 
					DPgrid[i][j] = 0;
			}
		}
		
		for(int i = 0 ; i < n ; i++)
		{
			System.out.println();
			for(int j = 0 ; j < n ; j++)
			{
				System.out.print(DPgrid[i][j] + "\t");
			}
		}
		
		int max = 0;
		
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < n ; j++)
			{
				if(max < DPgrid[i][j])
					max = DPgrid[i][j];
			}
		}
		
		System.out.println("The size of maximum sub matrix of all 1's : " + max);
		
	}

	private static int minValue(int a, int b, int c) {
		
		return (a<b) ? ((a<c) ? a : c) : ((b<c) ? b : c);
	}

}
