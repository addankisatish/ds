#include<iostream>
#include<string>
using namespace std;

class Dog
{
    int age;
    string name;
public:
    Dog() 
    {
        age = 3;
        name = "buddy";
    }
    void setAge(int &a) 
    { 
        cout << "Inside setAge with reference." << endl;
        age = a; 
    }
    void setAge(const int &a) 
    { 
        cout << "Inside setAge with const reference." << endl;
        age = a; 
    }

    const string& getName() { return name; }

    // const function.
    // This mean this function cannot change any member variables of this class.
    // Also the const function cannot call the non-const function.
    // The const function can only call another const function to maintain const-correctness.
    void printName() const
    {
        cout << name <<  "  const version." << endl;
    }

    void printName() 
    {
        cout << name <<  "  non-const version." << endl;
    }

    int getAge() { return age;}
};

int main()
{
    Dog d;
    int i = 3;
    d.setAge(i);
    cout << d.getAge() << endl;
    d.setAge(4);
    cout << d.getAge() << endl;

    const string& name = d.getName();
    cout << name << endl;

    d.printName();

    const Dog d1;
    d1.printName();

}

