#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include "factorialLibUsageLib.h"

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Invalid usage: Please provide number to calculate factorial\n");
        return -1;
    }

    void *pDLL = NULL;
    int (*fploadLibAndCalculate)(int);

    pDLL = dlopen("./factorialLibUsageLib.so", RTLD_LAZY);
    if(NULL == pDLL)
    {
        printf("Unable to dll\n");
        return -1;
    }

    fploadLibAndCalculate = dlsym(pDLL, "loadLibraryAndCalculateFactorial");
    if(NULL == fploadLibAndCalculate)
    {
        printf("Unable to dll function\n");
        return -1;
    }

    int iFactorialOfNumber = fploadLibAndCalculate(atoi(argv[1]));
    if(iFactorialOfNumber > 0)
    {
        printf("Factorial of number %s is %d\n", argv[1], iFactorialOfNumber);
    }
    return 0;
}