#include<iostream>
using namespace std;

template<class T>

struct node 
{
    T data;
    struct node<T> *next;
};

template<class T>
class singlyCLL
{
    private:
        struct node<T> *first;
        struct node<T>  *last;
        int icount;

    public:
        singlyCLL()
        {
            first = NULL;
            last = NULL;
            icount = 0;
        }

        void insertfirst(T no)
        {
            struct node<T>   *newn = NULL;

            newn = new (struct node<T>);

            newn -> data = no;
            newn-> next = NULL;

            if(first == NULL && last == NULL)
            {
                first = newn;
                last = newn;

                last -> next = first;
            }
            else
            {
                newn -> next = first;
                first = newn;

                last -> next = first;
            }
            icount++;
        }

        void insertlast(T no)
        {
            struct node<T>  *newn = NULL;

            newn = new (struct node<T>);

            newn -> data = no;
            newn-> next = NULL;

            if(first == NULL && last == NULL)
            {
                first = newn;
                last = newn;

                last -> next = first;

            }
            else
            {
                last -> next =newn;
                last = newn;

                last -> next = first;

            }
            icount++;
        }

        void insertatpos(T no, int pos)
        {
            struct node<T>  *newn = NULL;
            struct node<T>  *temp = NULL;
            int icnt = 0;

            newn = new (struct node<T> );
            newn->data = no;
            newn -> next = NULL;

            icount = count();

            if(pos < 1 || pos > icount + 1)
            {
                cout<<"invalid position\n";
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
                for(icnt =1;icnt < pos -1;icnt++)
                {
                    temp = temp->next;
                }
                newn->next =temp->next;
                temp -> next = newn;

                icount++;
            }

        }

        void deletefirst()
        {
            struct node<T>  *temp = NULL;

            if(first == NULL && last == NULL)
            {
                return;
            }
            else if (first == last)
            {
                delete first;

                first = NULL;
                last = NULL;
            }
            else
            {
                temp = first;

                first = temp -> next;// first = first ->next;
                delete temp; // delete last->next;

                last -> next = first;

            }
            icount--;
        }

        void deletelast()
        {
            struct node<T>  *temp = NULL;
            
            if(first == NULL && last == NULL)
            {
                return;
            }
            else if (first  == last)
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
                    temp = temp ->next;
                }
                delete temp -> next;
                last = temp;
                last-> next = first;
               
            }
            icount --;
        }
        
        void deleteatpos(int pos)
        {
            struct node<T>  *temp = NULL;
            struct node<T>  *target = NULL;
            int icnt = 0;

            icount = count();

            if(pos < 1 || pos > icount )
            {
                cout<<"invalid position\n";
                return;
            }

            if(pos == 1)
            {
                deletefirst();
            }
            else if(pos == icount + 1)
            {
                deletelast();
            }
            else
            {
                temp = first;
                for(icnt = 1;icnt < pos -1;icnt++)
                {
                    temp = temp ->next;
                }
                target = temp ->next;
                temp ->next = target->next;
                delete target;

                icount--;

            }

        }

        void display()
        {
            struct node<T>  *temp = NULL;

            if (first == NULL && last == NULL)
            {
                return;
            }

            temp = first;

            do
            {
                cout<<" | "<<temp->data<<" | -> ";
                temp = temp -> next;
            }while(temp != last->next);

            cout<<"\n";

        }

        int count()
        {
            return icount;
        }
};

int main()
{
    singlyCLL<int> *sobj = new singlyCLL<int>();
    int iret = 0;

    sobj->insertfirst(50);
    sobj->insertfirst(20);
    sobj->insertfirst(10);

    sobj->display();
    iret = sobj->count();
    cout<<"no of element in linkedlist :"<<iret<<"\n";

    sobj->insertlast(100);
    sobj->insertlast(110);
    sobj->insertlast(120);

    sobj->display();
    iret = sobj->count();
    cout<<"no of element in linkedlist :"<<iret<<"\n";

    sobj->deletefirst();

    sobj->display();
    iret = sobj->count();
    cout<<"no of element in linkedlist :"<<iret<<"\n";

    sobj->deletelast();

    sobj->display();
    iret = sobj->count();
    cout<<"no of element in linkedlist :"<<iret<<"\n";

    sobj->insertatpos(65,4);
    sobj->display();
    iret = sobj->count();
    cout<<"no of element in linkedlist :"<<iret<<"\n";

    sobj->deleteatpos(3);
    sobj->display();
    iret = sobj->count();
    cout<<"no of element in linkedlist :"<<iret<<"\n";
 ///////////////////////////////////////////////////////////////////////////////////////////////////////

 singlyCLL<double> *dobj = new singlyCLL<double>();
 
 dobj->insertfirst(50.55);
 dobj->insertfirst(20.22);
 dobj->insertfirst(10.11);

 dobj->display();
 iret = dobj->count();
 cout<<"no of element in linkedlist :"<<iret<<"\n";

 dobj->insertlast(100.23);
 dobj->insertlast(110.45);
 dobj->insertlast(120.67);

 dobj->display();
 iret = dobj->count();
 cout<<"no of element in linkedlist :"<<iret<<"\n";

 dobj->deletefirst();

 dobj->display();
 iret = dobj->count();
 cout<<"no of element in linkedlist :"<<iret<<"\n";

 dobj->deletelast();

 dobj->display();
 iret = dobj->count();
 cout<<"no of element in linkedlist :"<<iret<<"\n";

 dobj->insertatpos(65.45,4);
 dobj->display();
 iret = dobj->count();
 cout<<"no of element in linkedlist :"<<iret<<"\n";

 dobj->deleteatpos(3);
 dobj->display();
 iret = dobj->count();
 cout<<"no of element in linkedlist :"<<iret<<"\n";


 //////////////////////////////////////////////////////////////////////////////////////////////
 
 singlyCLL<string> *dobj1 = new singlyCLL<string>();
 
 dobj1->insertfirst("Aniket");
 dobj1->insertfirst("Devaba");
 dobj1->insertfirst("Markad");

 dobj1->display();
 iret = dobj1->count();
 cout<<"no of element in linkedlist :"<<iret<<"\n";

 dobj1->insertlast("Vaishnavi");
 dobj1->insertlast("Aniket");
 dobj1->insertlast("Markad");

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

 dobj1->insertatpos("And",4);
 dobj1->display();
 iret = dobj1->count();
 cout<<"no of element in linkedlist :"<<iret<<"\n";

 dobj1->deleteatpos(3);
 dobj1->display();
 iret = dobj1->count();
 cout<<"no of element in linkedlist :"<<iret<<"\n";

    return 0;
}