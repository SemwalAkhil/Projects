// 13. Create the program to create multiple threads, show an example of join and yield methods.

class MyThread extends Thread {
    public MyThread(String name) {
        super(name);
    }

    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println(getName() + " - Count: " + i);
            if (i == 3) {
                System.out.println(getName() + " yielding...");
                Thread.yield(); // hint to scheduler
            }
            try {
                Thread.sleep(200); // simulate work
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

public class Main {
    public static void main(String[] args) throws InterruptedException {
        MyThread t1 = new MyThread("Thread 1");
        MyThread t2 = new MyThread("Thread 2");

        t1.start();
        t1.join(); // wait for t1 to finish

        t2.start();
        t2.join(); // wait for t2 to finish

        System.out.println("Both threads have completed execution.");
    }
}

/*
Output (example):
Thread 1 - Count: 1
Thread 1 - Count: 2
Thread 1 - Count: 3
Thread 1 yielding...
Thread 1 - Count: 4
Thread 1 - Count: 5
Thread 2 - Count: 1
Thread 2 - Count: 2
Thread 2 - Count: 3
Thread 2 yielding...
Thread 2 - Count: 4
Thread 2 - Count: 5
Both threads have completed execution.
*/
