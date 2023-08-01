#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Inside child process, Parent peocess PID : %d\n", getppid());

    return 0;
}