using namespace std;

#include<iostream>

// Generic implementation of function
template<class T>     //templat header

T Maximum(T no1,T no2,T no3)
{
      T iMax;
      if((no1>=no2) && (no1>=no3))
      {
      	iMax=no1;

      }
      else if((no2>=no1) && (no2>=no3))
      {
      	iMax=no2;
      }
      else if((no3>=no1) && (no3>=no2))
      {
      	iMax=no3;
      }

      return iMax;
}


int main()
{
      int value1,value2,value3;
        int iRes=0;

      cout<<"Enter the first number\n";
      cin>>value1;
     cout<<"Enter the second number\n";
      cin>>value2;
      cout<<"Enter the third number\n";
      cin>>value3;

      iRes=Maximum(value1,value2,value3);
      cout<<"Largest number is"<<"\t"<<iRes<<endl;


	float fvalue1,fvalue2,fvalue3;
      float fRes=0.0;

	cout<<"Enter the first number\n";
	cin>>fvalue1;
     cout<<"Enter the second number\n";
	cin>>fvalue2;
	cout<<"Enter the third number\n";
	cin>>fvalue3;

	
	fRes=Maximum(fvalue1,fvalue2,fvalue3);
	cout<<"Largest number is"<<"\t"<<fRes<<endl;

	return 0;
}