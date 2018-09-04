#include<iostream>
#include<queue>
#include<string>
#include<iomanip>
using namespace std;

void sortStrings()
{
    priority_queue<string> pq;
    
    pq.push("the quick");
    pq.push("fox");
    pq.push("jumped over");
    pq.push("the lazy dog");

    cout << "Sorting strings is descending order ..." << endl;
    while(!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();  
    }

    priority_queue<string, vector<string>, greater<string>> pq1;
    
    pq1.push("the quick");
    pq1.push("fox");
    pq1.push("jumped over");
    pq1.push("the lazy dog");

    cout << "Sorting strings is ascending order ..." << endl;
    while(!pq1.empty())
    {
        cout << pq1.top() << endl;
        pq1.pop();  
    }
}

void userDefinedObjects()
{
    struct Time
    {
        int h;
        int m;
        int s;
    };

    class CompareTime
    {
    public:
        bool operator()(Time &t1, Time &t2)
        {
            if(t1.h < t2.h) return true;
            if(t1.h == t2.h && t1.m < t2.m) return true;
            if(t1.h == t2.h && t1.m == t2.m && t1.s < t2.s) return true;
            return false;
        }  
    }; 

    priority_queue<Time, vector<Time>, CompareTime> pq;
   
    // Array of 4 time objects
    Time t[4] = { {3,2,40}, {3,2,26}, {5,16,13}, {5,14,20} };

    for(int i = 0; i < 4; i++)
        pq.push(t[i]);

    cout << "Sorting time objects ..." << endl;
    while(!pq.empty())
    {
        Time t = pq.top();
        cout << setw(3) << t.h << " " << setw(3) << t.m << " " << setw(3) << t.s << endl;
        pq.pop();
    }    
}

int main()
{
    sortStrings();

    userDefinedObjects();
    return 0; 
}
