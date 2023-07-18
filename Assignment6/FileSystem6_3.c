#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

// Write a program which accept directory name and file name from user and
// create new file in that directory

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("INvalid usage: Please provide directory name and file name to be created\n");
        return -1;
    }

    int iResultDirectory = 0;
    int iFileCreatedFD = 0;
    char cNewFileName[256] = {'\0'};

    iResultDirectory = mkdir(argv[1], 0777);

    if(iResultDirectory == -1)
    {
        printf("Unable to create directory with specified name");
        return -1;
    }

    sprintf(cNewFileName, "%s/%s", argv[1], argv[2]);

    iFileCreatedFD = creat(cNewFileName, 0777);
    if(iFileCreatedFD == -1)
    {
        printf("Unable to create new directory and file name\n");
        return -1;
    }

    printf("Create file: %s\n", cNewFileName);

    return 0;
}