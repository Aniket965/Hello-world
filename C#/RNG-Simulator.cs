using System;
using System.Collections.Generic;
using System.Threading;

namespace rng_simulator
{
    class Program
    {
        static void Main(string[] args)
        {
            int dropRate = 0;
            Random random = new Random();
            int killCount = 0;
            int drop;
            int roll;
            bool flag = false;
            List<int> dropList = new List<int>();
            int repeatedDrops = 0;


            while (!flag)
            {
                Console.Write("Drop rate: 1/");
                if (int.TryParse(Console.ReadLine(), out dropRate))
                {
                    Console.WriteLine(dropRate);
                    flag = true;
                }
                else
                {
                    Console.WriteLine("Invalid input. Please enter numbers only.");
                }
            }

            drop = random.Next(dropRate);

            do
            {
                roll = random.Next(dropRate);
                killCount++;
                if(dropList.Contains(roll))
                {
                    repeatedDrops++;
                }
                else
                {
                    dropList.Add(roll);
                }
                Console.WriteLine("Kill " + killCount + ", You've rolled: " + roll + ", you need " + drop + ", and "+ repeatedDrops + " of them were repeated.");
                //Thread.Sleep(random.Next(20));
            } while (drop != roll);

            Console.WriteLine("It took you " + killCount + " to get a 1/" + dropRate + " item!");
            Console.Read();
        }
    }
}
