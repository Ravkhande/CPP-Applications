// Class for array

#include<iostream>
using namespace std;

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

int main()
{
    Array *obj1 = new Array();   // Dynamic object creation
    
    obj1->Accept();
    obj1->Display();
    
    delete obj1;                //  Dynmic memory deallocation
   
    return 0;
}





















