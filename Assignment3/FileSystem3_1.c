#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

// Write a program to access two file names from user
// and copies all contents of first file to second file

#define BLOCK_SIZE 1024

int main(int argc, char *argv[])
{
    char cSourceFileName[256] = {'\0'};
    char cDestinationFileName[256] = {'\0'};

    int iFDSourceFile = 0;
    int iFDDestinationFile = 0;

    int iRetValReadBytes = 0;

    char cReadBytes[BLOCK_SIZE] = {'\0'};

    printf("Enter source file name:\n");
    scanf("%s", cSourceFileName);

    printf("Enter destination file name: \n");
    scanf("%s", cDestinationFileName);

    iFDSourceFile = open(cSourceFileName, O_RDONLY);
    if(iFDSourceFile == -1)
    {
        printf("UNable to open source file: Invalid file name");
        return -1;
    }

    iFDDestinationFile = creat(cDestinationFileName, 0777);
    if(iFDDestinationFile == -1)
    {
        printf("Unable to create/open destonation file");
        return -1;
    }

    while((iRetValReadBytes = read(iFDSourceFile, cReadBytes, sizeof(cReadBytes))) != 0)
    {
        write(iFDDestinationFile, cReadBytes, iRetValReadBytes);
    }
    close(iFDSourceFile);
    close(iFDDestinationFile);

}