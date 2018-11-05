/***************************************************************************
 * A mutex is a variable that permits threads to implement critical sections.
 *
 * pthread_mutex_t myMutex = PTHREAD_MUTEX_INITIALIZER
 *
 * Types of mutex initializers
 * ---------------------------
 *
 *  PTHREAD_MUTEX_INITIALIZER        Fast Mutex
 *
 *  PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP  Recursive mutex
 *
 *  PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP  Error-checking mutex
 *
 *  The recursive mutex is a special mutex that allows the mutex to be locked
 *  several times without blocking, as long as it's locked by the same thread.
 *  Even though the mutex can be locked multiple times without blocking,
 *  the thread must unlock the mutex same number of timessss that it was locked.
 *
 *  The error-checking mutex can be used to help find errors when debugging.
 *
 *  int pthread_mutex_lock(pthread_mutex_t *mutex);
 *  int pthread_mutex_trylock(pthread_mutex_t *mutex);
 *  int pthread_mutex_unlock(pthread_mutex_t *mutex);
 *  int pthread_mutex_destroy(pthread_mutex_t *mutex);
 *
 *  pthread_mutext_t cntr_mutex = PTHREAD_MUTEX_INITIALIZER;
 *
 *  assert(pthread_mutex_lock( &cntr_mutex ) == 0);
 *  counter++;
 *  assert(pthread_mutex_unlock( &cntr_mutex ) == 0);
 *
 *  ret = pthread_mutex_trylock( &cntr_mutex);
 *  if(ret == EBUSY) {
 *     // couldn't lock, do something else 
 *  }
 *  else if(ret == EINVAL) {
 *       // Critical error
 *       assert(0);
 *  }
 *  else {
 *      // critical section.
 *      ret = pthread_mutex_unlock( &cntr_mutex);
 *  }
 *
 *  ret = pthread_mutex_destroy( &cntr_mutex);
 *  if(ret == EBUSY)
 *  {
 *      // Mutex is locked. can't destroy.
 *  }
 *  else
 *  {
 *      // mutex is destroyed.
 *  }
 *
 ********************************************************************************/
