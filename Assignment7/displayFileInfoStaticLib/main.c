#include <stdio.h>
#include "fileInfoStaticLib.h"

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Invalid usage: Please provide file name as input\n");
        return -1;
    }

    int retVal = 0;
    retVal = displayFileInfo(argv[1]);
    if(retVal == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    return 0;
}