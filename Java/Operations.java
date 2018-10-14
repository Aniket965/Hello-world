import java.util.Random;
import java.util.Scanner;

public class Operations {

	public void printAlter(Node start)
	{
		Node X=start;
		System.out.println("Alternate Nodes are:");

		while(X!=null)
		{
			System.out.print(X.d+"->");
			if(X.next!=null)
				X=X.next.next;
			else
				break;
		}

		System.out.println();
	}

	public void nthFromEnd(Node start, Scanner sc)
	{
		int l=0;
		Node X=start;
		while(X!=null)
		{
			l++;
			X=X.next;
		}
		X=start;
		System.out.println("Enter n:");
		int p=sc.nextInt();
		for(int i=1;i<l+1-p;i++)
			X=X.next;
		System.out.println("Nth Node from end="+X.d);
	}

	public void duplicate(Node start)
	{
		Node X=start;

		while(X!=null)
		{
			Node Y=X;
			while(Y.next!=null)
			{
				if(X.d==Y.next.d)
				{
					Y.next=Y.next.next;
				}
				else
				{
					Y=Y.next;
				}
			}
			X=X.next;
		}
		System.out.println("After removal of duplicate nodes:");
		print(start);
	}

	public void removeAlter(Node start)
	{
		Node X=start;
		Node Y=X.next;
		while(X!=null && Y!=null)
		{
			X.next=Y.next;
			X=X.next;
			if(X!=null)
				Y=X.next;
		}

		X=start;
		System.out.println("After removal of alternate nodes");
		print(X);
	}

	public void swap(Node start, Scanner sc)
	{
		Node X=start;
		Node Z1=null;
		Node Y=start;
		Node Z2=null;

		System.out.println("Original List");
		print(start);


		System.out.println("enter 2 numbers:");
		int a=sc.nextInt();
		int b=sc.nextInt();
		while(X.d!=a && X!=null)
		{
			Z1=X;
			X=X.next;
		}

		while(Y.d!=b && Y!=null)
		{
			Z2=Y;
			Y=Y.next;
		}

		if(X==null || Y==null)
			return;

		if(Z1!=null)
			Z1.next=Y;
		else
			start=Y;

		if(Z2!=null)
			Z2.next=X;
		else
			start=X;

		Node temp=X.next;
		X.next=Y.next;
		Y.next=temp;

		System.out.println("Swapped List");
		print(start);
	}

	public void reverse(Node start)
	{
		Node X=start;
		Node Y=null;
		Node Z;

		System.out.println("Original List");
		print(start);

		while(X.next!=null)
		{
			Z=X.next;
			X.next=Y;
			Y=X;
			X=Z;
		}

		X.next=Y;
		start=X;

		System.out.println("Reversed List:");
		print(start);
	}

	public void middle(Node start)
	{
		int l=0;
		Node X=start;
		while(X!=null)
		{
			l++;
			X=X.next;
		}
		X=start;
		int c=0;
		l/=2;
		while(c!=l)
		{
			X=X.next;
			c=c+1;
		}
		if(l%2==0)
			X=X.next;

		System.out.println("Middle Node:");
		System.out.println(X.d);
	}

	public void print(Node start)
	{
		while(start.next!=null)
		{
			System.out.print(start.d+"->");
			start=start.next;
		}
		System.out.println(start.d);
	}

	public Node input(Scanner sc)
	{
		Random random=new Random();
		Node start;
		Node X=new Node(random.nextInt(9)+1);
		start=X;
		for(int i=2;i<=10;i++)
		{
			Node Y=new Node(random.nextInt(9)+1);
			X.next=Y;
			X=Y;
		}
		X.next=null;
		return start;
	}

	public void join(Scanner sc)
	{
		Operations op=new Operations();
		Node start1=op.input(sc);
		Node start2=op.input(sc);
		Node X=start1;
		while(X.next!=null)
			X=X.next;
		X.next=start2;
		System.out.println("Joined Lists:");
		print(start1);
	}


	public static void main(String[] args) {


		Operations op=new Operations();
		Scanner sc=new Scanner(System.in);

		op.printAlter(op.input(sc));
		op.nthFromEnd(op.input(sc),sc);
		op.duplicate(op.input(sc));
		op.join(sc);
		op.removeAlter(op.input(sc));
		op.middle(op.input(sc));
		op.swap(op.input(sc),sc);
		op.reverse(op.input(sc));

	}

}