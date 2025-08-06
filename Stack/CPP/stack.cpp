#include<iostream>
using namespace std;

struct node
{
    int data ;
    struct node * next;
};

class StackX
{
    private: struct node * first;
    private: int iCount ;

    public: StackX()
    {
        this->first = NULL;
        this->iCount= 0;
    }
    
    void Push (int no)
    {
        struct node *newn = new struct node();

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

    int Pop()
    {
        struct node*temp = first;
        int data = 0;

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
        struct node *temp =first;

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
    StackX * sobj = new StackX();
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

    return  0;
}