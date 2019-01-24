#include<iostream>
using namespace std;

class Complex
{
    double real;
    double imag;

public:

    explicit Complex(double r=0.0, double i=0.0) : real(r), imag(i)
    {
    }

    bool operator==(Complex &rhs)
    {
        return (real == rhs.real && imag == rhs.imag) ? true : false;
    }
};

int main()
{
    Complex c1(3.0, 0.0);
    if( c1 == (Complex)3.0)
    {
        cout << "Same." << endl;
    }
    else
    {
        cout << "Not same." << endl;
    }
}

//
// In C++, if a class has a constructor which can be called with a single argument
// then this constructor becomes conversion constructor because such a constructor
// allows conversion of single argument to the class being constructed.
//
// We can avoid such implicit conversions as they may lead to unexpected results.
// We can make the constructor explicit with the help of explicit keyword.
//
// We can still typecast the double values to Complex, but now, we have
// to explicitly typecase it.
