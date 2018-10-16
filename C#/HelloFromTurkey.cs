using System;


namespace Hacktoberfest
{
    class Hello
    {
        static void Main(string[] args)
        {
            Console.BackgroundColor = ConsoleColor.Red;
            Console.ForegroundColor = ConsoleColor.White;

            Console.WriteLine("Merhaba Hacktoberfest " + DateTime.Today.Year + "!"); 
            Console.ReadLine();
        }
    }
}
