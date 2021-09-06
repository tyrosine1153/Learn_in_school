using System;

namespace Algorithm
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            var input = int.Parse(Console.ReadLine());
            var instance = new Make1();
            Console.WriteLine(instance.Func(input));
        }
    }
}