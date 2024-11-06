#include <iostream>
using namespace std;

class Base {
public:
    // Pure virtual destructor
    virtual ~Base() = 0; // Pure virtual destructor

    // Virtual function to demonstrate polymorphism
    virtual void show() {
        cout << "Base class" << endl;
    }
};

Base::~Base() {
    // Definition of pure virtual destructor (must be provided)
    cout << "Base class destructor called!" << endl;
}

class Derived : public Base {
public:
    ~Derived() override {
        cout << "Derived class destructor called!" << endl;
    }

    void show() override {
        cout << "Derived class" << endl;
    }
};

int main() {
    Base* basePtr = new Derived();
    basePtr->show();
    delete basePtr; // Properly calls the Derived and Base destructors
    return 0;
}
