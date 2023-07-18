#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

// Write a program which accept directory name from user
// and delete all files whose size is greater than 100 bytes
// from that directory

#define NO_OF_BYTES 100

int main(int argc, char *argv[])
{
    char cSourceDirectoryName[256] = {'\0'};
    char cFileName[256] = {'\0'};

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

    while((directoryEntry = readdir(directorySource)) != NULL)
    {
        sprintf(cFileName, "%s/%s", cSourceDirectoryName, directoryEntry->d_name);
        stat(cFileName, &sObjFileStat);
        if(sObjFileStat.st_size >= NO_OF_BYTES)
        {
            if(S_ISREG(sObjFileStat.st_mode))
            {
                remove(cFileName);
            }
        }
    }

    // Close the directory
    closedir(directorySource);

    return 0;
}