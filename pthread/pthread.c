/**************************************************************************
 *
 * To know which pthread library is being used, the below command:
 *
 * getconf GNU_LIBPTHREAD_VERSION
 *
 * Both processes and threads have control flows and can run concurrently,
 * but they differ in some very distinct ways.
 *
 * Threads, for example share data where as processes explictly don't.
 *
 * When a process is forked, a new process is created with its own global
 * and stack.
 *
 * When a thread is created, the only new element created is a stack that is
 * unique for the thread. The code and global data are common between the
 * threads.
 *
 * Each thread is identified by a thread identifier that is unique for every 
 * thread in the system. Each thread has its own stack and also a unique context
 * (program counter, registers ...). But since data space is shared by threads,
 * they share more than just user data. For example, file descriptors for open
 * files or sockets are shared also.
 *
 * int pthread_create(pthread_t *thread,
 *                    pthread_attr_t *attr,
 *                    void *(*start_routine)(void *),
 *                    void *arg);
 *
 * int pthread_exit(void *retval);
 *
 * pthread_t pthread_self(void);   // Gives the identifier.
 *
 * Most applications require some type of initialization.
 * pthread_once function allows a developer to create an initialization routine
 * that is invoked for a multithreaded application only once.(even though multiple
 * threads may attempt to invoke it.)
 *
 * pthread_once requires two objects:
 * pthread_once_t ( that is preinitializd with pthread_once_init)
 * initialization function.
 *
 * pthread_once_t my_init_mutex = pthread_once_init;
 *
 * void initialize_app(void )
 * {
 *    // single time init here.
 * }
 *
 * void *myThread(void *arg)
 * {
 *    pthread_once( &my_init_mutex, initialize_app);
 * }
 *
 * 
 * ****************************************************************************/

#include<pthread.h>
#include<stdio.h>
#include<error.h>
#include<stdlib.h>
#include<string.h>

void *myThread(void *arg)
{
    pthraed_t pt;

    pt = pthread_self();

    printf("Thread %x ran !!\n", (int)pt);

    pthread_exit(NULL);
}

int main()
{
    int ret;
    pthread_t mythread;

    ret = pthread_create( &mythread, NULL, myThread, NULL);

    if(ret != 0)
    {
        printf("Can't create pthread. (%s)\n", stderror(ret));
        exit(-1);
    }
}
