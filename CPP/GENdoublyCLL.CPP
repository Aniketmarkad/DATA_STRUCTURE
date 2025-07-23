#include<iostream>
using namespace std;

template<class T>

struct node
{
    T data;
    struct node<T> *next;
    struct node<T> *prev;
};

template<class T>

class DoublyCLL
{
    private:
        struct node<T> *first;
        struct node<T> *last;
        int iCount;

    public:
        DoublyCLL();

        void Display();
        int Count();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
};

template<class T>

DoublyCLL<T> :: DoublyCLL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

template<class T>

void DoublyCLL<T> :: InsertFirst(T no)
{
    struct node<T> *newn = NULL;
    
    newn = new (struct node<T>);

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

template<class T>

void DoublyCLL<T> :: InsertLast(T no)
{
    struct node<T> *newn = NULL;

    newn = new (struct node<T> );

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

template<class T>

void DoublyCLL<T> :: DeleteFirst()
{
    struct node<T> *temp = NULL;

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
template<class T>

void DoublyCLL<T> :: DeleteLast()
{
    struct node<T> *temp = NULL;

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
template<class T>

void DoublyCLL<T> :: Display()
{
    struct node<T> *temp = first;
    if(first == NULL && last == NULL)
    {
        return;
    }

    cout<<"<=>";
    do
    {
        cout<<"|"<<temp->data<<"| <=>";
        temp = temp ->next;
    }while(temp != first);

    cout<<"\n";

}

template<class T>

int DoublyCLL<T> :: Count()
{
    return iCount;
}

template<class T>

void DoublyCLL<T> :: InsertAtPos(T no,int pos)
{
    struct node<T> *temp = NULL;
    struct node<T> *newn = NULL;
    int icnt = 0;

    iCount = Count();
    
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
        newn = new (struct node<T>);

        newn -> data = no;
        newn -> next = NULL;
        newn -> prev = NULL;

        for (icnt = 1;icnt < pos -1;icnt++)
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

template<class T>

void DoublyCLL<T> :: DeleteAtPos(int pos)
{
    struct node<T> *temp = NULL;
    struct node<T> *target = NULL;
    int icnt = 0;

    iCount = Count();
    
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

        iCount--;
    }

}

int main()
{
    DoublyCLL<int>  dobj;
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


    //////////////////////////////////////////////////////////////////////////////////////////////////////


    DoublyCLL<string> *dobj1 = new DoublyCLL<string>();
 
 dobj1->InsertFirst("Aniket");
 dobj1->InsertFirst("Markad");
 dobj1->InsertFirst("Hello");

 dobj1->Display();
 iret = dobj1->Count();
 cout<<"no of element in linkedlist :"<<iret<<"\n";

 dobj1->InsertLast("Markad");
 dobj1->InsertLast("vaishnavi");
 dobj1->InsertLast("aniket");

 dobj1->Display();
 iret = dobj1->Count();
 cout<<"no of element in linkedlist :"<<iret<<"\n";

 dobj1->DeleteFirst();

 dobj1->Display();
 iret = dobj1->Count();
 cout<<"no of element in linkedlist :"<<iret<<"\n";

 dobj1->DeleteLast();

 dobj1->Display();
 iret = dobj1->Count();
 cout<<"no of element in linkedlist :"<<iret<<"\n";

 dobj1->InsertAtPos("And",3);
 dobj1->Display();
 iret = dobj1->Count();
 cout<<"no of element in linkedlist :"<<iret<<"\n";

 dobj1->DeleteAtPos(3);
 dobj1->Display();
 iret = dobj1->Count();
 cout<<"no of element in linkedlist :"<<iret<<"\n";


 ////////////////////////////////////////////////////////////////////////////////////////////////


 DoublyCLL<double> *dobj2 = new DoublyCLL<double>();
 
 dobj2->InsertFirst(50.55);
 dobj2->InsertFirst(20.22);
 dobj2->InsertFirst(10.11);

 dobj2->Display();
 iret = dobj2->Count();
 cout<<"no of element in linkedlist :"<<iret<<"\n";

 dobj2->InsertLast(100.23);
 dobj2->InsertLast(110.45);
 dobj2->InsertLast(120.67);

 dobj2->Display();
 iret = dobj2->Count();
 cout<<"no of element in linkedlist :"<<iret<<"\n";

 dobj2->DeleteFirst();

 dobj2->Display();
 iret = dobj2->Count();
 cout<<"no of element in linkedlist :"<<iret<<"\n";

 dobj2->DeleteLast();

 dobj2->Display();
 iret = dobj2->Count();
 cout<<"no of element in linkedlist :"<<iret<<"\n";

 dobj2->InsertAtPos(65.45,4);
 dobj2->Display();
 iret = dobj2->Count();
 cout<<"no of element in linkedlist :"<<iret<<"\n";

 dobj2->DeleteAtPos(3);
 dobj2->Display();
 iret = dobj2->Count();
 cout<<"no of element in linkedlist :"<<iret<<"\n";

    
    return 0;
}