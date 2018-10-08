import java.util.*;
public class MaximumLengthChainofPairs {

	public MaximumLengthChainofPairs() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner s = new Scanner(System.in);
		
		System.out.println("Enter the numbers of pairs :");
		int n = s.nextInt();
		
		int arr[][] = new int[n][2];
		
		System.out.println("enter the n number of pairs :");
		
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < 2; i++) {
				arr[j][i] = s.nextInt();
			}
		}
		
		
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < 2; i++) {
				System.out.print(arr[j][i] + "\t");
			}
			System.out.println();
		}
			
		System.out.println("The maximum length of increasing pair = " +findMaxLengthofPair(arr , n));
		
		
		
	}

	private static int findMaxLengthofPair(int[][] arr, int n) {
		// TODO Auto-generated method stub
		
		int Maxval[] = new int[n];
		
		for(int i = 0; i < n ; i++)
		{
			Maxval[i] = 1;
		}
		
		for(int i = 1 ; i < n ; i++)
		{
			for(int j = 0 ; j < i ; j++)
			{
				if(arr[j][1] < arr[i][0] && (Maxval[i] < Maxval[j] + 1))
				{
					Maxval[i] = Maxval[j] + 1;
				}
			}
		}
		
		int max = Integer.MIN_VALUE;
		for(int i = 0 ; i < n ; i++)
		{
			if(max < Maxval[i])
			{
				max = Maxval[i];
			}
		}
		return max;
	}

}
