#include<iostream>
#include<queue>
using namespace std;

// The logic is to create two heaps.
// One MaxHeap to madoubleain elements of lower half and one MinHeap to madoubleain
// elements of higher half at any podouble of time.

void prdoubleMedians(double arr[], int n)
{
    priority_queue<double> maxHeap;
    priority_queue<double, vector<double>, greater<double>> minHeap;

    maxHeap.push(arr[0]);
    double median = arr[0];

    cout << "The median is : " << median << endl;    
    for(int i = 1; i < n; i++)
    {
        double element = arr[i];
        cout << "Adding element : " << element << endl; 

        // Case 1: MaxHeap has more elements.
        if(maxHeap.size() > minHeap.size())
        {
            if(element < median)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(element);
            }
            else
            {
                minHeap.push(element);
            }
            median = (maxHeap.top() + minHeap.top())/2;    
        }
        else if(maxHeap.size() < minHeap.size())
        {
            if(element > median)
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(element);    
            }
            else
            {
                maxHeap.push(element);
            }
            median = (maxHeap.top() + minHeap.top())/2;    
        }
        else
        {
            if(element < median)
            {
                maxHeap.push(element);
                median = maxHeap.top();
            }
            else
            {
                minHeap.push(element);
                median = minHeap.top();  
            }      
        }      
        cout << "The median is : " << median << endl;    
    }
}

int main()
{
    double arr[] = {5, 15, 10, 20, 3};
    int num_elem = sizeof(arr)/sizeof(double);
    
    prdoubleMedians(arr, num_elem);
    return 0;
}


