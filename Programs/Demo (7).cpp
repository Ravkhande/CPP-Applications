// Class for array in generic way

#include<iostream>
using namespace std;

typedef int BOOL;

#define TRUE 1
#define FALSE 0

template <class T>      // Template header
class Array
{
public:
    T *Arr;           // Characteristics
    int size;           // Characteristics
    Array(int length = 10)      // Parametrised constructor with Defauly value
    {
        cout<<"Inside Constructor\n";
        Arr = new T[length];      // Dynamic memory allocation
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
    BOOL LinearSearch(T no)
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
    int no = 0;
    float value = 0;
    cout<<"Enter the number of elelemts\n";
    cin>>no;
    // Array obj(no);   specific
    Array <float>*obj;     // pointer of Array class
    obj = new Array<float>(no); // Dynamic object of Array class
    
    obj->Accept();
    obj->Display();
    cout<<"Enter element to search\n";
    cin>>value;
    
    BOOL bret = FALSE;
    bret = obj->LinearSearch(value);
    if(bret == TRUE)
    {
        cout<<"Element found\n";
    }
    else
    {
        cout<<"There is no such element\n";
    }
    
    return 0;
}





















