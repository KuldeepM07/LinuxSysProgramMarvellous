
int calculateFactorialOfNumber(int iInputNumber)
{
    if(iInputNumber <= 0)
    {
        return 0;
    }

    int iFactorialOfNumber = 1;
    int iITR = 0;
    for(iITR=1;iITR<=iInputNumber;iITR++)
    {
        iFactorialOfNumber = iFactorialOfNumber*iITR;
    }

    return iFactorialOfNumber;
}