//
// Created by Dany Jacob on 22/5/20.
//

#include "Car.h"
#include <iostream>
#include <iomanip>
void Foo(const Car &car);

int Car::total = 0;

Car::Car() : Car(0) {
    //delegate constructor applied
    std::cout << "Car()" << std::endl;
}

Car::Car(float amount) : Car(amount, 0) {
    //delegate constructor applied
    std::cout << "Car(float amount)" << std::endl;
}

Car::Car(float amount, int pass) {
    std::cout << "Car(float amount, int pass)" << std::endl;
    ++total;
    fuel = amount;
    passengers = pass;
    speed = 0;
}

void Car::FillFuel(float amount) {
    fuel = amount;

}

void Car::Dashboard() {
    std::cout << "Fuel: " << std::fixed << std::setprecision(2) << fuel << std::endl;
    std::cout << "passengers: " << passengers << std::endl;
    std::cout << "speed: " << speed << std::endl;
    std::cout << "total cars: " << total << std::endl;
}

void Car::Accelerate() {
    this->speed++;
    this->fuel -= 0.5f;

}

void Car::Brake() {
    speed--;
    fuel -=0.2;
}

void Car::AddPassengers(int count) {
    passengers = count;
    Foo(*this);
}

void Foo(const Car &car){
    std::cout << "passengers:....print from Foo: " << car.getPassengers() << std::endl;

}

int Car::getPassengers() const {
    return this->passengers;
}

int Car::getTotalCars() {
    return total;
}

Car::~Car() {
    total--;
    std::cout << "car destructor called" << std::endl;
}
