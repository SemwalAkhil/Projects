// 4. Write a C++ program to create an abstract class BankAccount with abstract methods deposit() and withdraw(). Create derived classes: SavingsAccount and CurrentAccount that extend the BankAccount class and implement the respective methods to handle deposits and withdrawals for each account type.
#include <iostream>
using namespace std;
class BankAccount{
    public:
        int balance;
        virtual void deposit(int amount) = 0;
        virtual void withdraw(int amount) = 0;
};
class SavingsAccount : public BankAccount{
    public:
        void deposit(int amount) override{
            cout<<"Rs. "<<amount<<" credited to your savings account"<<endl;
            balance += amount;
            cout<<"Current Balance : Rs. "<<balance<<endl;
        }
        void withdraw(int amount) override{
            if ((balance-amount)>0)
            {
                cout<<"Rs. "<<amount<<" debited from your savings account"<<endl;
                balance -= amount;
                cout<<"Current Balance : Rs. "<<balance<<endl;
            }
            else{
                cout<<"Not enough balance. Transaction failed."<<endl;
            }
        }
};
class CurrentAccount : public BankAccount{
    public:
        static int limit;
        void deposit(int amount) override{
            cout<<"Rs. "<<amount<<" credited to your current account"<<endl;
            balance += amount;
            cout<<"Current Balance : Rs. "<<balance<<endl;
        }
        void withdraw(int amount) override{
            if ((balance-amount)>limit)
            {
                cout<<"Rs. "<<amount<<" debited from your current account"<<endl;
                balance -= amount;
                cout<<"Current Balance : Rs. "<<balance<<endl;
            }
            else{
                cout<<"You have reached your balance limit. Transaction failed."<<endl;
            }
        }
};
int CurrentAccount :: limit = -10000;
int main() {
    BankAccount* ptr1; 
    SavingsAccount sa;
    CurrentAccount ca;
    ptr1 = &sa;
    ptr1->balance = 1000;
    ptr1->deposit(100);
    ptr1->withdraw(10000);
    ptr1 = &ca;
    ptr1->balance = 1000;
    ptr1->deposit(100);
    ptr1->withdraw(100000);
    return 0;
}