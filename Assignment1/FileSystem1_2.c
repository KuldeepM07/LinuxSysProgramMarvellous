#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Invalid usage: Please provide file name and mode to opne\n");
        return -1;
    }

    int fd = 0;
    int modeSpecifiedByUser = O_RDONLY;

    // O_RDONLY     Read Mode
    // O_RDWR       Read + Write Mode
    // O_WRONLY     Write Mode
    // O_CREATE     Create Mode

    if(strcmp(argv[2], "Read") == 0)
    {
        modeSpecifiedByUser = O_RDONLY;
    }
    else if(strcmp(argv[2], "Write") == 0)
    {
        modeSpecifiedByUser = O_WRONLY;
    }
    else
    {
        modeSpecifiedByUser = O_RDONLY;
    }

    fd = open(argv[1], modeSpecifiedByUser);
    if(fd == -1)
    {
        printf("Unable to open specified file\n");
        return -1;
    }
    else
    {
        printf("File opened with FD : %d\n", fd);
    }
    

    return 0;
}