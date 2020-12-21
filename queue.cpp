
#include <iostream>

using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
} NODE, *PNODE;

template <class T>

class Queue
{
private:
    PNODE Head;
    int iSize = 0;

public:
    Queue();
    ~Queue();
    void Enqueue(T); //same as insertLast
    void Display();
    T Count();
    T Dequeue(); //same as Deletefirst
};

template <class T>
Queue<T>::Queue()
{
    Head = NULL;
    iSize = 0;
}

template <class T>
Queue<T>::~Queue()
{
    cout << "we delete all element from queue"
         << "\n";
    if (Head == NULL)
    {
        return;
    }
    else
    {
        delete Head;
    }
}

template <class T>
void Queue<T>::Enqueue(T value)
{
    PNODE newn = NULL;
    newn = new NODE;
    newn->next = NULL;
    newn->data = value;

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
    }

    iSize++;
}

template <class T>
inline void Queue<T>::Display()
{
    PNODE temp = Head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "\n";
}

template <class T>
inline T Queue<T>::Count()
{
    return iSize;
}

template <class T>
T Queue<T>::Dequeue()
{
    if (Head == NULL)
    {
        cout << "queue is empty";
        return -1;
    }
    else
    {
        PNODE temp = Head;
        T no = 0;
        Head = Head->next;
        no = temp->data;
        delete temp;

        iSize--;
        return no;
    }
}

int main()
{
    Queue<int> intobj1; // class template object
    int choice = 1;
    int no = 0;

    while (choice != 0)
    {
        cout << "Object oriented approach of Queue"
             << "\n";
        cout << " 1:Insert last element in queue"
             << "\n";
        cout << " 2:Delete first element from queue"
             << "\n";
        cout << " 3:Display"
             << "\n";
        cout << " 4:Count"
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
            intobj1.Enqueue(no);

            break;

        case 2:
            no = intobj1.Dequeue();
            cout << "Removed element from queue is:" << no << "\n";
            cout << "\n";
            break;

        case 3:
            intobj1.Display();

            break;

        case 4:
            cout << "Number of elements are:" << intobj1.Count() << "\n";
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
