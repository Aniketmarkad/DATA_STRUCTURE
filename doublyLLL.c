#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void insertfirst(PPNODE first,int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data= no;
    newn->next = NULL;
    newn -> prev = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn ->next = *first;
        (*first) ->prev = newn;
        *first = newn;

    }
}

void insertlast(PPNODE first,int no)
{
    PNODE temp = NULL;
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data= no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;
        while(temp ->next != NULL)
        {
            temp = temp ->next;
        }
        temp->next = newn;
        newn->prev = temp;

    }
}

void deletefirst(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first) -> next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;
        *first = temp ->next;
        (*first) ->prev = NULL;
        free(temp);

    }
}
void deletelast(PPNODE first)
{

    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first) -> next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;
        while(temp->next->next != NULL)
        {
            temp = temp ->next;
        }
        free(temp->next);
        temp -> next = NULL;
    }
}

void display(PNODE first)
{
    PNODE temp = NULL;
    temp = first;

    printf("NULL <=>");
    while(temp != NULL)
    {
        printf("| %d | <=> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");


}

int count(PNODE first)
{
    PNODE temp = NULL;
    int icount = 0;

    temp = first;

    while(temp != NULL)
    {
        icount++;
        temp = temp -> next;
    }
    
    return icount;
}

void insertatpos(PPNODE first,int no,int pos)
{
    PNODE temp = NULL;
    PNODE newn = NULL;
    int icount = 0;
    int icnt = 0;

    icount = count(*first);

    if(pos < 1 || pos > icount+1)
    {
        printf("invalid position\n");
        return;
    }

    if(pos == 1)
    {
        insertfirst(first,no);
    }
    else if(pos == icount +1)
    {
        insertlast(first,no);
    }
    else
    {
        temp = *first;

        newn = (PNODE)malloc(sizeof(NODE));

        newn ->data = no;
        newn ->next = NULL;
        newn -> prev = NULL;

        for(icnt = 1; icnt < pos-1 ;icnt++)
        {
            temp = temp->next;
        }
        newn -> next = temp ->next;
        temp ->next->prev = newn;
        temp ->next = newn;
        newn-> prev = temp;


    }
}

void deleteatpos(PPNODE first,int pos)
{
    PNODE temp = NULL;
    PNODE target = NULL;
    int icount = 0;
    int icnt = 0;
    

    icount = count(*first);

    if(pos < 1 || pos > icount)
    {
        printf("invalid position\n");
        return;
    }

    if(pos == 1)
    {
        deletefirst(first);
    }
    else if(pos == icount )
    {
        deletelast(first);
    }
    else
    {
        temp = *first;

        for(icnt = 1; icnt < pos -1;icnt++)
        {
            temp = temp-> next;
        }
        target = temp -> next;
        temp ->next = target -> next;
        temp->next ->prev = temp;
        free(target);

    }
}

int main()
{
    PNODE head = NULL;
    int iret = 0;

    insertfirst(&head,51);
    insertfirst(&head,21);
    insertfirst(&head,11);

    display(head);

    iret = count(head);
    printf("no of element in linklist : %d\n",iret);

    insertlast(&head,101);
    insertlast(&head,111);
    insertlast(&head,121);

    display(head);

    iret = count(head);
    printf("no of element in linklist : %d\n",iret);

    deletefirst(&head);

    display(head);

    iret = count(head);
    printf("no of element in linklist : %d\n",iret);

    deletelast(&head);

    display(head);

    iret = count(head);
    printf("no of element in linklist : %d\n",iret);
    
    insertatpos(&head,105,3);

    display(head);

    iret = count(head);
    printf("no of element in linklist : %d\n",iret);

    deleteatpos(&head,3);

    display(head);

    iret = count(head);
    printf("no of element in linklist : %d\n",iret);


    return 0 ;
}

