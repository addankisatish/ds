#include<iostream>
using namespace std;

// A derived class virtual function is considered an override
// if its signature and return types match exactly.
//
// Override
// --------
// To help address the issue of functions that are meant to be overrides but aren't,
// c++11 introduced the overide specifier. Override can be applied to any override function by placing
// the specifier in the same place const would go. If the function does not override a base class function,
// the compiler will flag the function as an error.
//
//
// Final
// -----
// There may be cases where we don't want to override a virtual function or inherit from a class.
// the final specifier can be used to tell the compiler to enforce this.
//
class A
{
public:
    virtual const char* getName1(int x) { return "A"; }
    virtual const char* getName2(int x) { return "A"; }
    virtual const char* getName3(int x) { return "A"; }
};

class B : public A
{
public:
    virtual const char* getName1(short int x) override { return "B";} // parameter is short int. Compilation error
    virtual const char* getName2(int x) const override { return "B"; } // function is const. Compilation error
    virtual const char* getName3(int x) override { return "B"; } 
     
};

class AA
{
public:
    virtual const char *getName() { return "AA"; }
};

class BB : public AA
{
public:
    virtual const char *getName() override final { return "BB"; }
};

class CC final : public BB
{
public:
    virtual const char *getName() override { return "CC"; } // Compilation error: Cannot override final function
};

class DD : public CC //compilation error, cannot inherit from final class.
{
public:
    virtual const char *getName() override { return "DD"; } 
};

int main()
{
    B b;
    A &rBase = b;

    // Because B::getName1() takes a different parameter, it's not considered an override of A::getName1()
    cout << rBase.getName1(1) << endl;
    cout << rBase.getName2(2) << endl;
    cout << rBase.getName3(3) << endl;

    return 0;
}
