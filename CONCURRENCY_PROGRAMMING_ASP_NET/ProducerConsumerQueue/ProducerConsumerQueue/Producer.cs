using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;

namespace ProducerConsumerQueue
{
    class Producer
    {
        private Thread workingThread;
        private Consumer consumer;
        private Barrier informWhenFinished;
        public string Name { get; private set; }

        public Producer(String name, Consumer consumer, Barrier informWhenFinished)
        {
            this.Name = name;
            workingThread = new Thread(this.task);
            this.consumer = consumer;
            this.informWhenFinished = informWhenFinished;
        }

        public void Start()
        {
            workingThread.Start();
        }

        private void task()
        {
            Console.WriteLine("Starting Producer " + Name);
            for (int j = 0; j < 10; j++)
            {

                for (int i = 0; i < 100; i++)
                {
                    consumer.addRecord(new Record(this.Name, i + j * 100));
                }
                Thread.Sleep(3);
                Console.WriteLine(Name + " Next turn " + j);
            }
            Console.WriteLine("Producer " + Name + " finished");
            informWhenFinished.SignalAndWait();
        }
    }
}