#include<iostream>
#include<typeinfo>
using namespace std;

auto test() -> int    // trailing return types
{
    return 100;
}

// Trailing return types will be very useful for template functions.
template<class T>
auto test1(T value) -> decltype(value)
{
    return value;
}

template<class T, class S>
auto test2(T value1, S value2) -> decltype(value1 + value2)
{
    return value1 + value2;
}

int get()
{
    return 1234;
}

auto test3() -> decltype(get())
{
    return get();
}

int main()
{
    auto value = 7;
    cout << typeid(value).name() << ":" << value << endl;

    cout << test() << endl;
    
    cout << test1(45) << endl;
    cout << test1("Hello") << endl;

    cout << test2(5, 6) << endl;
    cout << test2(50, 70.5) << endl;
    cout << test2(2, "Hello") << endl; // Compiles without error

    cout << test3() << endl;
    return 0;
}
