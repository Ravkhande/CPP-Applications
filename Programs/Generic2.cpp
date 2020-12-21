#include<iostream>

using namespace std;
typedef int BOOL;
#define TRUE 1
#define FALSE 0

template<class T>

class Array
{
public:
	T *Arr;
	int size;
                         
	Array(int length=10)         // Parametrized constructor with default argument
	{
		cout<<"Inside Base constructor\n";
		Arr=new T[length];
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

	BOOL LinearSearch(T no)
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
	int no=0;
	char value='\0';
	cout<<"Enter the number of charcters\n";
	cin>>no;

     // Array<float>aobj(no);     static object creation
	Array <char>*aobj=new Array<char>(no);        // Dynamic object creation by using generic 
	aobj->Accept();
	aobj->Display();

	cout<<"Enter the character that we want to search\n";
	cin>>value;

    BOOL bRet=FALSE;
    bRet=aobj->LinearSearch(value);
    if(bRet==TRUE)
    {
    	cout<<"Element is present\n";
    }
    else
    {
    	cout<<"Element is not present\n";
    }

	delete aobj;       // Dynamic memory deallocation

     return 0;

}