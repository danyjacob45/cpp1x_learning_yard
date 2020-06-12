//
// Created by Dany Jacob on 21/5/20.
//

#include "Formula.h"


int Formula::bla(int arg1) {
    return arg1 * 2;
}

int Formula::add(int a, int b) {
    //return 0;
    return a+b;
}

int Formula::product() {
    this->prod = val1*val2;
    return val1*val2;
}

int Formula::getVal1() const {
    return val1;
}

void Formula::setVal1(int val1) {
    Formula::val1 = val1;
}

int Formula::getVal2() const {
    return val2;
}

void Formula::setVal2(int val2) {
    Formula::val2 = val2;
}
