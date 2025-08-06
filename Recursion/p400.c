// write program which add first 5 number using recurcion

#include<stdio.h>

int Addition()
{
    static int iSum = 0,i = 0;

    if(i <= 5)
    {
        iSum = iSum + i;
        i++;
        Addition();
  
    }
    return iSum;

}

int main()
{
    int iRet = 0;

    iRet = Addition();

    printf("sum of first 5 element is :%d \n",iRet);

    return 0;
}