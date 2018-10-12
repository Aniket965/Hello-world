
class Meth {
	int sum(int a,int b)
	{
		System.out.println("1");
		return a+b;
	}
	double sum(double a,double b)
	{
		
		System.out.println("2");
		return a+b; 
	}
	double sum(int a,double b)
	{
		
		System.out.println("3");	
		return a+b;
	}

}


class Poly {


	public static void main(String arg[])
	{
		
		Meth obj=new Meth();
		System.out.println(obj.sum(10,20 ));
		System.out.println(obj.sum(10.5,20.6 ));
		System.out.println(obj.sum(10.5,5 ));
		System.out.println(obj.sum(10,5.0 ));
		
		
		
	}
	
	


}

