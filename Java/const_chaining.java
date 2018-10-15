class Const_chain
{
	int no;
	String name;
	float age;
   	Const_chain()
	{
		no=0;
		name="default";
	}
	
	Const_chain(int no,String name)
	{
		this.no=no;
		this.name=name;
	}
	Const_chain(int no,String name,float age)
	{
		this(no,name);
		this.age=age;
	}
	void show()
	{
		System.out.println("no is: "+no+" name is: "+name+" age is: "+age);
	}
	
	public static void main(String... args)
	{
		Const_chain c=new Const_chain(12,"harsh",18);
		c.show();
   

		
	}	
}

	     