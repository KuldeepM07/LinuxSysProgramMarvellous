#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

// Write a program which writes emplyoee structure in file
// and read it from file
#pragma pack(1)
struct EmplyoeeInfo
{
    int iEmployeeID;
    char cEmployeeName[24];
};

int main(int argc, char *argv[])
{
    struct EmplyoeeInfo objEmployeeInfo;
    //objEmployeeInfo.iEmployeeID = 1456789;
    //strcpy(objEmployeeInfo.cEmployeeName, "Kuldeep");

    int iFDSourceFile = 0;
    char cFileNameToWrite[24] = {'\0'};

    printf("Please enter file name: \n");
    scanf("%s", cFileNameToWrite);

    // iFDSourceFile = creat(cFileNameToWrite, 0777);
    // if(iFDSourceFile == -1)
    // {
    //     printf("Unable to create file: Invalid file name");
    //     return -1;
    // }

    // write(iFDSourceFile, &objEmployeeInfo, sizeof(objEmployeeInfo));

    iFDSourceFile = open(cFileNameToWrite, O_RDONLY);
    if(iFDSourceFile == -1)
    {
        printf("Unable to open file: Invalid file name");
        return -1;
    }

    read(iFDSourceFile, &objEmployeeInfo, sizeof(objEmployeeInfo));

    printf("Emplyoee ID: %d\n", objEmployeeInfo.iEmployeeID);
    printf("Employee Name: %s\n", objEmployeeInfo.cEmployeeName);

    close(iFDSourceFile);
    
    return 0;
}