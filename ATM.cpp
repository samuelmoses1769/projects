#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Account {
private:
    int accountNumber;
    int balance;
    int pin;
public:
    // Constructor
    Account(int accNum, int initialBalance, int pin) : accountNumber(accNum), balance(initialBalance), pin(pin) {}

    // Accessors
    int getAccountNumber() { return accountNumber; }
    int getBalance() { return balance; }
    int getPIN() { return pin; }

    // Mutators
    void deposit(int amount) { balance += amount; }
    bool withdraw(int amount) {
        if (balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }
};

class ATM {
private:
    vector<Account> accounts;
public:
    void authenticateUser() {
        int accountNumber, pin;
        cout << "Enter account number: ";
        cin >> accountNumber;
        cout << "Enter PIN: ";
        cin >> pin;

        for (Account &acc : accounts) {
            if (acc.getAccountNumber() == accountNumber && acc.getPIN() == pin) {
                // Valid user
                performTransactions(acc);
                return;
            }
        }
        // Invalid credentials
        cout << "Invalid account number or PIN." << endl;
    }

    void performTransactions(Account& acc) {
        while (true) {
            cout << "\n1. Check Balance\n2. Deposit\n3. Withdraw\n4. Exit\nEnter your choice: ";
            int choice;
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Current balance: " << acc.getBalance() << endl;
                    break;
                case 2:
                    int depositAmount;
                    cout << "Enter amount to deposit: ";
                    cin >> depositAmount;
                    acc.deposit(depositAmount);
                    cout << "Deposit successful. New balance: " << acc.getBalance() << endl;
                    break;
                case 3:
                    int withdrawAmount;
                    cout << "Enter amount to withdraw: ";
                    cin >> withdrawAmount;
                    if (acc.withdraw(withdrawAmount)) {
                        cout << "Withdrawal successful. New balance: " << acc.getBalance() << endl;
                    } else {
                        cout << "Insufficient balance." << endl;
                    }
                    break;
                case 4:
                    return;
                    
                default:
                    cout << "Invalid choice." << endl;
            }
        }
    }

    void addAccount(Account acc) {
        accounts.push_back(acc);
    }
};

int main() {
    Account acc1(123456, 1000, 1234); // Account number, initial balance, PIN
    Account acc2(987654, 500, 4321);
    
    ATM atm;
    atm.addAccount(acc1);
    atm.addAccount(acc2);

    while (true) {
        cout << "\nWelcome to the ATM\n";
        atm.authenticateUser();
    }

    return 0;
}
