using System;

namespace HelloWorld
{
	public class Program
	{
		static void Main(string[] args)
		{
			System.Console.WriteLine("How many times do you want to say 'Hello, world'?");
			while(true)
			{
				int x = 1;
				if(int.TryParse(Console.ReadLine(), out x))
				{
					for(int i = 0; i < x; i++) Console.WriteLine("Hello World!");
					break;
				}
				else Console.WriteLine("Please enter valid value!");
			}
		}
	}
}