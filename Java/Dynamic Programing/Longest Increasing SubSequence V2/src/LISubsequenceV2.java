import java.util.*;

public class LISubsequenceV2 {

	public LISubsequenceV2() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		Scanner s =  new Scanner(System.in);
		
		System.out.println("Enter the number of elements : ");
		int n = s.nextInt();
		
		int arr[] = new int[n+1];
		int sortarr[] = new int[n+1];
		
		System.out.println("Enter the numbers :");
		for(int i = 0 ; i <= n ; i++)
		{
			if(i == 0)
				arr[i] = 0;
			else
				arr[i] = s.nextInt();
			
			sortarr[i] = arr[i];
		}
		
		
		Arrays.sort(sortarr);
		
		
		
		int DPgrid[][] = new int[n+1][n+1];
		
		for(int i = 0 ; i <= n ; i++)
		{
			for(int j = 0 ; j <= n ; j++) 
			{
				if(i == 0 && j == 0)
					DPgrid[i][j] = 0;
				else if(i == 0 && j != 0)
					DPgrid[i][j] = 0;
				else if(i != 0 && j == 0)
					DPgrid[i][j] = 0;
				else {
					if(arr[i] == sortarr[j])
						DPgrid[i][j] = DPgrid[i-1][j-1] + 1;
					else
					{
						DPgrid[i][j] = DPgrid[i][j-1];
						 if(DPgrid[i-1][j] > DPgrid[i][j-1])
							 DPgrid[i][j] = DPgrid[i-1][j];	 
					}
				}
			}
		}
		
		System.out.println("The length of Longest Common Subsequence is = " + DPgrid[n][n]);

		for(int i = 0 ; i < DPgrid.length ; i++)
		{
			System.out.println();
			for(int j = 0 ; j < DPgrid[0].length ; j++)
			{
				System.out.print(DPgrid[i][j] + "\t");
			}
		}
		
	}

}
