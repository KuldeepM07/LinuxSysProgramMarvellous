#include <stdio.h>
#include <pthread.h>

void* threadFunction1(void* ptr)
{
    printf("Inside Thread 1\n");
    for(int i=1;i<=500;i++)
    {
        printf("%d\n", i);
    }
}

void* threadFunction2(void* ptr)
{
    printf("Inside Thread 2\n");
    for(int i=500;i>=1;i--)
    {
        printf("%d\n", i);
    }
}


int main(int argc, char *argv[])
{
    // Create Thread
    printf("Creating new thread\n");

    pthread_t threadID1 = 0;
    pthread_t threadID2 = 0;

    int retVal = pthread_create(
                                &threadID1, // Out : Thread ID
                                NULL,       // Thread Attributes
                                threadFunction1,
                                NULL);
    if(retVal != 0)
    {
        printf("Unable to create thread 1\n");
        return -1;
    }
    pthread_join(threadID1, NULL);

    retVal = pthread_create(
                                &threadID2, // Out : Thread ID
                                NULL,       // Thread Attributes
                                threadFunction2,
                                NULL);
    if(retVal != 0)
    {
        printf("Unable to create thread 2\n");
        return -1;
    }
    pthread_join(threadID2, NULL);

    return 0;
}