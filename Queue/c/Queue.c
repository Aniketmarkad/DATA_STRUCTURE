#include<stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node ** PPNODE;

void Enqueue (PPNODE first,int ino ) // insert last
{
    PNODE newn = (PNODE *)malloc (sizeof(NODE));
    PNODE temp = NULL;

    newn->data = ino;
    newn->next = NULL;

    if( *first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

int Dequeue (PPNODE first )   // delete first
{
    PNODE temp = NULL;
    int data = 0;

    if(*first == NULL)
    {
        printf("queue is empty \n");
        return -1;
    }
    else
    {
        temp = *first ;
        *first = temp->next;
        data = temp->data;
        free(temp);

        return data;
    }
    
}

int Count(PNODE first)
{
    PNODE temp = first;
    int iCount = 0;

    while(temp != NULL)
    {
        iCount ++;
        temp = temp->next;
    }

    return iCount;

}

void Display(PNODE first)
{
    PNODE temp = first;

    while(temp != NULL)
    {
        printf(" |  %d   | - " ,temp->data);
        temp = temp-> next;
    }
    printf("\n");


}

int main()
{
    PNODE head = NULL;
    int iRet =0;

    Enqueue(&head,10);
    Enqueue(&head,20);
    Enqueue(&head,30);
    Enqueue(&head,40);

    Display(head);

    iRet = Count(head);
    printf("no of element in queue :%d\n",iRet);

    Dequeue(&head);

    Display(head);

    iRet = Count(head);
    printf("no of element in queue :%d\n",iRet);

    return 0;
}