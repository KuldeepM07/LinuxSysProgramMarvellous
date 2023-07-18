#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// Write a program which accept file name which contains data of all files
//We have to print all the file names whose size is greater
// than 10 bytes

struct FileInfo
{
    char cFileName[256];
    int iFileSize;
};

int main(int argc, char *argv[])
{
    char cFileNameToRead[256] = {'\0'};
    int iFDOfSourceFileForReading = 0;
    int iRetValReadBytes = 0;
   
    printf("Enter file name to read details: \n");
    scanf("%s", cFileNameToRead);

    // Now read file details and display list of all files
    iFDOfSourceFileForReading = 0;
    iFDOfSourceFileForReading = open(cFileNameToRead, O_RDONLY);

    if(iFDOfSourceFileForReading == -1)
    {
        printf("Unable to open file for reading\n");
        return -1;
    }

    struct FileInfo uObjFileInfoRead;
    int iTempFilesBytesRead = 0;
    int iTotalByesReadFromFile = 0;
    
    //printf("Return read bytes :%d FD %d File Name %s\n", iRetValReturnBytes, iFDDestinationFile, cFileName);
    while(read(iFDOfSourceFileForReading, &uObjFileInfoRead, sizeof(uObjFileInfoRead)) > 0)
    {
        if(uObjFileInfoRead.iFileSize > 10)
        {
            printf("-------------------------------------------\n");
            printf("Name of File: %s\n", uObjFileInfoRead.cFileName);
            printf("Size of File: %d\n", uObjFileInfoRead.iFileSize);
            printf("-------------------------------------------\n");
        }
        
        // Seek To Next File Name - No need to read byets
        // as we have to print only file names
        lseek(iFDOfSourceFileForReading, uObjFileInfoRead.iFileSize, SEEK_CUR);
    }

    close(iFDOfSourceFileForReading);

    return 0;
}