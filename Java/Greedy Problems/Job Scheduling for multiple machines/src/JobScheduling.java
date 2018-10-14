import java.util.*;

public class JobScheduling {

	public static int EndHeap[];
	
	public static void main(String[] args) {
	Scanner s = new Scanner(System.in);
		
		System.out.println("Enter the number of jobs you have : ");
		int jobs = s.nextInt();
		
		
		//using 2D array such that row 0 - indicates  Start time of jobs and row 1 - indicates End time of jobs
		int startendTime[][] = new int[2][jobs];
		
		for(int i = 0 ; i < jobs ; i++)
		{
			System.out.println("Enter Start time : ");
				startendTime[0][i] = s.nextInt();
			System.out.println("Enter End time : ");
				startendTime[1][i] = s.nextInt();
		}
		
		int tempstart = 0 , tempend = 0;
		
		//Sort according to start time in ascending order
		for(int i = 0 ; i < startendTime[0].length ; i++)
		{
			for(int j = i+1 ; j < startendTime[0].length ; j++)
			{
				if(startendTime[0][i] > startendTime[0][j])
				{
					tempstart = startendTime[1][i];
					tempend = startendTime[0][i];
					startendTime[1][i] = startendTime[1][j];
					startendTime[0][i] = startendTime[0][j];
					startendTime[1][j] = tempstart;
					startendTime[0][j] = tempend;
				}
			}
		}
		
		
		//find the time for last process 
		/*
		int findlast = 0;
		
		for(int i = 0 ; i < startendTime[1].length ; i++)
		{
			if(findlast < startendTime[1][i])
				findlast = startendTime[1][i];
		} 
		
		//
		
		int DPgrid[][] = new int[jobs][findlast+1];
		int count = 0, depth = 0 ;
		for(int i = 0 ; i < jobs ; i++)
		{
			for(int j = 0 ; j <= findlast ; j++)
			{
				if(startendTime[0][i] < j && startendTime[1][i] >= j)
				{
					DPgrid[i][j] = 1;
				}
				else 
					DPgrid[i][j] = 0;
			}
		}
		

		for(int i = 0 ; i < jobs ; i++)
		{
			System.out.println();
			for(int j = 0 ; j <= findlast ; j++)
			{
				System.out.print(DPgrid[i][j] + "\t");
			}
		}
		
		for(int j = 0 ; j <= findlast ; j++)
		{
			for(int i = 0 ; i < jobs ; i++)
			{
				if(DPgrid[i][j] == 1)
					count++;
			}
			if(depth < count)
				depth = count;
			
			count = 0;
		}
		*/
		
		for(int i = 0 ; i < startendTime[0].length ; i++)
		{
			if(EndHeap == null)
				insert(startendTime[0][i] , startendTime[1][i] , 0 , EndHeap);
			else
				insert(startendTime[0][i] , startendTime[1][i] , EndHeap.length , EndHeap);
		}
		
		System.out.println("The number of machines required = " + EndHeap.length);
	}
	

	private static void insert(int start, int end, int countnode, int[] tempheap) {
		// TODO Auto-generated method stub
		int i = 0;
		if(countnode == 0)
			countnode++;
		else {
			for(i = 0 ; i < EndHeap.length ; i++)
			{
				if(tempheap[i] <= start) {
					tempheap[i] = end;
					break;
				}
			}
			
			if(i == EndHeap.length)
				countnode++;
		}
		EndHeap = new int[countnode];
	
		for(int j = 0; j < countnode-1 ; j++ )
		{
			EndHeap[j] = tempheap[j];
		}
		
		EndHeap[countnode-1] = end;

		buildHeap(EndHeap);
	}
	
	public static void buildHeap(int[] build_heap)
	{
		
		int child = build_heap.length - 1;
		int parent = (child - 1)/2;
		int temp = 0;
		
		while(parent >= 0)
		{
			if(build_heap[parent] > build_heap[child])
			{
				temp = build_heap[parent];
				build_heap[parent]= build_heap[child];
				build_heap[child] = temp;
			}
			
			if(parent != 0)
			{
				child = parent;
				parent = (child - 1)/2;
			}
			else {
				parent = -1;
			}
			temp = 0;
		}
	}
}


