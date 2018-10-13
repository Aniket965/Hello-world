import java.util.Scanner;

public class BubbleSort {
	public static int[] takeInput()
	{
		Scanner s = new Scanner(System.in);
		System.out.println("Enter the number of elements in the array");
		int n=s.nextInt();
		System.out.println("Enter the array Elements");
		int input[]=new int [n];
		for(int i=0;i<n;i++)
		{
		input[i]=s.nextInt();
		}
		return input;
	}

	public static void printArray(int [] input) {
		for(int i=0;i<input.length;i++)
		{
		System.out.print(input[i]+ " ");
		}
		System.out.println();
	}

	public static void bubbleSort(int[] arr){
		//write your code here
		int flag;
    for(int i=0;i<arr.length-1;i++)
		{
			flag = 0;
			for(int j=0;j<arr.length-1-i;j++)
			{
				if(arr[j]>arr[j+1])
				{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				flag = 1;
				}
			}
			if(flag==0)
				return;
		}
	}

	public static void main(String[] args) {
		int input[]=takeInput();
		printArray(input);
		bubbleSort(input);
		System.out.println();
		printArray(input);

	}

}
