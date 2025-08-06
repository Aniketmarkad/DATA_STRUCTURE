class node
{
    public int data;
    public node next;
}

class QueueX
{
    private node first;
    private int iCount;

    public QueueX()
    {
        this.first = null;
        this.iCount = 0;
    }

    void enqueue (int iNo)  // insert last
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
            node temp = first;

            while(temp.next != null)
            {
                temp=temp.next;

               
            }
            temp.next = newn;
        }
        iCount++;

    }

    int dequeue()     // delete first
    {
        node temp = first;
        if(first ==null)
        {
            System.out.println("Queue is empty :");
            return -1;
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
            System.out.print(" | "+temp.data+" | - ");
            temp = temp.next ;
        }

    }

    int Count ()
    {
        return iCount;
    }

}

class Queue
{
    public static void main(String a[])
    {
        QueueX sobj = new  QueueX ();
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

    }
}  