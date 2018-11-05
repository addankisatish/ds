#include<pthread.h>
#include<stdio.h>

pthread_mutext_t cond_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition = PTHREAD_COND_INITIALIZER;

int workCount = 0;

#define MAX_CONSUMERS 10

int main()
{
    int i;
    pthread_t consumers[MAX_CONSUMERS];
    pthread_t producer;

    // spawn the consumer threads
    for(i = 0; i < MAX_CONSUMERS; i++)
    {
        pthread_create( &consumers[i], NULL, consumerThread, NULL);
    }

    // spawn the producer.
    pthread_create( &producer, NULL, producerThread, NULL );

    pthread_join(producer, NULL);

    while((workCount > 0));

    // cancel the consumer threads.
    for(i = 0; i < MAX_CONSMERS; i++)
        pthread_cancel( consumers[i]);

    pthread_mutex_destroy( &cond_mutex);
    pthread_cond_destroy( &condition);

    return 0;
}

void *producerThread(void *arg)
{
    int i, j, ret;
    double result = 0.0;

    for(i = 0; i < 30; i++)
    {
        ret = pthread_mutex_lock(&cond_mutex);
        if(ret == 0)
        {
            workCount++;
            pthread_cond_broadcast(&condition);
            pthread_mutex_unlock(&cond_mutex);
        }
        else
        {
            assert(0);                                                             
        }

        for(j = 0; j < 60000; j++)
            result = result + (double)random();
    }

    pthread_exit(NULL);
}

void *consumerThread(void *arg)
{
    int ret;

    pthread_detach(pthread_self());

    while(1)
    {
        assert(pthread_mutex_lock(&cond_mutex) == 0);
        assert(pthread_cond_wait(&condition, &cond_mutex) == 0);

        if(workCount) 
        {
            workCount--;
        }
        assert(pthread_mutex_unlock(&cond_mutex) == 0);
    }

    pthread_exit(NULL);
}

