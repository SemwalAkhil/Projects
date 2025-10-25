// 1. Write a Java program to create a basic Java thread that prints "Hello, World!" when executed.

class MyThread extends Thread {
    public void run() {
        System.out.println("Hello, World!");
    }
}

public class Main {
    public static void main(String[] args) {
        MyThread t = new MyThread();
        t.start();
    }
}

/*
Output:
Hello, World!
*/
