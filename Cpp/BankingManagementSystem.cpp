#include<iostream>
#include<vector>
using namespace std;

class BankAccount {
    private:
        string accountHolder;
        int accountNumber;
        double balance;

    public:

        BankAccount(string name, int accNumber, double initialBalance) {
            accountHolder = name;
            accountNumber = accNumber;
            balance = initialBalance;

        }

        void Deposit(double amount) {
            if(amount > 0) {
                balance += amount;
                cout<<"Deposit successful! New Balance: "<<balance <<endl;

            }else {
                cout<< "Invalid deposit amount!"<<endl;
            }
        }

        void withdraw(double amount) {
            if(amount > 0 && amount <= balance) {
                balance -= amount;
                cout<<"Withddrawl successful! New Balance: "<<balance <<endl;
            }else {
                cout<<"Insufficient balance or invalid amount!"<<endl;
            }
        }

        void displayAccount() const{
            cout<<"\nAccount Holder: "<<accountHolder<<endl;
            cout<<"Account Number: "<<accountNumber<<endl;
            cout<<"Balance: "<<balance <<endl;
        }

        int getAccountNumber() const {
            return accountNumber;
        }
};

class Bank {
    private:
        vector<BankAccount> accounts;

    public:

        void createAccount() {
            string name;
            int accNumber;
            double initalBalance;

            cout<<"Enter account holder name: ";
            cin.ignore();
            getline(cin , name);
            cout<<"Enter account Number: ";
            cin >> accNumber;
            cout<< "Enter initial Balance: ";
            cin >> initalBalance;

            BankAccount newAccount(name, accNumber, initalBalance);
            accounts.push_back(newAccount);
            cout<<"Account created successfully!\n";

        }

        BankAccount* findAccount(int accNumber) {
            for(auto &acc : accounts) {
                if(acc.getAccountNumber() == accNumber) {
                    return &acc;
                }
            }
            return nullptr;
        }

        void depositMoney() {
            int accNumber;
            double amount;
            cout<<"Enter account number: ";
            cin>> accNumber;

            BankAccount* account = findAccount(accNumber);
            if(account) {
                cout<<"Enter deposit amount: ";
                cin>> amount;
                account -> Deposit(amount);
            }else {
                cout<<"Account not found!\n";
            }
        }

        void withdrawMoney() {
            int accNumber;
            double amount;
            cout<< "Enter account Number: ";
            cin>> accNumber;

            BankAccount* account = findAccount(accNumber);
            if(account) {
                cout<< "Enter withdrawl amount: ";
                cin >> amount;
                account-> withdraw(amount);
            }else {
                cout<< "Account not found!\n";
            }
        }

        void displayAccountDetails() {
            int accNumber;
            cout<< "Enter account number: ";
            cin >> accNumber;

            BankAccount* account = findAccount(accNumber);
            if(account) {
                account-> displayAccount();
            }else{
                cout<<"Account not found!\n";
            }
        }
};

int main()
{
    Bank bank;
    int choice;

    while(true) {
        cout<< "\n ==== Banking Management System ===\n";
        cout<< "1. Create Account"<<endl;
        cout<< "2. Deposit Money "<<endl;
        cout<< "3. Withdraw Money"<<endl;
        cout<< "4. View Account Details"<<endl;
        cout<< "5. Exit"<<endl;
        cout<<"Enter your choice:";
        cin>>choice;

        switch (choice)
        {
        case 1:
            bank.createAccount();
            break;
        case 2:
            bank.depositMoney();
            break;
        case 3:
            bank.withdrawMoney();
            break;
        case 4:
            bank.displayAccountDetails();
            break;
        case 5:
            cout<<"Thank you for using our Banking System!"<<endl;
            return 0;
        default:
            cout<< "Invalid choice! Please try again."<<endl;
            break;
        }
    }

}