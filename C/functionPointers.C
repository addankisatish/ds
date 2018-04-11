#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

// Returns True if the length of string is 3.
bool match(string test)
{
    return test.size() == 3;
}

int my_count_if(vector<string> & texts, bool (*match)(string))
{
    int count = 0;
    for(int i = 0; i < texts.size(); i++)
    {
        if(match(texts[i]))
            count++;     
    }     
    return count;
}

int main()
{
    vector<string> texts;
    texts.push_back("one");
    texts.push_back("two");
    texts.push_back("three");
    texts.push_back("four");
    texts.push_back("five");
    texts.push_back("six");
    texts.push_back("seven");
    texts.push_back("eight");
    texts.push_back("nine");
    texts.push_back("ten");

    // count_if algorithm
    cout << count_if(texts.begin(), texts.end(), match) << endl;

    cout << my_count_if(texts, match) << endl;
    return 0;
}
