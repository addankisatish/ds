#include<iostream>
#include<typeinfo>
using namespace std;

extern "C"
{
int printf(const char *format, ...);
}

int main()
{
    int value;
    cout << typeid(value).name() << endl;
    float value1;
    cout << typeid(value1).name() << endl;
    double value2;
    cout << typeid(value2).name() << endl;
    string value3;
    cout << typeid(value3).name() << endl;

    decltype(value3) value4 = "bob"; //Decltype can be used in declaring the variables from the other variables.
    cout << typeid(value4).name() << endl;
    cout << value4 << endl;   

    //
    // C++ supports function overloading i.e. there can be more than one function with the same name but difference
    // in parameters. How does C++ compiler differentiates between different functions when it generates a object code ?
    // It changes names by adding information about arguments.  This technique of adding additional information to function
    // names is called "Name Mangling". 
    //
    // When some code is put in "extern C" block, the C++ compiler ensures that the function names are not mangled - i.e. the    // compiler emits the binary file with their names unchanged, as a C compiler would do.
    printf("GeeksforGeeks.\n");
    return 0;
}
