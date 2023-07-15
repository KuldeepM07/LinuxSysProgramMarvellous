#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

// Write a program which accepts file name and position 
// from user and read 20 bytes from that position 
//

int main(int argc, char *argv[])
{
    char cFileName[256] = {'\0'};
    int iFromNumberOfBytes = 0;

    int iFDSourceFile = 0;
    char cBytesToRead[20] = {'\0'};
    int iRetValReadBytes = 0;
    int iRetValLSeek = 0;

    printf("Enter file name:\n");
    scanf("%s", cFileName);

    printf("Enter position from which to read bytes: ");
    scanf("%d", &iFromNumberOfBytes);

    iFDSourceFile = open(cFileName, O_RDONLY);
    if(iFDSourceFile == -1)
    {
        printf("Unable to open file: Invalid file name");
        return -1;
    }

    iRetValLSeek = lseek(iFDSourceFile, iFromNumberOfBytes, iFDSourceFile);
    if(iRetValLSeek == -1)
    {
        printf("Invalid seek position");
        return -1;
    }

    iRetValReadBytes = read(iFDSourceFile, cBytesToRead, sizeof(cBytesToRead));

    if(iRetValReadBytes > 0)
    {
        write(1, cBytesToRead, iRetValReadBytes);
    }

    close(iFDSourceFile);

    return 0;
}