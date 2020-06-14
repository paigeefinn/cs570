#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *entry_point(void *value)
{
  printf("second thrAD\n");
  
  int *num = (int *) value;
  
  printf("the valuue of value is %d", *num);
  
  return NULL;
 }

int main(int argc, char **argv)
{
  pthread_t thread;
  
  printf("first thread \n ");
  
  int num = 5;
  
  pthread_create(&thread, NULL, entry_point, &num);
  
  pthread_join(thread, NULL);
  
  return EXIT_SUCCESS;
}
