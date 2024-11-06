#include <iostream>
using namespace std;

class Base {
public:
    // Virtual Destructor
    virtual ~Base() {
        cout << "Base Destructor called!" << endl;
    }
};

class Derived : public Base {
public:
    // Destructor of Derived class
    ~Derived() {
        cout << "Derived Destructor called!" << endl;
    }
};

int main() {
    Base* basePtr = new Derived(); // Base pointer to Derived object
    delete basePtr;  // Deletes the Derived object
    return 0;
}
