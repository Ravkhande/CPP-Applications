#include<iostream>

using namespace std;
typedef int BOOL;
#define TRUE 1
#define FALSE 0

class Array
{
public:
	int *Arr;
	int size;
                         
	Array(int length=10)         // Parametrized constructor with default argument
	{
		cout<<"Inside Base constructor\n";
		Arr=new int[length];
		size=length;

	}

	~Array()
	{
		cout<<"Inside Base destructor\n";
		delete []Arr;
	}

	void Accept()
	{
		cout<<"Enter the elements\n";
		for(int i=0;i<size;i++)
		{
			cin>>Arr[i];
		}
	}

	void Display()
	{
		cout<<"Entered elements are :\n";
		for(int i=0;i<size;i++)
		{
			cout<<Arr[i]<<"\t";
		}

		cout<<"\n";
	}




};

class Searching:public Array
{
public:

	Searching(int no=10):Array(no)        // Parametrized constructor with default argument and base member initialization
	{
        cout<<"Inside Derived constructor\n";
	}

	BOOL LinearSearch(int no)
	{
		int i=0;
		for(i=0;i<size;i++)
		{
			if(Arr[i]==no)
			{
				break;
			}
		}

		if(Arr[i]==no)
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	
};

int main()
{
	int no=0,value=0;
	cout<<"Enter the number of elements\n";
	cin>>no;

	Searching *sobj=new Searching(no);        // Dyanamic object creation
	sobj->Accept();
	sobj->Display();

	cout<<"Enter the number that we want to search\n";
	cin>>value;

    BOOL bRet=FALSE;
    bRet=sobj->LinearSearch(value);
    if(bRet==TRUE)
    {
    	cout<<"Element is present\n";
    }
    else
    {
    	cout<<"Element is not present\n";
    }

	delete sobj;       // Dynamic memory deallocation

     return 0;

}