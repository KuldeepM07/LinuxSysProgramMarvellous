#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    void *fPtrPrimeNumberDLL = NULL;
    void *fPtrPerfectNumberDLL = NULL;

    int (*fnPtrCheckPrimeNumber)(int);
    int (*fnPtrCheckPerfectNumber)(int);

    if(argc != 2)
    {
        printf("Invalid usage: Please provide number for prime and perfect number validation\n");
        return -1;
    }

    // Check prime number first
    fPtrPrimeNumberDLL = dlopen("./mathPrimeLib.so", RTLD_LAZY);
    if(NULL == fPtrPrimeNumberDLL)
    {
        printf("Unable to open prime number DLL\n");
        return -1;
    }

    fnPtrCheckPrimeNumber = dlsym(fPtrPrimeNumberDLL, "checkPrimeNumber");
    if(NULL == fnPtrCheckPrimeNumber)
    {
        printf("Unable to load prime number function\n");
        return -1;
    }

    if(fnPtrCheckPrimeNumber(atoi(argv[1])) == 1)
    {
        printf("%s is Prime number\n", argv[1]);
    }
    else
    {
        printf("%s is not prime number\n", argv[1]);
    }

    // Check perfect number
    fPtrPerfectNumberDLL = dlopen("./mathPerfectNumberLib.so", RTLD_LAZY);
    if(fPtrPerfectNumberDLL == NULL)
    {
        printf("Unable to open perfect number DLL\n");
        return -1; 
    }

    fnPtrCheckPerfectNumber = dlsym(fPtrPerfectNumberDLL, "checkPerfectNumber");
    if(NULL == fnPtrCheckPerfectNumber)
    {
        printf("Unable to load perfect number function\n");
        return -1;
    }

    if(fnPtrCheckPerfectNumber(atoi(argv[1])) == 1)
    {
        printf("%s is perfect number\n", argv[1]);
    }
    else
    {
        printf("%s is not perfect number\n", argv[1]);
    }
    return 0;
}