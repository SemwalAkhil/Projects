// 7. Write a Java program that creates a bank account with concurrent deposits and withdrawals using threads.

class BankAccount {
    private int balance = 0;

    public synchronized void deposit(int amount) {
        balance += amount;
        System.out.println(Thread.currentThread().getName() + " deposited " + amount + ", Balance: " + balance);
    }

    public synchronized void withdraw(int amount) {
        if (balance >= amount) {
            balance -= amount;
            System.out.println(Thread.currentThread().getName() + " withdrew " + amount + ", Balance: " + balance);
        } else {
            System.out.println(Thread.currentThread().getName() + " tried to withdraw " + amount + " but insufficient balance!");
        }
    }

    public int getBalance() {
        return balance;
    }
}

class DepositThread extends Thread {
    private BankAccount account;
    private int amount;

    DepositThread(BankAccount account, int amount) {
        this.account = account;
        this.amount = amount;
    }

    public void run() {
        account.deposit(amount);
    }
}

class WithdrawThread extends Thread {
    private BankAccount account;
    private int amount;

    WithdrawThread(BankAccount account, int amount) {
        this.account = account;
        this.amount = amount;
    }

    public void run() {
        account.withdraw(amount);
    }
}

public class Main {
    public static void main(String[] args) throws InterruptedException {
        BankAccount account = new BankAccount();

        Thread t1 = new DepositThread(account, 1000);
        Thread t2 = new WithdrawThread(account, 500);
        Thread t3 = new DepositThread(account, 700);
        Thread t4 = new WithdrawThread(account, 800);

        t1.start();
        t2.start();
        t3.start();
        t4.start();

        t1.join();
        t2.join();
        t3.join();
        t4.join();

        System.out.println("Final Balance: " + account.getBalance());
    }
}

/*
Output :
Thread-0 deposited 1000, Balance: 1000
Thread-1 withdrew 500, Balance: 500
Thread-2 deposited 700, Balance: 1200
Thread-3 withdrew 800, Balance: 400
Final Balance: 400
*/
