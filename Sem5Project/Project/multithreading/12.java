// 12. Create the program to create multiple threads, show an example of notify, notifyAll, wait, sleep methods.

class SharedResource {
    public synchronized void produce() {
        try {
            System.out.println(Thread.currentThread().getName() + " is producing...");
            Thread.sleep(500); 
            System.out.println(Thread.currentThread().getName() + " is waiting...");
            wait(); 
            System.out.println(Thread.currentThread().getName() + " resumed after notify");
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    public synchronized void consume() {
        try {
            System.out.println(Thread.currentThread().getName() + " will notify waiting threads...");
            notify(); 
            Thread.sleep(500);
            notifyAll(); 
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class Producer extends Thread {
    private SharedResource resource;

    Producer(SharedResource resource) {
        this.resource = resource;
    }

    public void run() {
        resource.produce();
    }
}

class Consumer extends Thread {
    private SharedResource resource;

    Consumer(SharedResource resource) {
        this.resource = resource;
    }

    public void run() {
        resource.consume();
    }
}

public class Main {
    public static void main(String[] args) throws InterruptedException {
        SharedResource resource = new SharedResource();

        Thread t1 = new Producer(resource);
        Thread t2 = new Producer(resource);
        Thread t3 = new Consumer(resource);

        t1.start();
        t2.start();

        Thread.sleep(1000); // ensure producers start first

        t3.start();

        t1.join();
        t2.join();
        t3.join();

        System.out.println("All threads have completed execution.");
    }
}

/*
Output :
Thread-0 is producing...
Thread-1 is producing...
Thread-0 is waiting...
Thread-1 is waiting...
Thread-2 will notify waiting threads...
Thread-0 resumed after notify
Thread-1 resumed after notify
All threads have completed execution.
*/
