#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// Write a program which accept directory name from user
// and copy first 10 bytes from all regular files
// from taht directory to newly create file named as Demo.txt

int main(int argc, char *argv[])
{
    char cSourceDirectoryName[256] = {'\0'};
    char cFileName[256] = {'\0'};
    strcpy(cFileName, "Demo.txt");
    int iFDSourceFile = 0;
    int iFDDestinationFile = 0;
    char cBytesToRead[10] = {'\0'};
    int iRetValReadBytes = 0;

    DIR *directorySource = NULL;
    struct dirent *directoryEntry = NULL;
    struct stat sObjFileStat;

    printf("Enter source directory name: \n");
    scanf("%s", cSourceDirectoryName);

    directorySource = opendir(cSourceDirectoryName);
    if(NULL == directorySource)
    {
        printf("Unable to open source directory : Invalid directory name");
        return -1;
    }

    iFDDestinationFile = creat(cFileName, 0777);
    if(iFDDestinationFile == -1)
    {
        printf("Unable to create destination file");
        return -1;
    }

    while((directoryEntry = readdir(directorySource)) != NULL)
    {
        sprintf(cFileName, "%s/%s", cSourceDirectoryName, directoryEntry->d_name);
        stat(cFileName, &sObjFileStat);
        if(sObjFileStat.st_size != 0)
        {
            if(S_ISREG(sObjFileStat.st_mode))
            {
                iFDSourceFile = open(cFileName, O_RDONLY);
                if(iFDSourceFile != -1)
                {
                    memset(cBytesToRead, '\0', 10);  
                    iRetValReadBytes = read(iFDSourceFile, cBytesToRead, 10);
                    if(iRetValReadBytes > 0)
                    {
                        write(iFDDestinationFile, cBytesToRead, iRetValReadBytes);
                    }
                }
                close(iFDSourceFile);
            }
        }
    }

    // Close the directory
    closedir(directorySource);
    close(iFDDestinationFile);

    return 0;
}