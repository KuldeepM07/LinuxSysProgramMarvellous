
// Thread synchronization problem - 
// We have two thread one will print even numbers from 1 - 100
// Second thread should print odd numbers from 1 - 100
// Output Should be like
// 1 - Odd
// 2 - Even
// 3 - Odd
// 4 - Even
// ...
// ...
// Without syncronization output will be different

#include <stdio.h>
#include <pthread.h>

void* threadFunction1(void* ptr)
{
    int i = 0;
    for(i=1;i<=100;i++)
    {
        if(i%2 != 0)
        {
            printf("%d - Odd\n", i);
        }
    }
}

void* threadFunction2(void* ptr)
{
    int i = 0;
    for(i=1;i<=100;i++)
    {
        if(i%2 == 0)
        {
            printf("%d - Even\n", i);
        }
    }
}


int main(int argc, char *argv[])
{
    pthread_t threadID1 = 0;
    pthread_t threadID2 = 0;
   
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

    pthread_join(threadID1, NULL);
    pthread_join(threadID2, NULL);
    
    return 0;
}