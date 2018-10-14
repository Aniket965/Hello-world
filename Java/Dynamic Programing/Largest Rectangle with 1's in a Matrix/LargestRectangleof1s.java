import java.util.*;

public class LargestRectangleof1s{

	public static void main(String args[])
	{
		Scanner s = new Scanner(System.in);
		System.out.println("Enter the size of matrix in rows and columns format :");
		
		int row = s.nextInt();
		int col = s.nextInt();
		int area = 0;
		int maxarea = 0;
		
		System.out.println("Enter the 1 and 0 in matrix :");
		int m[][] = new int[row][col];
		for(int i = 0 ; i < row ; i++)
		{
			for(int j = 0 ; j < col ; j++)
			{
				m[i][j] = s.nextInt();
			}
		}
		
		// create a temp array of size equals to columns;
		
		int T[] = new int[col];
		
		for(int i = 0 ; i < row ; i++)
		{
			for(int j = 0 ; j < col ; j++)
			{
				if(m[i][j] == 0)
					T[j] = 0;
				else
					T[j] += m[i][j];
					
				System.out.print(T[j] + "\t");
			}
			area = findAreaHistogram(T);
			maxarea = Math.max(area , maxarea);
			System.out.println("Area = " + area);
			System.out.println("MaxArea = " + maxarea);
		}
		
		System.out.println("the maximum area of all 1's = " + maxarea);
	}
	
	public static int findAreaHistogram(int a[])
	{
		Stack<Integer> s = new Stack<>();
		int i = 0;
		int n = a.length;
		int area = 0;
		int maxarea = 0;
		
		while(i < n)
		{
			if(s.isEmpty() || a[s.peek()] <= a[i])
				s.push(i++);
			else
			{
				int top = s.pop();
					if(s.isEmpty())
						area = a[top] * i;
					else
						area = a[top] * (i - s.peek() - 1);
						
					maxarea = Math.max(maxarea , area);
			}
		}
		
		while(!s.isEmpty())
		{
			int top = s.pop();
				if(s.isEmpty())
					area = a[top] * i;
				else
					area = a[top] * (i - s.peek() - 1);
					
				maxarea = Math.max(maxarea , area);		
		}
		
		return maxarea;
	}
}