#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insertfirst(struct node ** first,int no)
{
    struct node * newn = NULL;

    newn = (struct node *)malloc(sizeof(struct node));

    newn-> data = no;
    newn-> next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn-> next = *first;
        *first = newn;
    }
}

void insertlast(struct node ** first,int no)
{
    struct node * newn = NULL;
    struct node * temp = NULL;

    newn = (struct node *)malloc (sizeof(struct node));

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;

        while(temp->next != NULL)
        {
            temp = temp-> next;
        }
        temp -> next = newn;

    }


}

void deletefirst(struct node ** first)
{
    struct node * temp= NULL;

   if(*first == NULL)
   {
        return ;
   }
   else if( (*first)-> next == NULL)
   {
        free(*first);
        *first = NULL;
   }
   else
   {
       temp = *first;
       *first = temp -> next;
       free(temp);
       
   }
}

void deletelast(struct node ** first)
{
    struct node * temp = NULL;

    if(*first == NULL)
    {
         return ;
    }
    else if( (*first)-> next == NULL)
    {
         free(*first);
         *first = NULL;
    }
    else
    {
        temp = *first;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }
        free (temp->next);
        temp ->next = NULL;

 
    }
}

void display(struct node * first)
{

    while(first != NULL)
    {
        printf("| %d | -> " ,first->data);
        first = first->next;
    }
    printf("NULL\n");
}

int count (struct node * first)
{
    int icount = 0;

    while(first != NULL)
    {
        icount++;
        first = first -> next;
    }
    return icount;
}

void insertatpos(struct node ** first,int no,int pos)
{
    struct node * newn = NULL;
    struct node * temp = NULL;
    int icnt = 0;
    int icount = 0;
  
    icount = count(*first);
    if(pos < 1 || pos > icount+1)
    {
        printf("invalid position \n");
        return;
    }

    if(pos == 1)
    {
        insertfirst(first ,no);
    }
    else if(pos == icount + 1)
    {
        insertlast(first,no);
    }
    else
    {
        temp = *first;

        newn = (struct node *)malloc(sizeof(struct node));
        
        for(icnt = 1; icnt < pos-1;icnt++)
        {
            temp = temp -> next;
        }

        newn-> data = no;
        newn -> next = NULL;

        newn->next = temp->next;
        temp->next = newn;
    }
}

void deleteatpos(struct node ** first ,int pos)
{
    int icount = 0;
    int icnt = 0;
    struct node * temp = NULL;
    struct node * target = NULL;

    icount = count(*first);

    if(pos < 1 || pos > icount )
    {
        printf("invalid position \n");
        return;
    }

    if(pos == 1)
    {
        deletefirst(first);   
    }
    else if(pos == icount)
    {
        deletelast(first);
    }
    else
    {
        temp = *first;

        for(icnt = 0; icnt < pos-1;icnt++)
        {
            temp = temp -> next;
        }
        target = temp -> next;
        temp -> next = target->next;
        free(target);

    }
}



int main()
{
    struct node * head = NULL;
    int iret = 0;

    
    insertfirst(&head,51);
    insertfirst(&head,21);
    insertfirst(&head,11);

    display(head);

    iret = count(head);
    printf("element in linkedlist is : %d \n",iret);

    insertlast(&head,101);
    insertlast(&head,111);
    insertlast(&head,121);

    display(head);

    iret = count(head);
    printf("element in linkedlist is : %d \n",iret);

    deletefirst(&head);

    display(head);

    iret = count(head);
    printf("element in linkedlist is : %d \n",iret);

    deletelast(&head);

    display(head);

    iret = count(head);
    printf("element in linkedlist is : %d \n",iret);

    insertatpos(&head,105,5);

    display(head);

    iret = count(head);
    printf("element in linkedlist is : %d \n",iret);

    deleteatpos(&head,5);

    display(head);

    iret = count(head);
    printf("element in linkedlist is : %d \n",iret);

    return 0;
}