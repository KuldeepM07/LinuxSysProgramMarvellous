#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// Program to take input - File Name from user
// and write whole file to monitor

#define BLOCK_SIZE 1024

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Invalid usage : Please provide file name to read\n");
        return -1;
    }

    int iFD = 0;
    char cBufferToRead[BLOCK_SIZE] = {'\0'};
    int iRetValRead = 0;
    iFD = open(argv[1], O_RDONLY);
    if(iFD == 0)
    {
        printf("Unable to read file: Invalid file name\n");
        return -1;
    }

    while((iRetValRead = read(iFD, cBufferToRead, sizeof(cBufferToRead))) != 0)
    {
        // 1 - Means we are writing to monitor
        // FD of monitor
        write(1, cBufferToRead, iRetValRead);
    }

    close(iFD);

    return 0;
}