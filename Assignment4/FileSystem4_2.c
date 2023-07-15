#include <stdio.h>
#include <sys/stat.h>

// Write a program which accept directory name from user and
// create new directory of that name

int main(int argc, char *argv[])
{
    char cDirectoryNameToCreate[256] = {'\0'};
    int iResultDirectory = 0;

    printf("Enter directory name to be created:\n");
    scanf("%s", cDirectoryNameToCreate);

    iResultDirectory = mkdir(cDirectoryNameToCreate, 0777);

    if(iResultDirectory == -1)
    {
        printf("Unable to create directory with specified name");
        return -1;
    }

    return 0;
}