#include<iostream>
#include<thread>
using namespace std;

/******************************************************************************************
 * Method 1:
 * --------
 * void do_some_work()
 * std::thread t(do_some_work);
 *
 * Method 2:
 * --------
 *  std::thread works with any callable type, so you can pass an instance of class
 *  with a function call operator to the std::thread constructor.
 *
 *  class background_task
 *  {
 *  public:
 *      void operator() () const
 *      {
 *          do_something();
 *          do_something_else();  
 *      }   
 *  };
 *
 *  background_task f;
 *  std::thread t1(f);
 *
 *  In this case, the supplied function object is copied into the storage belonging to the
 *  newly created thread of execution and invoked from there. It's therefore essential that the
 *  copy behave equivalently to the original.
 *
 *  One thing to consider when passing a function object to the thread constructor is to avoid what is
 *  dubbed "C++'s most vexing parse". If you pass a temporary rather
 *  than a named variable, then the syntax can be the same as that of a function declaration.
 *
 *  std::thread t2(background_task());
 *
 *  declares a function t2 that takes a single parameter ( of type pointer to a function taking no 
 *  paramters and returning background_task object) and returns a std::thread object, rather than 
 *  launching a new thread.
 *
 *  To avoid the above, we can define as below:
 *  std::thread t2((background_task())); <- Extra parentheses
 *  std::thread t2{background_task()}; <- uniform initialization
 *
 *  Method 3:
 *  -------
 *  std::thread t3( [] {
 *       do_something();
 *       do_something_else();
 *  } );
 *
 ***********************************************************************************************/
