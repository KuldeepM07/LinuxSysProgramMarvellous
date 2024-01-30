#include <stdio.h>
#include <fcntl.h>

// Test Comment

// Take input file name from user and open that file
int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Invalid usage: Please provide file name to opne\n");
        return -1;
    }

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
    

    return 0;
}
