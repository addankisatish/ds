/*************************************************************************
 * 
 *  A condition variable is a special thread construct that allows a thread
 *  to wake up another thread based upon a condition.
 *
 *  Consider the problem of a thread waiting a particular condition being met.
 *  With only mutexes, the thread would have to poll to acquire the mutex,
 *  check the condition, and then release the mutex if there was no work to do
 *  (the condition wasn't met). That kind of busy looping can lead to poor
 *  performing applications and should therefore be avoided.
 *
 *  int pthread_cond_wait(pthread_cond_t *cond, 
 *                        pthread_mutex_t *mutex);
 *
 *  int pthread_cond_timedwait(pthread_cond_t *cond, 
 *                             pthread_mutex_t *mutex,
 *                             const struct timespec *abstime);
 *
 *  int pthread_cond_signal(pthread_cond_t *cond);
 *
 *  int pthread_cond_broadcast(pthread_cond_t *cond);
 *
 *  int pthread_cond_destroy(pthread_cond_t *cond);
 *
 *  e.g Fault recovery thread loop 
 *  ------------------------------
 *
 *  while(1)
 *  {
 *      assert(pthread_mutex_lock( &recoveryMutex ) == 0);
 *      while(workload < MAX_NORMAL_WORKLOAD)
 *      {
 *          pthread_cond_wait( &recoveryCond, &recoveryMutex );
 *      }
 *
 *      //
 *      // Recovery code
 *      //
 *
 *      assert(pthread_mutex_unlock( &recoveryMutex );
 *
 *  }
 *
 *  This is the standard pattern while dealing with condition variables.
 *
 *  we start by locking the mutex, entering pthread_cond_wait, and upon waking
 *  up from our condition, unlocking the mutex.
 *
 *  The mutex must be locked first because upon entry to pthread_cond_wait, the
 *  mutex is automatically unlocked. When we return from pthread_cond_wait, the 
 *  mutex has been reacquired, meaning that we will need to unlock it afterward.
 *
 *
 * **********************************************************************/
