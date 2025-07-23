#include<iostream>
using namespace std;

template<class T>

struct node
{
    T data;
    struct node<T> * next;
};

template<class T>

class singlyLLL
{
    private:
        struct node<T> *first;
        struct node<T>  *last;
        int icount;
    
    public:
        singlyLLL()
        {
            first = NULL;
            last = NULL;
            icount = 0;
        }

        void insertfirst(T no)
        {
            struct node<T> *newn = NULL;

            newn = new node<T>;

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

        void insertlast(T no)
        {
            struct node<T> *newn = NULL;
            struct node<T> *temp = NULL;

            newn = new node<T>;

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
            struct node<T> *temp = NULL;

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
            struct node<T> *temp = NULL;

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
            struct node<T> *temp = NULL;
            temp = first;

            while (temp != NULL)
            {
                cout<< " | "<<temp->data<<" | ->";
                temp = temp -> next;
            }
            cout<<"NULL\n";
        }

        T count()
        {
            struct node<T> *temp = NULL;
            int icount = 0;
            temp = first;

            while (temp != NULL)
            {
                icount++;
                temp = temp -> next;
            }
            return icount;

        }
        void insertatpos(T no,int pos)
        {
            struct node<T> *temp = NULL;
            struct node<T> *newn = NULL;
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
                newn = new node<T>;

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
            struct node<T> *temp = NULL;
            struct node<T> *target = NULL;
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
    singlyLLL<int> sobj1 ;
    int  iret ;

    sobj1.insertfirst(51);
    sobj1.insertfirst(21);
    sobj1.insertfirst(11);

    sobj1.display();

    iret = sobj1.count();
    cout<<"no of element in likedlist is :"<<iret<<"\n";

    sobj1.insertlast(101);
    sobj1.insertlast(111);
    sobj1.insertlast(121);

    sobj1.display();

    iret = sobj1.count();
    cout<<"no of element in likedlist is :"<<iret<<"\n";

    sobj1.deletefirst();

    sobj1.display();

    iret = sobj1.count();
    cout<<"no of element in likedlist is :"<<iret<<"\n";

    sobj1.deletelast();

    sobj1.display();

    iret = sobj1.count();
    cout<<"no of element in likedlist is :"<<iret<<"\n";

    sobj1.insertatpos(105,5);
    sobj1.display();

    iret = sobj1.count();
    cout<<"no of element in likedlist is :"<<iret<<"\n";

    sobj1.deleteatpos(5);
    sobj1.display();

    iret = sobj1.count();
    cout<<"no of element in likedlist is :"<<iret<<"\n";

    /////////////////////////////////////////////////////////////

    singlyLLL<double> sobj2;
  
    sobj2.insertfirst(51.33);
    sobj2.insertfirst(21.90);
    sobj2.insertfirst(11.56);

    sobj2.display();

    iret = sobj2.count();
    cout<<"no of element in likedlist is :"<<iret<<"\n";

    sobj2.insertlast(101.34);
    sobj2.insertlast(111.78);
    sobj2.insertlast(121.74);

    sobj2.display();

    iret = sobj2.count();
    cout<<"no of element in likedlist is :"<<iret<<"\n";

    sobj2.deletefirst();

    sobj2.display();

    iret = sobj2.count();
    cout<<"no of element in likedlist is :"<<iret<<"\n";

    sobj2.deletelast();

    sobj2.display();

    iret = sobj2.count();
    cout<<"no of element in likedlist is :"<<iret<<"\n";

    sobj2.insertatpos(105.89,5);
    sobj2.display();

    iret = sobj2.count();
    cout<<"no of element in likedlist is :"<<iret<<"\n";

    sobj2.deleteatpos(5);
    sobj2.display();

    iret = sobj2.count();
    cout<<"no of element in likedlist is :"<<iret<<"\n";

    return 0;
}
