#include<bits/stdc++.h>
using namespace std;

class Base{
    int x;
    int y;
    public:
    Base(){}
    Base(int a, int b): x(a), y(b) {}
    void setX(int a)  {x = a;}
    int getX() const { return x;} // if write x = 20 error since function //cannot change the value as it is a const function
};


int main(){
    Base* b = new Base(10,20);
    b->setX(30);
    cout<<b->getX()<<endl;
}