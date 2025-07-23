class node<T>
{
    public T data ;
    public node<T> next;
    public node<T> prev;
}

class doublyCLLX<T>
{
    private node<T> first;
    private node<T> last ;
    private int icount;

    public
    doublyCLLX()
    {
        first = null;
        last = null;
        icount = 0;
    }

    void insertfirst(T no)
    {
        node<T> newn = new node<T>();

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

    void insertlast(T no)
    {
        node<T> newn = new node<T>();

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

    void insertatpos(T no,int pos)
    {
        int icnt = 0;
        node<T> newn = new node<T>();
        node<T> temp = new node<T>();

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
            node<T> temp = new node<T>();
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
        node<T> temp = new node<T>();

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

class GENdoublyCLL
{
    public static void main(String a[])
    {
        doublyCLLX<Integer> sobj = new doublyCLLX<>();
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

        ////////////////////////////////////////////////////////////////////////////////////////
        
        doublyCLLX<Double> sobj1 = new doublyCLLX<>();
        

        sobj1.insertfirst(51.34);
        sobj1.insertfirst(21.45);
        sobj1.insertfirst(11.34);

        sobj1.display();
        iret = sobj1.count();
        System.out.println("no of element in linklist : " + iret);

        sobj1.insertlast(101.34);
        sobj1.insertlast(111.67);
        sobj1.insertlast(121.89);

        sobj1.display();
        iret = sobj1.count();
        System.out.println("no of element in linklist : " + iret);

        sobj1.insertatpos(105.45,5);

        sobj1.display();
        iret = sobj1.count();
        System.out.println("no of element in linklist : " + iret);


        sobj1.deletefirst();

        sobj1.display();
        iret = sobj1.count();
        System.out.println("no of element in linklist : " + iret);

        sobj1.deletelast();

        sobj1.display();
        iret = sobj1.count();
        System.out.println("no of element in linklist : " + iret);

        sobj1.deleteatpos(5);

        sobj1.display();
        iret = sobj1.count();
        System.out.println("no of element in linklist : " + iret);


        ///////////////////////////////////////////////////////////////////////////////////
        
        doublyCLLX<String> sobj3 = new doublyCLLX<>();

        sobj3.insertfirst("anii");
        sobj3.insertfirst("devaba");
        sobj3.insertfirst("markad");

        sobj3.display();
        iret = sobj3.count();
        System.out.println("no of element in linklist : " + iret);

        sobj3.insertlast("sagar");
        sobj3.insertlast("devaba");
        sobj3.insertlast("markad");

        sobj3.display();
        iret = sobj3.count();
        System.out.println("no of element in linklist : " + iret);

        sobj3.insertatpos("and",5);

        sobj3.display();
        iret = sobj3.count();
        System.out.println("no of element in linklist : " + iret);


        sobj3.deletefirst();

        sobj3.display();
        iret = sobj3.count();
        System.out.println("no of element in linklist : " + iret);

        sobj3.deletelast();

        sobj3.display();
        iret = sobj3.count();
        System.out.println("no of element in linklist : " + iret);

        sobj3.deleteatpos(5);

        sobj3.display();
        iret = sobj3.count();
        System.out.println("no of element in linklist : " + iret);



    }
}


