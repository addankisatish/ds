#include <iostream>
using namespace std;

class Base
{
public:
    Base() { cout << "Constructing base." << endl; }
    ~Base() { cout << "Destructing base." << endl; }
};

class Derived : public Base
{
public:
    Derived() { cout << "Constructing derived." << endl; }
    ~Derived() { cout << "Destructing derived." << endl; }
};

int main()
{
    Derived *d = new Derived();
    Base *b = d;
    
    delete b;
    return 0;
}

/*
 * O/P: 
 *
 * Constructing base
 * Constructing derived
 * Destructing base
 *
 * Deleting a derived class object using a pointer to a base class that has a
 * non-virtual destructor results in undefined behaviour.
 *
 * Making base class destructor virtual gaurantees that the object of the derived class
 * is destructed properly. i.e both the base class and derived class destructors will be called.
 *
 */
