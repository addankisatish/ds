#include<iostream>
using namespace std;

void findWater(int arr[], int n)
{
    // left[i] contains the tallest bar to the left of i including itself
    int left[n];

    //right[i] contains the tallest bar to the right of i including itself
    int right[n];

    int water = 0;
    
    left[0] = arr[0];
    for(int i = 1; i < n; i++)
        left[i] = max(left[i-1], arr[i]);

    right[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--)
        right[i] = max(right[i+1], arr[i]);

    // the amount of water accumulated on this bar will be 
    // min(left[i], right[i]) - a[i]
    for(int i = 0; i < n; i++)
        water += (min(left[i], right[i]) - arr[i]);

    cout << "The amount of water accumulated is: " << water << endl;
}

int main()
{
    int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = sizeof(arr)/sizeof(int);

    findWater(arr, n);

    int arr1[] = {3,0,0,2,0,4};
    n = sizeof(arr1)/sizeof(int);
  
    findWater(arr1, n);
    return 0;
}
