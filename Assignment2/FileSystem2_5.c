#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

// Write a program to get directory name from user and 
// printf largest file name in that directory

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Invalid usage: Please provide directory name");
        return -1;
    }

    DIR *directory = NULL;
    struct dirent *directoryEntry = NULL;
    struct stat objFile;
    char cFileName[256] = {'\0'};
    char cLargestFileNameInDirectory[256] = {'\0'};
    int iMaxFileSize = 0;

    directory = opendir(argv[1]);
    if(NULL == directory)
    {
        printf("Unable to open directory : Invalid directory name");
        return -1;
    }

    while((directoryEntry = readdir(directory)) != NULL)
    {
        sprintf(cFileName, "%s/%s", argv[1], directoryEntry->d_name);
        stat(cFileName, &objFile);
        if(S_ISREG(objFile.st_mode))
        {
            if(iMaxFileSize < objFile.st_size)
            {
                iMaxFileSize = objFile.st_size;
                strcpy(cLargestFileNameInDirectory, cFileName);
            }
        }
    }

    printf("Largest file name from directory: \n");
    printf("File Name : %s\n", cLargestFileNameInDirectory);
    printf("File Size: %d\n", iMaxFileSize);

    // Close the directory
    closedir(directory);

    return 0;
}