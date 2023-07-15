#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Invalid usage: Please provide file name and number bytes to read\n");
        return -1;
    }

    int iNumberOfBytesToRead = atoi(argv[2]);

    char *pcBytesToRead = (char *)malloc(iNumberOfBytesToRead);

    int fd = 0;
    fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open specified file\n");
        return -1;
    }
    else
    {
        printf("File opened with FD : %d\n", fd);
    }
    
    int iRetValBytes = read(fd, pcBytesToRead, iNumberOfBytesToRead);
    if(iRetValBytes == 0)
    {
        
        printf("Unable to read bytes from file\n");
    }
    else
    {
        //printf("%s\n", pcBytesToRead);
        write(1, pcBytesToRead, iRetValBytes);
    }

    free(pcBytesToRead);
    pcBytesToRead = NULL;

    return 0;
}