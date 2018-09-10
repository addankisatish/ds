#include<iostream>
#include<thread>
using namespace std;

/* RESOURCE ACQUISITION IS INITIALIZATION */


struct func
{
    int& i;

    func(int& i_) : i(i_) {}

    void operator() ()
    {
        for(unsigned j = 0; j < 100000; ++j)
        {
            do_something(i);
        }
    }
};

class thread_guard
{
    std::thread& t;
public:
    explicit thread_guard(std::thread& t_) : t(t_)
    {

    }

    ~thread_guard()
    {
        if(t.joinable())
        {
            t.join();
        } 
    }  

    thread_guard(thread_guard const &) = delete;
    thread_guard& operator=(thread_guard const&) = delete;
};

void f()
{
    int some_local_state = 0;
    func my_func(some_local_state);

    std::thread t(my_func);
    thread_guard g(t);

    do_something_in_current_thread();
}

/**************************************************************************************************
 *
 * When the execution of the current thread reaches the end of f(), the local objects 
 * are destroyed in reverse order of construction. Consequently, the thread_guard object g
 * is destroyed first, and the thread is joined with in the destructor. This even happens if the
 * function exits because do_something_in_current_thread throws an exception.
 *
 * The destructor of thread_guard first tests to see if the thread object is joinable before
 * calling join(). This is important as join() can be called only once for a given thread
 * of execution, so it would therefore be a mistake to do so if the thread had already been joined.
 *
 * If you don't need to wait for a thread to finish, you can avoid this exception-safety issue by
 * detaching it. This breaks the association of the thread with the std::thread object and ensures
 * that std::terminate() won't be called when the std::thread object is destroyed, even though the thread
 * is still running in the background.
 *
 * **************************************************************************************************/

/***************************************************************************************************
 *
 * RUNNING THREADS IN THE BACKGROUND
 *----------------------------------
 *
 * Calling detach() on the std::thread object leaves the thread to run in the background with 
 * no direct means of communicating with it. It's no longer possible to wait for that thread to 
 * complete; if the thread becomes detached, it isn't possible to obtain a std::thread object that
 * references it, so it can no longer be joined.
 * Detached threads truly run in the background; ownership and control are passed over to the C++
 * RunTime library, which ensures that the resources associated with the thread are correctly
 * reclaimed when the thread exits.
 *
 * Detached threads are often called daemon threads after the UNIX concept of a daemon process that
 * runs in the background without any explicit user interface.
 *
 * std::thread t(do_background_work);
 * t.detach();
 *
 * *************************************************************************************************/

/**************************************************************************************************
 *
 * PASSING ARGUMENTS TO A THREAD FUNCTION
 * -------------------------------------
 * 
 *  By default, the arguments are copied into internal storage, where they can be accessed
 *  by the newly created thread of execution, even if the corresponding parameter in the function
 *  is expecting a reference.
 *
 *  void f(int i, string const& s);
 *  std::thread t(f, 3, "hello");
 *
 *  This creates a new thread of execution associated with t, which calls f(3, "hello").
 *  Note that even though f takes a std::string as a second parameter, the string literal
 *  is passed as a char const* and converted to a std::string only in the context
 *  of the new thread.
 *
 *  void f(int i, string const& s);
 *  void oops(int some_param)
 *  {
 *      char buffer[1024];
 *      sprintf(buffer, "%i", some_param);
 *      std::thread t(f, 3, buffer);
 *      t.detach();  
 *  }
 *
 *  In this case, it's a pointer to the local variable buffer that's passed through to the
 *  new thread, and there's a significant chance that the function oops will exit before the buffer
 *  has been converted to std::string on the new thread, thus leading to undefined behaviour.
 *  The solution is to cast std::string before passing the buffer to the std::thread constructor.
 *
 *  void f(int i, string const& s);
 *  void not_oops(int some_param)
 *  {
 *      char buffer[1024];
 *      sprintf(buffer, "%i", some_param);
 *      std::thread t(f, 3, std::string(buffer));
 *      t.detach();  
 *  }
 *
 *  As we see the object is copied, and what you wanted was a reference ??
 *
 *  void update_data_for_widget(widget_id w, widget_data& data);
 *  void oops_again(widget_id w)
 *  {
 *      widget_data data;
 *      std::thread t(update_data_for_widget, w, data);
 *      display_status();
 *      t.join();
 *      process_widget_data(data);
 *  }
 *
 *  Although update_data_for_widget expects the second paramter to be passed by reference,
 *  the std::thread constructor doesn't know that; it's oblivious to the types of the 
 *  arguments expected by the function and blindly copies the supllied values. When it calls
 *  update_data_for_widget, it will end up passing a reference to the internal copy of data 
 *  and not a reference to data itself. Consequently, when the thread finishes, these updates 
 *  will be discarded as the internal copies of the supplied arguments are destroyed, and
 *  process_widget_data will be passed an unchanged data rather than a correctly updated version.
 *  The solution for the problem s to wrap the arguments that really need to be references
 *  in std::ref.
 *
 *  std::thread t(update_data_for_widget, w, std::ref(data));
 *  
 *  and then update_data_for_widget will be correctly passed a reference to data rather
 *  than a reference to a copy of data.
 *
 *  You can pass a member function pointer as a function, provided you supply a 
 *  suitable object pointer as the first argument.
 *
 *  class X
 *  {
 *  public:
 *      void do_lengthy_work();
 *  };
 * 
 *  X my_x;
 *  std::thread t(&X:do_lengthy_work, &my_x);
 *
 *  The above code will invoke my_x.do_length_work() on the new thread, because the
 *  address of my_x is supplied as the object pointer. You can also supply arguments
 *  to such a member function call: the thrid argument to the std::thread constructor will
 *  be the first argument to the member function and so forth.
 *
 *  Another interesting scenario for supplying arguments is where the arguments can't be copied
 *  but can only be moved: the data held within one object is transferred over to another, leaving
 *  the original object "empty". An example of such type is std::unique_ptr, which provides
 *  automatic memory management for dynamically allocated objects. Only one std::unique_ptr
 *  instance can point to a given object at a time, and when that instance is destroyed, the 
 *  pointer-to object is deleted. The move constructor and move assignment operator allow the 
 *  ownership of an object to be transfered around between std::unique_ptr instances.
 *
 *  Where the source object is a temporary, the move is automatic, but where the source is
 *  a named value, the transfer must be requested directly by invoking std::move(). The following
 *  example shows the use of std::move to transfer ownership of a dynamic object into a thread:
 *
 *  void process_big_object(std::unique_ptr<big_object);
 *
 *  std::unique_ptr<big_object> p(new big_object);
 *  p->prepare_data(42);
 *  std::thread t(process_big_object, std::move(p));
 *
 *  By specifying std::move(p) in the std::thread constructor, the ownership of the big_object
 *  is transferred first into the internal storage for the newly created thread and then into
 *  process_big_object.
 *
 ************************************************************************************************/

