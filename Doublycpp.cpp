
#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} NODE, *PNODE;

class DoublyLL
{
private:
    PNODE Head; // Head pointer is same as First pointer in Linked list
    int iSize;

public:
    DoublyLL(); // function Declaration in class
    void InsertFirst(int);
    void DeleteFirst();
    void DeleteLast();
    void Display();
    int Count();
    void InsertLast(int);
    void InsertAtPos(int, int);
    void DeleteAtPos(int);
};

DoublyLL::DoublyLL()
{
    Head = NULL;
    iSize = 0;
}

void DoublyLL::InsertFirst(int value)
{
    PNODE newn = NULL;
    newn = new NODE;
    newn->data = value;
    newn->next = NULL;
    newn->prev = NULL;

    if (Head == NULL) // if LL is empty
    {
        Head = newn;
    }
    else // if LL contain atlest on node
    {
        newn->next = Head;
        Head->prev = newn;
        Head = newn;
    }

    iSize++;
}

void DoublyLL::InsertLast(int value)
{
    PNODE newn = NULL;
    newn = new NODE;
    newn->data = value;
    newn->next = NULL;
    newn->prev = NULL;

    if (Head == NULL) // if LL is empty
    {
        Head = newn;
    }
    else // if LL contain atlest on node
    {
        PNODE temp = Head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iSize++;
}

inline void DoublyLL::Display()
{
    PNODE temp = Head;
    while (temp != NULL)
    {
        cout << temp->data << "<->";
        temp = temp->next;
    }
    cout << "\n";
}

inline int DoublyLL::Count()
{
    return iSize;
}

void DoublyLL::DeleteFirst()
{
    if (Head == NULL)
    {
        cout << "Linked list is empty" << endl;
        return;
    }
    else
    {
        PNODE temp = Head;
        Head = Head->next;
        delete temp;

        iSize--;
    }
}

void DoublyLL::DeleteLast()
{
    if (Head == NULL)
    {
        cout << "Linked list is empty" << endl;
        return;
    }
    else
    {
        PNODE temp = Head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete (temp->next);
        temp->next = NULL;

        iSize--;
    }
}

void DoublyLL::InsertAtPos(int value, int pos)
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

void DoublyLL::DeleteAtPos(int pos)
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
    DoublyLL intobj1; // class template object
    int choice = 1;
    int pos = 0;
    int no = 0;
    while (choice != 0)
    {
        cout << "Object oriented approach of Doubly Linked list"
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
            intobj1.InsertFirst(no);

            break;

        case 2:
            cout << "Enter the number"
                 << "\n";
            cin >> no;
            intobj1.InsertLast(no);
            break;

        case 3:
            intobj1.Display();

            break;

        case 4:
            cout << "Number of elements are:" << intobj1.Count() << "\n";
            break;

        case 5:
            intobj1.DeleteFirst();
            break;

        case 6:
            intobj1.DeleteLast();
            break;

        case 7:
            cout << "Enter the number"
                 << "\n";
            cin >> no;

            cout << "Enter the position"
                 << "\n";
            cin >> pos;

            intobj1.InsertAtPos(no, pos);

            break;

        case 8:
            cout << "Enter the position"
                 << "\n";
            cin >> pos;

            intobj1.DeleteAtPos(pos);

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
