#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Invalid usage: Please provide file name and mode to check\n");
        return -1;
    }

    int fd = 0;
    int modeSpecifiedByUser = F_OK;

    if(strcmp(argv[2], "Read") == 0)
    {
        modeSpecifiedByUser = R_OK;
    }
    else if(strcmp(argv[2], "Write") == 0)
    {
        modeSpecifiedByUser = W_OK;
    }
    else
    {
        modeSpecifiedByUser = F_OK;
    }

    if(access(argv[1], modeSpecifiedByUser)< 0)
    {
        printf("Can not open file in specified mode\n");
    }
    else
    {
        printf("Can open file in specified mode\n");
    }

    return 0;
}
