
#include <stdio.h>
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BLOCK_SIZE 1024

void* threadFunction1(void* ptr)
{
    int iFD = open("Demo.c", O_RDONLY);

    iFD = open("Demo.c", O_RDONLY);
    if(iFD == -1)
    {
        printf("Unable to open the file\n");
        return -1;
    }

    int iCount = 0;
    int iRet = 0;
    char bufferRead[BLOCK_SIZE];

    int iCounter = 0;

    while((iRet = read(iFD, bufferRead, sizeof(bufferRead))) != 0)
    {
        for(iCounter=0;iCounter<iRet;iCounter++)
        {
            if(bufferRead[iCounter] >= 'A' && bufferRead[iCounter] <= 'Z')
            {
                iCount++;
            }
        }
    }

    close(&iFD);

    pthread_exit(iCount);
}

void* threadFunction2(void* ptr)
{
    int iFD = open("Demo.c", O_RDONLY);

    iFD = open("Demo.c", O_RDONLY);
    if(iFD == -1)
    {
        printf("Unable to open the file\n");
        return -1;
    }

    int iCount = 0;
    int iRet = 0;
    char bufferRead[BLOCK_SIZE];

    int iCounter = 0;

    while((iRet = read(iFD, bufferRead, sizeof(bufferRead))) != 0)
    {
        for(iCounter=0;iCounter<iRet;iCounter++)
        {
            if(bufferRead[iCounter] >= 'a' && bufferRead[iCounter] <= 'z')
            {
                iCount++;
            }
        }
    }

    close(&iFD);

    pthread_exit(iCount);
}


int main(int argc, char *argv[])
{
    pthread_t threadID1 = 0;
    pthread_t threadID2 = 0;

    int iCapitalLetters = 0;
    int iSmallCaseLetters = 0;
   
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

    pthread_join(threadID1, &iCapitalLetters);
    pthread_join(threadID2, &iSmallCaseLetters);

    printf("Capital letter count from files is : %d\n", iCapitalLetters);
    printf("Smallcase letter count from files is : %d\n", iSmallCaseLetters);
    
    return 0;
}