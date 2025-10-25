// CODE:-

abstract class BankAccount {
    double balance;

    BankAccount(double balance) {
        this.balance = balance;
    }

    abstract void deposit(double amount);
    abstract void withdraw(double amount);
}

class SavingsAccount extends BankAccount {
    SavingsAccount(double balance) {
        super(balance);
    }

    void deposit(double amount) {
        balance += amount;
        System.out.println("Rs." + amount + " deposited in Savings Account.");
        System.out.println("Current Balance: " + balance);
    }

    void withdraw(double amount) {
        if ((balance - amount) < 100) {
            System.out.println("Withdrawal denied! Minimum balance of Rs.100 must be maintained.");
        } else {
            balance -= amount;
            System.out.println("Rs." + amount + " withdrawn from Savings Account.");
            System.out.println("Current Balance: " + balance);
        }
    }
}

class CurrentAccount extends BankAccount {
    CurrentAccount(double balance) {
        super(balance);
    }

    void deposit(double amount) {
        balance += amount;
        System.out.println("Rs." + amount + " deposited in Current Account.");
        System.out.println("Current Balance: " + balance);
    }

    void withdraw(double amount) {
        if (amount > balance) {
            System.out.println("Withdrawal denied! Insufficient balance in Current Account.");
        } else {
            balance -= amount;
            System.out.println("Rs." + amount + " withdrawn from Current Account.");
            System.out.println("Current Balance: " + balance);
        }
    }
}

class Main {
    public static void main(String[] args) {
        SavingsAccount s = new SavingsAccount(500);
        CurrentAccount c = new CurrentAccount(1000);

        System.out.println("----- Savings Account Operations -----");
        s.deposit(200);
        s.withdraw(550);
        s.withdraw(50);

        System.out.println("\n----- Current Account Operations -----");
        c.deposit(300);
        c.withdraw(1200);
        c.withdraw(800);
    }
}
