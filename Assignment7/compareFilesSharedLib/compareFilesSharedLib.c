#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BLOCK_SIZE 1024

int compareFiles(char* pcFileName1, char *pcFileName2)
{
    int fd1 = 0;
    int fd2 = 0;

    int iRetValReadBytes = 0;
    struct stat firstFile;
    struct stat secondFile;

    char cDataFromFirstFile[BLOCK_SIZE] = {'\0'};
    char cDataFromSecondFile[BLOCK_SIZE] = {'\0'};

    fd1 = open(pcFileName1, O_RDONLY);
    if(fd1 == -1)
    {
        printf("Unable to open first file\n");
        return -1;
    }

    fd2 = open(pcFileName2, O_RDONLY);
    if(fd2 == -1)
    {
        printf("Unable to open second file");
        return -1;
    }

    fstat(fd1, &firstFile);
    fstat(fd2, &secondFile);

    if(firstFile.st_size != secondFile.st_size)
    {
        return 0;
    }

    // Both files have same size compare both files
    while((iRetValReadBytes = read(fd1, cDataFromFirstFile, BLOCK_SIZE)) != 0)
    {
        iRetValReadBytes = read(fd2, cDataFromSecondFile, BLOCK_SIZE);
        if(memcmp(cDataFromFirstFile, cDataFromSecondFile, iRetValReadBytes) != 0)
        {
            break;
        }
    }

    close(fd1);
    close(fd2);

    if(0 == iRetValReadBytes)
    {
        // Both file are same
        return 1;
    }
    else 
    {
        return 0;
    }
}