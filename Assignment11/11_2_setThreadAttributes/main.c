#define _GNU_SOURCE
#include <stdio.h>
#include <pthread.h>

void* threadFunction1(void* ptr)
{
    int retVal = 0;
    pthread_attr_t threadParams;

    size_t iDefaultThreadStackSize = 0;

    retVal = pthread_getattr_np(pthread_self(), &threadParams);

    retVal = pthread_attr_getstacksize(&threadParams, &iDefaultThreadStackSize);

    printf("Stack size inside thread 1 is  : %ld\n", iDefaultThreadStackSize);
}

void* threadFunction2(void* ptr)
{
   int retVal = 0;
    pthread_attr_t threadParams;

    size_t iDefaultThreadStackSize = 0;

    retVal = pthread_getattr_np(pthread_self(), &threadParams);

    retVal = pthread_attr_getstacksize(&threadParams, &iDefaultThreadStackSize);

    printf("Stack size inside thread 2 is  : %ld\n", iDefaultThreadStackSize);
}


int main(int argc, char *argv[])
{
    pthread_t threadID1 = 0;
    pthread_t threadID2 = 0;

    pthread_attr_t threadAtrributes1;
    int iRetValThreadAtrributes = 0;
    iRetValThreadAtrributes = pthread_attr_init(&threadAtrributes1);
    if(iRetValThreadAtrributes == -1)
    {
        printf("Unable to initialize thread attributes\n");
        return -1;
    }
    
    size_t iDefaultThreadStackSize = 0;
    pthread_attr_init(&threadAtrributes1);
    iRetValThreadAtrributes = pthread_attr_getstacksize(&threadAtrributes1, &iDefaultThreadStackSize);
    if(iRetValThreadAtrributes == -1)
    {
        printf("Unable to initialize get thread attributes\n");
        return -1;
    }

    printf("Default statck size of thread  is %ld\n", iDefaultThreadStackSize);
    printf("Minimum stack size is %ld\n", PTHREAD_STACK_MIN);

    iRetValThreadAtrributes = pthread_attr_setstacksize(&threadAtrributes1, PTHREAD_STACK_MIN);
    if(iRetValThreadAtrributes == -1)
    {
        printf("Unable to initialize set thread attributes\n");
        return -1;
    }

    iRetValThreadAtrributes = pthread_attr_getstacksize(&threadAtrributes1, &iDefaultThreadStackSize);
    if(iRetValThreadAtrributes == -1)
    {
        printf("Unable to initialize get thread attributes after set\n");
        return -1;
    }

    printf("New statck size of thread 1 is %ld\n", iDefaultThreadStackSize);

    int retVal = pthread_create(&threadID1,&threadAtrributes1,threadFunction1,NULL);
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

    pthread_join(threadID1, NULL);
    pthread_join(threadID2, NULL);
    
    iRetValThreadAtrributes = pthread_attr_destroy(&threadAtrributes1);

    return 0;
}