/***********************************************************************************************
 *
 * TRANSFERRING OWNERSHIP OF A THREAD
 * ---------------------------------
 *
 *  The ownership of a particular thread of execution can be moved between std::thread instances.
 *
 *  The following example shows the creation of two threads of execution and the transfer of 
 *  ownership of those threads among three std::thread instances t1, t2, and t3.
 *
 *  void some_function();
 *  void some_other_function();
 *
 *  std::thread t1(some_function); <- 1
 *  std::thread t2 = std::move(t1); <- 2
 *  t1 = std::thread(some_other_function); <- 3
 *
 *  std::thread t3; <- 4
 *  t3 = std::move(t2); <- 5
 *  t1 = std::move(t3); <- 6
 *
 *  At 1) new thread is started and associated with t1.
 *  At 2) Ownership is then transferred over to t2 when t2 is constructed, by invoking std::move()
 *  to explicitly move ownership. At this point t1 is no longer has an associated thread of execution;
 *  the thread running some_function is now associated with t2.
 *  At 3) a new thread is started and associated with a temporary std::thread object. The subsequent
 *  transfer of ownership into t1 doesn't require a call to std:;move() to explictly move ownership,
 *  because the owner is temporary object and moving from temporaries is automatic and implicit.
 *  At 4) t3 is default constructed, which means that it's created without any associated thread of
 *  execution.
 *  At 5) Ownership of the thread currently associated with t2 is transferred int t3, again with an
 *  explicit call to std::move(), because t2 is a named object.
 *
 *  At this point, t1 is associated with the thread running some_other_function,
 *                 t2 has no associated thread
 *                 t3 is associated with the thread running some_function
 *
 *  At 6) transfers ownership of thread running some_function back to t1. In this case t1 already had an 
 *  associated thread(which was running some_other_function), so std::terminate() is called to terminate
 *  the program. This is done for consistency with the std::thread destructor. As seen earlier, we must
 *  explicitly wait for the thread to complete or detach it before destruction, and the same applies to
 *  assignment - You can't just drop a thread by assigning a new value to a std::thread object that 
 *  manages it.
 *
 * **************************************************************************************/

/*****************************************************************************************
 *
 * RETURNING A std::thread from a function.
 * ---------------------------------------
 *
 *  std::thread f()
 *  {
 *      void some_function();
 *      return std::thread(some_function);  
 *  }
 *
 *  std::thread g()
 *  {
 *      void some_other_function(int);
 *      std::thread t(some_other_function, 42); 
 *      return t;
 *  }
 *
 *  Likewise, if ownership should be transferred int a function, it can just accept an instance of
 *  std::thread by value as one of the paramters:
 *
 *  void f(std::thread t);
 *  void g()
 *  {
 *      void some_function();
 *      f(std::thread(some_function));
 *
 *      std::thread t(some_function); 
 *      f(std::move(t));
 *  }
 *
 * ***************************************************************************************/

/*****************************************************************************************
 *
 * Chossing the number of threads at run-time
 * ------------------------------------------
 *
 *  std::thread::hardware_concurrency() -
 *
 *  This function returns an indication of the number of threads that can truly run 
 *  concurrently for a given execution of a program.
 *
 *  ***************************************************************************************/

/*****************************************************************************************
 *
 * Identifying threads
 * -------------------
 *
 *  Thread identifiers are of type std::thread::id and can be retrieved in two ways.
 *
 *  First, the identifier for a thread can be obtained from its associated std::thread object
 *  by calling the get_id() member function.
 *  Alternatively, the identifier of the current thread can be obtained by calling
 *  std::thread::get_id(), which is also defined in <thread> header.
 *
 *  Objects of std::thread::id can be freely copied and compared.
 *
 *******************************************************************************************/
