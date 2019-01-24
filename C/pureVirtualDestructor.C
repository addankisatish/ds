#include<iostream>
using namespace std;

//
// Yes, it is possible to have pure virtual destructor.
//
// Pure virtual destructor are legal and one of the most important thing
// is that if class contains pure virtual destructor, it MUST provide
// a unction body for the pure virtual destructor.
//
// Destructors are always called in the reverse order. If definition of
// the pure virtual destructor is not provided then what function body will be called
// during object destruction ?
//
// Therefore compiler and linker enforce existance of function body for
// pure virtual destructor.
//

class Base
{
public:
    virtual ~Base() = 0;
};

//
//solution to avoid compiler error
// We have to provide function body for the pure virtual destructor.
// Note: Class becomes abstract when it contains pure virtual destructor.
//
Base::~Base()
{
    cout << "Pure virtual destructor is called." << endl;
}

class Derived  : public Base
{
public:
    ~Derived()
    {
        cout << "Derived is destructed." << endl; 
    }
};

int main()
{
    Base *ptr = new Derived();
    delete ptr;
}


//
// output:
// -------
// [saddanki@saddanki-dev] g++ pureVirtualDestructor.C 
// /tmp/ccTdyU9Q.o: In function `Derived::~Derived()':
// pureVirtualDestructor.C:(.text._ZN7DerivedD2Ev[_ZN7DerivedD5Ev]+0x3c): undefined reference to `Base::~Base()'
// pureVirtualDestructor.C:(.text._ZN7DerivedD2Ev[_ZN7DerivedD5Ev]+0x65): undefined reference to `Base::~Base()'
// collect2: error: ld returned 1 exit status
//
