#include<iostream>
using namespace std;

void segregate0and1(int arr[], int n)
{
    int left = 0;
    int right = n-1;

    while(left < right)
    {
        // Increment the left index as long as we see 0
        while(arr[left] == 0 && left < right)
            left++;

        // Decrement the right index as long as we see 1
        while(arr[right] == 1 && left < right)
            right--;

        if(left < right)
        {
            arr[left++] = 0;
            arr[right--] = 1;
        }
    }
}

int main()
{
    int arr[] = { 0, 0, 1, 0, 1, 1, 1};
    int size = sizeof(arr)/sizeof(int);

    segregate0and1(arr, size);
 
    for(int i : arr)
        cout << i << " ";

    cout << endl;
}
