#include <iostream>

using namespace std;

class BankAccount
{
private:
    static int count;
    int ID;
    int balance;

public:
        BankAccount() //Defualt
    {
        balance = 0;
        count++;
        ID = count;
    }
    BankAccount(int amount) //parameteraized
    {
        balance = amount;
        count++;
        ID = count;
    }
    BankAccount(const BankAccount &obj) //copy
    {
        this->balance = obj.balance;
        count++;
        ID = count;
    }
    void displayBalance()
    {
        cout << "Balance" << this->ID << "$" << balance << endl;
    }
    void deductBalance(int deduction)
    {
        this->balance = balance - deduction;
    }
};
int BankAccount::count = 0;

int main()
{
    BankAccount account1;
    cout<<"Welcome To My Bank"<<endl;
    acc1.displayBalance();

    BankAccount account2(1000);
    acc2.displayBalance();

    BankAccount account3(account2);
    acc3.displayBalance();
    acc3.deductBalance(200);
    acc3.displayBalance();
    acc2.displayBalance();
    return 0;
}
