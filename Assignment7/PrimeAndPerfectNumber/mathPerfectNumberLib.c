
int checkPerfectNumber(int iInputNumber)
{
    if(iInputNumber <= 0)
    {
        // This is negative numbet - Not a perfect number
        return 0;
    }

    int iITR=0;
    int iSumOfAllDivisors = 0;

    // Number is perfect number when
    // sum of all its divisors is eqaul to 
    // number itself 
    for(iITR=1;iITR<iInputNumber;iITR++)
    {
        if(iInputNumber%iITR == 0)
        {
            iSumOfAllDivisors = iSumOfAllDivisors + iITR;
        }
    }

    if(iSumOfAllDivisors == iInputNumber)
    {
        // Number is perfect number
        return 1;
    }
}