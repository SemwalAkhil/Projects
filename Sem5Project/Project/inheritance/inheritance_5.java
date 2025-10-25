// CODE:-

class BankAccount
{
    int account_balance = 0;

    void deposit(int money)
    {
        System.out.println("Rs." + money + " successfully deposited in your account.");
        account_balance += money;
        System.out.println("Current Balance: " + account_balance);
    }

    void withdraw(int money)
    {
        System.out.println("Rs." + money + " successfully withdrawn from your account.");
        account_balance -= money;
    }
}

class SavingsAccount extends BankAccount
{
    void withdraw(int money)
    {
        if((account_balance - money) < 100)
        {
            System.out.println("You can withdraw only Rs. "+(account_balance-100)+" from your account because the account balance falls below one hundred.");
        }
        else
        {
        System.out.println("Rs." + money + " successfully withdrawn from your account.");
        account_balance -= money;
        System.out.println("Current Balance: " + account_balance);

        }
    }
}
    

class Main
{
    public static void main(String st[])
    {
        SavingsAccount s = new SavingsAccount();

        s.deposit(199);
        s.withdraw(100);
    }
}