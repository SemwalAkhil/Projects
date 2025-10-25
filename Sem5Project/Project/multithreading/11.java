// 11. Create the program to create multiple threads, show an example of synchronization keyword.

class Counter {
    private int count = 0;

    public synchronized void increment() {
        count++;
        System.out.println(Thread.currentThread().getName() + " incremented count to " + count);
    }

    public int getCount() {
        return count;
    }
}

class MyThread extends Thread {
    private Counter counter;

    MyThread(Counter counter) {
        this.counter = counter;
    }

    public void run() {
        for (int i = 0; i < 5; i++) {
            counter.increment();
            try {
                Thread.sleep(50); // simulate some work
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

public class Main {
    public static void main(String[] args) throws InterruptedException {
        Counter counter = new Counter();

        Thread t1 = new MyThread(counter);
        Thread t2 = new MyThread(counter);

        t1.start();
        t2.start();

        t1.join();
        t2.join();

        System.out.println("Final count: " + counter.getCount());
    }
}

/*
Output (example):
Thread-0 incremented count to 1
Thread-1 incremented count to 2
Thread-0 incremented count to 3
Thread-1 incremented count to 4
Thread-0 incremented count to 5
Thread-1 incremented count to 6
Thread-0 incremented count to 7
Thread-1 incremented count to 8
Thread-0 incremented count to 9
Thread-1 incremented count to 10
Final count: 10
*/
