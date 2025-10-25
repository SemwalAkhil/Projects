// 2. Java program to print even and odd numbers from 1 to 20 sequentially

class EvenThread extends Thread {
    public void run() {
        System.out.print("Even numbers: ");
        for (int i = 1; i <= 20; i++) {
            if (i % 2 == 0) System.out.print(i + " ");
        }
        System.out.println();
    }
}

class OddThread extends Thread {
    public void run() {
        System.out.print("Odd numbers: ");
        for (int i = 1; i <= 20; i++) {
            if (i % 2 != 0) System.out.print(i + " ");
        }
        System.out.println();
    }
}

public class Main {
    public static void main(String[] args) throws InterruptedException {
        OddThread ot = new OddThread();
        EvenThread et = new EvenThread();

        ot.start();
        ot.join(); 

        et.start();
        et.join(); 
    }
}

/*
Output:
Odd numbers: 1 3 5 7 9 11 13 15 17 19 
Even numbers: 2 4 6 8 10 12 14 16 18 20 
*/
