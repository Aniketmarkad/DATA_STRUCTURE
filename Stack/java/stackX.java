class node
{
    public int data;
    public node next;
}


class StackX
{
    private node first;
    private int iCount;


    public StackX()
    {
        first = null;
        iCount = 0;
    }

    void Push(int iNo)   // insert first
    {
        node newn = new node();

        newn.data = iNo;
        newn.next = null;

        if(first == null)
        {
            first = newn;
        }
        else
        {
            newn.next = first;
            first = newn;   
        }
        iCount++;
    }

    int Pop()               // delete first
    {
        node temp = first;
        if(first == null)
        {
            System.out.println("Stack is empty \n");
            return -1 ;
        }
        else
        {
            first = first.next;
            iCount--;
            return temp.data;

        }
      
    }
    
    void Display()
    {
        node temp = first;


        while(temp != null)
        {
            System.out.println(" | "+temp.data+" | ");
            temp = temp.next;
        }
    }

    int Count ()
    {
        return iCount;
    }

    int  Peek()
    {
        node temp = first;
        if(temp == null)
        {
            System.out.println("stack is empty");
            return -1;
        }
        return temp.data;
    }

    boolean isempty()
    {
        boolean bflage = false;

        if(first == null)
        {
            bflage= true;
        }
        return bflage;
    }
}

class p380
{
    public static void main(String a[])
    {
        StackX sobj = new StackX();
        int iRet = 0;
        boolean bRet = false;

        sobj.Push(121);
        sobj.Push(111);
        sobj.Push(101);
        sobj.Push(51);
        sobj.Push(21);
        sobj.Push(11);
        

        sobj.Display();

        iRet = sobj.Count();
        System.out.println("no of element in stack :"+iRet);

        iRet = sobj.Pop();
        System.out.println("poped element is  :"+iRet);

        sobj.Display();

        iRet = sobj.Count();
        System.out.println("no of element in stack :"+iRet);

        iRet = sobj.Peek ();
        System.out.println("top  element in stack  is :"+iRet);

        bRet = sobj.isempty();
        if(bRet == true)
        {
            System.out.println("satck is empty");
        }
        else
        {
            System.out.println("stack is not empty");
        }

      


    }
}
