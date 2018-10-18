using System;
using System.Collections.Generic;
using System.Threading;
using System.Threading.Tasks;

namespace HacktoberfestHelloWorld
{
    class Worker
    {
        public string Message;
        public int SleepTimeout;

        public async Task DoWork()
        {
            await Task.Delay(SleepTimeout);
            Console.WriteLine("Thread {0} > {1}", Thread.CurrentThread.ManagedThreadId, Message);
        }
    }

    class HelloFromMilan
    {
        static void Main(string[] args)
        {
            var workers = new List<Worker>
            {
                new Worker { Message = "!!!", SleepTimeout = 6000 },
                new Worker { Message = "Hacktoberfest", SleepTimeout = 4000 },
                new Worker { Message = "Hello", SleepTimeout = 2000 },
                new Worker { Message = "2018", SleepTimeout = 5000 },
                new Worker { Message = "World", SleepTimeout = 3000 }
            };

             Parallel.ForEach(workers, worker => worker.DoWork().Wait());
        }
    }
}
