


class D
{
	D()
	{
		
		System.out.println("A const");
	}
	static
	{

		System.out.println("A static");
		
	}
	
	{

		System.out.println("A NOn static");
		
	}
	
	
}

class B extends D
{
	B()
	{
		
		System.out.println("A const");
	}
	static
	{

		System.out.println("B static");
		
	}
	
	{

		System.out.println("B NON static");
		
	}
	
	
}


 class State{

	
	public static void main(String arg[])
	{
	
		B abg=new B();	
		
		
	}
	
}

