#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

// Write a program which accept two directory names from user and 
// move all the files from source directory to destination 
// directory

int main(int argc, char *argv[])
{
    char cSourceDirectoryName[256] = {'\0'};
    char cDestinationDirectoryName[256] = {'\0'};

    DIR *directorySource = NULL;
    struct dirent *directoryEntry = NULL;

    char cOldDirectoryAndFileName[256] = {'\0'};
    char cNewDirectoryAndFileName[256] = {'\0'};

    printf("Enter source directory name: \n");
    scanf("%s", cSourceDirectoryName);

    printf("Enter destination directory name: \n");
    scanf("%s", cDestinationDirectoryName);

    directorySource = opendir(cSourceDirectoryName);
    if(NULL == directorySource)
    {
        printf("Unable to open source directory : Invalid directory name");
        return -1;
    }

    if(-1 == mkdir(cDestinationDirectoryName, 0777))
    {
        printf("Unable to open/create destination directory");
        return -1;
    }

    while((directoryEntry = readdir(directorySource)) != NULL)
    {
        sprintf(cOldDirectoryAndFileName, "%s/%s", cSourceDirectoryName, directoryEntry->d_name);
        sprintf(cDestinationDirectoryName, "%s/%s", cDestinationDirectoryName, directoryEntry->d_name);

        rename(cOldDirectoryAndFileName, cDestinationDirectoryName);
    }

    // Close the directory
    closedir(directorySource);

    return 0;
}