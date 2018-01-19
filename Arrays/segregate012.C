#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void segregate012(int arr[], int n)
{
    int low = 0;
    int mid = 0;
    int high = n-1;

    while(mid <=high)
    {
        switch(arr[mid])
        {
            case 0:
                swap(arr[low++], arr[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid], arr[high--]);
                break;
        }
    }
}

int main()
{
    int arr[] = {0,1,1,0,1,2,1,2,0,0,0,1};
    int size = sizeof(arr)/sizeof(int);

    segregate012(arr, size);

    for(auto i: arr)
        cout << i << " ";

    cout << endl;
    return 0;
}
