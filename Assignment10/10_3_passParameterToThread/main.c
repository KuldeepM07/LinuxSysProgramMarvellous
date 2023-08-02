#include <stdio.h>
#include <pthread.h>
#include <string.h>

struct StudentInfo
{
    char cName[32];
    int iRollNumber;
};

void* threadFunction1(void* ptr)
{
    struct StudentInfo *pObj = (struct StudentInfo *)ptr;
    printf("Student Name: %s\n", pObj->cName);
    printf("Student Roll Number: %d\n", pObj->iRollNumber);
}


int main(int argc, char *argv[])
{
    // Create Thread
    printf("Creating new thread\n");

    struct StudentInfo uObjStudentInfo;
    strcpy(uObjStudentInfo.cName, "Kuldeep");
    uObjStudentInfo.iRollNumber = 156;

    pthread_t threadID1 = 0;
    pthread_t threadID2 = 0;

    int retVal = pthread_create(
                                &threadID1, // Out : Thread ID
                                NULL,       // Thread Attributes
                                threadFunction1,    // Therad Routine
                                (struct StudentInfo *)&uObjStudentInfo  // Parameter to thread routine
                                );
    if(retVal != 0)
    {
        printf("Unable to create thread 1\n");
        return -1;
    }
    pthread_join(threadID1, NULL);


    return 0;
}