#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

// Write a program which writes structure in file
//Structure should contain information about student
#pragma pack(1)
struct StudentInfo
{
    int iRollNo;
    char cStudentName[24];
    float fMarks;
    int age;
};

int main(int argc, char *argv[])
{
    struct StudentInfo objStudentInfo;
    objStudentInfo.iRollNo = 29;
    objStudentInfo.fMarks = 84.25;
    objStudentInfo.age = 36;
    strcpy(objStudentInfo.cStudentName, "Kuldeep");

    int iFDSourceFile = 0;
    char cFileNameToWrite[24] = {'\0'};

    printf("Please enter file name: \n");
    scanf("%s", cFileNameToWrite);

    iFDSourceFile = creat(cFileNameToWrite, 0777);
    if(iFDSourceFile == -1)
    {
        printf("Unable to create file: Invalid file name");
        return -1;
    }

    write(iFDSourceFile, &objStudentInfo, sizeof(objStudentInfo));

    close(iFDSourceFile);

    return 0;
}