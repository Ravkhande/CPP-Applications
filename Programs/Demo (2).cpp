// Maximum of 3 numbers

#include<iostream>
using namespace std;

// Generic implementation of maximum function
template <class T>          // Template header
T Maximum(T no1, T no2, T no3)
{
    T max = 0;
    
    if((no1 >= no2) && (no1 >= no3))
    {
        max = no1;
    }
    else if((no2 >= no1) && (no2 >= no3))
    {
        max = no2;
    }
    else
    {
        max = no3;
    }
    return max;
}

int main()
{
    int value1, value2, value3;
    int iret = 0;
    
    cout<<"Enter first number\n";
    cin>>value1;
    cout<<"Enter second number\n";
    cin>>value2;
    cout<<"Enter third number\n";
    cin>>value3;
    iret = Maximum(value1,value2,value3);
    cout<<"Largest number is : "<<iret<<"\n";
    
    float fvalue1, fvalue2, fvalue3;
    float fret = 0.0;
    
    cout<<"Enter first number\n";
    cin>>fvalue1;
    cout<<"Enter second number\n";
    cin>>fvalue2;
    cout<<"Enter third number\n";
    cin>>fvalue3;
    fret = Maximum(fvalue1,fvalue2,fvalue3);
    cout<<"Largest number is : "<<fret<<"\n";
    
    return 0;
}
