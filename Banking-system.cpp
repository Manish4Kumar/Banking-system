#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string accountHolderName;
    int accountNumber;
    double balance;

public:
    BankAccount(string name, int accNumber) {
        accountHolderName = name;
        accountNumber = accNumber;
        balance = 0.0;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount deposited successfully. Current balance: $" << balance << endl;
        } else {
            cout << "Invalid amount. Please deposit a positive value." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Amount withdrawn successfully. Current balance: $" << balance << endl;
        } else {
            cout << "Insufficient balance or invalid amount. Please check your balance or enter a valid amount." << endl;
        }
    }

    void displayBalance() {
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: $" << balance << endl;
    }
};

int main() {
    string name;
    int accNumber;
    double initialBalance;

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your account number: ";
    cin >> accNumber;

    cout << "Enter your initial balance: $";
    cin >> initialBalance;

    BankAccount myAccount(name, accNumber);
    myAccount.deposit(initialBalance);

    int choice;
    double amount;

    do {
        cout << "\n\n--- Banking System Menu ---" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Display Balance" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1/2/3/4): ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the amount to deposit: $";
            cin >> amount;
            myAccount.deposit(amount);
            break;
        case 2:
            cout << "Enter the amount to withdraw: $";
            cin >> amount;
            myAccount.withdraw(amount);
            break;
        case 3:
            myAccount.displayBalance();
            break;
        case 4:
            cout << "Thank you for using our banking system. Have a great day!" << endl;
            break;
        default:
            cout << "Invalid choice. Please choose a valid option." << endl;
        }
    } while (choice != 4);

    return 0;
}
