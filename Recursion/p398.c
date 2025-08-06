//print 5 time jay ganesh on consol using recursion concepet

#include<stdio.h>

void Display()
{
   static int i = 0;

    if(i <= 5)
    {
        printf("jay ganesh..\n");
        i++;
        Display();
    }
}

int main()
{

    Display();
    return 0;
}