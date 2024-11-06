// Create a class "BankAccount" with attributes account number and
//  balance. Implement methods to deposit and withdraw funds,
//   and a display method to show the account details.


#include <iostream>
#include <string>

class BankAccount {
private:
    std::string account_number;
    double balance;

public:
    BankAccount(std::string acc_num, double initial_balance) :
     account_number(acc_num), balance(initial_balance) {}

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            std::cout << "Insufficient balance!" << std::endl;
        }
    }

    void display() {
        std::cout << "Account Number: " << account_number << std::endl;
        std::cout << "Balance: " << balance << std::endl;
    }
};

int main() {
    BankAccount account("123456789", 1000);
    account.deposit(500);
    account.withdraw(200);
    account.display();

    return 0;
}