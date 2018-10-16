namespace Pumpkin
{
    using System;

    public static class Pumpkin
    {
        public static void Main()
        {
            Console.WriteLine(" {0}/{0} ", new string('_', 3));
            Console.WriteLine(@"/{0}\", new string('.', 7));
            Console.WriteLine(@"|{0}^,^{0}|", new string('.', 2));
            Console.WriteLine(@"\{0}\_/{0}/", new string('.', 2));
        }
    }
}
