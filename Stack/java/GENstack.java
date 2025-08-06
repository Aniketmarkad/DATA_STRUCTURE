class node<T>
{
    public T data;
    public node<T> next;
}


class StackX<T>
{
    private node<T> first;
    private int iCount;


    public StackX()
    {
        first = null;
        iCount = 0;
    }

    void Push(T iNo)   // insert first
    {
        node<T> newn = new node<T>();

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

    public T Pop()               // delete first
    {
        node<T> temp = first;
        if(first == null)
        {
            System.out.println("Stack is empty \n");
            return null;
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
        node<T> temp = first;


        while(temp != null)
        {
            System.out.println(" | "+temp.data+" | ");
            temp = temp.next;
        }
    }

    public int Count ()
    {
        return iCount;
    }

    T  Peek()
    {
        node<T> temp = first;
        if(temp == null)
        {
            System.out.println("stack is empty");
            return null;
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

class GENstack
{
    public static void main(String a[])
    {
        StackX<Integer> sobj = new StackX<>();
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
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        
        StackX<Double> sobj1 = new StackX<>();
        double dRet = 0.0;

        sobj1.Push(121.09);
        sobj1.Push(111.56);
        sobj1.Push(101.56);
        sobj1.Push(51.87);
        sobj1.Push(21.89);
        sobj1.Push(11.79);
        

        sobj1.Display();

        iRet = sobj1.Count();
        System.out.println("no of element in stack :"+iRet);

        dRet = sobj1.Pop();
        System.out.println("poped element is  :"+dRet);

        sobj1.Display();

        iRet = sobj1.Count();
        System.out.println("no of element in stack :"+iRet);

        dRet = sobj1.Peek ();
        System.out.println("top  element in stack  is :"+dRet);

        bRet = sobj1.isempty();
        if(bRet == true)
        {
            System.out.println("satck is empty");
        }
        else
        {
            System.out.println("stack is not empty");
        }
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        
        
        StackX<String> sobj3 = new StackX<>();
        String str = null;

        sobj3.Push("anii");
        sobj3.Push("sagar");
        sobj3.Push("suresh");
        sobj3.Push("chandu");
        sobj3.Push("omkar");
        sobj3.Push("trisha");
        

        sobj3.Display();

        iRet = sobj3.Count();
        System.out.println("no of element in stack :"+iRet);

        str = sobj3.Pop();
        System.out.println("poped element is  :"+str);

        sobj3.Display();

        iRet = sobj3.Count();
        System.out.println("no of element in stack :"+iRet);

        str = sobj3.Peek ();
        System.out.println("top  element in stack  is :"+str);

        bRet = sobj3.isempty();
        if(bRet == true)
        {
            System.out.println("satck is empty");
        }
        else
        {
            System.out.println("stack is not empty");
        }
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    }
}

