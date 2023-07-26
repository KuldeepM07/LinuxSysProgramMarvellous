#include <dlfcn.h>
#include <stdio.h>
#include "mathFactorialLib.h"

int loadLibraryAndCalculateFactorial(int iInputNumber)
{
    void *pDLL = NULL;
    int (*fnCalculateFactorial)(int);

    pDLL = dlopen("./mathFactorialLib.so", RTLD_LAZY);
    if(NULL == pDLL)
    {
        printf("Unable load inside DLL\n");
        return -1;
    }

    fnCalculateFactorial = dlsym(pDLL, "calculateFactorialOfNumber");
    if(NULL == fnCalculateFactorial)
    {
        printf("Unable to load factorial inside DLL function\n");
        return -1;
    }

    return fnCalculateFactorial(iInputNumber);
}