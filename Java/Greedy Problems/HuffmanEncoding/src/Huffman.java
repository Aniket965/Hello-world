import java.util.Scanner;

class Node{
	
	Node left;
	Node right;
	int data;
	
	
	public Node(int data) {
		this.data = data; 
	}
} 

public class Huffman {

	public static Node Heap[];
	public static int frequency[];
	public static String code[];
	public static Node root = null;
	
	public static void main(String args[])
	{
		Scanner s = new Scanner(System.in);
		int option = 0 ; 
		int count = 0;

		do{
			System.out.println("Press 1 to insert !");
			System.out.println("Press 2 to Delete !");
			System.out.println("Press 3 to Sort the data !");
			System.out.println("Press 4 to print Heap !");
			System.out.println("Press 5 to print the Huffman Tree in PreOrder :");
			System.out.println("Press 6 to print the Codes :");;
			System.out.println("Press 0 to Exit !");
		
			option = s.nextInt();
			
			switch(option)
				{
					case 1 : System.out.println("Enter the key to insert in heap : ");
							 int key = s.nextInt();
							 count++;		 
							 createFrequency(key , count , frequency);
							 Node Keynode = new Node(key);
							 insert(Keynode , count , Heap);
							 break;
							 
					case 2 : count--;
							 Node min = deleteMinKey(Heap , count);
							 System.out.println("After min deletion the Heap become : ");
							 showHeap(Heap);
							 break;
							 
					case 3 : break;
							 
					case 4 : System.out.println("The Heap entries are : ");
							 showHeap(Heap);
							 break;
					
					case 5 : System.out.println("The PreOrder traversal of Huffman Tree :");
							 createHuffmanTree();
							 break;
							 
					case 6 : System.out.println("The Codes for given frequencies are : ");
							 createCode("" , root , code);
							 showCodes();
							 break;
							 
					case 0 : break;
				}
		}while(option != 0);
	}
	
	private static void createCode(String s, Node root, String[] nodecode) {
		
		if(isLeaf(root)) {
			nodecode[searchposition(frequency , root.data)] = s;
		}
		else if(!isLeaf(root)) 
		{
			createCode(s + '0' , root.left , nodecode);
			createCode(s + '1' , root.right , nodecode);
		}
	}
	
	public static int searchposition(int []frequency , int key)
	{
		for(int i = 0 ; i < frequency.length ; i++)
		{
			if(key == frequency[i])
			{
				return i;
			}
		}
		return -1;
	}
	
	public static boolean isLeaf(Node node)
	{
		if(node.left == null && node.right == null)
			return true;
		else
			return false;
	}

	private static void createHuffmanTree() {
		
		while(Heap.length > 0)
		 {
			 int count = Heap.length;
			 
			 Node lchild = deleteMinKey(Heap , --count);
			 Node rchild = deleteMinKey(Heap , --count);
				 
			 
			 Node parent = new Node(0);
			 parent.data = lchild.data + rchild.data;
			 
			 if(lchild.data < rchild.data)
			 {
				 parent.left = lchild;
			 	 parent.right = rchild;
			 }
			 else
			 {
				 parent.left = rchild;
				 parent.right = lchild;
			 }
			 insert( parent , count+1, Heap);
			 
			 root = parent;
			 
			 if(Heap.length == 1)
				 break;
		 }
		
		showPreOrder(root);
	}

	private static void showPreOrder(Node root) {
		
		if(root != null) {
			System.out.print(root.data + " ");
			showPreOrder(root.left);
			showPreOrder(root.right);
		}
		
	}
	
	public static void showCodes()
	{
		System.out.println("frequency \t code");
		for(int i = 0 ; i < frequency.length ; i++)
		{
			System.out.println(frequency[i] + " \t \t" + code[i]);
		}
	}

	public static void createFrequency(int key , int count, int[] f) {
		frequency = new int[count];	
		code = new String[count];
	
		for(int i = 0; i < count-1 ; i++ )
		{
			frequency[i] = f[i];
		}
		frequency[count-1] = key;
	}
	
	private static void insert(Node node, int count, Node[] tempheap) {
		// TODO Auto-generated method stub
		
		Heap = new Node[count];
	
		for(int i = 0; i < count-1 ; i++ )
		{
			Heap[i] = tempheap[i];
		}
		
		Heap[count-1] = node;

		buildHeap(Heap);
	}
	
	public static void buildHeap(Node[] build_heap)
	{
		
		int child = build_heap.length - 1;
		int parent = (child - 1)/2;
		Node temp = null;
		
		while(parent >= 0)
		{
			if(build_heap[parent].data > build_heap[child].data)
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
			temp = null;
		}
	}
	
	public static Node deleteMinKey(Node[] heap , int count) 
	{

		Node min = heap[0];
		
		Node temp = heap[0];
		heap[0] = heap[heap.length - 1];
		heap[heap.length - 1] = temp;
		
		Heap = new Node[count];
		
		for(int i = 0; i < Heap.length ; i++)
		{
			Heap[i] = heap[i];
		}
		
		heapify(Heap);
		
		return min;
	}
	
	public static void heapify(Node[] heap)
	{
		int parent = 0;
		int lchild = (2*parent) + 1;
		int rchild = (2*parent) + 2;
		int len = heap.length - 1;
		
		while((parent <= len) || (parent <= len-1))
		{
			if(lchild >= len) {
				if(len == 1)
				{
					if(heap[lchild].data < heap[parent].data) {
						Node temp = heap[lchild];
						heap[lchild] = heap[parent];
						heap[parent] = temp;
						
						break;
					}
					else 
						break;
				}
				else 
					break;
			}
				
			else {
				int small_child = (heap[lchild].data > heap[rchild].data) ? rchild : lchild; 
				
				if(heap[small_child].data < heap[parent].data)
				{
					Node temp = heap[small_child];
					heap[small_child] = heap[parent];
					heap[parent] = temp;
					
					parent = small_child;
					lchild = (2*parent) + 1;
					rchild = (2*parent) + 2; 
					
				}
				else
					break;
			}

		}
	}
	
	public static void showHeap(Node[] heap) {
		
		for(int i = 0; i < heap.length ; i++)
		{
			System.out.println(heap[i].data);
		}
	}

}
