#include<iostream>
using namespace std;

typedef struct node // Structure declaratiom
{
    int data;
    struct node *next;
    struct node *prev;
}NODE,*PNODE;

class DoublyLL
{
private:                        // Characteristics
    PNODE Head;             // Its like First pointer from main function in C language
    int iSize;
    
public:                         // Behaviours
    DoublyLL();         // Constructor
    void Display();
    int Count();
    void InsertFirst(int);
    void InsertLast(int);
    void InsertAtPos(int,int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
}; // End of class Declartion

DoublyLL::DoublyLL()
{
    Head = NULL;
    iSize = 0;
}

inline void DoublyLL::Display()
{
    PNODE temp = Head;
    
    while(temp != NULL)
    {
        cout<<temp->data<<"-> ";
        temp = temp->next;
    }
    cout<<"\n";
}

inline int DoublyLL::Count()
{
    return iSize;
}

void DoublyLL::InsertFirst(int value)
{
    PNODE newn = new NODE;
    
    newn->data = value;
    newn->next = NULL;
    newn->prev = NULL;
    
    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head->prev = newn;
        Head = newn;
    }
    iSize++;
}

void DoublyLL::InsertLast(int value)
{
    PNODE newn = new NODE;
    
    newn->data = value;
    newn->next = NULL;
    newn->prev = NULL;
    
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
        newn->prev = temp;
    }
    iSize++;
}

void DoublyLL::InsertAtPos(int value ,int pos)
{
    if((pos < 1) || (pos > iSize + 1))
    {
        return;
    }
    if(pos == 1)
    {
        InsertFirst(value);
    }
    else if(pos == iSize +1)
    {
        InsertLast(value);
    }
    else
    {
        PNODE newn = new NODE;
        newn->data = value;
        newn->next = NULL;
        newn->prev = NULL;
        
        PNODE temp = Head;
        
        for(int i = 1; i< pos-1; i++)
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

void DoublyLL::DeleteFirst()
{
    
}

void DoublyLL::DeleteLast()
{
    
}

void DoublyLL::DeleteAtPos(int pos)
{
    
}

int main()
{
    DoublyLL obj;       // Object creation
    
    int choice = 1, no = 0, pos = 0;
    
    while(choice)
    {
        cout<<"Enter choice\n";
        cout<<"1 Insert at first: \n";
        cout<<"2 Insert at last: \n";
        cout<<"3 Insert at position: \n";
        cout<<"4 Delete first: \n";
        cout<<"5 Delete last: \n";
        cout<<"6 Delete at position: \n";
        cout<<"7 Display contents: \n";
        cout<<"8 Count number of node: \n";
        cout<<"0 Exit the application: \n";
    
        cin>>choice;
        
        switch(choice)
        {
            case 1:
                cout<<"Enter number\n";
                cin>>no;
                obj.InsertFirst(no);
            break;
            
            case 2:
                cout<<"Enter number\n";
                cin>>no;
                obj.InsertLast(no);
            break;
            
            case 3:
                cout<<"Enter number\n";
                cin>>no;
                cout<<"Enter position\n";
                cin>>pos;
                obj.InsertAtPos(no,pos);
                break;
            
            case 4:
                obj.DeleteFirst();
                break;
            
            case 5:
                obj.DeleteLast();
                break;
            
            case 6:
                cout<<"Enter position\n";
                cin>>pos;
                obj.DeleteAtPos(pos);
                break;
            
            case 7:
                cout<<"Contents of linked list are\n";
                obj.Display();
                break;
            
            case 8:
                cout<<"Number of elements are : "<<obj.Count()<<"\n";
                break;
            
            case 0:
                cout<<"Thank you for using the application\n";
                break;
                
            default:
                cout<<"Wrong choice\n";
                break;
        }// End of swirch
    }   // End of while
    
    return 0;
}// End of main
























