using System;

namespace lab1
{
    class Program
    {
        static void Main(string[] args)
        {
            App app = new App();

            app.Create("A").doSomething();
            app.Create("B").doSomething();
            app.Create("A").doSomething();
        }

    }

    class App : Creator
    {
        public override IChat Create(string type)
        {
            switch (type)
            {
                case "A":
                    return new GroupChat();
                case "B":
                    return new Chat();
            }
            return null;
        }
    }

    interface IChat
    {
        void doSomething();
    }

    abstract class Creator
    {
        public abstract IChat Create(string type);
    }

    class GroupChat : IChat
    {
        public void doSomething()
        {
            Console.WriteLine("class A");
        }
    }
    class Chat : IChat
    {
        public void doSomething()
        {
            Console.WriteLine("class B");
        }
    }
}