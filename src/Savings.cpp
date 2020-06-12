//
// Created by Dany Jacob on 24/5/20.
//

#include "Savings.h"

Savings::Savings(const std::string &name,
                 double balance,
                 float m_Rate) : Account(name, balance), m_Rate(m_Rate) {

}

Savings::~Savings() {

}

float Savings::getInterestRate() const {
    return m_Rate; //return a constant now.
}

void Savings::accumulateInterest() {
    balance += balance * m_Rate;
}

