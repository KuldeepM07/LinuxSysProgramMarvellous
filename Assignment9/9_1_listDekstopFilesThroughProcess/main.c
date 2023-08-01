#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int PIDChildProcess = 0;
    PIDChildProcess = fork();
    if(PIDChildProcess == 0)
    {
        execl("./childProcess", "NULL", NULL);
    }
    else
    {
        printf("Child provcess created with PID : %d\n", PIDChildProcess);
    }
}