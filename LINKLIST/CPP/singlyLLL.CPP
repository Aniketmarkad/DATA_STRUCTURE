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

class singlyLLL
{
    private:
        PNODE first;
        PNODE last;
        int icount;
    
    public:
        singlyLLL()
        {
            first = NULL;
            last = NULL;
            icount = 0;
        }

        void insertfirst(int no)
        {
            PNODE newn = NULL;

            newn = new node;

            newn ->data = no;
            newn ->next = NULL;

            if(first == NULL )
            {
                first = newn;
            }
            else
            {
                newn->next = first;
                first = newn;
            }
        }

        void insertlast(int no)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;

            newn = new node;

            newn ->data = no;
            newn ->next = NULL;

            if(first == NULL )
            {
                first = newn;
            }
            else
            {
                temp = first;

                while(temp -> next != NULL)
                {
                    temp = temp -> next;
                }  
                temp -> next = newn;
            }    
        }

        void deletefirst()
        {
            PNODE temp = NULL;

            if(first == NULL)
            {
                return;
            }
            else if(first -> next == NULL)
            {
                delete first;
            }
            else
            {
                temp = first;
                first = temp -> next;
                delete temp;

            }
        }

        void deletelast()
        {
            PNODE temp = NULL;

            if(first == NULL)
            {
                return;
            }
            else if(first -> next == NULL)
            {
                delete first;
            }
            else
            {
                temp = first;

                while(temp->next->next !=  NULL)
                {
                    temp = temp -> next;
                }
                delete temp ->next;
                temp -> next = NULL;

            }
        }

        void display()
        {
            PNODE temp = NULL;
            temp = first;

            while (temp != NULL)
            {
                cout<< " | "<<temp->data<<" | ->";
                temp = temp -> next;
            }
            cout<<"NULL\n";
        }

        int count()
        {
            PNODE temp = NULL;
            int icount = 0;
            temp = first;

            while (temp != NULL)
            {
                icount++;
                temp = temp -> next;
            }
            return icount;

        }
        void insertatpos(int no,int pos)
        {
            PNODE temp = NULL;
            PNODE newn = NULL;
            int icnt = 0;
            int icount = 0;

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
                newn = new node;

                newn -> data = no;
                newn -> next = NULL;

                for(icnt = 1; icnt < pos - 1; icnt ++)
                {
                    temp = temp ->next;
                }
                newn -> next = temp -> next;
                temp -> next = newn;
            }
        }

        void deleteatpos(int pos)
        {
            PNODE temp = NULL;
            PNODE target = NULL;
            int icnt = 0;
            int icount = 0;

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
            else if(pos == icount )
            {
                deletelast();
            }
            else
            {
                temp = first;
                for(icnt = 1;icnt < pos - 1;icnt++)
                {
                    temp = temp -> next;
                }
                target = temp -> next;
                temp ->next = target ->next;

                delete target;
                
            }
        }


};

int main()
{
    singlyLLL sobj;
    int iret = 0;

    sobj.insertfirst(51);
    sobj.insertfirst(21);
    sobj.insertfirst(11);

    sobj.display();

    iret = sobj.count();
    cout<<"no of element in likedlist is :"<<iret<<"\n";

    sobj.insertlast(101);
    sobj.insertlast(111);
    sobj.insertlast(121);

    sobj.display();

    iret = sobj.count();
    cout<<"no of element in likedlist is :"<<iret<<"\n";

    sobj.deletefirst();

    sobj.display();

    iret = sobj.count();
    cout<<"no of element in likedlist is :"<<iret<<"\n";

    sobj.deletelast();

    sobj.display();

    iret = sobj.count();
    cout<<"no of element in likedlist is :"<<iret<<"\n";

    sobj.insertatpos(105,5);
    sobj.display();

    iret = sobj.count();
    cout<<"no of element in likedlist is :"<<iret<<"\n";

    sobj.deleteatpos(5);
    sobj.display();

    iret = sobj.count();
    cout<<"no of element in likedlist is :"<<iret<<"\n";

    return 0;
}
