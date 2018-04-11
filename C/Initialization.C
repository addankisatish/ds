#include<iostream>
#include<vector>
#include<initializer_list>
using namespace std;

class Test
{
public:
    Test(initializer_list<string> texts)
    {
        for(auto text:texts)
            cout << text << endl;
    }

    void print(initializer_list<int> numbers)
    {
        for(auto value : numbers)
            cout << value << endl;
    }
};

int main()
{
    int value{5};
    cout << value << endl; // 5

    string text{"Hi Everyone !!!"};
    cout << text << endl; // Hi Everyone !!!

    int myInts[]{1, 2, 3};
    cout << myInts[1] << endl; // 2

    int *pMyInts = new int[3]{1, 2, 3}; // Notice we need to define the size.
    cout << pMyInts[1] << endl; // 2
    delete[] pMyInts;

    int defInt{}; //Initializes to default value
    cout << defInt << endl; // 0

    int *pMyInt{&value};
    cout << *pMyInt << endl; // 5 

    int *pDefault{}; // Equivalent to int *pDefault = nullptr;
    cout << pDefault << endl; // 0

    struct
    {
       int age;
       string name;
    }s1{5, "Niru"};

    cout << s1.age << " " << s1.name << endl; // 5 Niru

    vector<string> numbers{"one", "two", "three"};
    cout << numbers[1] << endl; // two 

    Test test{"one", "two", "three"}; // one, two, three 
    test.print({1, 2, 3}); // 1, 2, 3
    
    return 0;
}
