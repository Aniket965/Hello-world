using System;
using System.Linq;

public class Test
{
	public static void Main()
	{
		// your code goes here
		int[] s = { 1, 2, 3, 3, 4, 5, 5, 5};
		Console.WriteLine(string.Join(",", s.Distinct()));
	}
}
