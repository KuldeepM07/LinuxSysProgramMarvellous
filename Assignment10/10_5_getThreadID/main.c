#include <stdio.h>
#include <pthread.h>

void* threadFunction(void* ptr)
{
    printf("Inside Thread: Thread ID: %d\n", pthread_self());
}

int main(int argc, char *argv[])
{
    // Create Thread
   

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
    printf("Inside Main Thread : Created thread with thread ID: %d\n", threadID);
    pthread_join(threadID, NULL);

    return 0;
}