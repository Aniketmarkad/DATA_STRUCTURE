#include<iostream>
using namespace std;

template<class T>

struct node
{
    T data ;
    struct node<T> * next;
};

template<class T>

class StackX
{
    private: struct node<T> * first;
    private: int iCount ;

    public: StackX()
    {
        this->first = NULL;
        this->iCount= 0;
    }
    
    void Push (T no)
    {
        struct node<T> *newn = new struct node<T>();

        newn->data = no;
        newn->next = NULL;

        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            newn->next = first;
            first = newn;
        }
        iCount++;
    }

    T Pop()
    {
        struct node<T>*temp = first;
        T data = 0;

        if(first == NULL)
        {
            cout<<"stack is empty no element for pop \n";
            return NULL;
        }
        else
        {
            first = temp->next;
            data =  temp->data;
            iCount--;
            delete temp;
            return data;
        }

    }

    void Display()
    {
        struct node<T> *temp =first;

        while(temp != NULL)
        {
            cout<<" | "<<temp->data<<" | -"<<"\n";
            temp = temp->next;
        }
    }

    int Count()
    {
        return iCount;
    }


};

int main()
{
    StackX<int> * sobj = new StackX<int>();
    int i = 0,ivalue = 0,isize = 0,iret = 0;

    cout<<"enter no of element you want to enter :\n";
    cin>>isize;

    for(i = 1; i <= isize ;i++)
    {
        cin>>ivalue;
        sobj->Push(ivalue);
    }
   
    sobj->Display();

    iret = sobj->Count();
    cout<<"no of element in stack is :"<<iret<<"\n";

    iret = sobj->Pop();
    cout<<" element poped from  stack is :"<<iret<<"\n";

    sobj->Display();

    iret = sobj->Count();
    cout<<"no of element in stack is :"<<iret<<"\n";

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    StackX<double> * sobj1 = new StackX<double>();
    double dvalue = 0.0,dret = 0.0;

    cout<<"enter no of element you want to enter :\n";
    cin>>isize;

    for(i = 1; i <= isize ;i++)
    {
        cin>>dvalue;
        sobj1->Push(dvalue);
    }
   
    sobj1->Display();

    iret = sobj1->Count();
    cout<<"no of element in stack is :"<<iret<<"\n";

    dret = sobj1->Pop();
    cout<<" element poped from  stack is :"<<dret<<"\n";

    sobj1->Display();

    iret = sobj1->Count();
    cout<<"no of element in stack is :"<<iret<<"\n";

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

     StackX<float> * sobj2 = new StackX<float>();
    float fvalue = 0.0,fret = 0.0;

    cout<<"enter no of element you want to enter :\n";
    cin>>isize;

    for(i = 1; i <= isize ;i++)
    {
        cin>>fvalue;
        sobj2->Push(fvalue);
    }
   
    sobj2->Display();

    iret = sobj2->Count();
    cout<<"no of element in stack is :"<<iret<<"\n";

    fret = sobj2->Pop();
    cout<<" element poped from  stack is :"<<fret<<"\n";

    sobj2->Display();

    iret = sobj2->Count();
    cout<<"no of element in stack is :"<<iret<<"\n";

    return 0;
}