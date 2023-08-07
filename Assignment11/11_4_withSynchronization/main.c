
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
//

#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;
pthread_cond_t condition;
int iCounter = 1;

void* threadFunction1(void* ptr)
{
    do
    {
        pthread_mutex_lock(&lock);

        if(iCounter%2 != 0)
        {
            // we will wait till counter gets increamented and 
            // other thread signals the condition
            pthread_cond_wait(&condition, &lock);
        }
        printf("%d - Odd\n", iCounter);
        iCounter++;
        pthread_cond_signal(&condition);

        pthread_mutex_unlock(&lock); 
    }while(iCounter<100);
}

void* threadFunction2(void* ptr)
{
   do
    {
        pthread_mutex_lock(&lock);

        if(iCounter%2 == 0)
        {
            // we will wait till counter gets increamented and 
            // other thread signals the condition
            pthread_cond_wait(&condition, &lock);
        }
        printf("%d - Even\n", iCounter);
        iCounter++;
        pthread_cond_signal(&condition);

        pthread_mutex_unlock(&lock); 
    }while(iCounter<100);

}


int main(int argc, char *argv[])
{
    pthread_t threadID1 = 0;
    pthread_t threadID2 = 0;

    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&condition, NULL);
   
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

    pthread_mutex_destroy(&lock);
    
    return 0;
}