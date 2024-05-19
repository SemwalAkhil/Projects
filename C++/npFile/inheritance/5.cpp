// 5. Write a C++ program to create a class known as "BankAccount" with methods called deposit() and withdraw(). Create a derived class called SavingsAccount that overrides the withdraw() method to prevent withdrawals if the account balance falls below one hundred.
#include <iostream>
using namespace std;
class BankAccount{
    public:
    int balance;
    void deposit(int amount){
        cout<<"DEPOSITING : "<<amount<<endl;
        balance += amount;
        cout<<"BALANCE : "<<balance<<endl;
    }
    virtual void withdraw(int amount){
        cout<<"WITHDRWAING : "<<amount<<endl;
        balance -= amount;
        cout<<"BALANCE : "<<balance<<endl;
    }
};
class SavingAccount : public BankAccount{
    public:
    void withdraw(int amount) override{
        if ((balance-amount)>100)
        {
            cout<<"WITHDRWAING : "<<amount<<endl;
            balance -= amount;
        }
        else{
            cout<<"MINIMUM BALANCE REACHED ! TRANSACTION FAILED !"<<endl;
        }
        cout<<"BALANCE : "<<balance<<endl;
    }
};
int main() {
    BankAccount bankaccount;
    SavingAccount savingaccount;
    bankaccount.balance = 1000;
    savingaccount.balance = 1000;
    bankaccount.deposit(1000);
    bankaccount.withdraw(3000);
    savingaccount.deposit(1000);
    savingaccount.withdraw(2000);
    return 0;
}