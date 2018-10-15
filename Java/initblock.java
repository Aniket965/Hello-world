class Initblock
{
        int no;
	String name;
	{
		System.out.println("First initialisation block");
	}
	Initblock()
	{
		no=0;
		name="default";
	}
	{
		System.out.println("Second initialisation block");
	}
	Initblock(int no,String name)
	{
		this.no=no;
		this.name=name;
	}
	void show()
	{
		System.out.println("No is: "+no+" name is: "+name);
	}
	public static void main(String... args)
	{
	        Initblock c1=new Initblock();
		Initblock c2=new Initblock(12,"harsh");
		c1.show();
		c2.show();    

		
	}	
}

	     