#include<iostream>
using namespace std;

class Base
{
    public:
	virtual void func(int x = 0)
        {
            cout << "Base::func(), x = " << x << endl;
        }
};

class Derived : public Base
{
    public:
	virtual void func(int x)
        {
            cout << "Derived::func(), x = " << x << endl;
        }
};

int main()
{
    Derived d1;
    Base *dp = &d1;

    dp->func();
    return 0;
}

/*
 *  o/p: Derived::func(), x = 0
 *
 *  We observe that func() of derived class is called and default value of the base
 *  class func() is used.
 *
 *  Default arguments do not participate in the signature of the functions.
 *
 *  So signature of func() in the base class and derived class are considered same.
 *  Hence func() of base class is overridden.
 *
 *  Also, default value is used at compile time. When compiler sess argument is missing in the
 *  function call, it substitutes the default value given.
 *
 *  So, x is substituted at compile time and at run time derived class's func() is called.
 *
 *  Suppose if we have:
 *
 *  class Derived : public Base
 *  {
 *      public:
 *	    virtual void func(int x = 10)
 *          {
 *              cout << "Derived::func(), x = " << x << endl;
 *          }
 *  };
 *
 *  The above is same i.e Derived::func(), x = 0
 *
 *  The reason is same, the efault value is substituted at compile time. The func() is called with bp
 *  which is a pointer of Base Type. So compiler substitues 0 and not 10.
 *
 */
