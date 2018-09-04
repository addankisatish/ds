#include<iostream>
#include<queue>
using namespace std;

void maxElements(vector<int>& input, int num_elements)
{
    priority_queue<int> myQueue;
    for(auto element: input)
    {
        myQueue.push(element);
    }

    int i = 0;
    while((!input.empty()) && (i < num_elements))
    {
        cout << myQueue.top() << " ";
        i++;
        myQueue.pop();
    }
    cout << endl;
}

void minElements(vector<int>& input, int num_elements)
{
    priority_queue<int, vector<int>, greater<int>> myQueue;
    for(auto element: input)
    {
        myQueue.push(element);
    }

    int i = 0;
    while((!input.empty()) && (i < num_elements))
    {
        cout << myQueue.top() << " ";
        i++;
        myQueue.pop();
    }
    cout << endl;
}


int main()
{
    vector<int> array = {100, 10, 500, 200, 20, 150};
    for(auto x : array)
        cout << x << " ";
    cout << endl;

    maxElements(array, 3);
    minElements(array, 3); 

    return 0;
}

