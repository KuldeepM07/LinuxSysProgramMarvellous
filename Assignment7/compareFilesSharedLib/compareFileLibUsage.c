#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Invalid usage: Please provide file names to compare\n");
        return -1;
    }

    void *ptrDLL = NULL;
    int (*fptrCompareFile)(char*, char*);

    ptrDLL = dlopen("./comapreFilesSharedLib.so", RTLD_LAZY);
    if(NULL == ptrDLL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    fptrCompareFile = dlsym(ptrDLL, "compareFiles");
    if(NULL == fptrCompareFile)
    {
        printf("Unable to load library function\n");
        return -1;
    }

    if(fptrCompareFile(argv[1], argv[2]) == 1)
    {
        printf("Both files are same\n");
    }
    else
    {
        printf("Both files are different\n");
    }

    return 0;
}