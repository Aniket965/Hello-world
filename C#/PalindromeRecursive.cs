using System;
using System.Linq;

namespace RecursivePalindrome
{
    class Program
    {
        private static void Main()
        {
            bool another;
            Console.WriteLine("This is aRecursive Palindrome Test");
            Console.WriteLine("To exit please use Ctrl+C");

            do
            {
                Console.WriteLine("Please enter a possible palindrome: ");
                var posPalin = Console.ReadLine()?.Trim().ToLower();
                Console.WriteLine(IsPalindrome(posPalin)
                    ? $"{posPalin} is a palindrome"
                    : $"{posPalin} is not a palindrome");
                Console.WriteLine("Do you want to test another palindrome? (y/n)");
                another = (bool) Console.ReadLine()?.Trim().ToLower().Equals("y");
            } while (another);
        }

        private static bool IsPalindrome(string s)
        {
            if (s.Length == 0 || s.Length == 1) return true;
            
            return s.ToCharArray().First() == s.ToCharArray().Last() && IsPalindrome(s.Substring(1,s.Length-2));
        }
    }
}
