#include<iostream>
using namespace std;

//
// In C++, a derived class object can be assigned to a base class object.
// OBJECT SLICING happens when a derived class object is assigned to a
// base class object, additional attributes of a derived class object
// are sliced off to form the base class object.
//

class Base
{
protected:
   int i;

public:
   Base(int a) : i(a)
   {
   }

   virtual void display()
   {
       cout << "I am base class object i = " << i << endl;
   }
};

class Derived: public Base
{
   int j;

public:
   Derived(int a, int b) : Base(a)
   {
       j = b;
   }

   virtual void display()
   {
       cout << "I am derived class object i = " << i << "  j = " << j << endl;
   }
};

void someFunc(Base obj)
{
    obj.display();
}

//
// Object slicing doesn't occur when pointers or references to objects
// are passed as function arguments, since thhe pointer or reference of any type
// takes same amount of memory.
//
void someFunc1(Base& obj)
{
    obj.display();
}

int main()
{
    Base b(33);
    Derived d(45, 54);

    someFunc(b);
    someFunc(d);

    someFunc1(b);
    someFunc1(d);
}

//
// [saddanki@saddanki-dev] g++ objectSlicing.C
// [saddanki@saddanki-dev] ./a.out 
// I am base class object i = 33
// I am base class object i = 45
// I am base class object i = 33
// I am derived class object i = 45  j = 54
//
