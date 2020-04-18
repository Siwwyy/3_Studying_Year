using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Threading;

namespace ProducerConsumerQueue
{
    class Consumer
    {
        private Queue<Record> queue = new Queue<Record>();
        private Thread workingThread;
        private bool notStopped = true;
        private StreamWriter writer;

        public void addRecord(Record record)
        {
            lock (this)
            {
                queue.Enqueue(record);
            }
        }

        public Consumer()
        {
            workingThread = new Thread(workerTask);
        }

        public void Start()
        {
            workingThread.Start();
        }

        public void Stop()
        {
            notStopped = false;
        }

        private void workerTask()
        {
            Record record;
            writer = new StreamWriter("out.csv");
            Console.WriteLine("Starting Consumer");
            while (notStopped)
            {
                record = null;
                lock (this)
                {
                    if (queue.Count > 0)
                    {
                        record = queue.Dequeue();
                    }
                }
                if (record == null)
                {
                    //Console.WriteLine("Consumer wait for records");
                    Thread.Sleep(5);
                    continue;
                }
                write(record);
            }
            writer.Close();
        }

        private void write(Record record)
        {
            writer.Write("{0};{1}\n", record.Id, record.Value);
        }
    }
}