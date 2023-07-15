#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdbool.h>
#include <unistd.h>

// Write a program to access directory name and file name
// from user
// and check wheather file name is present in that directory


int main(int argc, char *argv[])
{
    char cSourceDirectoryName[256] = {'\0'};
    char cFileNameToBeChecked[256] = {'\0'};

    DIR *pDirectoryToBeChcked = NULL;
    struct dirent *pDirectoryToBeChckedEntry = NULL;

    bool bFileIsPresent = false;

    printf("Enter directory name to search:\n");
    scanf("%s", cSourceDirectoryName);

    printf("Enter file name to search in above directory:\n");
    scanf("%s", cFileNameToBeChecked);

    pDirectoryToBeChcked = opendir(cSourceDirectoryName);
    if(pDirectoryToBeChcked == NULL)
    {
        printf("Unable to open directory: Invalid directory name");
        return -1;
    }

    while((pDirectoryToBeChckedEntry = readdir(pDirectoryToBeChcked)) != NULL)
    {
        if(strcmp(cFileNameToBeChecked, pDirectoryToBeChckedEntry->d_name) == 0)
        {
            bFileIsPresent = true;
            break;
        }
    }

    if(bFileIsPresent == true)
    {
        printf("File is present in directory\n");
    }
    else
    {
        printf("File is not present in directory\n");
    }

    closedir(pDirectoryToBeChcked);

    return 0;
}