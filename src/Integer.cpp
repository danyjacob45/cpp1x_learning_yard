//
// Created by Dany Jacob on 22/5/20.
//

#include "Integer.h"
#include <iostream>

int Integer::getValue() const {
    return *p_int;
}

void Integer::setValue(int value) {
    if(p_int != nullptr)
        *p_int = value;
    else {
       p_int = new int(value);
    }
}

Integer::~Integer() {
    delete p_int;
//    std::cout << "destructor invoked" << std::endl;
}

Integer::Integer(const Integer &obj) {
    p_int = new int(*obj.p_int);
    std::cout << "const Integer &obj" <<std::endl;
}

Integer::Integer(Integer &&obj) { //move constructor
    std::cout << "Integer(Integer &&obj) invoked" << std::endl;
    p_int = obj.p_int;
    obj.p_int = nullptr;

}

Integer Integer::operator +(const Integer &obj) const {
    //Integer temp;
    //*temp.p_int =
    return (Integer(*obj.p_int + *this->p_int));
}

Integer& Integer::operator++() {
    ++*p_int;
    return *this;
}

Integer Integer::operator++(int) {
    Integer temp(*this);
    ++(*p_int);
    return temp;
}

bool Integer::operator==(const Integer &obj) const {
    return (*this->p_int == *obj.p_int ? true : false);
    //return (*this->p_int == *obj.p_int);
}

Integer& Integer::operator=(const Integer &a) {
    if(this != &a){ //check for self assignment eg.a=a
        delete p_int; //clear left operand
        p_int = new int(*a.p_int);
    }
    return *this;
}

Integer & Integer::operator=(Integer &&a) {
    if(this != &a){ //check for self assignment eg.a=a
        delete p_int; //clear left operand
        p_int = a.p_int;
        a.p_int = nullptr;
    }
    return *this;
}

Integer::operator int() {
    return this->getValue();
}
