#include<iostream>
using namespace std;

//
// const - A compile time constraint that an object cannot be modified.
//

int main()
{
    const int i = 1;
    cout << "i = " << i << endl;
    int j = 10;
 
    //i = 6;  //error: assignment of read-only variable 'i'

    //const int *p1 = &i; // data is constant and not the pointer
    //*p1 = 7;   //error: assignment of read-only location '* p1'
    // p1++;

    //int* const p2 = &i; // error: invalid conversion from 'const int*' to 'int*'. Note i is a const int.
    //int* const p3 = &j; // const pointer

    //const int * const p4 = &i;; // both data and pointer are const.

    //int const *p5 = &i;

 
    // If const is on the left of *, then data is constant.
    // If const is on the right of *, then pointer is constant.
    //

    //If we really want to change the const (i), we can cast away the constness using const_cast.
    const_cast<int &>(i) = 6;
    cout << "i = " << i << endl; // Doesn't change the value of i from 1 to 6.

    volatile const int k = 6;
    cout << "k = " << k << endl; 
    const_cast<int &>(k) = 9;
    cout << "k = " << k << endl; // changes the value of k from 6 to 9.

    //We can do the other way also, where we can make the variable const.
    int p = 6;
    cout << "p = " << p << endl; 
    static_cast<const int &>(p) = 7;  //error: assignment of read-only location '*(const int*)(& p)'

    //
    // Why use const ???
    //
    // 1) Guard against inadvertent write to the variable.
    // 2) Enable compiler to do more optimization.
    // 3) const means the variable can be put in ROM. (That's the reason we use volatile)
    //

}
