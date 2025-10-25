// 9. Create the program to create multiple threads by using Thread class

class MyThread extends Thread {
    private String name;

    MyThread(String name) {
        this.name = name;
    }

    public void run() {
        System.out.println(name + " is running.");
    }
}

public class Main {
    public static void main(String[] args) throws InterruptedException {
        MyThread t1 = new MyThread("Thread 1");
        MyThread t2 = new MyThread("Thread 2");
        MyThread t3 = new MyThread("Thread 3");

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
Output (order may vary):
Thread 1 is running.
Thread 2 is running.
Thread 3 is running.
All threads have finished execution.
*/
