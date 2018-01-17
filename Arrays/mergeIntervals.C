#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class Interval
{
    int start_time;
    int end_time;
public:
    Interval(): start_time(0), end_time(0)
    {
    }

    Interval(int st, int et) : start_time(st), end_time(et)
    {
    }

    Interval(const Interval &rhs)
    {
        start_time = rhs.start_time;
        end_time = rhs.end_time;
    }

    void setStartTime(int st) { start_time = st; }
    void setEndTime(int et) { end_time = et; }
    int getStartTime() const { return start_time; }
    int getEndTime() const { return end_time; }

    friend ostream& operator<<(ostream& outputStream, const Interval& ivl)
    {
        cout << "[" << ivl.start_time << "," << ivl.end_time << "]" ;
        return outputStream;
    }
};

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int max(int a, int b)
{
    return ( a > b ) ? a : b;
}

bool compareInterval(const Interval &i1, const Interval &i2)
{
    return (i1.getStartTime() < i2.getStartTime());
}

void mergeIntervals(vector<Interval> &intervals)
{
    stack<Interval> s;
    
    // Sort the intervals in the increasing order of intervals.
    sort(intervals.begin(), intervals.end(), compareInterval);

    cout << "The sorted intervals are: " << endl;
    vector<Interval>::iterator iter = intervals.begin();
    for(; iter != intervals.end(); iter++)
        cout << *iter ;
    cout << endl;

    //Push the first elemnt onto stack.
    s.push(intervals[0]);

    for(int i = 0; i < intervals.size(); i++)
    {
        Interval top = s.top();

        // If the current interval doesn't overlap with the top
        // push it to the stack.
        if(top.getEndTime() < intervals[i].getStartTime())
            s.push(intervals[i]);
        else if(top.getEndTime() < intervals[i].getEndTime())
        {
            top.setEndTime(intervals[i].getEndTime());
            s.pop();
            s.push(top);
        }
    }

    cout << "The merged intervals are: " << endl;
    while(!s.empty())
    {
        Interval top = s.top();
        cout << top;
        s.pop();
    }
    cout << endl;
}

int main()
{
    vector<Interval> intervals;
    intervals.push_back(Interval(10, 13));
    intervals.push_back(Interval(-1, 4));
    intervals.push_back(Interval(0, 6));
    intervals.push_back(Interval(9, 10));

    vector<Interval> intervals1;
    intervals1.push_back(Interval(10, 13));
    intervals1.push_back(Interval(-1, 4));
    intervals1.push_back(Interval(0, 6));
    intervals1.push_back(Interval(9, 10));

    cout << "The intervals are: " << endl;
    vector<Interval>::iterator iter = intervals.begin();
    for(; iter != intervals.end(); iter++)
        cout << *iter ;
    cout << endl;

    // Merge the overlapping intervals
    vector<Interval>::iterator currIter = intervals.begin();
    for(; currIter != intervals.end(); )
    {
        bool found = false;
        vector<Interval>::iterator tempIter = currIter + 1;
        for(; tempIter != intervals.end(); tempIter++)
        {
            cout << "Comparing Intervals: " << endl;
            cout << *currIter << *tempIter << endl;
            if(((tempIter->getStartTime() <= currIter->getStartTime()) &&   //[10,13][9,10]
                (currIter->getStartTime() <= tempIter->getEndTime())) ||
               ((currIter->getStartTime() <= tempIter->getStartTime()) &&
                (tempIter->getStartTime() <= currIter->getEndTime()))) //[-1,4][0,6]
            {
                found = true;
                int start_time = min(currIter->getStartTime(), tempIter->getStartTime());
                int end_time = max(currIter->getEndTime(), tempIter->getEndTime());
                tempIter->setStartTime(start_time);
                tempIter->setEndTime(end_time);
                //
                // Remove the interval.
                //
                currIter = intervals.erase(currIter);
                break;
            } 
        }
        if(found == false)
        {
            currIter++;
        }
    }
    cout << "The merged intervals are: " << endl;
    vector<Interval>::iterator iter1 = intervals.begin();
    for(; iter1 != intervals.end(); iter1++)
        cout << *iter1 ;

    cout << endl;

    mergeIntervals(intervals1);
    return 0;
}
