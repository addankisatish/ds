#include<iostream>
using namespace std;

/*
 * A singleton pattern ensures that a class has only one instance
 * and provides a global point of access to that instance.
 *
 * Checklist:
 * ---------
 *  1. define a private static attribute in the class.
 *  2. define a public static accessor function in the class.
 *  3. Do "lazy initiliazation" (creation on first use) in accessor function.
 *  4. Define all constructors to be protected or private.
 *  5. clients may only use the accessor function to manipulate the system.
 *
 */

class StringSingleton
{
public:
    std::string Getstring() const
    {
        return mString;
    }

    void setString(const std::string &newStr)
    {
        mString = newStr;
    }

    static StringSingleton &getInstance()
    {
        static StringSingleton *instance = new StringSingleton;
        return instance;
    }
private:
    StringSingleton() {}
    
    StringSingleton(const StringSingleton &old);  // disallow copy constructor
   
    const StringSingleon& operator= (const StringSingleton &old); //disallow assignment operator

    ~StringSingleton() {}

private:
    std::string mString;
}


