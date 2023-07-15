#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// Write a program which accept directory name from user
// and write contents of all regular files and to single file

struct FileInfo
{
    char cFileName[256];
    int iFileSize;
};

#define BLOCK_SIZE 1024

int main(int argc, char *argv[])
{
    char cDestinationDirectory[256] = {'\0'};
    char cFileNameToRead[256] = {'\0'};
    char cNameFileNameToCreate[256] = {'\0'};
    
    int iFDDestinationFile = 0;
    int iFDOfSourceFileForReading = 0;
    int iRetValReadBytes = 0;
    char cBufferForReadingBytes[BLOCK_SIZE];
    memset(cBufferForReadingBytes, '\0', BLOCK_SIZE);
   
    printf("Enter file name to read details: \n");
    scanf("%s", cFileNameToRead);

    printf("Enter destination directory name: \n");
    scanf("%s", cDestinationDirectory);

    if(-1 == mkdir(cDestinationDirectory, 0777))
    {
        printf("Unable to create destination directory : Invalid directory name");
        return -1;
    }

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
        printf("-------------------------------------------\n");
        printf("Name of File: %s\n", uObjFileInfoRead.cFileName);
        printf("Size of File: %d\n", uObjFileInfoRead.iFileSize);
        printf("-------------------------------------------\n");

        // Create File with name
        iFDDestinationFile = 0;
        iTempFilesBytesRead = 0;
        iTotalByesReadFromFile = 0;

        sprintf(cNameFileNameToCreate, "%s/%s", cDestinationDirectory, uObjFileInfoRead.cFileName);
        printf("File name to create : %s\n", cNameFileNameToCreate);
        iFDDestinationFile = creat(cNameFileNameToCreate, 0777);
        if(iFDDestinationFile != -1)
        {
            memset(cBufferForReadingBytes,'\0', BLOCK_SIZE);
            while(iTotalByesReadFromFile != uObjFileInfoRead.iFileSize)
            {
                if(uObjFileInfoRead.iFileSize > BLOCK_SIZE)
                {
                    iTempFilesBytesRead = BLOCK_SIZE;
                }
                else
                {
                    iTempFilesBytesRead = uObjFileInfoRead.iFileSize;
                }

                printf("Reading bytes for file : %d\n", iTempFilesBytesRead);
                
                // Read Byets
                iRetValReadBytes = read(iFDOfSourceFileForReading, cBufferForReadingBytes, iTempFilesBytesRead);

                // Write exact byte to newly created file
                write(iFDDestinationFile, cBufferForReadingBytes, iRetValReadBytes);
                
                // Update counter for total bytes read
                iTotalByesReadFromFile = iTotalByesReadFromFile + iRetValReadBytes;
            }
        }
        close(iFDDestinationFile);
    }

    close(iFDOfSourceFileForReading);

    return 0;
}