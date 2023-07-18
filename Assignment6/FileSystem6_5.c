#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Invalid usage: Please provide file and offset");
        return -1;
    }

    int iFDForFile = 0;
    iFDForFile = open(argv[1], O_RDWR);
    if(iFDForFile == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    if(ftruncate(iFDForFile, atoi(argv[2])) == -1)
    {
        printf("Unable to truncate file\n");
        return -1;
    }
}