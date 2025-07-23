#include<iostream>
using namespace std;

struct node
{
    int data ;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class doublyLLL
{
  private:
    PNODE first;
    PNODE last;
    int icount; 
  
  public:
  doublyLLL()
  {
    first = NULL;
    last = NULL;
    icount = 0;

  }

  void insertfirst(int no)
  {
    PNODE newn = NULL;
    newn = new node;

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

  void insertlast(int no)
  {
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = new node;

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

  void insertatpos(int no,int pos) 
  {
    int icount = 0;
    int icnt = 0;
    PNODE temp = NULL;
    PNODE newn = NULL;

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
      newn = new node;

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
    PNODE temp = NULL;

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
    PNODE temp = NULL;

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
    int icount = 0;
    int icnt = 0;
    PNODE temp = NULL;
    PNODE target = NULL;

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
    PNODE temp = first;

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
    doublyLLL dobj;
    int iret = 0;

    dobj.insertfirst(51);
    dobj.insertfirst(21);
    dobj.insertfirst(11);

    dobj.display();

    iret = dobj.count();
    cout<<"no of element in likedlist is :"<<iret<<"\n";

    dobj.insertlast(101);
    dobj.insertlast(111);
    dobj.insertlast(121);

    dobj.display();

    iret = dobj.count();
    cout<<"no of element in likedlist is :"<<iret<<"\n";

    dobj.deletefirst();

    dobj.display();

    iret = dobj.count();
    cout<<"no of element in likedlist is :"<<iret<<"\n";

    dobj.deletelast();

    dobj.display();

    iret = dobj.count();
    cout<<"no of element in likedlist is :"<<iret<<"\n";

    dobj.insertatpos(105,5);
    dobj.display();

    iret = dobj.count();
    cout<<"no of element in likedlist is :"<<iret<<"\n";

    dobj.deleteatpos(5);
    dobj.display();

    iret = dobj.count();
    cout<<"no of element in likedlist is :"<<iret<<"\n";


    return 0;
}