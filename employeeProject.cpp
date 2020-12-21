

#include <stdio.h>
#include <stdlib.h>

typedef struct employee
{
    int EID;
    char Ename[30];
    char Eaddress[30];
    char EProject[30];
    char EGender;
    float ESalary;
    int EAge;
    struct employee *next;
} NODE, *PNODE, **PPNODE;

void InsertFirst(PPNODE Head)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    printf("Enter the employee ID\n");
    scanf("%d", &(newn->EID));

    printf("Enter the employee name\n");
    scanf(" %[^'\n']s", (newn->Ename));

    printf("Enter the employee Adress\n");
    scanf(" %[^'\n']s", (newn->Eaddress));

    printf("Enter the employee Project\n");
    scanf(" %[^'\n']s", (newn->EProject));

    printf("Enter the employee gender\n");
    scanf(" %c", &(newn->EGender));

    printf("Enter the employee salary\n");
    scanf(" %f", &(newn->ESalary));

    printf("Enter the employee Age\n");
    scanf(" %d", &(newn->EAge));

    if (*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = *Head;
        *Head = newn;
    }
}

void Display(PNODE Head)
{

    while (Head != NULL)
    {
        printf("Employee ID: %d\t Name: %s\t Adress: %s\t Project: %s\t gender: %c\t salary: %f\t Age: %d\n", Head->EID, Head->Ename, Head->Eaddress, Head->EProject, Head->EGender, Head->ESalary, Head->EAge);
        Head = Head->next;
    }
}

int main()
{
    PNODE First = NULL;

    InsertFirst(&First);

    printf("Employee Information\n");

    Display(First);

    return 0;
}