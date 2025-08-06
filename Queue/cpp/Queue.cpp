#include<iostream>
using namespace std;

struct node
{
    int data ;
    struct node* next;
};

class QueueX
{
    public: struct node* first;
    public: int iCount ;

    public : QueueX()
    {
        this->first = NULL;
        this->iCount = 0;
    }

    void Enqueue(int no)   //insert last
    {
        struct node * temp = NULL;
        struct node *newn = NULL;

        newn = new struct node();

        newn->data = no;
        newn->next = NULL;

        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            temp =first;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
        }
        iCount++;
    }

    int Dequeue ()
    {
        struct node * temp = first;
        int data = 0;

        if(temp == NULL)
        {
            cout<<"Queue is empty no element \n";
            return -1;
        }
        else
        {
            first = temp->next;
            data = temp->data;
            delete temp;
            iCount--;

            return data;

        }
    }

    void Display()
    {
        struct node * temp = first;

        while(temp != NULL)
        {
            cout<<" | "<<temp->data<<" | -";
            temp = temp->next;
        }
        cout<<"\n";
    }

    int Count()
    {
        return iCount;
    }

};

int main()
{
    QueueX* sobj = new QueueX();
    int iRet = 0;
    int isize = 0;
    int i = 0;
    int ivalue=0;

    cout<<"enter the how many no of element you want to enter :";
    cin>>isize;

    cout<<"enter the element :\n";
    for(i = 1; i <= isize;i++ )
    {
        cin>>ivalue;
        sobj->Enqueue(ivalue);
    }
   /* sobj->Enqueue(10);
    sobj->Enqueue(20);
    sobj->Enqueue(30);
    sobj->Enqueue(40);
    sobj->Enqueue(50);*/

    sobj->Display();

    iRet = sobj->Count();
    cout<<"no of elemrnt in queue is :"<<iRet<<"\n";

    iRet = sobj->Dequeue();
    cout<<"removed element from  Queue is :"<<iRet<<"\n";

    sobj->Display();

    iRet = sobj->Count();
    cout<<"no of elemrnt in queue is :"<<iRet<<"\n";

    return 0;
}