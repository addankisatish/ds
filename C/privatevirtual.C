#include<iostream>
using namespace std;

class Base
{
    virtual void func() 
    {
        cout << "Base func." << endl;
    }   
friend int main(); 
};

class Derived : public Base
{
public:
    void func()
    {
        cout << "Derived func." << endl;
    }
};

int main()
{
    Base *ptr = new Derived;
    ptr->func();

    return 0;
}

// Output: Derived func


