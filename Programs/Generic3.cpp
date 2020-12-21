#include<iostream>

using namespace std;
typedef int BOOL;
#define TRUE 1
#define FALSE 0

template<class T>
struct node
{
	T data;
	struct node*next;
};


template<class T>
class SinglyLL
{
public:
	struct node<T>*Head;

	SinglyLL()
	{
		Head=NULL;
	}

	void InsertFirst(T no)
	{
		struct node<T>*newn=new struct node<T>;

		newn->data=no;
		newn->next=NULL;

		if(Head==NULL)
		{
			Head=newn;
		}
		else
		{
			newn->next=Head;
			Head=newn;
		}
	}
     

     void InsertLast(T no)
	{
	     struct node<T>*newn=new struct node<T>;

		newn->data=no;
		newn->next=NULL;

		if(Head==NULL)
		{
			Head=newn;
		}
		else
		{
			struct node<T>*temp=Head;

			while(temp->next!=NULL)
			{
				temp=temp->next;
			}

			temp->next=newn;
		}
	}


	void Display()
	{
		struct node<T>*temp=Head;
         
         cout<<"Entered elements are :\n";
         while(temp!=NULL)
         {
         	cout<<temp->data<<"\t";
         	temp=temp->next;
         }

         cout<<"\n";

	}


	int Count()
	{
		struct node<T>*temp=Head;
         int iCnt=0;

        
         while(temp!=NULL)
         {
         	cout<<temp->data<<"\t";
         	temp=temp->next;
         	iCnt++;
         }

         return iCnt; 
        }

};


int main()
{
	SinglyLL<int>obj;

	obj.InsertFirst(51);
	obj.InsertFirst(21);
	obj.InsertFirst(61);
	obj.InsertLast(110);
	obj.InsertLast(123);

       obj.Display();

     SinglyLL<float>obj1;

     obj.InsertFirst(51.67);
	obj.InsertFirst(21.89);
	obj.InsertFirst(61.76);
	obj.InsertLast(110.78);
	obj.InsertLast(123.54);
     
      obj1.Display();
     return 0;

}