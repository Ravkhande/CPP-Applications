// Class for array

#include<iostream>
using namespace std;

typedef int BOOL;

#define TRUE 1
#define FALSE 0

class Array
{
public:
    int *Arr;           // Characteristics
    int size;           // Characteristics
    Array(int length = 10)      // Parametrised constructor with Defauly value
    {
        cout<<"Inside Constructor\n";
        Arr = new int[length];      // Dynamic memory allocation
        size = length;
    }
    ~Array()    // Desructor
    {
        cout<<"Inside destructor\n";
        delete []Arr;                   // Dynamic memory deallocation
    }
    void Accept()       // Behaviour
    {
        cout<<"Enter elemets\n";
        for(int i = 0; i < size; i++)
        {
            cin>>Arr[i];
        }
    }
    void Display()  // Behaviour
    {
        cout<<"Elements from array are : \n";
        for(int i = 0; i <size; i++)
        {
            cout<<Arr[i]<<"\t";
        }
        cout<<"\n";
    }
};

class Searching : public Array      // Ingheritance
{
public:
    Searching(int no = 10) : Array(no)
    {}
    BOOL LinearSearch(int no)
    {
        int i = 0;
        for(i = 0; i < size; i++)
        {
            if(Arr[i] == no){break;}
        }
        if(i == size){return FALSE;}
        else{return TRUE;}
    }
};
int main()
{
    int no = 0, value = 0;
    cout<<"Enter number of elements\n";
    cin>>no;
    Searching *obj1 = new Searching(no);   // Dynamic object creation
    obj1->Accept();
    obj1->Display();
    cout<<"Enter the element to search\n";
    cin>>value;
    BOOL bret = FALSE;
    bret = obj1->LinearSearch(value);
    if(bret == TRUE)
    {
        cout<<"Element present in the array\n";
    }
    else
    {
        cout<<"There is no such element\n";
    }
    
    delete obj1;                //  Dynmic memory deallocation
   
    return 0;
}





















