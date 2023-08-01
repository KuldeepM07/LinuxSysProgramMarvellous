#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <errno.h>

int main()
{
    int ret = 0;

    ret = getpriority(PRIO_PROCESS, 0);

    printf("Current priority of process is %d\n", ret);

    ret = nice(-10);
    //ret = getpriority(PRIO_PROCESS, 0);

    printf("Current priority of process is %d\n", errno);

    return 0;
}