#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int pidChildProcess = 0;
    int pidOfChildFromWait = 0;
    int exitStatus = 0;
    printf("Inside first process with pid: %d\n", getpid());

    // Creating next process
    pidChildProcess = fork();
    if(pidChildProcess == 0)
    {
        //
        execl("./process2", "", NULL);
    }
    else
    {
        // Parent process
        printf("Created process with pid: %d\n", pidChildProcess);
        pidOfChildFromWait = wait(&exitStatus);
    }

    return 0;
}