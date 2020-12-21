
//  Stack using Object oriented Approach  //

using namespace std;

#include <iostream>

typedef struct Node
{
    int data;
    struct Node *next;
} NODE, *PNODE;

class Stack
{
public:
    PNODE Head;

    Stack() // default constructor
    {
        Head = NULL;
    }

    void Push(int value)
    {
        PNODE newn = NULL;
        newn = new NODE;
        newn->data = value;
        newn->next = NULL;

        if (Head == NULL) // if LL is empty
        {
            Head = newn;
        }
        else
        {
            newn->next = Head;
            Head = newn;
        }
    }

    int Pop()
    {
        PNODE temp = Head;

        if (Head == NULL)
        {
            printf("Stack is empty\n");
            return -1;
        }
        else
        {
            int no = 0;
            no = Head->data;
            Head = Head->next;
            delete temp;
            return no;
        }
    }

    int Peep()
    {
        if (Head == NULL)
        {
            printf("Stack is empty\n");
            return -1;
        }
        else
        {
            int no = 0;
            no = Head->data;
            return no;
        }
    }

    void Display()
    {
        PNODE temp = Head;

        while (temp != NULL)
        {
            printf("| %d |\n", temp->data);
            temp = temp->next;
        }
    }

    int Count()
    {
        int iCnt = 0;
        PNODE temp = Head;

        while (temp != NULL)
        {
            iCnt++;                             //printf("| %d |\n",temp->data);
            temp = temp->next;
        }

        return iCnt;
    }
};

int main()
{
    int iRet = 0, choice = 1, no = 0;
    Stack obj1;

    while (choice != 0)
    {

        printf("\n Object orientation approach of Stack\n");
        printf("_____________________________________________\n");
        printf(" 1:Pushed the element in stack\n");
        printf(" 2:Poped the element from stack\n");
        printf(" 3:Display the element from stack\n");
        printf(" 4:Count the element from stack\n");
        printf(" 5:Peeped element from stack \n");
        printf(" 6:Exit\n");

        printf("Enter your choice:\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            cout << "Enter the number" << endl;
            cin >> no;
            obj1.Push(no);
            break;

        case 2:
            iRet = obj1.Pop();
            cout << "Popped element is :" << iRet << endl;
            break;

        case 3:
            obj1.Display();
            break;

        case 4:
            iRet = obj1.Count();
            cout << "\n Number of element from stack is :" << iRet << endl;
            break;

        case 5:
            iRet = obj1.Peep();
            cout << "\n Peeped element from stack is :" << iRet << endl;
            break;

        case 6:
            cout << "Thanks for using Application" << endl;
            exit(0);
            break;

        default:
            cout << "Error: Wrong Choice" << endl;
        }
    }

    return 0;
}
