#include <iostream>

using namespace std;

//CRTP static interface example

template <typename T>
class Amount {
public:
    double getValue() const {
        return static_cast<T const&>(*this).getValue();
    }
    
};

//constant
class Constant42 : public Amount<Constant42> {
public:
    double getValue() const {return 42; };

};

//variable
class Variable : public Amount<Variable> {
public:
    explicit Variable(double value) : value_(value) {}
    double getValue() const { return value_; }

private:
    double value_;
};

template <typename T>
void print(Amount<T> const& amount) {
    cout << amount.getValue() << '\n';
}


int main() {
    Constant42 c42;
    print(c42);
    Variable v(34);
    print(v);

    return 0;
}




// template <typename T>
// class NumericalFunctions {
// public:
//     void scale(double multiplicator) {
//         T& underlying = static_cast<T&>(*this);
//         underlying.setValue(underlying.getValue()*multiplicator);
//     }
//     void square();
//     void setToOpposite();
// };



// class Sensitivity : public NumericalFunctions<Sensitivity> {
// public:
//     double getValue();
//     void setValue();
//     //other interfaces
// };
