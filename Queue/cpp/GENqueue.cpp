#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data ;
    struct node<T>  *next;
};

template<class T>

class QueueX 
{
    public: struct node<T> *first;
    public: int iCount ;

    public : QueueX()
    {
        this->first = NULL;
        this->iCount = 0;
    }

    void Enqueue(T no)   //insert last
    {
        struct node<T>  * temp = NULL;
        struct node<T>  *newn = NULL;

        newn = new struct node<T> ();

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

    T Dequeue ()
    {
        struct node<T>  * temp = first;
        T data = 0;

        if(temp == NULL)
        {
            cout<<"Queue is empty no element \n";
            return NULL;
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
        struct node<T>  * temp = first;

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
    QueueX<int> *sobj = new QueueX<int>();
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

    sobj->Display();

    iRet = sobj->Count();
    cout<<"no of element in queue is :"<<iRet<<"\n";

    iRet = sobj->Dequeue();
    cout<<"removed element from  Queue is :"<<iRet<<"\n";

    sobj->Display();

    iRet = sobj->Count();
    cout<<"no of element in queue is :"<<iRet<<"\n";

    delete sobj;

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    QueueX<double> *sobj1 = new QueueX<double>();
    double dvalue = 0.0;
    double dRet = 0.0;

    cout<<"enter the how many no of element you want to enter  :";
    cin>>isize;

    cout<<"enter the element in doble format :\n";
    for(i = 1; i <= isize;i++ )
    {
        cin>>dvalue;
        sobj1->Enqueue(dvalue);
    }

    sobj1->Display();

    iRet = sobj1->Count();
    cout<<"no of element in queue is :"<<iRet<<"\n";

    dRet = sobj1->Dequeue();
    cout<<"removed element from  Queue is :"<<dRet<<"\n";

    sobj1->Display();

    iRet = sobj1->Count();
    cout<<"no of element in queue is :"<<iRet<<"\n";
    delete sobj1;

    return 0;
}