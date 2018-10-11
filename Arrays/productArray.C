#include<iostream>
using namespace std;

/*************************************************************
 * arr[] = {10, 3, 5, 6, 2}
 * o/p   = {180, 600, 360, 300, 900}
 *
 * Algorithm:
 * ---------
 *  1) Construct a temporary array left[] such that left[i] contains
 *     product of all elements on left of arr[i] excluding arr[i]
 *
 *  2) Construct a temporary array right[] such that right[i] contains
 *     product of all elements on right of arr[i] excluding arr[i].
 *
 *  3) To get output, mulitply left[] and right[]
 *
 ***************************************************************/

void productArray(int a[], int n)
{
    int *left = new int[n];
    int *right = new int[n];
    int *result = new int[n];

    left[0] = 1;
    right[n-1] = 1;

    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    // Construct the left array.
    for(int i = 1; i < n; i++)
        left[i] = a[i-1] * left[i-1];


    for(int i = n-2; i >= 0; i--)
        right[i] = a[i+1] * right[i+1];


    for(int i = 0; i < n; i++)
    {
        result[i] = left[i] * right[i];
        cout << result[i] << " ";
    }
    cout << endl;

    delete[] left;
    delete[] right;
    delete[] result;
} 

void productArray1(int a[], int n)
{
    int temp = 1;
    int *result = new int[n];

    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    // Construct the left array.
    for(int i = 0; i < n; i++)
    {
        result[i] = temp;
        temp = temp * a[i];
    }

    temp = 1;
    for(int i = n-1; i >=0 ; i--)
    {
        result[i] *= temp;
        temp = temp * a[i]; 
    } 

    for(int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    delete[] result;
}

int main()
{
    int arr[] = {10, 3, 5, 6, 2};
    productArray(arr, sizeof(arr)/sizeof(int));
    productArray1(arr, sizeof(arr)/sizeof(int));

    return 0;
}
