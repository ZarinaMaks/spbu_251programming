// paralleling via POSIX Threads:
// https://habr.com/ru/post/326138/
// pthread.h:
// https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/pthread.h.html

/*
LinuxThreads is a fairly complete and solid implementation of "shared everything" as per the POSIX 1003.1c threads standard. 
Unlike other POSIX threads ports, LinuxThreads uses the same Linux kernel threads facility (clone()) that is used by bb_threads. 
POSIX compatibility means that it is relatively easy to port quite a few threaded applications 
from other systems and various tutorial materials are available. 
In short, this is definitely the threads package to use under Linux for developing large-scale threaded programs.

The basic program structure for using the LinuxThreads library is:

1) Start the program running as a single process.
2) The next step is to initialize any locks that you will need. Unlike bb_threads locks, which are identified by numbers, POSIX locks are declared as variables of type pthread_mutex_t lock. Use pthread_mutex_init(&lock,val) to initialize each one you will need to use.
3) As with bb_threads, spawning a new thread is done by calling a library routine that takes arguments specifying what function the new thread should execute and what arguments should be transmitted to it. However, POSIX requires the user to declare a variable of type pthread_t to identify each thread. To create a thread pthread_t thread running f(), one calls pthread_create(&thread,NULL,f,&arg).
4) Run parallel code, being careful to use pthread_mutex_lock(&lock) and pthread_mutex_unlock(&lock) as appropriate.
5) Use pthread_join(thread,&retval) to clean-up after each thread.
6) Use -D_REENTRANT when compiling your C code.
*/

#include <stdio.h>
#include <stdlib.h>
#include "pthread.h"

volatile double pi = 0.0;  /* Approximation to pi (shared) */
pthread_mutex_t pi_lock;   /* Lock for above */
volatile double intervals; /* How many intervals? */

void *
process(void *arg)
{
  register double width, localsum;
  register int i;
  register int iproc = (*((char *) arg) - '0');

  // Setting width:
  width = 1.0 / intervals;

  // Local computations:
  localsum = 0;
  for (i=iproc; i<intervals; i+=2) {
    register double x = (i + 0.5) * width;
    localsum += 4.0 / (1.0 + x * x);
  }
  localsum *= width;

  // Locking pi for update, updating it, and unlocking:
  pthread_mutex_lock(&pi_lock);
  pi += localsum;
  pthread_mutex_unlock(&pi_lock);

  return(NULL);
}

int
main(int argc, char **argv)
{
  pthread_t thread0, thread1;
  void * retval;

  // Getting the number of intervals:
  intervals = atoi(argv[1]);

  // Initializing the lock on pi:
  pthread_mutex_init(&pi_lock, NULL);

  // Make TWO threads:
  if (pthread_create(&thread0, NULL, process, "0") ||
      pthread_create(&thread1, NULL, process, "1")) {
    fprintf(stderr, "%s: cannot make thread\n", argv[0]);
    exit(1);
  }

  // Joining TWO threads
  if (pthread_join(thread0, &retval) ||
      pthread_join(thread1, &retval)) {
    fprintf(stderr, "%s: thread join failed\n", argv[0]);
    exit(1);
  }

  // Print the result:
  printf("Estimation of pi is %f\n", pi);

  exit(0);
}