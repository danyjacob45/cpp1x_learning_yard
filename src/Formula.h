//
// Created by Dany Jacob on 21/5/20.
//

#ifndef FORMULA_H
#define FORMULA_H

class Formula {

private:
    int val1, val2;

public:
    int prod;
    Formula(int val1, int val2): val1(val1), val2(val2) {}
    Formula():val1(0),val2(0) {} //direct initialisation.
    static int bla(int arg1);
    int add(int a, int b);
    int product();

    int getVal1() const;

    void setVal1(int val1);

    int getVal2() const;

    void setVal2(int val2);
};


#endif //FORMULA_H

