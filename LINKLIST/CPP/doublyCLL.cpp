#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;

class DoublyCLL
{
    private:
        PNODE first;
        PNODE last;
        int iCount;

    public:
        DoublyCLL();

        void Display();
        int Count();

        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPos(int,int);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
};

DoublyCLL :: DoublyCLL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

void DoublyCLL :: InsertFirst(int no)
{
    PNODE newn = NULL;
    
    newn = new node;

    newn->data=no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;

        last -> next = first;
        first ->prev = last;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;

        last ->next = first;
        first ->prev = last;
    }

    iCount++;
}

void DoublyCLL :: InsertLast(int no)
{
    PNODE newn = NULL;

    newn = new node;

    newn->data=no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;

        last -> next = first;
        first ->prev = last;
    }
    else
    {
        last -> next = newn;
        last = newn;

        last -> next = first;
        first->prev = last;
    }
    iCount++;
}

void DoublyCLL :: DeleteFirst()
{
    PNODE temp = NULL;

    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        temp = first;
        first = temp -> next;

        first -> prev = last;
        last -> next = first;
    }
    iCount--;

}
void DoublyCLL :: DeleteLast()
{
    PNODE temp = NULL;

    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        temp = first;
        while(temp -> next ->next != first)
        {
            temp = temp -> next;
        }
        
        delete temp->next;
        last = temp;

        first -> prev = last;
        last -> next = first;
    }
    iCount--;
}

void DoublyCLL :: Display()
{
    PNODE temp = first;
    if(first == NULL && last == NULL)
    {
        return;
    }

    do
    {
        cout<<"|"<<temp->data<<"| <=>";
        temp = temp ->next;
    }while(temp != first);

}
int DoublyCLL :: Count()
{
    return iCount;
}

void DoublyCLL :: InsertAtPos(int no,int pos)
{
    PNODE temp = NULL;
    PNODE newn = NULL;
    int icnt = 0;
    
    if(pos < 1 || pos > iCount + 1)
    {
        cout<<"invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if (pos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        temp = first;
        newn = new node;

        newn -> data = no;
        newn -> next = NULL;
        newn -> prev = NULL;

        for (icnt = 1;pos < pos -1;icnt++)
        {
            temp = temp ->next;
        }

        newn -> next = temp -> next;
        temp -> next ->prev = newn;

        temp -> next = newn;
        newn -> prev = temp;

        iCount++;
        
    }
    
}

void DoublyCLL :: DeleteAtPos(int pos)
{
    PNODE temp = NULL;
    PNODE target = NULL;
    int icnt = 0;
    
    if(pos < 1 || pos > iCount )
    {
        cout<<"invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if (pos == iCount )
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(icnt = 1;icnt < pos-1 ;icnt++)
        {
            temp = temp -> next;
        }
        target = temp -> next;
        temp -> next = target -> next;
        target ->next ->prev = temp;
    }

}

int main()
{
    DoublyCLL dobj;
    int iret = 0;

    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);

    dobj.Display();

    iret = dobj.Count();
    cout<<"no of element in likedlist is :"<<iret<<"\n";

    dobj.InsertLast(101);
    dobj.InsertLast(111);
    dobj.InsertLast(121);

    dobj.Display();

    iret = dobj.Count();
    cout<<"no of element in likedlist is :"<<iret<<"\n";

    dobj.DeleteFirst();

    dobj.Display();

    iret = dobj.Count();
    cout<<"no of element in likedlist is :"<<iret<<"\n";

    dobj.DeleteLast();

    dobj.Display();

    iret = dobj.Count();
    cout<<"no of element in likedlist is :"<<iret<<"\n";

    dobj.InsertAtPos(105,5);
    dobj.Display();

    iret = dobj.Count();
    cout<<"no of element in likedlist is :"<<iret<<"\n";

    dobj.DeleteAtPos(5);
    dobj.Display();

    iret = dobj.Count();
    cout<<"no of element in likedlist is :"<<iret<<"\n";
    
    return 0;
}