/*27. Write a Java program to create a class called BankAccount with private instance variables
    accountNumber and balance. Provide public getter and setter methods to access and modify these variables.*/

import java.io.*;

class p27 {
    public static void main(String st[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        // Create a BankAccount object
        BankAccount acc = new BankAccount();

        // Input and set account number
        System.out.print("Enter account number: ");
        acc.setAccountNumber(br.readLine());

        // Input and set initial balance
        System.out.print("Enter initial balance: ");
        acc.setBalance(Double.parseDouble(br.readLine()));

        // Display account details using getters
        System.out.println("\nBank Account Details:");
        System.out.println("Account Number: " + acc.getAccountNumber());
        System.out.println("Balance: " + acc.getBalance());
    }
}

// BankAccount class demonstrating encapsulation
class BankAccount {
    private String accountNumber;
    private double balance;

    // Getter for accountNumber
    public String getAccountNumber() {
        return accountNumber;
    }

    // Setter for accountNumber
    public void setAccountNumber(String accNo) {
        accountNumber = accNo;
    }

    // Getter for balance
    public double getBalance() {
        return balance;
    }

    // Setter for balance
    public void setBalance(double bal) {
        balance = bal;
    }
}
