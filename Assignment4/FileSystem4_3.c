#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

// Write a program to accept two file names from user
// and check whether contents of that two files are equal or not

#define BLOCK_SIZE 1024

int main(int argc, char *argv)
{
    char cFirstFileName[256] = {'\0'};
    char cSecondFileName[256] = {'\0'};

    char cDataFromFirstFile[BLOCK_SIZE] = {"\0"};
    char cDataFromSecondFile[BLOCK_SIZE] = {"\0"};

    int iFDFirstFile = 0;
    int iFDSecondFile = 0;

    int iRetValReadBytesFirstFile = 0;
    int iRetValReadBytesSecondFile = 0;

    struct stat sObjFirstFile;
    struct stat sObjSecondFile;

    bool bFileAreDifferent = true;

    printf("Enter first file name:\n");
    scanf("%s", cFirstFileName);

    printf("Enter second file name:\n");
    scanf("%s", cSecondFileName);

    iFDFirstFile = open(cFirstFileName, O_RDONLY);
    if(iFDFirstFile == -1)
    {
        printf("Unable to open first file : Invalid file name");
        return -1;
    }

    iFDSecondFile = open(cSecondFileName, O_RDONLY);
    if(iFDSecondFile == -1)
    {
        printf("Unable to open second file : Invalid file name");
        return -1;
    }

    stat(cFirstFileName, &sObjFirstFile);
    stat(cSecondFileName, &sObjSecondFile);

    if(sObjFirstFile.st_size != sObjSecondFile.st_size)
    {
        printf("Both files are different\n");
    }
    else
    {
        // Compare file bytes/Data
        strcpy(cDataFromFirstFile, "");
        strcpy(cDataFromSecondFile, "");
        while((iRetValReadBytesFirstFile = read(iFDFirstFile, cDataFromFirstFile, sizeof(cDataFromFirstFile))) != 0)
        {
           iRetValReadBytesSecondFile = read(iFDSecondFile, cDataFromSecondFile, sizeof(cDataFromSecondFile));
           
            if(memcmp(cDataFromFirstFile, cDataFromSecondFile, iRetValReadBytesFirstFile) != 0)
            {
                bFileAreDifferent = true;
                break;
            }
        }

        if(bFileAreDifferent == true)
        {
            printf("Contents of both the files are same\n");
        }
        else
        {
            printf("Contents of both the files are different\n");
        }
    }

    return 0;
}