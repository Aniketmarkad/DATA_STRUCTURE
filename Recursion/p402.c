//write a program which accept number from user and  find factorial of that number using recursion
#include<stdio.h>

int Factorial(int ino)
{
    static int iSum = 1,i = 1;

    if(i <= ino)
    {
        iSum = iSum * i;
        i++;

        Factorial(ino);
  
    }
    return iSum;

}


int main()
{
    int iRet = 0;
    int ivalue = 0;

    printf("enter the number that you want to find factorial \n");
    scanf(" %d",&ivalue);

    iRet = Factorial(ivalue);

    printf(" factorial of number is :%d ",iRet);

    return 0;

}
