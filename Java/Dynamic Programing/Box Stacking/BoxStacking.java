import java.util.*;

class Box{
	int length;
	int breadth;
	int height;
	
	public Box(int l , int b , int h)
	{
		length = l;
		breadth = b;
		height = h;
	}
}
public class BoxStacking{
	public static void main(String args[])
	{
		Scanner s = new Scanner(System.in);
		System.out.println("Enter the number of boxes :");
		int n = s.nextInt();
		
		Box boxes[] = new Box[n];
		for(int i = 0 ; i < n ;i++){
		System.out.println("Enter l, b, h");
			boxes[i] = new Box(s.nextInt() , s.nextInt() , s.nextInt());
		}
		
		//now create a new array of boxes which stores all the variations of lxbxh
		Box box[] = new Box[3*n];
		int size = box.length;
		int j = 0;
		
		for(int i = 0 ; i < n ; i++)
		{
			box[j++] = new Box(Math.max(boxes[i].breadth , boxes[i].height) , Math.min(boxes[i].breadth , boxes[i].height) , boxes[i].length);
			box[j++] = new Box(Math.max(boxes[i].length , boxes[i].height) , Math.min(boxes[i].length , boxes[i].height) , boxes[i].breadth);
			box[j++] = new Box(Math.max(boxes[i].breadth , boxes[i].length) , Math.min(boxes[i].breadth , boxes[i].length) , boxes[i].height);
		}
			
		//sorting according to the height of every box
		
		Arrays.sort(box , new Comparator<Box>(){
		@Override
			public int compare(Box h1 , Box h2)
			{
				return Integer.compare((h2.length * h2.breadth) , (h1.length * h1.breadth));					
			}
		});
		
			for(int i = 0 ; i < size ; i++){
				System.out.print(box[i].length + "\t");
				System.out.print(box[i].breadth + "\t");
				System.out.print(box[i].height + "\t");
				
				System.out.println();
			}
			
			//now apply longest increasing subsequence
			
			int T[] = new int[size];
			int maxheight = Integer.MIN_VALUE;
			
			for(int i = 0 ; i < size ; i++)
			{
				T[i] = box[i].height;
			}
			
			int i = 1; 
				j = 0;
			
			for(i = 1 ; i < size ; i++)
			{
				for(j = 0 ;j < i ; j++)
				{
					if((box[j].length > box[i].length) && (box[j].breadth > box[i].breadth))
					{
						if(T[j] + box[i].height > T[i])
							{
								T[i] = T[j] + box[i].height;								
								maxheight = Math.max(maxheight , T[i]);
							}
					}
				}
			}
			
			
			System.out.println(T[size-1]);
	}
}