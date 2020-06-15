#include <stdio.h>
#include <stdlib.h>  
#include <pthread.h> // for threads
#include <semaphore.h> // for FLAG
#include <unistd.h> // for pid

void odd_thread( void * arg ){
    for (int i=0; i< 7; i++)
    {
        sleep(3);
        printf("the thread id is %d\n", i);
        printf("Computer science is no more about computers than astronomy is about telescopes' --Edsger Dijkstra\n");
    } 
}

void even_thread(){
    for (int i=0; i< 8; i++)
    {
        sleep(2);
        printf("the thread id is %d\n", i);
        printf("Controlling complexity is the essence of computer programming' --Brian Kernigan \n");
    } 
}

int main(){
    pthread_t newthread;

    for (int i = 0; i <9; i++){
        pthread_create(&newthread, NULL, odd_thread, NULL);
        even_thread();
        pthread_join(newthread, NULL);
        printf("%d thread's done\n ", i);
    }

    pthread_exit(NULL); 
    }