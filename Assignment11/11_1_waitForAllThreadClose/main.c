#include <stdio.h>
#include <pthread.h>

void* threadFunction1(void* ptr)
{
    int i = 0;
    for(i=1;i<=100;i++)
    {
        printf("Thread1 with counter : %d\n", i);
    }
}

void* threadFunction2(void* ptr)
{
    int i = 0;
    for(i=101;i<=200;i++)
    {
        printf("Thread2 with counter : %d\n", i);
    }
}

void* threadFunction3(void* ptr)
{
    int i = 0;
    for(i=201;i<=300;i++)
    {
        printf("Thread3 with counter : %d\n", i);
    }
}

void* threadFunction4(void* ptr)
{
    int i = 0;
    for(i=401;i<=500;i++)
    {
        printf("Thread4 with counter : %d\n", i);
    }
}

int main(int argc, char *argv[])
{
    pthread_t threadID1 = 0;
    pthread_t threadID2 = 0;
    pthread_t threadID3 = 0;
    pthread_t threadID4 = 0;

    int retVal = pthread_create(&threadID1,NULL,threadFunction1,NULL);
    if(retVal != 0)
    {
        printf("Unable to create thread 1\n");
        return -1;
    }

    retVal = pthread_create(&threadID2,NULL,threadFunction2,NULL);
    if(retVal != 0)
    {
        printf("Unable to create thread 2\n");
        return -1;
    }

    retVal = pthread_create(&threadID3,NULL,threadFunction3,NULL);
    if(retVal != 0)
    {
        printf("Unable to create thread 3\n");
        return -1;
    }

    retVal = pthread_create(&threadID4,NULL,threadFunction4,NULL);
    if(retVal != 0)
    {
        printf("Unable to create thread 4\n");
        return -1;
    }

    pthread_join(threadID1, NULL);
    pthread_join(threadID2, NULL);
    pthread_join(threadID3, NULL);
    pthread_join(threadID4, NULL);

    return 0;
}