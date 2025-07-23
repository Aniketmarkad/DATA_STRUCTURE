#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node * next;
};

typedef struct node  NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class singlyCLL
{
    private:
        PNODE first;
        PNODE last;
        int icount;

    public:
        singlyCLL()
        {
            first = NULL;
            last = NULL;
            icount = 0;
        }

        void insertfirst(int no)
        {
            PNODE newn = NULL;

            newn = new node;

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

        void insertlast(int no)
        {
            PNODE newn = NULL;

            newn = new node;

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

        void insertatpos(int no, int pos)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;
            int icnt = 0;
            int  icount = 0;

            newn = new node;
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
            PNODE temp = NULL;

            if(first == NULL && last == NULL)
            {
                return;
            }
            else if (first -> next == NULL)
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
            PNODE temp = NULL;
            
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
            PNODE temp = NULL;
            PNODE target = NULL;
            int icnt = 0;
            int  icount = 0;

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

                icount--;

            }

        }

        void display()
        {
            PNODE temp = NULL;

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
    singlyCLL sobj;
    int iret = 0;

    sobj.insertfirst(51);
    sobj.insertfirst(21);
    sobj.insertfirst(11);

    sobj.display();
    iret = sobj.count();
    cout<<"no of element in linkedlist :"<<iret<<"\n";

    sobj.insertlast(101);
    sobj.insertlast(111);
    sobj.insertlast(121);

    sobj.display();
    iret = sobj.count();
    cout<<"no of element in linkedlist :"<<iret<<"\n";

    sobj.deletefirst();

    sobj.display();
    iret = sobj.count();
    cout<<"no of element in linkedlist :"<<iret<<"\n";

    sobj.deletelast();

    sobj.display();
    iret = sobj.count();
    cout<<"no of element in linkedlist :"<<iret<<"\n";

    sobj.insertatpos(105,3);
    sobj.display();
    iret = sobj.count();
    cout<<"no of element in linkedlist :"<<iret<<"\n";

    sobj.deleteatpos(3);
    sobj.display();
    iret = sobj.count();
    cout<<"no of element in linkedlist :"<<iret<<"\n";

    return 0;
}