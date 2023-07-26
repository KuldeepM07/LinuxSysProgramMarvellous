#include "mathPrimeLib.h"

int checkPrimeNumber(int iInputNumber)
{
    if(iInputNumber <= 1)
    {
        // NUmber is not prime number
        return 0;
    }

    int iITR=0;
    for(iITR=2;iITR<iInputNumber;iITR++)
    {
        if(iInputNumber%iITR == 0)
        {
            // Not a prime number
            return 0;
        }
    }

    // Else - This is prime number
    return 1;
} 