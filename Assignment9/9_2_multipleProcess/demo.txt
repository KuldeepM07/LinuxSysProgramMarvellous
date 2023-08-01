#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DESKTOP_RELATIVE_PATH "/home/kuldeep/Desktop"

int main(int argc, char *argv[])
{
    printf("Inside child process\n");

    DIR *pDirDesktop = NULL;
    struct dirent *pDirEntry = NULL;
    int fdNewFile = 0;
    char cFileName[512];
    struct stat objFile;

    pDirDesktop = opendir(DESKTOP_RELATIVE_PATH);
    if(NULL == pDirDesktop)
    {
        printf("Unable to open desktop directory\n");
        return -1;
    }

    fdNewFile = creat("Demo.txt", 0777);
     

    while((pDirEntry = readdir(pDirDesktop)) != NULL)
    {
        memset(cFileName, 0, 512);
        sprintf(cFileName, "%s/%s", DESKTOP_RELATIVE_PATH, pDirEntry->d_name);
        stat(cFileName, &objFile);
        if(S_ISREG(objFile.st_mode))
        {
            printf("%s\n", pDirEntry->d_name);
            write(fdNewFile, cFileName, strlen(cFileName));
            write(fdNewFile, "\n", strlen("\n"));
        }
    }

    close(fdNewFile);
    closedir(pDirDesktop);

    return 0;
}