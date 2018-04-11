#include<iostream>
using namespace std;

class Student
{
    int age{5};
    string name{"Niru"};

public:
    Student() = default; // Generates default constructor
    
    Student(const Student &other) = default; // Default copy constructor

    Student& operator=(const Student &other) = delete;

    Student(int in_age): age(in_age) 
    {

    }

    void print() 
    {
        cout << age << " : " <<  name << endl;
    }
};

int main()
{
    Student s1;
    s1.print(); // 5 , Niru

    Student s2{10}; 
    s2.print(); // 10, Niru

    return 0;
}
