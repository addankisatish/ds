#include<iostream>
#include<vector>
using namespace std;

// If logical constness is what is desired, you should use mutable keyword.

class BigArray
{
    vector<int> v;
    mutable int accessCounter;  // Method 1
    //int accessCounter;            // Method 2
    //
    int *v2;

public:
    BigArray()
    {
        v.clear();
        accessCounter = 0;
        v2 = new int[10];
    }

    ~BigArray()
    {
        delete[] v2;
    }

    int getItem(int index) const  
    {
        accessCounter++; // If the accessCounter is not defined as mutable, then we get compilation error
                         // as we are trying to modify a member varibale in a const function.
                         
        // If we don't want to use the mutable keyword, we can do this as:
        //const_cast<BigArray*>(this)->accessCounter++;
        return v[index];
    }

    int getAccessCounter() const { return accessCounter; }

    void pushItem(int val)
    {
        v.push_back(val);
    }

    // Even though the v2 is a member variable, we are still able to assign the value in the const function.
    // This function maintains the bitwise constness of the class.
    void setV2Item(int index, int val) const
    {
        *(v2+index) = val;
    }

    int getV2Item(int index) const { return v2[index]; }

};

int main()
{
    BigArray b;

    b.pushItem(10);
    b.pushItem(20);
    b.pushItem(30);
    b.pushItem(40);
    b.pushItem(50);

    cout << b.getItem(0) << endl;
    cout << b.getAccessCounter() << endl;
    cout << b.getItem(1) << endl;
    cout << b.getAccessCounter() << endl;

    b.setV2Item(0, 30);
    b.setV2Item(1, 40);
    cout << b.getV2Item(0) << endl;
    cout << b.getV2Item(1) << endl;
}
