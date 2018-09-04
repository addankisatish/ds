#include<iostream>
#include<queue>
using namespace std;

void maxHeap()
{
    priority_queue< pair<int, int> > pq;
    pq.push(make_pair(10, 200));
    pq.push(make_pair(20, 100));
    pq.push(make_pair(15, 400));

    while(pq.empty() == false)
    {
        pair<int, int> top = pq.top();
        pq.pop();
        cout << top.first << " " << top.second << endl;
    }
}

typedef pair<int, int> pi;
void minHeap()
{
    priority_queue< pi, vector<pi>, greater<pi> > pq;
    pq.push(make_pair(10, 200));
    pq.push(make_pair(20, 100));
    pq.push(make_pair(15, 400));

    while(pq.empty() == false)
    {
        pair<int, int> top = pq.top();
        pq.pop();
        cout << top.first << " " << top.second << endl;
    }
}
int main()
{
    maxHeap();
    minHeap();
    return 0;
}
