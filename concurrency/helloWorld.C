#include<iostream>
#include<thread>
using namespace std;

void hello()
{
    cout << "Hello World!!!" << endl;
}

int main()
{
    thread t(hello);
    t.join();

    return 0;
}

/*
 * Every thread has to have an initial function, which is where the new thread execution begins.
 * For the initila thread in an application, this is main(), but for every other thread,
 * it is specified in the constructor of a std::thread object.
 *
 * After the new thread is launched, the initial thread continues execution.
 * If it didn't wait for the new thread to finish, it would merrily continue to the end of
 * main() and thus end the program - possibly before the new thread had a chance to run.
 * join() - causes the calling thread to wait for the thread associated with std::thread object.
 *
 */
