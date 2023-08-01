#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int pidChildProcess = 0;
    printf("Inside third process with pid and parent pid: %d  %d\n", getpid(), getppid());
    return 0;
}