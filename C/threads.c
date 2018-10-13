/*
Create an array of 1 – 1000 and calculate the sum of it using two threads.
*/

#include <stdio.h>
#include <pthread.h>

#define ARRAYSIZE 1000
#define NUM_THREADS 2

int array[ARRAYSIZE]; // create a array of size 1000;
int sum = 0;
int wsize;
pthread_mutex_t mutex; //mutually exclution


void* adder(void* tid){
    int start, end, tempSum = 0;

    start = *((int*)tid) * wsize;
    end = start + wsize;

    for(int i = start; i< end; i++){
        tempSum += array[i]; 
    }

    pthread_mutex_lock(&mutex); // lock the critical section
    sum += tempSum;
    pthread_mutex_unlock(&mutex);

    return NULL;

}


int main(int argc, char const *argv[])
{   
    wsize = ARRAYSIZE/NUM_THREADS; // initialize work size of a thread
    
    // initialize the array with values 1 - 1000;
    for(int i = 0; i < ARRAYSIZE; i++){
        array[i] = i+1;
    }

    pthread_t threads[NUM_THREADS]; // initialize thread array
    pthread_mutex_init(&mutex, NULL); //initialize mutex;

    int tNum[NUM_THREADS]; //initialize local thread store;

    // create threads one by one
    for(int i = 0; i < NUM_THREADS; i++){
        tNum[i] = i;
        int tc = pthread_create(&threads[i], NULL, adder, &tNum[i]);
        if(tc != 0) perror("thread creating error\n");
        

    }
    // join main and forked threads
    for(int i = 0; i < NUM_THREADS; i++){
        int tj = pthread_join(threads[i], NULL);
        if(tj != 0) perror("Error occured\n");
    }

    printf("Sum is: %d\n", sum);

    return 0;
}