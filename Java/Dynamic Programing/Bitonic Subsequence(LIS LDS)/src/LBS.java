import java.util.*;

public class LBS {

	public LBS() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);

		System.out.println("Enter the number of elements : ");
		int n = s.nextInt();

		int arr[] = new int[n];
		System.out.println("Enter the elements of array :");
		for (int i = 0; i < n; i++) {
			arr[i] = s.nextInt();
		}

		// first find the longest increasing subsequence from left to right

		int lis[] = findLIS(arr, n);
		
		// now find the longest decreasing subsequence from right to left
		System.out.println();

		int lds[] = findLDS(arr, n);
		
		 int max = lis[0] + lds[0] - 1;
		for(int i = 1 ; i < n ; i++)
		{
			if(max < (lis[i] + lds[i] - 1))
				max = lis[i] + lds[i] - 1;
		}
		
		System.out.println(max);
	
	}


	private static int[] findLDS(int[] arr, int n) {
		// TODO Auto-generated method stub

		int lds[] = new int[n];
		for (int i = 0; i < n; i++)
			{
				lds[i] = 1;
			}

		for (int i = n - 2; i >= 0; i--) {
			for (int j = n - 2; j > i; j--) {
				if (arr[i] > arr[j] && lds[i] < lds[j] + 1) {
					lds[i] = lds[j] + 1;
				}
			}
		}
		

		for (int i = 0; i < n; i++) {
			System.out.print(lds[i ]+ "\t");
		}

		return lds;
	}

	private static int[] findLIS(int[] arr, int n) {
		// TODO Auto-generated method stub
		int lis[] = new int[n];
		for (int i = 0; i < n; i++) {
			lis[i] = 1;
		}
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (arr[j] < arr[i] && lis[i] < lis[j] + 1) {
					lis[i] = lis[j] + 1;
				}
			}
		}
		
		for (int i = 0; i < n; i++) {
			System.out.print(lis[i] + "\t");
		}
		return lis;
	}

}





