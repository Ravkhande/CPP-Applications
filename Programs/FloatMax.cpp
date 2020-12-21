using namespace std;

#include<iostream>

float Maximum(float no1,float no2,float no3)
{
      float iMax=0;
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
	float value1=0,value2=0,value3=0;

	cout<<"Enter the first number\n";
	cin>>value1;

     cout<<"Enter the second number\n";
	cin>>value2;

	cout<<"Enter the third number\n";
	cin>>value3;


	float iRes=0;
	iRes=Maximum(value1,value2,value3);
	cout<<"Largest number is"<<"\t"<<iRes<<endl;

	return 0;
}