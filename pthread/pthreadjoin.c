#include<pthread.h>
#include<stdio.h>

/*************************************************************************
 *
 * int pthread_join(pthread_t th, void **thread_return);
 *
 * int pthread_detach(pthread_t th);
 *
 * ***********************************************************************/

#define MAX_THREADS 5

void *myThread(void *arg)
{
    printf("Thread %d started.\n", (int)arg);

    pthread_detach( pthread_self());

    pthread_exit(arg);
}

int main()
{
    int ret, i, status;
    pthread_t threadIds[MAX_THREADS];

    for(i = 0; i < MAX_THREADS; i++)
    {
        ret = pthread_create(&threadIds[i], NULL, myThread, (void *)i);
        if(ret != 0 )
        {
            printf("Error creating thread %d\n", i);
        }
    }

    for(i = 0; i < MAX_THREADS; i++)
    {
        ret = pthread_join(threadIds[i], (void **)&status);
        if(ret != 0)
        {
            printf("Error joining the thread %d\n", (int)threadIds[i]);
        }
        else
        {
            printf("status = %d\n", status);
        }
    }
    return 0;
}




