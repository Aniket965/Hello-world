import java.util.*;

public class LargestSuminMatrix{
	public static void main(String args[])
	{
		Scanner s = new Scanner(System.in);
		System.out.println("Enter the size of matrix in n x m format:");
		int n = s.nextInt();
		int m = s.nextInt();
		
		System.out.println("Enter the elements of matrix :");
		int mat[][] = new int[n][m];
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < m ; j++)
			{
				mat[i][j] = s.nextInt();
			}
		}
		
		//initial variables
		int l = 0;
		int r = 0;
		int currentSum = 0;
		int maxSum = 0;
		int left= 0;
		int right = 0; 
		int up = 0;
		int down = 0;
		
		int T[] = new int[m];
		
		while(r < m)
		{
			while(l <= r && r < m)
			{
				for(int i = 0 ; i < n ; i++)
				{
					T[i] = T[i] + mat[i][r];
				}
				int kadane[] = arraySumUsingKadane(T);
				
				currentSum = kadane[2];
				if(currentSum > maxSum)
				{
					maxSum = currentSum;
					left = l;
					right = r;
					up = kadane[0];
					down = kadane[1];
				}
				r++;
			}
			l++;
			r = l;
			Arrays.fill(T , 0);
		}
		
		System.out.println("Current Sum = " + currentSum);
		System.out.println("Maximum Sum = " + maxSum);
		
		System.out.println("The maximum Sub Matrix is =");
		
		for(int i = left ; i <= right ; i++)
		{
			for(int j = up ; j <= down ; j++)
			{
				System.out.print(mat[i][j] + "\t");
			}
			System.out.println();
		}
		
	}
	
	public static int[] arraySumUsingKadane(int[] a)
	{
		int n = a.length;
		int currentSum = 0;
		int maxstart = -1;
		int maxend = -1;
		int currentStart = -1;
		int maxSum = Integer.MIN_VALUE;
		
		for(int i = 0 ; i < n ; i++)
		{
			currentSum += a[i];
			
			if(currentSum < 0)
			{
				currentSum = 0;
				currentStart = i+1;
			}
			
			if(currentSum > maxSum)
			{
				maxstart = currentStart;
				maxend = i;
				maxSum = currentSum;
			}
		}
		
		/* This is to find the sum only, here you need the start and end position as well
		for(int i = 0 ; i < n ; i++)
		{
			currentSum = Math.max(a[i] , currentSum + a[i]);
			maxSum = Math.max(maxSum , currentSum);
		}
		*/
		
		int arr[] = new int[3];
		arr[0] = maxstart; // this represent the startint point of Array;
		arr[1] = maxend; // this represent the ending point of Array;
		arr[2] = maxSum; // this represent the maximum Sum of Array;
		return arr;
	}
}