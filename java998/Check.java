
import java.io.*;
import  java.util.*;


class Check
{

	public static void main(String arg[]) {
		

			int arr[]=new int[4];
	
		arr[0]=2;
		arr[1]=2;
		arr[2]=1;
		arr[3]=8;
		
		
		
		
		int sum=0;
	
		for(int i=3;i>=0;i--)
		{
			
		sum=sum+arr[i]*10^i;
		}
		
		System.out.println(sum);
	}
	
}
