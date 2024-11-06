// CPP Program to demonstrate the use of copy constructor
// and assignment operator
#include <iostream>
#include <stdio.h>
using namespace std;

class Test {
public:
    int p;
    Test(int a) {p=a;}
    Test() {}
    Test(const Test& t)
    {
        cout << "Copy constructor called " << endl;
    }

    // Test& operator=(const Test& t)
    // {
    //     cout << "Assignment operator called " << endl;
    //     return *this;
    // }
};

// Driver code
int main()
{
    Test t1(4), t2;
    t2 = t1;
    cout<<t1.p<<endl;
    cout<<t2.p<<endl;
    Test t3 = t1;
    cout<<"B"<<endl;
    getchar();
    return 0;
}
