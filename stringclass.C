#include <string.h>
#include<iostream>
#include<memory>

using namespace std;

class MyString
{
    int size;
    char *buffer;

public:
    MyString() : size(0), buffer(nullptr)
    {
    }
    
    MyString(const char *inputStr) 
    {
        size = strlen(inputStr);
        buffer = new char[size + 1];
        strcpy(buffer, inputStr);
    }

    //
    // Copy Constructor
    //
    MyString(const MyString& other)
    {
        cout << "In copy constructor." << endl;
        size = other.size;
        buffer = new char[size + 1];
        strcpy(buffer, other.buffer);
    }

    //
    // Assignment operator
    //
    MyString& operator=(const MyString& other)
    {
        cout << "In assignment operator." << endl;
        //
        // Check for self assignment
        //
        if(this == &other)
            return *this;

        size = other.size;

        char *pOriginalString =  buffer;
        buffer = new char[size + 1];
        strcpy(buffer, other.buffer);

        delete[] pOriginalString;
        
        return *this;
    }

    //
    // Move constructor
    //
    MyString(MyString&& other)
    {
        cout << "In move constructor." << endl;
        size = other.size;
        buffer = other.buffer;

        other.size = 0;
        other.buffer = nullptr;
    }

    //
    // Move assignment
    //
    MyString& operator=(MyString&& other)
    {
        cout << "In move assignment operator." << endl;
        if( this == &other)
            return *this;

        //
        // Delete the original
        //
        size = 0;
        delete [] buffer;

        size = other.size;
        buffer = other.buffer;

        other.size = 0;
        other.buffer = nullptr;

    }

    ~MyString()
    {
        delete[] buffer;
    }

    int getLength() { return size; }

    char * getString() { return buffer; }

    MyString getNewString()
    {
        MyString temp(this->buffer);
        cout << "Returning temporary object." << endl;
        return temp;
    }

};

int main()
{
    // Calls default constructor
    MyString s1;

    // Calls parametrized constructor
    MyString s2("This is a string");
    cout << "S2 : " << s2.getString() << endl;

    // Calls copy constructor
    MyString s3(s2);
    cout << "S3 : " << s3.getString() << endl;

    // Calls assignment operator
    MyString s4;
    s4 = s3;
    cout << "S4 : " << s4.getString() << endl;

    // Calls move constructor
    MyString s5 = s4.getNewString();
    cout << "S5 : " << s5.getString() << endl;

    // Calls move assignment operator
    MyString s6;
    s6 = s5.getNewString();
    cout << "S6 : " << s5.getString() << endl;

    return 0;
}


#if 0

// To disable copy elision (Return value optimization)
g++ -std=c++11 -fno-elide-constructors stringclass.C
./a.out                                             
In copy constructor.
In assignment operator.
Returning temporary object.
In move constructor.
In move constructor.
Returning temporary object.
In move constructor.
In move assignment operator.


// Copy elision comes into picture here (Return value optimization)
g++ -std=c++11  stringclass.C                       
./a.out                      
In copy constructor.
In assignment operator.
Returning temporary object.
Returning temporary object.
In move assignment operator

#endif
