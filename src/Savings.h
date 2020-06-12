//
// Created by Dany Jacob on 24/5/20.
//

#ifndef FIRSTPROGRAM_SAVINGS_H
#define FIRSTPROGRAM_SAVINGS_H
#include "Account.h"

class Savings : public Account{
public:
    Savings(const std::string &name, double balance, float m_Rate);
    virtual ~Savings();

    float getInterestRate() const override ;
    void accumulateInterest() override ;


private:
    float m_Rate;

};


#endif //FIRSTPROGRAM_SAVINGS_H
