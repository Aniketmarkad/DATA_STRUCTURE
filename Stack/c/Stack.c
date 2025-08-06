#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void Push (PPNODE first ,int ino)
{
    PNODE newn = (PNODE) malloc(sizeof(NODE));

    newn->data = ino;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        *first = newn;
    }
}

int Pop(PPNODE first)
{
    PNODE temp = *first;
    int data = 0;

    if(*first == NULL)
    {
        printf("stack is empty no element to pop \n");
        return -1;
    }
    else
    {
        *first = temp->next;
        data = temp->data;
        free(temp);

        return data;
    }
}

void Display(PNODE first )
{
    PNODE temp = first;
    
    while(first != NULL)
    {
        printf(" |  %d  | \n",first->data );
        first = first->next;
    }

    printf("\n");

}

int Count(PNODE first)
{

    int iCount = 0;
    PNODE temp = first;
    
    while(first != NULL)
    {
       iCount++;
       first = first->next;
    }
    return iCount;
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;
    int i = 0,isize= 0;
    int ivalue = 0;

    printf("enetr no element you want to enter : \n"); 
    scanf("%d",&isize);

    for(i = 1;i <= isize;i++)
    {
        scanf("%d",&ivalue);
        Push(&head,ivalue);
    }
    
    Display(head);

    iRet = Count(head);
    printf("no of element in Stack : %d\n",iRet);

    iRet = Pop(&head);
    printf("element poped from stack is : %d\n",iRet);

    Display(head);

    iRet = Count(head);
    printf("no of element in Stack : %d\n",iRet);
    
    return 0 ;
}