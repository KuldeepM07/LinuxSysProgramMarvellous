#include <stdio.h>
#include <pthread.h>
#include <string.h>

void* threadFunction1(void* ptr)
{
    int *pArrayOfInt = (int *)ptr;
    int iSizeOfArray = pArrayOfInt[0];
    int iSumOfAllElementsInArray = 0;

    printf("Size of array received is: %d\n", iSizeOfArray);

    for(int i=1;i<=iSizeOfArray;i++)
    {
        printf("Elements[%d]: %d\n", i, pArrayOfInt[i]);
        iSumOfAllElementsInArray = pArrayOfInt[i] + iSumOfAllElementsInArray;
    }

    pthread_exit(iSumOfAllElementsInArray);
}


int main(int argc, char *argv[])
{
    // Create Thread
    int iIntArray[6] = {5, 10, 20, 30, 40, 50}; // First element is size of array

    pthread_t threadID1 = 0;
    int iSummOfAll = 0;

    int retVal = pthread_create(
                                &threadID1, // Out : Thread ID
                                NULL,       // Thread Attributes
                                threadFunction1,    // Therad Routine
                                (int *)&iIntArray  // Parameter to thread routine
                                );
    if(retVal != 0)
    {
        printf("Unable to create thread 1\n");
        return -1;
    }
    pthread_join(threadID1, &iSummOfAll);

    printf("Sum of all elements is: %d\n", iSummOfAll);

    return 0;
}