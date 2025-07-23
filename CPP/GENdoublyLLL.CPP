#include<iostream>
using namespace std;

template<class T>

struct node
{
    T data ;
    struct node<T> *next;
    struct node<T> *prev;
};

template<class T>

class doublyLLL
{
  private:
    struct node<T> *first;
    struct node<T> *last;
    int icount; 
  
  public:
  doublyLLL()
  {
    first = NULL;
    last = NULL;
    icount = 0;

  }

  void insertfirst(T no)
  {
    struct node<T> *newn = NULL;
    newn = new (struct node<T>);

    newn->data = no;
    newn-> next = NULL;
    newn-> prev = NULL;

    if(first == NULL && last == NULL)
    {
      first = newn;
      last = newn;
    }
    else
    {
      newn->next = first;
      first->prev = newn;
      first = newn;

    }
    icount++;
  }

  void insertlast(T no)
  {
    struct node<T> *newn = NULL;
    struct node<T> *temp = NULL;

    newn = new (struct node<T>);

    newn->data = no;
    newn-> next = NULL;
    newn-> prev = NULL;

    if(first == NULL && last == NULL)
    {
      first = newn;
      last = newn;
    }
    else
    {
      temp = first;
      while(temp -> next != NULL)
      {
        temp = temp->next;
      }
      temp->next = newn;
      newn->prev = temp;
    }
    icount++;
  }

  void insertatpos(T no,int pos) 
  {
    int icnt = 0;
    struct node<T> *temp = NULL;
    struct node<T> *newn = NULL;

    icount = count();

    if(pos < 1 || pos > icount + 1)
    {
      cout<<"invaliad position\n";
      return;
    }

    if(pos == 1)
    {
      insertfirst(no);
    }
    else if(pos == icount + 1)
    {
      insertlast(no);
    }
    else
    {
      temp = first;
      newn = new (struct node<T>);

      newn -> data = no;
      newn -> next = NULL;
      newn -> prev = NULL;

      for(icnt = 1;icnt < pos-1 ; icnt++)
      {
        temp = temp ->next;
      }
      newn->next =temp ->next;
      temp -> next ->prev = newn;
      temp -> next = newn;
      newn -> prev = temp;
  
      icount++;
    }
  }

  void deletefirst()
  {
    struct node<T> *temp = NULL;

    if(first == NULL && last == NULL)
    {
      return;
    }
    else if(first-> next == NULL)
    {
      delete first;
      first = NULL;
      last = NULL;
    }
    else
    {
      temp = first;
      first = temp ->next;
      first -> prev = NULL;

      delete temp;
    }
    icount--;

  }

  void deletelast()
  {
    struct node<T> *temp = NULL;

    if(first == NULL && last == NULL)
    {
      return;
    }
    else if(first-> next == NULL)
    {
      delete first;
      first = NULL;
      last = NULL;
    }
    else
    {
      temp = first;
      
      while(temp -> next->next != NULL)
      {
        temp = temp -> next;
      }
      delete temp->next;
      temp -> next = NULL;
    }
    icount--;
  }

  void deleteatpos(int pos)
  {
    
    int icnt = 0;
    struct node<T> *temp = NULL;
    struct node<T> *target = NULL;

    icount = count();

    if(pos < 1 || pos > icount)
    {
      cout<<"invaliad position\n";
      return;
    }

    if(pos == 1)
    {
      deletefirst();
    }
    else if(pos == icount )
    {
      deletelast();
    }
    else
    {
      temp = first;
      
      for (icnt = 1;icnt < pos -1;icnt++)
      {
        temp = temp->next;
      }
      target = temp ->next;
      temp ->next = target ->next;
      temp ->next->prev= temp;

      delete target;

      icount--;

    }
  }

  void display()
  {
    struct node<T> *temp = first;

    cout<<"NULL <=> ";
    while(temp != NULL)
    {
      cout<<" | "<<temp->data<<"| <=> ";
      temp = temp -> next;
    }
    cout<<"NULL\n";

  }

