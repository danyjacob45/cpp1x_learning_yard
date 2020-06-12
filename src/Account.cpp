//
// Created by Dany Jacob on 24/5/20.
//

#include "Account.h"
#include <iostream>

//internal prototypes
void displayMessage(std::string message);

//static
int Account::accNumGenerator = 100;

Account::Account(const std::string &name, double balance) : name(name), balance(balance) {
    acc_num = ++accNumGenerator;
}
Account::Account() {

}
//class member functions
const std::string &Account::getName() const {
    return name;
}

double Account::getBalance() const {
    return balance;
}

int Account::getAccNum() const {
    return acc_num;
}

void Account::accumulateInterest() {

}

void Account::withdraw(double amount) {
    if(amount < balance)
        balance-=amount;
    else displayMessage("insufficient balance");
}

void Account::deposit(double amount) {
    balance+=amount;

}

float Account::getInterestRate() const {
    return 0;
}

void displayMessage(std::string message){
    std::cout << message << std::endl;
}
