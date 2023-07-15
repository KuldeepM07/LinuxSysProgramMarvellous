#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

// Write a program to get directory name from user and 
// printf all file names and types from that directory

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Invalid usage: Please provide director name");
        return -1;
    }

    DIR *directory = NULL;
    struct dirent *directoryEntry = NULL;
    struct stat objFile;
    char cFileName[256] = {'\0'};

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
            printf("Regular file: %s\n", cFileName);
        }
        else if(S_ISDIR(objFile.st_mode))
        {
            printf("Directory: %s\n", cFileName);
        }
        else if(S_ISLNK(objFile.st_mode))
        {
            printf("Link: %s\n", cFileName);
        }
    }

    // Close the directory
    closedir(directory);

    return 0;
}