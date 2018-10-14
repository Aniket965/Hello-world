import java.util.Arrays;
import java.util.Scanner;

public class BinarySearch {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);//declaring a scanner to take inputs from the user
		System.out.println("Enter the size of the array");
		int size=sc.nextInt();//size of the array
		
		int arry[]=new int[size];//declaring an integer type array
		
		
		
		System.out.println("Enter "+ size + " elments");
		for(int i=0;i<size;i++)//storing elements entered by user into an array
		{
			arry[i]=sc.nextInt();
		}
		
		int low=0,high=size-1,mid;//assigning lowest and highest index of array to the variables
		
		System.out.println("Enter the element you want to search in array");
		int find=sc.nextInt();
		
		//for binary search array needs to be i sorted order so we first sort it using inbuilt sort function
		Arrays.sort(arry);
		
		while(low<=high)
		{
			mid=(low+high)/2;
			if(find>arry[size-1] || find<arry[0])
			{
				System.out.println("Element not in the array");
				break;
			}
			else if(find==arry[mid])
			{
				System.out.println("Element "+ find +" found at position "+ mid+1);
				break;
			}
			else if(find>arry[mid])
			{
				low=mid;
			}
			else
			{
				high=mid;
			}
		}
	}

}
