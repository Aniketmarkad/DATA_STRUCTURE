class node
{
    public int data ;
    public node next;
    public node prev;
}

class doublyCLLX
{
    private node first;
    private node last ;
    private int icount;

    public
    doublyCLLX()
    {
        first = null;
        last = null;
        icount = 0;
    }

    void insertfirst(int no)
    {
        node newn = new node();

        newn.data = no;
        newn.next = null;
        newn.prev = null;

        if(first == null && last == null)
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn.next = first;
            first.prev = newn;

            first = newn;   
        }
        last.next= first;
        first.prev = last;
        icount++;

    }

    void insertlast(int no)
    {
        node newn = new node();

        newn.data = no;
        newn.next = null;
        newn.prev = null;

        if(first == null && last == null)
        {
            first = newn;
            last = newn;
        }
        else
        {
            last.next = newn;
            newn.prev = last;

            last = newn;
        }
        last.next = first;
        first.prev = last;
        icount++;

    }

    void insertatpos(int no,int pos)
    {
        int icnt = 0;
        node newn = new node();
        node temp = new node();

        if(pos < 1 || pos > icount + 1) 
        {
            System.out.println("invalid position");
            return;
        }

        if(pos == 1)
        {
            insertfirst(no);
        }
        else if( pos == icount + 1)
        {
            insertlast(no);
        }
        else
        {
            temp = first;

            newn.data = no;
            newn.next = null;
            newn.prev = null;

            for(icnt = 1;icnt < pos - 1;icnt++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
            temp.next.prev = newn;

            temp.next  = newn;
            newn.prev = temp;

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
        last.next = first;
        first.prev= last;

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
            last = last.prev;
        }
        last.next = first;
        first.prev = last;

        icount--;

    }

    void deleteatpos(int pos)
    {
        if(pos < 1 || pos > icount) 
        {
            System.out.println("invalid position");
            return;
        }

        if(pos == 1)
        {
            deletefirst();
        }
        else if( pos == icount)
        {
            deletelast();
        }
        else
        {
            node temp = new node();
            int icnt  = 0;
            temp = first;

            for(icnt = 1;icnt < pos-1;icnt++)
            {
                temp = temp.next;
            }
            temp.next = temp.next.next;
            temp.next.prev = temp;

            icount--;
        }
    }

    void display()
    {
        node temp = new node();

        temp = first;

        if(first == null && last == null)
        {
            return;
        }

        System.out.print(" <=>");
        do
        {
            System.out.print(" | "+ temp.data +" | <=> ");
            temp = temp.next;
        }while(temp != last.next);
        System.out.println();
        
    }

    int count ()
    {
        return icount;
    }

}

class doublyCLL
{
    public static void main(String a[])
    {
        doublyCLLX sobj = new doublyCLLX();
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

