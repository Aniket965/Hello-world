import java.util.*;
public class MaximumSumIncreasingSubsequence {

	public MaximumSumIncreasingSubsequence() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		
		System.out.println("Enter the length of string : ");
		int n = s.nextInt();
		
		int num[] = new int[n];
		int sumval[] = new int[n];
		
		System.out.println("Enter the numbers : ");
		for(int i = 0 ; i < n ; i++)
		{
			num[i] = s.nextInt();
		}
		
		// using single array of length n, with 2 variables i and j
		sumval[0] = num[0];
		
		for(int i = 1 ; i < n ; i++)
		{
			sumval[i] = num[i]; 
			for(int j = 0 ; j < i ; j++)
			{
				if(num[j] < num[i] && sumval[i] < sumval[j] + sumval[i])
					sumval[i] = sumval[j] + num[i];
			}
		}
		
		int max = 0 ; 
		for(int i = 0 ; i < n ; i++)
		{
			System.out.print(sumval[i] + "\t");
			if(max < sumval[i])
				max = sumval[i];
		}
		
		System.out.println("The length of Longest increasing subsequence is : " + max);
		
	}

}
