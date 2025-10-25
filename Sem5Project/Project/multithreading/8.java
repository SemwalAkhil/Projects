// 8. Create the program to create multiple threads by using Runnable interface

class MyRunnable implements Runnable {
    private String name;

    MyRunnable(String name) {
        this.name = name;
    }

    public void run() {
        System.out.println(name + " is running.");
    }
}

public class Main {
    public static void main(String[] args) throws InterruptedException {
        Thread t1 = new Thread(new MyRunnable("Thread 1"));
        Thread t2 = new Thread(new MyRunnable("Thread 2"));
        Thread t3 = new Thread(new MyRunnable("Thread 3"));

        t1.start();
        t2.start();
        t3.start();

        t1.join();
        t2.join();
        t3.join();

        System.out.println("All threads have finished execution.");
    }
}

/*
Output :
Thread 1 is running.
Thread 2 is running.
Thread 3 is running.
All threads have finished execution.
*/
