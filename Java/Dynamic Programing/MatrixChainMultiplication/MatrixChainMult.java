import java.util.*;

public class MatrixChainMult
{
	public static void main(String args[])
	{
		Scanner s = new Scanner(System.in);
		System.out.println("Enter the size of array : ");
		int n = s.nextInt();
		
		int arr[] = new int[n];
		for(int i = 0 ; i < n ; i++)
		{
			arr[i] = s.nextInt();
		}
		
		int grid[][] = new int[n][n];
		
		for(int i = 0 ; i < n ; i++)
		{
			grid[i][i] = 0;
		}
		
		int temp = 0;
		
		//now l here denotes the length of matrix multiplication
		for(int l = 2; l < n ; l++)
		{
			for(int i = 0 ; i < n-l ; i++)
			{
				int j = i + l;
				grid[i][j] = Integer.MAX_VALUE;
				for(int k = i+1 ; k < j ; k++)
				{
					temp = (grid[i][k] + grid[k][j]) + (arr[i] * arr[k] * arr[j]); //here we have to take the minimum value of temp
					
					if(temp < grid[i][j])
						grid[i][j] = temp;
				}
			}
		}
		
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < n ; j++)
			{
				System.out.print(grid[i][j] + "\t");
			}
			System.out.println();
		}
	}
}