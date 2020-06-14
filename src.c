#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
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
  # assigns a file pointer and creates the txt file QUOTE
  FILE *fp;
  fp = fopen ("QUOTE.txt", "w")
  
  pthread_t thread;
  
  printf("first thread \n ");
  
  int num = 5;
  
  pthread_create(&thread, NULL, odd_threads, &num);
  
  pthread_join(thread, NULL);
  
  return EXIT_SUCCESS;
}
