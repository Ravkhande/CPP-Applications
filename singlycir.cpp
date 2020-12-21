
#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
} NODE, *PNODE;

class Singlycir
{
private:
    PNODE Head;
    PNODE Tail;
    int iSize;

public:
    Singlycir();
    ~Singlycir();
    void InsertFirst(int);
    void InsertLast(int);
    void Display();
    int Count();
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPos(int, int);
    void DeleteAtPos(int);
};

Singlycir::Singlycir()
{
    Head = NULL;
    Tail = NULL;
    iSize = 0;
}

Singlycir::~Singlycir()
{
    cout << "Inside destructor"
         << "\n";
}

void Singlycir::InsertFirst(int value)
{
    PNODE newn = NULL;
    newn = new NODE;
    newn->next = NULL;

    if (Head == NULL && Tail == NULL)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }

    iSize++;
    Tail->next = Head;
}

void Singlycir::InsertLast(int value)
{

    PNODE newn = NULL;
    newn = new NODE;
    newn->next = NULL;

    if (Head == NULL && Tail == NULL)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        Tail->next = newn;
        Tail = newn;
    }

    iSize++;

    Tail->next = Head;
}

inline void Singlycir::Display()
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
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != Tail->next);
        cout << "\n";
    }
}

inline int Singlycir::Count()
{
    return iSize;
}

void Singlycir::DeleteFirst()
{
    if ((Head == NULL) && (Tail == NULL))
    {
        return;
    }
    else if (Head == Tail)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        PNODE temp = Head;
        Head = Head->next;
        delete temp;

        iSize--;
    }

    Tail->next = Head;
}

void Singlycir::DeleteLast()
{
    if ((Head == NULL) && (Tail == NULL))
    {
        return;
    }
    else if (Head == Tail)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        PNODE temp = Head;
        PNODE temp2 = NULL;

        while (temp->next->next != Head)
        {
            temp = temp->next;
        }

        delete (temp->next);
        Tail = temp;

        iSize--;
    }
    Tail->next = Head;
}

void Singlycir::InsertAtPos(int value, int pos)
{
    PNODE newn = NULL;
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
        newn = new NODE;
        newn->data = value;
        newn->next = NULL;
        PNODE temp = Head;

        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iSize++;
    }
}

void Singlycir::DeleteAtPos(int pos)
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
        PNODE temp2 = NULL;

        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;

        iSize--;
    }
}

int main()
{
    Singlycir intobj;
    int choice = 1;
    int pos = 0;
    int no = 0;

    while (choice != 0)
    {
        cout << "Object oriented approach of Singly circular Linked list"
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

            break;
        }
    }
    return 0;
}
