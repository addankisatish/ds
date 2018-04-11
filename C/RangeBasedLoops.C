#include<iostream>
#include<vector>
#include<list>
using namespace std;

int main()
{
    auto texts = {"one", "two", "three"};

    for(auto text: texts)
    {
        cout << text << endl;
    }

    vector<int> numbers{25, 50, 75};
    for(auto number: numbers)
    {
        cout << number << endl;
    }

    string text = "Hello";
    for(auto c: text)
    {
        cout << c;
    }
    cout << endl;

    list<int> list_numbers{5, 15, 25, 35};
    for(auto number : list_numbers)
    {
        cout << number << endl;
    }
    
    return 0;
}
