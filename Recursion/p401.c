// write program of factorial  using recurcion

#include<stdio.h>

int Factorial()
{
    static int iSum = 1,i = 1;

    if(i <= 5)
    {
        iSum = iSum * i;
        i++;
        Factorial();
  
    }
    return iSum;

}

int main()
{
    int iRet = 0;

    iRet = Factorial();

    printf("factorial of 5 is  :%d \n",iRet);

    return 0;
}