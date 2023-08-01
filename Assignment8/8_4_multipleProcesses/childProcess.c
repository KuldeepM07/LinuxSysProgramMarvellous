#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Inside child process with PID: %d and parent process ID %d\n", getpid(), getppid());

    return 0;
}