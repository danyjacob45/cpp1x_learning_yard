//
// Created by Dany Jacob on 24/5/20.
//

#ifndef FIRSTPROGRAM_CHECKING_H
#define FIRSTPROGRAM_CHECKING_H
#include "Account.h"

class Checking : public Account {

    static float minBal;
public:
    Checking(const std::string &name, double balance);

    void withdraw(double amount) override;


public:

};


#endif //FIRSTPROGRAM_CHECKING_H
