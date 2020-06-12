//
// Created by Dany Jacob on 22/5/20.
//
#pragma once
#ifndef FIRSTPROGRAM_INTEGER_H
#define FIRSTPROGRAM_INTEGER_H
#include <iostream>

class Integer {
    int *p_int;

public:
    Integer() : p_int(new int(0)) {std::cout << "Integer()\n";}
    Integer(int value): p_int(new int(value)) {std::cout << "Integer(int value)\n";}
    Integer(const Integer &obj); //copy constructor
    Integer(Integer &&obj); //move constructor

    int getValue() const;
    void setValue(int value);

    //operator overloading
    Integer operator + (const Integer &obj) const;
    Integer& operator ++(); //prefix
    Integer operator ++(int); //postfix
    bool operator == (const Integer &obj) const;
    Integer& operator =(const Integer &a); //assignment constructor
    Integer& operator =(Integer &&a);
    explicit operator int();

    ~Integer();

    friend class friendOfInteger;
};

class friendOfInteger {

};


#endif //FIRSTPROGRAM_INTEGER_H
