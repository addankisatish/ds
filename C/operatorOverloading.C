#include<iostream>
using namespace std;

class ComplexNumber
{
    int realPart;
    int imaginaryPart;

public:
    ComplexNumber(int real, int img) : realPart(real), imaginaryPart(img)
    { 
    }
    
    //
    // Overloading += 
    // The rhs should never be changed, so it should be const reference.
    // The return type should be just a reference. It should not be a const reference
    // or a value. ( a += b) += c; should work just like built in types.
    // This will work only if we return reference and not const reference.
    // (a.operator+=(b)).opreator+=(c);
    // const reference is not possible as const object cannot be modified.
    // chained operation would fail it it had been const reference.
    //
    ComplexNumber& operator+=(const ComplexNumber& rhs)
    {
        this->realPart += rhs.realPart;
        this->imaginaryPart += rhs.imaginaryPart;
        return *this;
    }

    //
    // Overloading + (c = a + b)
    // It is defined as const function as the lhs of the operator(a) is not modified.
    // The rhs(b) also should never be changed, so it should be const reference.
    // The return type cannot be a reference and a non-const.
    // ( a + b ) = d; should not work.
    // If we have returned a non const object, the above would have worked just fine.
    // We cannot return a reference as we are returning a stack variable.
    //
    const ComplexNumber operator+(const ComplexNumber &rhs) const
    {
        ComplexNumber result(this->realPart + rhs.realPart,
                             this->imaginaryPart + rhs.imaginaryPart);

        return result;
    }

    // 
    // Overloading ++ and -- operators.
    // ++a = b; is a valid statement for built-in types.
    //
    ComplexNumber& operator++() //pre-increment
    {
        this->realPart++;
        this->imaginaryPart++;
        return *this;
    }
    ComplexNumber& operator--() //pre-increment
    {
        this->realPart--;
        this->imaginaryPart--;
        return *this;
    }
    //
    // a++++ is invalid and statements like this do not compile.
    //
    const ComplexNumber operator++(int)
    {
       ComplexNumber result(this->realPart, this->imaginaryPart);
       this->realPart++;
       this->imaginaryPart++;
       return result; 
    }
    const ComplexNumber operator--(int)
    {
       ComplexNumber result(this->realPart, this->imaginaryPart);
       this->realPart--;
       this->imaginaryPart--;
       return result; 
    }

    //
    // ComplexNumber& opeartor=(const ComplexNumber &rhs);
    //
    // The return type is not const ComplexNumber& because (a = b) = c will not work.
    // 1. check for self-assignment.
    // 2. Deallocate any memory that is being used currently.
    // 3. Allocate the memory to hold the contents of the rhs.
    // 4. copy the values from rhs into the instance.
    // 5. return *this
    //
    friend ostream& operator<< (ostream &s, const ComplexNumber &c);
    friend istream& operator>> (istream &s, ComplexNumber &c);

    void setRealPart(int real) { realPart = real; }
    void setImaginaryPart(int img) { imaginaryPart = img; }
    int getRealPart() { return realPart; }
    int getImaginaryPart() { return imaginaryPart; }
};

ostream& operator<< (ostream &outputStream, const ComplexNumber &c)
{
    outputStream << "real = " << c.realPart << " imaginary = " << c.imaginaryPart << endl;
    return outputStream;
}

istream& operator>> (istream &inputStream, ComplexNumber &c)
{
    inputStream >> c.realPart >> c.imaginaryPart;
    return inputStream;
}

int main()
{
    return 0;
}

