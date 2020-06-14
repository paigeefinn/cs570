#include <stdio.h>
#include <stdlib.h>  
#include <pthread.h> // for threads
#include <semaphore.h> // for FLAG
#include <unistd.h> // for pid
#define NUM_THREADS     7

void *odd_threads(void *value)
{
  printf("second thrAD\n");
  
  int *num = (int *) value;
  
  printf("the value of value is %d", *num);
  
  return NULL;
 }



int main(int argc, char **argv)
{
  // 1.1 assigns a file pointer and creates the txt file QUOTE
  FILE *fp;
  fp = fopen ("QUOTE.txt", "w+");
    // w+ opens the file for reading/writing AND overwriting
  
  //1.2 get & write the process ID then Carriage return & newline
    // notes from guru99.com helped here
    // combo of carriage return and newline is basically 'enter'
  fprintf(fp, "Process ID %d", getpid());

  //1.3 closes Quote txt file
  fclose(fp);

  //1.4 semaphore FLAG manages QUOTE txt file access
    // notes from csc villanova helped here
  sem_t FLAG;
  sem_init(&FLAG, 0, 10 );

  pthread_t thread;
  
  printf("first thread \n ");
  
  int num = 5;
  
  pthread_create(&thread, NULL, odd_threads, &num);
  
  pthread_join(thread, NULL);

  sem_destroy(&FLAG);
  
  return EXIT_SUCCESS;
}
