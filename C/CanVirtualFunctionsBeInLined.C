#include<iostream>
using namespace std;

//
//  Whenever virtual function is called using base class reference or pointer
//  it cannot be inlined ( because call is resolved at runtime).
//
//  However whenever it is called using the object of that class, it can be inlined
//  because compiler knows the exact class of the object at compile time.
//

class Base
{
public:
    inline virtual void who()
    {
        cout << "I am Base." << endl;
    }
};

class Derived: public Base
{
public:
    virtual void who()
    {
        cout << "I am Derived." << endl;
    }
};

int main()
{
    Base b;
    b.who(); // who() is called through object of the class. It is resolved at compile time and so it can be inlined.

    Base *ptr = new Derived();
    ptr->who(); //who() is called through pointer. So, it cannot be inlined.
}
