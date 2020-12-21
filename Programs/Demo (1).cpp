// Maximum of 3 numbers

#include<iostream>
using namespace std;

float Maximum(float no1, float no2, float no3)
{
    float max = 0;
    
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
    float value1, value2, value3;
    float iret = 0;
    
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
