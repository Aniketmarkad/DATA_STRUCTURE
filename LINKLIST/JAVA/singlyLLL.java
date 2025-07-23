class node
{
    public int data ;
    public node next;
}

class singlyLLLX
{
    private node first;
    private node last ;
    private int icount;

    public
    singlyLLLX()
    {
        first = null;
        last = null;
        icount = 0;
    }

    void insertfirst(int no)
    {
        node newn = null;
        newn = new node();

        newn.data = no;
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
        icount++;
    }

    void insertlast(int no)
    {
        node newn = null;
        node temp = null;

        newn = new node();

        newn.data = no;
        newn.next = null;
    
        if(first == null)
        {
            first = newn;
        }
        else
        {
            temp = first;

            while(temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = newn;
        }
        icount++;
    }

    void insertatpos(int no,int pos)
    {
        node newn = null;
        node temp = null;
        int icnt = 0;


        icount = count();

        if(pos < 1 || pos > icount + 1)
        {
            System.out.println("invalid position");
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
            newn = new node();

            newn.data = no;
            newn.next = null;

            for(icnt = 1;icnt < pos-1 ;icnt++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
            temp.next= newn;

            icount++;

        }
    }

    void deletefirst()
    {
        if(first == null)
        {
            return;
        }
        else if (first.next == null)
        {
            first = null;
        }
        else
        {
            first = first.next;
        }
        icount--;
    }

    void deletelast()
    {
        node temp = null;

        if(first == null)
        {
            return;
        }
        else if (first.next == null)
        {
            first = null;
        }
        else
        {
            temp = first;

            while(temp.next.next != null)
            {
                temp = temp.next;
            }
            temp.next = null;
        }
        icount--;
    }

    void deleteatpos(int pos)
    {
        node temp = null;
        int icnt = 0;
        icount = count();

        if(pos < 1 || pos > icount )
        {
            System.out.println("invalid position");
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
                temp = temp.next;
            }
            temp.next = temp.next.next;

            icount--;
        }

    }

    void display()
    {
        node temp = null;

        temp = first;

        while(temp != null)
        {
            System.out.print(" | "+temp.data+" | ->");
            temp = temp.next;
        }
        System.out.println("NULL");

    }

    int count ()
    {
        return icount;
    }

}

class singlyLLL
{
    public static void main(String a[])
    {
        singlyLLLX sobj = new singlyLLLX();
        int iret = 0;

        sobj.insertfirst(51);
        sobj.insertfirst(21);
        sobj.insertfirst(11);

        sobj.display();
        iret = sobj.count();
        System.out.println("no of element in linklist : " + iret);

        sobj.insertlast(101);
        sobj.insertlast(111);
        sobj.insertlast(121);

        sobj.display();
        iret = sobj.count();
        System.out.println("no of element in linklist : " + iret);

        sobj.insertatpos(105,5);

        sobj.display();
        iret = sobj.count();
        System.out.println("no of element in linklist : " + iret);


        sobj.deletefirst();

        sobj.display();
        iret = sobj.count();
        System.out.println("no of element in linklist : " + iret);

        sobj.deletelast();

        sobj.display();
        iret = sobj.count();
        System.out.println("no of element in linklist : " + iret);

        sobj.deleteatpos(5);

        sobj.display();
        iret = sobj.count();
        System.out.println("no of element in linklist : " + iret);

    }
}
