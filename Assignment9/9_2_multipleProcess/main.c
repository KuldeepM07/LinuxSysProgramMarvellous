#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int iPIDOfChildProcess1 = 0;
    int iPIDOfChildProcess2 = 0;

    int iExitStatusProcess1 = 0;
    int iExitStatusProcess2 = 0;

    iPIDOfChildProcess1 = fork();
    if(iPIDOfChildProcess1 == 0)
    {
        execl("./childProcess1", "demo.txt", NULL);
    }
    else
    {
        printf("Create child process with PID : %d\n", iPIDOfChildProcess1);
        wait(&iExitStatusProcess1);
    }

    iPIDOfChildProcess2 = fork();
    if(iPIDOfChildProcess2 == 0)
    {
        execl("./childProcess1", "hello.txt", NULL);
    }
    else
    {
        printf("Create child process with PID : %d\n", iPIDOfChildProcess2);
        wait(&iExitStatusProcess2);
    }

    return 0;
}