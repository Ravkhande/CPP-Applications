#include<iostream>

using namespace std;


class Array
{
public:
	int *Arr;
	int size;
                         
	Array(int length=10)         // Parametrized constructor with default argument
	{
		cout<<"Inside constructor\n";
		Arr=new int[length];
		size=length;

	}

	~Array()
	{
		cout<<"Inside destructor\n";
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


int main()
{
	Array *aobj=NULL;

	aobj=new Array();        // Dyanamic object creation
	aobj->Accept();
	aobj->Display();


	delete aobj;       // Dynamic memory deallocation

     return 0;

}