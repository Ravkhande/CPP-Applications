
/*
Complete below code snippet by writing definitions of below function
1.SearchLast() - Search last occurrence of number
2.EvenCount() - Count even elements
3.OddCount(). - Count odd elements
4.SumAll(). - sum of all elements 

*/

using namespace std;
#include<iostream>


class Array
{
    protected:
    	int *Arr;
    	int Size;

    public:
    	Array(int iLength=10)
    	{
    		cout<<"Inside Parametrized constructor with default arguments\n";
           this->Size=iLength;
           this->Arr=new int[Size];
    	}

    	Array(Array &ref)
    	{
    		cout<<"Inside copy constructor\n";
    		this->Size=ref.Size;
    		this->Arr=new int[this->Size];


    		for(int i=0;i<Size;i++)
    		{
                 this->Arr[i]=ref.Arr[i];
    		}

    	}


    	~Array()
    	{
    		cout<<"Inside Destructor\n";

    		delete[]Arr;
    	}

    	inline void Accept();
    	inline void Display();
};


void Array::Accept()
{
	cout<<"Enter the elements of array:\n";
	for(int i=0;i<this->Size;i++)
	{
		cin>>Arr[i];
	}
}

void Array::Display()
{
	cout<<"Enterred elements are :\n";
	for(int i=0;i<this->Size;i++)
	{
		cout<<Arr[i]<<"\t";
	}
}


class ArraySearch:public Array
{
      public:
      	ArraySearch(int no = 10) : Array(no)        
        {
           
        } 

 int Frequency(int);
 int SearchFirst(int);
 int SearchLast(int);
 int EvenCount();
 int OddCount(); 

};


int ArraySearch::Frequency(int value)
{
	int iCnt=0;
	for(int i=0;i<Size;i++)
	{
		if(Arr[i]==value)
		{
			iCnt++;
		}
	}

	return iCnt;
}


int ArraySearch::SearchFirst(int value)
{
	int iCnt=0;
	for(int i=0;i<Size;i++)
	{
		iCnt++;
		if(Arr[i]==value)
		{
			break;
		}
	}

	return iCnt;
}


int ArraySearch::SearchLast(int value)
{
	int iCnt=0,iPos=0;
	for(int i=0;i<Size;i++)
	{
		iCnt++;
		if(Arr[i]==value)
		{
			iPos=iCnt;
		}
	}
	return iCnt;
}

int ArraySearch::EvenCount()
{
	int iCnt=0;
	for(int i=0;i<Size;i++)
	{
         if((Arr[i]%2)==0)
         {
         	iCnt++;
         }
	}

	return iCnt;
}


int ArraySearch::OddCount()
{
	int iCnt=0;
	for(int i=0;i<Size;i++)
	{
		if((Arr[i]%2)!=0)
		{
			iCnt++;

		}
	}

	return iCnt;
}


int main()
{
	int iSize=0,iValue=0,iRet=0;

	 cout<<"Inside main\n";
	 cout<<"Enter the Size of array:\n";
	 cin>>iSize;
	 ArraySearch sobj1(iSize);
	 sobj1.Accept();
	 sobj1.Display();

     cout<<"\nEnter the value whose Frequency we want:\n";
     cin>>iValue;
	 iRet=sobj1.Frequency(iValue);
	 cout<<"Frequency of that value is : "<<"\t"<<iRet<<"\n";

	 cout<<"\nEnter the value whose first occurrence we want :\n";
     cin>>iValue;
	 iRet=sobj1.SearchFirst(iValue);
	 cout<<"First occurance of that value is : "<<"\t"<<iRet<<"\n";

	 cout<<"\nEnter the value whose Last occurrence we want :\n";
     cin>>iValue;
	 iRet=sobj1.SearchLast(iValue);
	 cout<<"Last occurrence of that value is : "<<"\t"<<iRet<<"\n";

	 iRet=sobj1.EvenCount();
	 cout<<"\nCount of even elements are : "<<"\t"<<iRet<<"\n";

	 iRet=sobj1.OddCount();
	 cout<<"\nCount of odd elements are : "<<"\t"<<iRet<<"\n";

	return 0;
}