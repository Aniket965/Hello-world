using System;

namespace AgeThing {
    class Program {
        static void Main(string[] args) {

            int age = CheckInputInt("How old are you?");
            int changeAgeByThisNumber = CheckInputInt("How many years would you like to add/subtract to your age?");
            Console.WriteLine("You will be {0} in {1} years.", age+changeAgeByThisNumber, changeAgeByThisNumber);
            Console.WriteLine("Press any key to exit.");
            Console.ReadKey();
        }

        public static int CheckInputInt(string message) {
            int tempValue = 0;
            string inputString = "";
            Console.WriteLine(message);
            inputString = Console.ReadLine();
            while (!int.TryParse(inputString, out tempValue) == true) {
                Console.WriteLine(message);
                inputString = Console.ReadLine();
            }
            return tempValue;
        }
    }
}
