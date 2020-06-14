#include <stdio.h>
#include <stdlib.h>  
#include <pthread.h> // for threads
#include <semaphore.h> // for FLAG
#include <unistd.h> // for pid
#define NUM_THREADS     7

void *thread_start (long *t)
{
  //2.1.1 Write thread ID and quote
  FILE *fp;
  fp = fopen("QUOTE.txt", "w+");
  fprintf("Thread ID: %n", t);
  if ( (*t % 2) == 0) {
    fprintf(fp, " 'Controlling complexity is the essence of computer programming' --Brian Kernigan");
  }
     else
  {
    fprintf(fp, "Computer science is no more about computers than astronomy is about telescopes' --Edsger Dijkstra" );
  }
  
  printf("second thrAD\n");

  
  
  return NULL;
 }


int main(int argc, char **argv)
{
  int num = NUM_THREADS;
  sem_t FLAG;
  
  // 1.1 assigns a file pointer and creates the txt file QUOTE
  FILE *fp;
  fp = fopen ("QUOTE.txt", "w+");
    // w+ opens the file for reading/writing AND overwriting
  
  //1.2 get & write the process ID then Carriage return & newline
    // notes from guru99.com helped here
    // combo of carriage return and newline is basically 'enter'
  fprintf(fp, "Process ID %d \r\n", getpid());

  //1.3 closes Quote txt file
  fclose(fp);

  //1.4 semaphore FLAG manages QUOTE txt file access
    // notes from csc villanova helped here
  sem_init(&FLAG, 0, 10 );

  // 2.2 Repeat the thread process 
    // see GNU 13.18 Open File Description Locks Example
  for (int i = 0; i < 8; i++) {
    // initialize thread index
    //2.1.1 
    pthread_t threads[num];
    int rc;
    long t;
    for(t=0; t<num; t++){
       printf("In main: creating thread %ld\n", t);

       
       if (t % 2 == 0){
       rc = pthread_create(&threads[t], NULL, thread_start, (long *)t);
  // 2.1 periodically get the sempahore flag
  //establish periodicity based on even vs odd
        }
        return 0;
        }
  }
}
