import java.util.*;
import java.lang.*;
import java.io.*;

class BinarySearch2DArray
{
	public static int get(int in[][], int index)
	{
		int r = index / in[0].length;
		int c = index % in[0].length;
		//System.out.println("Get ==> index: " + index + " r: " + r + " c: " + c);
		return in[r][c];
	}
	
	public static boolean contains(int in[][], int val)
	{
		int start = 0;
		int end = in.length * in[0].length - 1;
		int mid;
		while (start <= end)
		{
			mid = (end + start) / 2;
			//System.out.println(start + " " + end + " " + mid);
			if (get(in, mid) > val)
			{
				end = mid - 1;
			}
			else if (get(in, mid) < val)
			{
				start = mid + 1;
			}
			else
			{
				return true;
			}
		}
		
		return false;
	}
	public static void main (String[] args) throws java.lang.Exception
	{
		int in[][] = new int[][]{{1, 2, 3}, {5, 6, 9}};
		System.out.println("1:  " + contains(in, 1));
		System.out.println("2:  " + contains(in, 2));
		System.out.println("3:  " + contains(in, 3));
		System.out.println("4:  " + contains(in, 4));
		System.out.println("5:  " + contains(in, 5));
		System.out.println("6:  " + contains(in, 6));
		System.out.println("7:  " + contains(in, 7));
		System.out.println("8:  " + contains(in, 8));
		System.out.println("9:  " + contains(in, 9));
		System.out.println("10: " + contains(in, 10));
	}
}