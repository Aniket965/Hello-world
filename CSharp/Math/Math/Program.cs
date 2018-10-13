using System;

namespace Math
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Multiplication tables 1-10");

            for (int i = 1; i <= 10; i++) {
                Console.WriteLine($"Table {i}");
                Console.WriteLine();

                for (int j = 0; j < 10; j++) {
                    Console.WriteLine($"{i} x {j} = ({i*j})");
                }

                Console.WriteLine();
            }

            Console.ReadKey();
        }
    }
}
