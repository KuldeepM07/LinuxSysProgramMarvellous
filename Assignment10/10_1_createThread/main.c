#include <stdio.h>
#include <pthread.h>

void* threadFunction(void* ptr)
{
    printf("Inside Thread: Thread created using pTHread library\n");
}

int main(int argc, char *argv[])
{
    // Create Thread
    printf("Creating new thread\n");

    pthread_t threadID = 0;

    int retVal = pthread_create(
                                &threadID, // Out : Thread ID
                                NULL,       // Thread Attributes
                                threadFunction,
                                NULL);
    if(retVal != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }
    pthread_join(threadID, NULL);

    return 0;
}