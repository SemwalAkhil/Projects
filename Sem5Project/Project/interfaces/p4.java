// 4. Write a Java programming to create a banking system with three classes - Bank, Account, SavingsAccount, and CurrentAccount. The bank should have a list of accounts and methods for adding them. Accounts should be an interface with methods to deposit, withdraw, calculate interest, and view balances. SavingsAccount and CurrentAccount should implement the Account interface and have their own unique methods.

import java.util.*;

interface Account {
    void deposit(double amount);
    void withdraw(double amount);
    void calculateInterest();
    void viewBalance();
}

class SavingsAccount implements Account {
    double balance;
    double interestRate = 0.04;

    SavingsAccount(double initialBalance) {
        balance = initialBalance;
    }

    public void deposit(double amount) {
        balance += amount;
    }

    public void withdraw(double amount) {
        if(amount <= balance) balance -= amount;
        else System.out.println("Insufficient balance");
    }

    public void calculateInterest() {
        balance += balance * interestRate;
    }

    public void viewBalance() {
        System.out.println("Savings Account Balance: " + balance);
    }
}

class CurrentAccount implements Account {
    double balance;
    double overdraftLimit = 1000;

    CurrentAccount(double initialBalance) {
        balance = initialBalance;
    }

    public void deposit(double amount) {
        balance += amount;
    }

    public void withdraw(double amount) {
        if(amount <= balance + overdraftLimit) balance -= amount;
        else System.out.println("Overdraft limit exceeded");
    }

    public void calculateInterest() {
        System.out.println("Current account does not earn interest");
    }

    public void viewBalance() {
        System.out.println("Current Account Balance: " + balance);
    }
}

class Bank {
    List<Account> accounts = new ArrayList<>();

    void addAccount(Account acc) {
        accounts.add(acc);
    }

    void showAllBalances() {
        for(Account acc : accounts) {
            acc.viewBalance();
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Bank bank = new Bank();

        SavingsAccount sa = new SavingsAccount(5000);
        CurrentAccount ca = new CurrentAccount(2000);

        bank.addAccount(sa);
        bank.addAccount(ca);

        sa.deposit(1000);
        sa.calculateInterest();
        ca.withdraw(500);

        bank.showAllBalances();
    }
}

/*
Output:
Savings Account Balance: 6240.0
Current Account Balance: 1500.0
*/
