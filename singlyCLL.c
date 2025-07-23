#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void insertfirst(PPNODE first,PPNODE last,int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;

    if(*first == NULL && *last == NULL)
    {
       *first = newn;
       *last = newn;
       
       (*last)->next= *first;
    }
    else
    {
        newn -> next = *first;
        *first = newn;

        (*last)-> next = *first;
    }

}

void insertlast(PPNODE first,PPNODE last,int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn-> next = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;

        (*last)-> next = *first;

    }
    else
    {
        (*last)-> next = newn;
        *last = newn;

        (*last) -> next  = *first;

    }
}

void deletefirst(PPNODE first,PPNODE last )
{
    PNODE temp = NULL;

    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if (*first == *last)
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
        free(*last);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        temp = *first;
        while(temp-> next ->next != *first)
        {
            temp = temp->next;
        }
        *last = temp;
        free(temp->next);

        (*last)->next = *first;


    }
}

void display(PNODE first,PNODE last)
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    do
    {
        printf("| %d | -> ",first->data);
        first= first->next;
    }while(first != last-> next);
    printf("\n");
}

int count(PNODE first,PNODE last)
{
    int icount = 0;
    if(first == NULL && last == NULL)
    {
        return icount; 
    }

    do
    {
        icount++;
        first = first ->next;
    }while(first != last->next);
    return icount;
}

void insertatpos(PPNODE first,PPNODE last,int no,int pos)
{
    PNODE temp = NULL;
    PNODE newn = NULL;
    int icount = 0;
    int icnt = 0;

    icount = count(*first,*last);

    if(pos < 1 || pos > icount+1)
    {
        printf("invalid position entered \n");
        return;
    }

    if(pos == 1)
    {
        insertfirst(first,last,no);
    }
    else if(pos == icount+1)
    {
        insertlast(first,last,no);
    }
    else
    {
        temp = *first;

        newn = (PNODE)malloc(sizeof(NODE));

        newn ->data = no;
        newn->next = NULL;

        for(icnt = 1;icnt < pos-1;icnt++)
        {
            temp = temp->next;
        }
        newn->next = temp ->next;
        temp ->next = newn;
        
    }
}

void deleteatpos(PPNODE first,PPNODE last,int pos)
{
    PNODE temp = NULL;
    PNODE target = NULL;
    int icount = 0;
    int icnt = 0;

    icount = count(*first,*last);

    if (pos < 1 || pos > icount )
    {
        printf("invalid syntax\n");
        return ;
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

        for(icnt = 1;icnt < pos-1;icnt++)
        {
            temp = temp ->next;
        }

        target = temp->next;
        temp ->next = target ->next;
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