#include<iostream>
using namespace std;

/*
 * RTTI - Runtime Type Information
 *
 * In C++, RTTI is available only for classes which have atleast one virtual function.
 *
 */

class B
{
};

class D : public B
{
};

int main()
{
    B *b = new D;
    D *d = dynamic_cast<D*>(b);

    if( d != NULL)
        cout << "Works !!" << endl;
    else
        cout << "Not Working !!!" << endl;

    return 0;
}

/*
 * The following code gives the following compilation error:
 *
 * RTTI.C: In function 'int main()':
 * RTTI.C:25:30: error: cannot dynamic_cast 'b' (of type 'class B*') to type 'class D*' (source type is not polymorphic)
 *
 * Adding a virtual function to the base class B makes it working.
 *
 * class B
 * {
 *     virtual void func() {} 
 * };
 *
 */


