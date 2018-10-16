import java.util.*;

public class BubbleSort {
	public static void main(String[] args) {

		Scanner s = new Scanner(System.in);

		System.out.println("enter number of elements");
		int n = s.nextInt();

		int arr[] = new int[n];

		System.out.println("enter elements");

		for (int i = 0; i < n; i++) {
			arr[i] = s.nextInt();
		}
		BubbleSort b=new BubbleSort();
		b.bubble(arr);
	}

	public void bubble(int[] arr) {
		for (int i = 0; i < arr.length - 1; i++) {
			for (int j = 0; j < arr.length - i - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
		 for(int i: arr)
	            System.out.println(i);
	}
	
}
