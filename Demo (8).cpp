// Class for array in generic way

#include<iostream>
using namespace std;

typedef int BOOL;

#define TRUE 1
#define FALSE 0

typedef struct node
{
    int data;
    struct node *next;
}NODE, *PNODE;

class SinglyLinkedList
{
public:
    PNODE Head;
    
    SinglyLinkedList()
    {
        Head = NULL;
    }
    
    void InsertFirst(int no)
    {
        PNODE newn = new NODE;
        newn->data = no;
        newn->next = NULL;
        
        if(Head == NULL)
        {
            Head = newn;
        }
        else
        {
            newn->next = Head;
            Head = newn;
        }
    }
    
    void InsertLast(int no)
    {
        PNODE newn = new NODE;
        newn->data = no;
        newn->next = NULL;
        
        if(Head == NULL)
        {
            Head = newn;
        }
        else
        {
            PNODE temp = Head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
        }
    }
    
    void Display()
    {
        PNODE temp = Head;
        cout<<"Elements of linked list are\n";
        while(temp != NULL)
        {
            cout<<temp->data<<"\t";
            temp = temp -> next;
        }
        cout<<"\n";
    }
    
    int Count()
    {
        int iCnt = 0;
        PNODE temp = Head;

        while(temp != NULL)
        {
            temp = temp -> next;
            iCnt++;
        }
        return iCnt;
    }
};

int main()
{
    SinglyLinkedList obj;
    
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    
    obj.Display();
    
    return 0;
}





















