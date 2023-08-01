#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pid = 0;
    int pidOfChildCompleted = 0;
    int exitStatusofChild = 0;

    printf("Parent process PID : %d\n", getpid());

    pid = fork();
    if(pid == 0)
    {
        execl("./childProcess", "", NULL);
    }
    else
    {
        printf("PID of child process is %d\n", pid);
        pidOfChildCompleted = wait(&exitStatusofChild);

        printf("Child process execution is completed\n");
    }

    return 0;
}