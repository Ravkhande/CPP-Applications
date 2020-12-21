// Class for array in generic way

#include<iostream>
using namespace std;

typedef int BOOL;

#define TRUE 1
#define FALSE 0

template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class SinglyLinkedList
{
public:
    struct node<T> * Head;
    
    SinglyLinkedList()
    {
        Head = NULL;
    }
    
    void InsertFirst(T no)
    {
        struct node<T> * newn = new node<T>;
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
    
    void InsertLast(T no)
    {
        struct node<T> * newn = new node<T>;
        newn->data = no;
        newn->next = NULL;
        
        if(Head == NULL)
        {
            Head = newn;
        }
        else
        {
            struct node<T> *temp = Head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
        }
    }
    
    void Display()
    {
        struct node<T> * temp = Head;
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
        struct node<T> * temp = Head;

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
    SinglyLinkedList <float>obj1;
    
    obj1.InsertFirst(51.23);
    obj1.InsertFirst(21.45);
    obj1.InsertFirst(11.78);
    
    obj1.Display();
    
    SinglyLinkedList <char>obj2;
    
    obj2.InsertFirst('C');
    obj2.InsertFirst('B');
    obj2.InsertFirst('A');
    
    obj2.Display();
   
    return 0;
}





















