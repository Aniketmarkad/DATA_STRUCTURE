 a#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data ;
    struct node * next;
    struct node * prev;
};

typedef struct node  NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void insertfirst(PPNODE first,PPNODE last,int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn ->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;

        (*last)->next = *first;
        (*first)-> prev = *last;
    }
    else
    {
        newn->next = *first;
        (*first)->prev = newn;
        *first = newn;

        (*last)->next = *first;
        (*first)-> prev = *last;

    }

}

void insertlast(PPNODE first,PPNODE last,int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn ->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;

        (*last)->next = *first;
        (*first)-> prev = *last;
    }
    else
    {
        (*last)->next = newn;
        newn-> prev = *last;
        *last = newn;
        
        (*last)->next = *first;
        (*first)-> prev = *last;

    }
}

void deletefirst(PPNODE first,PPNODE last)
{
    PNODE temp = NULL ;

    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if(*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        temp = *first;
        *first = temp -> next;
        free(temp);

        (*last)-> next = *first;
        (*first)-> prev = *last;

    }
}

void deletelast(PPNODE first,PPNODE last)
{
    PNODE temp = NULL;

    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if(*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        temp = (*last)->prev;
        free(*last);
        *last = temp;

        (*last)->next = *first;
        (*first)->prev = *last;
    }
}

void display(PNODE first,PNODE last)
{
    PNODE temp = NULL;
    temp = first;

    if(first == NULL && last == NULL)
    {
        return;
    }

    printf("NULL");
    do
    {
        printf("| %d | <=> ",temp -> data);
        temp = temp -> next;
    }while(temp != first);
    printf("NULL\n");

}

int count(PNODE first,PNODE last)
{
    PNODE temp = NULL;
    int icount = 0;
    temp = first;

    if(first == NULL && last == NULL)
    {
        return icount;
    }

    do
    {
        icount++;
        temp = temp -> next;
    }while(temp != first);

    return icount;
  
}

void insertatpos(PPNODE first,PPNODE last,int no,int pos)
{
    PNODE temp = NULL;
    PNODE newn = NULL;
    int icnt = 0;
    int icount = 0;

    icount = count(*first,*last);

    if(pos < 1 || pos > icount + 1)
    {
        printf("invalid position\n");
        return;
    }

    if(pos == 1)
    {
        insertfirst(first,last,no);
    }
    else if(pos == icount + 1)
    {
        insertlast(first,last,no);
    }
    else
    {
        temp = *first;

        newn = (PNODE)malloc(sizeof (NODE));

        newn -> data = no;
        newn -> next = NULL;
        newn -> prev = NULL;

        for(icnt = 1;icnt < pos-1; icnt++)
        {
            temp = temp ->next;
        }
        newn->next = temp ->next;
        temp ->next ->prev = newn;
        temp->next = newn;
        newn->prev = temp;

    }
}
void deleteatpos(PPNODE first,PPNODE last,int pos)
{
    PNODE target = NULL;
    PNODE temp = NULL;
    int icnt = 0;
    int icount = 0;

    icount = count(*first,*last);

    if(pos < 1 || pos > icount)
    {
        printf("invalid position\n");
        return;
    }

    if(pos == 1)
    {
        deletefirst(first,last);

    }
    else if(pos == icount)
    {
        deletelast(first,last);
    }
    else
    {
        temp = *first;

        for(icnt = 1;icnt < pos -1;icnt++)
        {
            temp = temp -> next;
        }
        target = temp -> next;
        temp -> next = target ->next;
        temp -> next ->prev = temp;

        free(target);

    }
}

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;
    int iret = 0;

    insertfirst(&head,&tail,51);
    insertfirst(&head,&tail,21);
    insertfirst(&head,&tail,11);

    display(head,tail);
    iret = count(head,tail);
    printf("no of element in linklist is :%d\n",iret);

    insertlast(&head,&tail,101);
    insertlast(&head,&tail,111);
    insertlast(&head,&tail,121);

    display(head,tail);
    iret = count(head,tail);
    printf("no of element in linklist is :%d\n",iret);

    deletefirst(&head,&tail);

    display(head,tail);
    iret = count(head,tail);
    printf("no of element in linklist is :%d\n",iret);

    deletelast(&head,&tail);

    display(head,tail);
    iret = count(head,tail);
    printf("no of element in linklist is :%d\n",iret);

    insertatpos(&head,&tail,105,5);

    display(head,tail);
    iret = count(head,tail);
    printf("no of element in linklist is :%d\n",iret);

    deleteatpos(&head,&tail,5);

    display(head,tail);
    iret = count(head,tail);
    printf("no of element in linklist is :%d\n",iret);

    
    return 0;
}
