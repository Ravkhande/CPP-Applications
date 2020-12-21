// Maximum of 3 numbers

#include<iostream>
using namespace std;

int Maximum(int no1, int no2, int no3)
{
    int max = 0;
    
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
    
    return 0;
}
