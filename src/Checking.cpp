//
// Created by Dany Jacob on 24/5/20.
//

#include "Checking.h"
#include <iostream>

float Checking::minBal = 50;

Checking::Checking(const std::string &name, double balance) : Account(name, balance) {}

void Checking::withdraw(double amount) {
    if((balance - amount) > minBal)
        Account::withdraw(amount);
    else
        std::cout << "min balance shouldn't fall below " << minBal << std::endl;
}
