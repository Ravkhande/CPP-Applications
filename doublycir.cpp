
#include <iostream>

using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} NODE, *PNODE;

template <class T>

class Doublycir
{
private:
    PNODE Head;
    PNODE Tail;
    T iSize;

public:
    Doublycir();
    ~Doublycir();
    void InsertFirst(T);
    void InsertLast(T);
    void Display();
    T Count();
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPos(T, T);
    void DeleteAtPos(T);
};

template <class T>
Doublycir<T>::Doublycir()
{
    Head = NULL;
    Tail = NULL;
    iSize = 0;
}

template <class T>
Doublycir<T>::~Doublycir()
{
    cout << "Inside destructor"
         << "\n";
}

template <class T>
void Doublycir<T>::InsertFirst(T value)
{
    PNODE newn = NULL;
    newn = new NODE;
    newn->next = NULL;
    newn->prev = NULL;

    if ((Head == NULL) && (Tail == NULL))
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        newn->next = Head;
        Head->prev = newn;
        Head = newn;
    }

    Tail->next = Head;
    Head->prev = Tail;

    iSize++;
}

template <class T>
void Doublycir<T>::InsertLast(T value)
{
    PNODE newn = NULL;
    newn = new NODE;
    newn->next = NULL;
    newn->prev = NULL;

    if ((Head == NULL) && (Tail == NULL))
    {
        Head = newn;
    }
    else
    {
        Tail->next = newn;
        newn->prev = Tail;
        Tail = newn;
    }

    Tail->next = Head;
    Head->prev = Tail;

    iSize++;
}

template <class T>
void Doublycir<T>::Display()
{
    if ((Head == NULL) && (Tail == NULL))
    {
        return;
    }
    else
    {
        PNODE temp = Head;

        do
        {
            cout << temp->data << "<->";
            temp = temp->next;
        } while (temp != Tail->next);

        cout << "\n";
    }
}

template <class T>
T Doublycir<T>::Count()
{
    return iSize;
}

template <class T>
void Doublycir<T>::DeleteFirst()
{
    if ((Head == NULL) && (Tail == NULL))
    {
        return;
    }
    else
    {
        PNODE temp = Head;
        Head = Head->next;
        delete temp;

        iSize--;
    }

    Tail->next = Head;
    Head->prev = Tail;
}

template <class T>
void Doublycir<T>::DeleteLast()
{
    if ((Head == NULL) && (Tail == NULL))
    {
        return;
    }
    else
    {
        PNODE temp = Tail;
        Tail = Tail->prev;
        delete temp;

        iSize--;
    }

    Tail->next = Head;
    Head->prev = Tail;
}

template <class T>
void Doublycir<T>::InsertAtPos(T value, T pos)
{
    if ((pos < 1) || (pos > iSize + 1))
    {
        return;
    }
    else if (pos == 1)
    {
        InsertFirst(value);
    }
    else if (pos == iSize + 1)
    {
        InsertLast(value);
    }
    else
    {

        PNODE newn = NULL;
        newn = new NODE;
        newn->data = value;
        newn->next = NULL;
        newn->prev = NULL;

        PNODE temp = Head;

        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

        iSize++;
    }
}

template <class T>
void Doublycir<T>::DeleteAtPos(T pos)
{
    if ((pos < 1) || (pos > iSize))
    {
        return;
    }
    else if (pos == 1)
    {
        DeleteFirst();
    }
    else if (pos == iSize)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp = Head;

        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete (temp->next->prev);
        temp->next->prev = temp;

        iSize--;
    }
}

int main()
{
    Doublycir<int> intobj; // class template object
    int choice = 1;
    int pos = 0;
    int no = 0;

    while (choice != 0)
    {
        cout << "Object oriented approach of Doubly circular Linked list"
             << "\n";
        cout << " 1:Insert First element"
             << "\n";
        cout << " 2:Insert Last element"
             << "\n";
        cout << " 3:Display"
             << "\n";
        cout << " 4:Count"
             << "\n";
        cout << " 5:Delete first element"
             << "\n";
        cout << " 6:Delete Last element"
             << "\n";
        cout << " 7:Insert element at position"
             << "\n";
        cout << " 8:Delete element from position "
             << "\n";
        cout << " 0: Exit the Application"
             << "\n";

        cout << "Enter your choice"
             << "\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the number"
                 << "\n";
            cin >> no;
            intobj.InsertFirst(no);

            break;

        case 2:
            cout << "Enter the number"
                 << "\n";
            cin >> no;
            intobj.InsertLast(no);
            break;

        case 3:
            intobj.Display();
            break;

        case 4:
            cout << "Number of elements are:" << intobj.Count() << "\n";
            break;

        case 5:
            intobj.DeleteFirst();
            break;

        case 6:
            intobj.DeleteLast();
            break;

        case 7:
            cout << "Enter the number"
                 << "\n";
            cin >> no;

            cout << "Enter the position"
                 << "\n";
            cin >> pos;
            intobj.InsertAtPos(no, pos);

            break;

        case 8:
            cout << "Enter the position"
                 << "\n";
            cin >> pos;
            intobj.DeleteAtPos(pos);

            break;

        case 0:
            cout << "Thanks"
                 << "\n";
            break;

        default:
            cout << "wrong choice";
        }
    }

    return 0;
}
