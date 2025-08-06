class node<N>
{
    public N data;
    public node<N> next;
}

class QueueX<N>
{
    private node<N> first;
    private int iCount;

    public QueueX()
    {
        this.first = null;
        this.iCount = 0;
    }

    void enqueue (N iNo)  // insert last
    {
        node<N> newn = new node<N>();

        newn.data = iNo;
        newn.next = null;

        if(first == null)
        {
            first = newn;
        }
        else
        {
            node<N> temp = first;

            while(temp.next != null)
            {
                temp=temp.next;

               
            }
            temp.next = newn;
        }
        iCount++;

    }

    public N dequeue()     // delete first
    {
        node<N> temp = first;
        if(first ==null)
        {
            System.out.println("Queue is empty :");
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
        node<N> temp = first;
        while(temp != null)
        {
            System.out.print(" | "+temp.data+" | - ");
            temp = temp.next ;
        }
        System.out.println();

    }

    public int Count ()
    {
        return iCount;
    }

}

class   GENqueue
{
    public static void main(String a[])
    {
        QueueX<Integer> sobj = new  QueueX <>();
        int iRet = 0;

        sobj. enqueue (10);
        sobj. enqueue (20);
        sobj. enqueue (30);
        sobj.enqueue(40);

        sobj.Display();
        iRet = sobj.Count();
        System.out.println("element in queue:"+iRet);

        sobj.dequeue();
        
        sobj.Display();
        iRet = sobj.Count();
        System.out.println("element in queue:"+iRet);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        
        QueueX<Double> sobj1 = new  QueueX <>();
        double dRet = 0;

        sobj1. enqueue (10.30);
        sobj1. enqueue (20.70);
        sobj1. enqueue (30.89);
        sobj1.enqueue(40.99);

        sobj1.Display();
        iRet = sobj1.Count();
        System.out.println("element in queue:"+iRet);

        sobj1.dequeue();
        
        sobj1.Display();
        iRet = sobj1.Count();
        System.out.println("element in queue:"+iRet);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        
        QueueX<String> sobj2 = new  QueueX <>();
        String str = null;

        sobj2. enqueue ("c");
        sobj2. enqueue ("cpp");
        sobj2. enqueue ("java");
        sobj2.enqueue("python");

        sobj2.Display();
        iRet = sobj2.Count();
        System.out.println("element in queue:"+iRet);

        sobj2.dequeue();
        
        sobj2.Display();
        iRet = sobj2.Count();
        System.out.println("element in queue:"+iRet);

    }
}  
