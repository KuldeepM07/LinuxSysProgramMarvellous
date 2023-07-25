#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "mathsSharedLib.h"

int main(int argc, char *argv[])
{
    void *ptr = NULL;
    int (*fptrAddition)(int, int);
    int (*fptrSubstraction)(int, int);
    int (*fptrMultiplication)(int, int);
    int (*fptrDivision)(int, int);

    ptr = dlopen("./mathsSharedLic.so", RTLD_LAZY);
    if(NULL == ptr)
    {
        printf("Unable to load the library\n");
        return -1;
    }

    fptrAddition = dlsym(ptr, "addition");
    if(NULL == fptrAddition)
    {
        printf("Unable to load the library function addition\n");
        return -1;
    }
    printf("Addition of 10 and 20 is : %d\n", fptrAddition(10, 20));

    fptrSubstraction = dlsym(ptr, "substraction");
    if(NULL == fptrSubstraction)
    {
        printf("Unable to load the library function substraction\n");
        return -1;
    }
    printf("Substraction of 100 and 75 is : %d\n", fptrSubstraction(100, 75));

    fptrMultiplication = dlsym(ptr, "multiplication");
    if(NULL == fptrMultiplication)
    {
        printf("Unable to load the library function multiplication\n");
        return -1;
    }
    printf("Multiplication of 1000 and 2000 is : %d\n", fptrMultiplication(1000, 2000));

    fptrDivision = dlsym(ptr, "division");
    if(NULL == fptrDivision)
    {
        printf("Unable to load the library function division\n");
        return -1;
    }
    printf("Division of 5000/20 is : %d\n", fptrDivision(5000, 20));


    return 0;
}