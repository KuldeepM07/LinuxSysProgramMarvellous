#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// Write a program which accept directory name from user
// and write information of all regular files and to single file
// and read from that file and display
struct FileInfo
{
    char cFileName[256];
    int iFileSize;
};


int main(int argc, char *argv[])
{
    char cSourceDirectoryName[256] = {'\0'};
    char cFileNameToCreate[256] = {'\0'};
    char cFileName[256] = {'\0'};
   
    int iFDDestinationFile = 0;
   
    DIR *directorySource = NULL;
    struct dirent *directoryEntry = NULL;
    struct stat sObjFileStat;

    struct FileInfo uObjFileInfo;

    printf("Enter source directory name: \n");
    scanf("%s", cSourceDirectoryName);

    printf("Enter file name to write details: \n");
    scanf("%s", cFileNameToCreate);

    directorySource = opendir(cSourceDirectoryName);
    if(NULL == directorySource)
    {
        printf("Unable to open source directory : Invalid directory name");
        return -1;
    }

    iFDDestinationFile = creat(cFileNameToCreate, 0777);
    if(iFDDestinationFile == -1)
    {
        printf("Unable to create destination file");
        return -1;
    }

    while((directoryEntry = readdir(directorySource)) != NULL)
    {
        sprintf(cFileName, "%s/%s", cSourceDirectoryName, directoryEntry->d_name);
        stat(cFileName, &sObjFileStat);
        
        if(S_ISREG(sObjFileStat.st_mode))
        {
            memset(uObjFileInfo.cFileName, '\n', 256);
            strcpy(uObjFileInfo.cFileName, cFileName);
            uObjFileInfo.iFileSize = sObjFileStat.st_size;

            write(iFDDestinationFile, &uObjFileInfo, sizeof(uObjFileInfo));
        }
    }

    // Close the directory - Done with writing
    closedir(directorySource);
    close(iFDDestinationFile);

    // Now read file details and display list of all files
    iFDDestinationFile = 0;
    iFDDestinationFile = open(cFileNameToCreate, O_RDONLY);

    if(iFDDestinationFile == -1)
    {
        printf("Unable to open file for reading\n");
        return -1;
    }

    struct FileInfo uObjFileInfoRead;
    
    //printf("Return read bytes :%d FD %d File Name %s\n", iRetValReturnBytes, iFDDestinationFile, cFileName);
    while(read(iFDDestinationFile, &uObjFileInfoRead, sizeof(uObjFileInfoRead)) > 0)
    {
        printf("-------------------------------------------\n");
        printf("Name of File: %s\n", uObjFileInfoRead.cFileName);
        printf("Size of File: %d\n", uObjFileInfoRead.iFileSize);
        printf("-------------------------------------------\n");
    }

    close(iFDDestinationFile);

    return 0;
}