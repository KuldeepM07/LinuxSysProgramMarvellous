#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

// Program to take input - File Name from user
// And write string to that File

#define BLOCK_SIZE 1024

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Invalid usage : Please provide file name to read\n");
        return -1;
    }

    int iFD = 0;
    char cBufferToWrite[BLOCK_SIZE] = {'\0'};
    strcpy(cBufferToWrite, "Data To Write To File");
    int iRetValRead = 0;
    iFD = open(argv[1], O_WRONLY);
    if(iFD == -1)
    {
        // File Not available Create File
        iFD = creat(argv[1], 0777);
        if(iFD == -1)
        {
            // Unable to create file
            printf("Unable to open/create file: Invalid file name\n");
            return -1;
        }
    }

    write(iFD, cBufferToWrite, strlen(cBufferToWrite));

    close(iFD);

    printf("File create with FD and file Name: %d   %s\n", iFD, argv[1]);

    return 0;
}