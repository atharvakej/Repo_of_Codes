#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Car {
public:
    int speed;

    Car(int s) : speed(s) {} // Parameterized constructor

    Car(const Car &car) { // Copy constructor
        speed = car.speed;
        std::cout << "Car copied with speed of " << speed << std::endl;
    }
};

int main() {
    Car car1(120);
    Car car2 = car1; // Calls the copy constructor
    cout<<car1.speed<<endl;
}
