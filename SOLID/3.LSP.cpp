//Lsp stands for Liskov Substitution Principle. It states that objects of a superclass should be replaceable with objects of a subclass without affecting the correctness of the program. In other words, if class S is a subclass of class T, then objects of type T in a program can be replaced with objects of type S without altering any of the desirable properties of that program (correctness, task performed, etc.).

#include<iostream>
using namespace std;

class DepositOnlyAccount {
    public:
    virtual void deposit(double amount) = 0;
};
class WithdrawableAccount : public DepositOnlyAccount {
    public:
    virtual void withdraw(double amount) = 0;
};
        
class SavingsAccount : public WithdrawableAccount {
    private:
    double balance;
    public:
    SavingsAccount() : balance(0) {}
    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
    }
    void withdraw(double amount) override {
        if(amount <= balance) {
            balance -= amount;
            cout << "Withdrew: " << amount << ", New Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds for withdrawal of: " << amount << endl;
        }
    }
};

class FixedDepositAccount : public DepositOnlyAccount {
    private:
    double balance;
    public:
    FixedDepositAccount() : balance(0) {}
    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
    }
    // No withdraw method, as fixed deposit accounts do not allow withdrawals
};
int main(){
    SavingsAccount savings;
    savings.deposit(1000);
    savings.withdraw(500);
    savings.withdraw(600); // Should show insufficient funds

    FixedDepositAccount fixedDeposit;
    fixedDeposit.deposit(2000);
    // fixedDeposit.withdraw(500); // This line would cause a compile-time error, as FixedDepositAccount does not have a withdraw method

    return 0;
}