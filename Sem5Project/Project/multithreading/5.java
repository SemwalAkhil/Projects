// 5. Write a Java program that calculates the sum of all prime numbers up to a given limit using multiple threads.

class PrimeSumThread extends Thread {
    private int start, end;
    private long sum = 0;

    PrimeSumThread(int start, int end) {
        this.start = start;
        this.end = end;
    }

    public void run() {
        for (int i = start; i <= end; i++) {
            if (isPrime(i)) sum += i;
        }
    }

    private boolean isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i <= Math.sqrt(n); i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    public long getSum() {
        return sum;
    }
}

public class Main {
    public static void main(String[] args) throws InterruptedException {
        int limit = 50; // sum primes up to 50

        PrimeSumThread t1 = new PrimeSumThread(1, limit / 2);
        PrimeSumThread t2 = new PrimeSumThread(limit / 2 + 1, limit);

        t1.start();
        t2.start();

        t1.join();
        t2.join();

        long totalSum = t1.getSum() + t2.getSum();
        System.out.println("Sum of prime numbers up to " + limit + " is: " + totalSum);
    }
}

/*
Output:
Sum of prime numbers up to 50 is: 328
*/
