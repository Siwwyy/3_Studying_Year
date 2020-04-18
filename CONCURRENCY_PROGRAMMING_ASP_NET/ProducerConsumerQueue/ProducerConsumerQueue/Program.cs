using System;
using System.Threading;

namespace ProducerConsumerQueue
{
    class Program
    {
        static void Main(string[] args)
        {

            Consumer consumer = new Consumer();
            consumer.Start();
            Producer[] producer = new Producer[10];
            Barrier finishedAllTasks = new Barrier(10, (b) => { consumer.Stop(); Console.WriteLine("FINISHED"); });
            for (int i = 0; i < producer.Length; i++)
            {
                producer[i] = new Producer("Producer" + (i + 1), consumer, finishedAllTasks);
            }
            foreach (Producer p in producer)
            {
                p.Start();
            }

        }
    }
}