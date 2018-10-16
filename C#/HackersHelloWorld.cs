using System;

namespace HelloWorld
{
    class Program
    {
        private static string HELLO_STRING = "Hello World!";

        static void Main(string[] args)
        {
            int i = 0;
			
            // Type furiously on your keyboard to write Hello World! repeatedly
            // Press ESC to quit
            while (Console.ReadKey(true).Key != ConsoleKey.Escape)
            {
                Console.Write(HELLO_STRING[i]);
                i = (i + 1) % HELLO_STRING.Length;

                if (i == 0)
                    Console.WriteLine();
            }

            Console.WriteLine();
            Console.WriteLine();
            Console.WriteLine("Bye!");
        }
    }
}
