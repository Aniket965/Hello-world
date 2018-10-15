using System;
using System.IO;

namespace ConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            var filePath = "";
            while (!GetFilePath(out filePath))
            {
                Console.WriteLine("Invalid filepath specified!");
                Console.WriteLine();
            }

            string greeting = "Hello, World!";
            Console.WriteLine(greeting);
            File.WriteAllText(filePath, greeting);

            Console.WriteLine("Press the [any] key to continue...");
            Console.ReadKey(true);
        }

        private static bool GetFilePath(out string filePath)
        {
            Console.WriteLine("Enter a filepath and press [Enter]: ");
            filePath = Console.ReadLine();

            if (string.IsNullOrWhiteSpace(filePath))
            {
                return false;
            }
            
            try
            {
                var fileInfo = new FileInfo(filePath);
                if (!fileInfo.Directory.Exists)
                {
                    return false;
                }
            }
            catch
            {
                return false;
            }

            return true;
        }
    }
}
