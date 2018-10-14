import java.util.*;
public class LISubsequenceV1 {

	public LISubsequenceV1() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		
		System.out.println("Enter the length of string : ");
		int n = s.nextInt();
		
		int num[] = new int[n];
		int numval[] = new int[n];
		
		System.out.println("Enter the numbers : ");
		for(int i = 0 ; i < n ; i++)
		{
			num[i] = s.nextInt();
			numval[i] = 1;
		}
		
		// using single array of length n, with 2 variables i and j
		
		for(int i = 1 ; i < n ; i++)
		{
			for(int j = 0 ; j < i ; j++)
			{
				if(num[j] < num[i] && numval[i] < numval[j] + 1)
					numval[i] = numval[j] + 1;
			}
		}
		
		int max = 0 ; 
		for(int i = 0 ; i < n ; i++)
		{
			if(max < numval[i])
				max = numval[i];
		}
		
		System.out.println("The length of Longest increasing subsequence is : " + max);
		
		
	}

}
