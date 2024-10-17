template <class T >
struct DOUBLY
{
    T Data ; 
    DOUBLY <T> * next;
    DOUBLY <T>* prev ;
    public : 
    DOUBLY (  T value )
    {
        next = nullptr;
        prev= nullptr;
        Data = value;
    }
};

template < class T>
class DLL
{
    private : 

        int dataCount;
        struct DOUBLY <T> * Head;
        struct DOUBLY <T> * Tail;
    public : 
        DLL();
        void Display ();
        void DisplayRev ();
        int Count();
        void InsertFirst(T value);
        void InsertLast(T value);
        void InsertAtPos(T value , int Pos);
        void DeleteAtPos(  int Pos);
        void DeleteFirst ( );
        void DeleteLast ();
};

template <class T>
DLL <T> :: DLL()
{
    dataCount = 0 ; 
    this-> Head = nullptr;
}

template <class T>
int  DLL <T> :: Count()
{
    return dataCount;
} 

template <class T >
void DLL <T> :: Display()
{
    if ( Head != nullptr && Tail != nullptr)
    {
        struct DOUBLY <T> * temp = Head; 
        // printf("Elements of Linked List Are  : \n");
        while ( temp != nullptr )
        {
            cout<<temp-> Data <<"\t";
            temp = temp -> next;
        }
    }
    cout<<endl;
}

template <class T >
void DLL <T> :: DisplayRev()
{
    if ( Head != nullptr && Tail != nullptr)
    {
        struct DOUBLY <T> * temp = Tail; 
        printf("Elements of Linked List Are  : \n");
        while ( temp != nullptr )
        {
            cout<<temp-> Data <<"\t";
            temp = temp -> prev;
        }
    }
    cout<<endl;
}

template <class T >
void DLL <T> :: InsertFirst(T value)
{
    struct DOUBLY <T> *  newn  = new DOUBLY(value);

    if ( Head == nullptr)
    {
        Head = newn;
        Tail = newn;
    }
    else 
    {
        newn -> next =  Head;
        Head -> prev = newn ;
        Head =  newn;
    }
    

    dataCount++;
} 

template <class T>
void DLL <T> :: InsertLast( T value)
{
    struct DOUBLY <T> *  newn  = new DOUBLY(value);

    if ( Head == nullptr)
    {
        Head = newn;
        Tail = newn;
    }
    else 
    {
        Tail -> next = newn ;
        newn -> prev = Tail;
        Tail = Tail -> next;
    }
    dataCount++;
}

template <class T>
void DLL <T> :: InsertAtPos( T value , int Pos)
{
    if ( (Pos > dataCount + 1 ) || ( Pos < 1))
    {
        printf("InValid Position \n ");
        return ;
    }
     if ( Pos == 1)
    {
        InsertFirst(value);
    }
    else if ( Pos == dataCount+1)
    {
        Insert(value);
    }
    else 
    {
        struct DOUBLY <T> * newn  =  new DOUBLY(value);
        struct DOUBLY <T > * temp = Head;
        for (int iCnt= 1 ; iCnt < Pos - 1 ; iCnt ++)
        {
            temp = temp -> next;
        }

        newn -> next  =  temp -> next;
        temp -> next -> prev = newn;

        temp -> next = newn ;
        newn -> prev = temp;

        dataCount++;
    }
}

template <class T >
void DLL  < T> :: DeleteFirst()
{
    if ( Head == nullptr && Tail == nullptr)
    {
        printf("Linked List Is Empty\n");
        return ;
    }
    else if ( Head == Tail)
    {
        delete Head ; 
        Head = nullptr ; 
        Tail = nullptr;
    }
    else 
    {
        Head = Head -> next;
        delete Head -> prev;
        Head -> prev = nullptr;
    }

    Tail -> next = Head;
    dataCount--;
}

template <class T >
void DLL <T> :: DeleteLast()
{
    if ( Head == nullptr && Tail == nullptr)
    {
        printf("Linked List Is Empty\n");
        return ;
    }
    else if ( Head == Tail)
    {
        delete Head ; 
        Head = nullptr ; 
        Tail = nullptr;
    }
    else 
    {
        Tail = Tail -> prev ; 
        delete Tail -> next;
        Tail -> next = nullptr;
        
    }
    dataCount--;
}

template <class T>
void DLL <T> :: DeleteAtPos ( int Pos)
{
    if (( Pos < 1  )  | ( Pos > dataCount) )
    {
        printf("Invalid Position \n");
        return ;
    }
    if ( Pos == 1)
    {
        DeleteFirst();
    }
    else if ( Pos == dataCount)
    {
        DeleteLast();
    }
    else 
    {
        struct DOUBLY < T > * temp = Head;
        for ( int iCnt = 1 ; iCnt < Pos - 1 ; iCnt++)
        {
            temp = temp -> next;
        }

        temp -> next = temp -> next -> next;
        delete temp -> next -> prev;
        temp -> next -> prev = temp;

        dataCount--;
    }
    
}