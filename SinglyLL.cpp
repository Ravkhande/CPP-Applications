
#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
} NODE, *PNODE;

class SinglyLL
{
private:
    PNODE Head;
    int iSize;

public:
    SinglyLL();
    void InsertFirst(int);
    void InsertLast(int);
    void Display();
    int Count();
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPos(int, int);
    void DeleteAtPos(int);
};

SinglyLL::SinglyLL()
{
    Head = NULL;
    iSize = 0;
}

void SinglyLL::InsertFirst(int value)
{
    PNODE newn = NULL;
    newn = new NODE;
    newn->next = NULL;

    if (Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }

    iSize++;
}

void SinglyLL::InsertLast(int value)
{
    PNODE newn = NULL;
    newn = new NODE;
    newn->next = NULL;

    if (Head == NULL)
    {
        Head = newn;
    }
    else
    {
        PNODE temp = Head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->next = NULL;
    }
    iSize++;
}

inline void SinglyLL::Display()
{
    PNODE temp = Head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "\n";
}

inline int SinglyLL::Count()
{
    return iSize;
}

void SinglyLL::DeleteFirst()
{
    if (Head == NULL)
    {
        return;
    }
    else if (Head->next == NULL)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        PNODE temp = Head;
        Head = Head->next;
        delete temp;

        iSize--;
    }
}

void SinglyLL::DeleteLast()
{
    if (Head == NULL)
    {
        return;
    }
    else if (Head->next == NULL)
    {
        delete (Head);
        Head = NULL;
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

void SinglyLL::InsertAtPos(int value, int pos)
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

void SinglyLL::DeleteAtPos(int pos)
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
    SinglyLL obj;
    int choice = 1;
    int pos = 0;
    int no = 0;

    while (choice != 0)
    {
        cout << "Object oriented approach of Singly Linear Linked list"
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
            obj.InsertFirst(no);

            break;

        case 2:
            cout << "Enter the number"
                 << "\n";
            cin >> no;
            obj.InsertLast(no);
            break;

        case 3:
            cout << "Contents of Linked list are\n";
            obj.Display();
            break;

        case 4:
            cout << "Number of elements are:" << obj.Count() << "\n";
            break;

        case 5:
            obj.DeleteFirst();
            break;

        case 6:
            obj.DeleteLast();
            break;

        case 7:
            cout << "Enter the number"
                 << "\n";
            cin >> no;

            cout << "Enter the position"
                 << "\n";
            cin >> pos;

            obj.InsertAtPos(no, pos);

            break;

        case 8:
            cout << "Enter the position"
                 << "\n";
            cin >> pos;

            obj.DeleteAtPos(pos);

            break;

        case 0:
            cout << "Thanks for using the aplication"
                 << "\n";

            break;

        default:

            cout << "wrong choice";
        }
    }
    return 0;
}
