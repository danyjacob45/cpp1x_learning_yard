//
// Created by Dany Jacob on 23/5/20.
//
#pragma once
#include "Integer.h"
#ifndef FIRSTPROGRAM_INTPTR_H
#define FIRSTPROGRAM_INTPTR_H


class IntPtr {
    Integer *m_p;

public:
    IntPtr(Integer *p): m_p(p) {
        //m_p = nullptr;
    }
    ~IntPtr() {
        delete m_p;
    }
    Integer * operator ->();
    Integer & operator *();

};


#endif //FIRSTPROGRAM_INTPTR_H
