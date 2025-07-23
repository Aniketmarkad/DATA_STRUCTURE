class node
{
    public int data ;
    public node next;
}

class singlyCLLX
{
    private node first;
    private node last ;
    private int icount;

    public
    singlyCLLX()
    {
        first = null;
        last = null;
        icount = 0;
    }

    void insertfirst(int no)
    {
        node newn = null;
        newn = new node ();

        newn.data = no;
        newn.next = null;

        if(first == null)
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn.next = first;
            first = newn;
        }
        last.next = first;
        icount++;
    }

    void insertlast(int no)
    {
        node newn = null;
        newn = new node ();

        newn.data = no;
        newn.next = null;

        if(first == null)
        {
            first = newn;
            last = newn;
        }
        else
        {
            last.next = newn;
            last = newn;
        }
        last.next = first;
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
        if(first == null && last == null)
        {
            return;
        }
        else if (first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            first = first.next;
        }
        last.next= first;
        icount--;
    }

    void deletelast()
    {
        if(first == null && last == null)
        {
            return;
        }
        else if (first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            node temp = null;
            temp = first;

            while(temp.next.next != first)
            {
                temp = temp.next;
            }
            temp.next = first;
            last = temp;
        }
        last.next = first;
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

        if(first == null && last == null)
        {
            return;
        }
        temp = first;

        System.out.print("->");
        do
        {
            System.out.print(" | "+temp.data+" | -> ");
            temp = temp.next;
        }while(temp != last.next);
        System.out.println();
        
    }

    int count ()
    {
        return icount;
    }

}

class singlyCLL
{
    public static void main(String a[])
    {
        singlyCLLX sobj = new singlyCLLX();
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

