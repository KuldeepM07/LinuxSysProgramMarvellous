#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int iPIDFirstProcess = 0;
    int iPIDSecondProcess = 0;
    int iPIDThirdProcess = 0;

    // First process
    iPIDFirstProcess = fork();
    if(iPIDFirstProcess == 0)
    {
        execl("./childProcess", "", NULL);
    }
    else
    {
        printf("Created cild process with pid: %d\n", iPIDFirstProcess);
    }

    // Second process
    iPIDSecondProcess = fork();
    if(iPIDSecondProcess == 0)
    {
        execl("./childProcess", "", NULL);
    }
    else
    {
        printf("Created cild process with pid: %d\n", iPIDSecondProcess);
    }

    // Third process
    iPIDThirdProcess = fork();
    if(iPIDThirdProcess == 0)
    {
        execl("./childProcess", "", NULL);
    }
    else
    {
        printf("Created cild process with pid: %d\n", iPIDThirdProcess);
    }

    return 0;
}