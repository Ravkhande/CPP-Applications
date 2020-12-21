#include<stdio.h>
#include<stdlib.h>

struct Employee
{
    int Eid;
    char Ename[20];
    char Eaddress[30];
    char EProject[20];
    char EGender;
    float ESalary;
    int EAge;
    struct Employee *next;
};

int main()
{
    
    return 0;
}
