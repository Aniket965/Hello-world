using System;

namespace HelloWorld.Pt.Pt
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.ForegroundColor = ConsoleColor.DarkGreen;
            Console.Write("Hel");
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.Write("lo");
            Console.ForegroundColor = ConsoleColor.Red;
            Console.Write(" World");
            Console.ReadKey();
        }
    }
}
