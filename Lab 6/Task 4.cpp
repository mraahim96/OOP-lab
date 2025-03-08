#include <iostream>
#include <string>
using namespace std;

class Account{
protected:
    int accountNumber;
    float balance;
public:
    Account(int acc,float bal):accountNumber(acc),balance(bal){}
    virtual void displayDetails(){
        cout<<"Account Number:"<<accountNumber<<endl;
        cout<<"Balance:"<<balance<<endl;
    }
    virtual ~Account(){}
};

class SavingsAccount:public Account{
private:
    float interestRate;
public:
    SavingsAccount(int acc,float bal,float rate):Account(acc,bal),interestRate(rate){}
    void displayDetails()override{
        Account::displayDetails();
        cout<<"Interest Rate:"<<interestRate<<"%"<<endl;
    }
};

class CheckingAccount:public Account{
private:
    float ovl;
public:
    CheckingAccount(int acc,float bal,float limit):Account(acc,bal),ovl(limit){}
    void displayDetails()override{
        Account::displayDetails();
        cout<<"Overdraft Limit:"<<ovl<<endl;
    }
};

int main(){
    int accnum;
    float balance,interestRate,overdraftLimit;
    cout<<"Enter Savings Account details:\n";
    cout<<"Account Number:";
    cin>>accnum;
    cout<<"Balance:";
    cin>>balance;
    cout<<"Interest Rate in %:";
    cin>>interestRate;
    SavingsAccount savings(accnum,balance,interestRate);
    cout<<"\nEnter Checking Account details:\n";
    cout<<"Account Number:";
    cin>>accnum;
    cout<<"Balance:";
    cin>>balance;
    cout<<"Overdraft Limit:";
    cin>>overdraftLimit;
    CheckingAccount checking(accnum,balance,overdraftLimit);
    cout<<"\nSavings Account Details:\n";
    savings.displayDetails();
    cout<<"\nChecking Account Details:\n";
    checking.displayDetails();
}
