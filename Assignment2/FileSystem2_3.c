#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

// Write a program to get directory name from user and 
// printf all file names from that directory

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Invalid usage: Please provide director name");
        return -1;
    }

    DIR *directory = NULL;
    struct dirent *directoryEntry = NULL;

    directory = opendir(argv[1]);
    if(NULL == directory)
    {
        printf("Unable to open directory : Invalid directory name");
        return -1;
    }

    while((directoryEntry = readdir(directory)) != NULL)
    {
        printf("%s\n", directoryEntry->d_name);
    }

    // Close the directory
    closedir(directory);

    return 0;
}