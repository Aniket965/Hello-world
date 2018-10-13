#include <unistd.h>     /* Symbolic Constants */
 
#include <stdio.h>      
#include <stdlib.h>   
#include <pthread.h>    /* POSIX Threads */


#define BUFFER_SIZE 10
#define BREAK_CONDITION 20
 
typedef struct
{
int items;
} item;
item buffer[BUFFER_SIZE];
int countproduced=0;
int countconsumed=0;
int in = 0;
int out = 0;
item *nextproduced;
item *nextconsumed;
void *Consumer(void *arg)
{
     while (1)
    { printf("\nConsumer thread");
     while (in == out) {printf("\n\t Buffer Empty");sleep(1);}
    
      nextconsumed = &buffer[out];
      printf("\n\tConsumed : %d ",++countconsumed);
      out = (out + 1) % BUFFER_SIZE;
      if(countconsumed==BREAK_CONDITION)break;
    }
    return NULL;
}
 
void *Producer(void *arg)
{    
     while (1)
    {
         printf("\nProducer thread");
         while (((in + 1) % BUFFER_SIZE) == out) {printf("\n\t Buffer Full");sleep(1);}
  
         nextproduced=malloc(sizeof(item*));
      nextproduced->items=++countproduced;
 printf("\n\tProduced : %d ",countproduced);
      buffer[in] = *nextproduced;
      in = (in + 1) % BUFFER_SIZE;
      if(countproduced==BREAK_CONDITION)break;

    }
    return NULL;
}
 
int main()
{    
      pthread_t producer_thread_id, consumer_thread_id;
          
      pthread_create(&producer_thread_id, NULL, Producer, NULL);
      pthread_create(&consumer_thread_id, NULL, Consumer, NULL);
      pthread_join(producer_thread_id, NULL);
      pthread_join(consumer_thread_id, NULL);
      return 0;
}