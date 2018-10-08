import java.util.*;
public class Solution {

	public Solution() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner s = new Scanner(System.in);
		System.out.println("Enter the size of array : ");
		int n = s.nextInt();
		
		System.out.println("Enter the array elements : ");
		int arr[] = new int[n];
		int jumps[] = new int[n];
		int pre[] = new int[n];
		
		for(int i = 0 ; i < n ; i++)
		{
			arr[i] = s.nextInt();
		}
		
		int numberofjumps = get_jumps(arr , jumps , pre);  
		System.out.println();
		System.out.println("The min number of jumps = " + numberofjumps);
	}

	private static int get_jumps(int[] arr, int[] jumps, int pre[]) {
		
		jumps[0] = 0;
		pre[0] = 0;
		if(arr[0] == 0)
		{
			return -1;
		}
		
		for(int i = 1 ; i < arr.length ; i++)
		{
			jumps[i] = Integer.MAX_VALUE;
			for(int j = 0 ; j <= i ; j++)
			{
				if(arr[j] >= i-j)
				{
					jumps[i] = Math.min(jumps[i] , jumps[j] + 1);
					pre[i] = j;
					break;
				}
			}
		}
		
		
		for(int i = 0 ;  i < pre.length; i++)
		{
			System.out.print(pre[i] + "\t");
		}
		return jumps[jumps.length-1];
	}

}
