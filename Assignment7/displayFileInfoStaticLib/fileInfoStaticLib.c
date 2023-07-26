#include <stdio.h>
#include <sys/stat.h>


int displayFileInfo(char *pcFileName)
{
    struct stat fileDetails;
    if(stat(pcFileName, &fileDetails) == -1)
    {
        return -1;
    }

    printf("Details of file %s:\n", pcFileName);
    printf("Size of file: %ld\n", fileDetails.st_size);
    if(S_ISREG(fileDetails.st_mode))
    {
        printf("Regular file\n");
    }
    else if(S_ISDIR(fileDetails.st_mode))
    {
        printf("Directory\n");
    }
    else if(S_ISLNK(fileDetails.st_mode))
    {
        printf("Link\n");
    }
    printf("Inode number: %ld\n", fileDetails.st_ino);

    return 1;
}