  int count()
  {
    return icount;
  }

};

int main()
{
    doublyLLL<int> * dobj = new doublyLLL<int>();
    int iret = 0;

    dobj->insertfirst(51);
    dobj->insertfirst(21);
    dobj->insertfirst(11);

    dobj->display();

    iret = dobj->count();
    cout<<"no of element in likedlist is :"<<iret<<"\n";

    dobj->insertlast(101);
    dobj->insertlast(111);
    dobj->insertlast(121);

    dobj->display();

    iret = dobj->count();
    cout<<"no of element in likedlist is :"<<iret<<"\n";

    dobj->deletefirst();

    dobj->display();

    iret = dobj->count();
    cout<<"no of element in likedlist is :"<<iret<<"\n";

    dobj->deletelast();

    dobj->display();

    iret = dobj->count();
    cout<<"no of element in likedlist is :"<<iret<<"\n";

    dobj->insertatpos(105,5);
    dobj->display();

    iret = dobj->count();
    cout<<"no of element in likedlist is :"<<iret<<"\n";

    dobj->deleteatpos(5);
    dobj->display();

    iret = dobj->count();
    cout<<"no of element in likedlist is :"<<iret<<"\n";

 //////////////////////////////////////////////////////////////////////////////////////////////
 
 doublyLLL<string> *dobj1 = new doublyLLL<string>();
 
 dobj1->insertfirst("Aniket");
 dobj1->insertfirst("Markad");
 dobj1->insertfirst("Hello");

 dobj1->display();
 iret = dobj1->count();
 cout<<"no of element in linkedlist :"<<iret<<"\n";

 dobj1->insertlast("Markad");
 dobj1->insertlast("vaishnavi");
 dobj1->insertlast("aniket");

 dobj1->display();
 iret = dobj1->count();
 cout<<"no of element in linkedlist :"<<iret<<"\n";

 dobj1->deletefirst();

 dobj1->display();
 iret = dobj1->count();
 cout<<"no of element in linkedlist :"<<iret<<"\n";

 dobj1->deletelast();

 dobj1->display();
 iret = dobj1->count();
 cout<<"no of element in linkedlist :"<<iret<<"\n";

 dobj1->insertatpos("And",3);
 dobj1->display();
 iret = dobj1->count();
 cout<<"no of element in linkedlist :"<<iret<<"\n";

 dobj1->deleteatpos(3);
 dobj1->display();
 iret = dobj1->count();
 cout<<"no of element in linkedlist :"<<iret<<"\n";


 ////////////////////////////////////////////////////////////////////////////////////////////////


 doublyLLL<double> *dobj2 = new doublyLLL<double>();
 
 dobj2->insertfirst(50.55);
 dobj2->insertfirst(20.22);
 dobj2->insertfirst(10.11);

 dobj2->display();
 iret = dobj2->count();
 cout<<"no of element in linkedlist :"<<iret<<"\n";

 dobj2->insertlast(100.23);
 dobj2->insertlast(110.45);
 dobj2->insertlast(120.67);

 dobj2->display();
 iret = dobj2->count();
 cout<<"no of element in linkedlist :"<<iret<<"\n";

 dobj2->deletefirst();

 dobj2->display();
 iret = dobj2->count();
 cout<<"no of element in linkedlist :"<<iret<<"\n";

 dobj2->deletelast();

 dobj2->display();
 iret = dobj2->count();
 cout<<"no of element in linkedlist :"<<iret<<"\n";

 dobj2->insertatpos(65.45,4);
 dobj2->display();
 iret = dobj2->count();
 cout<<"no of element in linkedlist :"<<iret<<"\n";

 dobj2->deleteatpos(3);
 dobj2->display();
 iret = dobj2->count();
 cout<<"no of element in linkedlist :"<<iret<<"\n";

    return 0;
}