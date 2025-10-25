/*7. Write a Java program to create a class called "Bank" with a collection of accounts 
   and methods to add and remove accounts, and to deposit and withdraw money. 
   Also define a class called "Account" to maintain account details of a particular customer.*/

class p7 {
    public static void main(String st[]) {
        // Create a bank object with space for 100 accounts
        Bank b1 = new Bank(100);
        // Add an account for customer Raj
        b1.addAccount(new Account("Raj", "AB123"));
        // Deposit money into Raj's account
        b1.addMoney("AB123", 5000);
        // Withdraw money from Raj's account
        b1.withdrawMoney("AB123", 600);
        // Try withdrawing more than available balance
        b1.withdrawMoney("AB123", 6000);
        // Attempt to remove a non-existing account
        b1.removeAccount("AB1234");
    }
}
// Represents a customer's account
class Account {
    String name;
    String Ac_number;
    double balance;
    // Constructor initializes account with zero balance
    Account(String nm, String acno) {
        name = nm;
        Ac_number = acno;
        balance = 0;
    }
    // Deposit money into the account
    void addFund(double fund) {
        if (fund < 0) {
            System.out.println("Amount cannot be negative");
        } else {
            balance += fund;
        }
    }
    // Withdraw money with validation checks
    void withdrawFund(double fund) {
        if (balance <= 0) {
            System.out.println("Amount must be positive");
        } else if (fund > balance) {
            System.out.println("Insufficient balance");
        } else {
            balance -= fund;
            System.out.println(fund + " withdrawn from Account having Account Number : " + Ac_number);
        }
    }
}
// Represents the bank containing multiple accounts
class Bank {
    Account accounts[];
    int cur;
    // Constructor initializes storage for accounts
    Bank(int size) {
        accounts = new Account[size];
        cur = 0;
    }
    // Search account by account number
    int searchAccount(String acno) {
        for (int i = 0; i < cur; i++) {
            if (accounts[i].Ac_number.equals(acno)) {
                return i;
            }
        }
        return -1;
    }
    // Add a new account if it doesn't already exist
    void addAccount(Account ac) {
        if (searchAccount(ac.Ac_number) != -1) {
            System.out.println("Account already exists for Account Number : " + ac.Ac_number);
        } else {
            accounts[cur++] = ac;
            System.out.println("Account added having Account Number : " + ac.Ac_number);
        }
    }
    // Remove an account by shifting elements in the array
    void removeAccount(String acno) {
        int acloc = searchAccount(acno);
        if (acloc == -1) {
            System.out.println("No Account found having Account Number : " + acno);
        } else {
            for (int i = acloc; i < cur - 1; i++) {
                accounts[i] = accounts[i + 1];
            }
            accounts[--cur] = null;
            System.out.println("Account removed having Account Number : " + acno);
        }
    }
    // Deposit money into an account
    void addMoney(String acno, double fund) {
        int acloc = searchAccount(acno);
        if (acloc == -1) {
            System.out.println("No Account found having Account Number : " + acno);
        } else {
            accounts[acloc].addFund(fund);
            System.out.println(fund + " added in account having Account Number : " + acno);
        }
    }
    // Withdraw money from an account
    void withdrawMoney(String acno, double fund) {
        int acloc = searchAccount(acno);
        if (acloc == -1) {
            System.out.println("No Account found having Account Number : " + acno);
        } else {
            accounts[acloc].withdrawFund(fund);
        }
    }
}
