//
// Created by Dany Jacob on 24/5/20.
//

#ifndef FIRSTPROGRAM_ACCOUNT_H
#define FIRSTPROGRAM_ACCOUNT_H
#include <string>

class Account {
public:
    Account();

    Account(const std::string &name, double balance);

    virtual ~Account() {

    }
    const std::string &getName() const;
    double getBalance() const;
    int getAccNum() const;

    virtual float getInterestRate() const;
    virtual void accumulateInterest();
    virtual void withdraw(double amount);

    void deposit(double amount);

protected:
    double balance;

private:
    std::string name;
    int acc_num;
    static int accNumGenerator;
};


#endif //FIRSTPROGRAM_ACCOUNT_H
