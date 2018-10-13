class Grand
{
   	Grand(String x)
	{
		System.out.println("Grand class constructor");
	}
		
}
class Parent extends Grand
{
   	Parent(int x)
	{
		super("harsh");
		System.out.println("Parent class constructor");
	}
		
}
class Child extends Parent
{
	Child()
	{
		super(5);
		System.out.println("Child class constructor");
	}
   public static void main(String... args)
	{
		new Child();
	}	
		
}


		     