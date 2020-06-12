//
// Created by Dany Jacob on 22/5/20.
//
#pragma once
#ifndef FIRSTPROGRAM_CAR_H
#define FIRSTPROGRAM_CAR_H


class Car {

    float fuel{0};
    int speed{5};
    int passengers{10};

    static int total;

public:
    Car();
    Car (float amount); //with specific fuel.
    Car (float, int); //with fuel and passengers
    ~Car();
    void FillFuel(float amount);
    void Accelerate();
    void Brake();
    void AddPassengers(int);
    void Dashboard();
    int getPassengers() const;

    static int getTotalCars();
};


#endif //FIRSTPROGRAM_CAR_H
