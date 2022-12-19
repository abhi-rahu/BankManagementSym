#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


void addAccount(void);
void accountcreated(void);
void displayAccount(void);
void deleteAccount(void);

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;

	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}

struct Account
{

    char name[20];
	int age;
	char phno[15];
	char adharnum[20];
	char fathname[20];
	char mothname[20];
	char address[50];
	char typeaccount[20];

    struct Account *next;
};

struct Account *head = NULL;


int main()
{
    
    int choice;
    system("cls");
    while (1)
    {
        gotoxy(20, 3);

	// Creating a Main
	// menu for the user
	printf("WELCOME TO BANK ACCOUNT SYSTEM\n\n");
	gotoxy(18, 5);

	printf("**********************************");
	gotoxy(25, 7);

	printf("DEVELOPER- GROUP 5 \n ");

	gotoxy(20, 10);
	printf("\n1.... CREATE A BANK ACCOUNT");

	gotoxy(20, 12);
    printf("\n2.... Display Account");
	gotoxy(20, 14);
    printf("\n3.... Delete Account");
    gotoxy(20, 15);
    printf("\n4.... Exit");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addAccount();
            break;
        case 2:
            displayAccount();
            printf("\n");
            break;
        case 3:
            deleteAccount();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice");
            break;
        }
    }
return 0;
}


void addAccount()
{
    system("cls");
    struct Account *newAccount = (struct Account *)malloc(sizeof(struct Account));
	printf("\n\n!!!!!CREATE ACCOUNT!!!!!");

    printf("\n\n NAME..");
    scanf("%s", newAccount->name);
    printf("\n\nEnter Age...");
    scanf("%d", &newAccount->age);  
    printf("\n\nFATHER's NAME..");
    scanf("%s", newAccount->fathname);
    printf("\n\nMOTHER's NAME..");
    scanf("%s", newAccount->mothname);
    printf("\n\nAADHAR NUMBER: ");
    scanf("%s", newAccount->adharnum);
    printf("\n\nADDRESS..");
    scanf("%s", newAccount->address);
    printf("\n\nPHONE NUMBER: ");
    scanf("%s", newAccount->phno);
    printf("\n\nACCOUNT TYPE...(Saving or current or business)...");
    scanf("%s", newAccount->typeaccount);
    

    newAccount->next = head;
    head = newAccount;
    accountcreated();
}

// Successful account creation
void accountcreated(void)
{
	system("cls");
	int i;
	char ch;
	printf(
		"PLEASE WAIT....\n\nYOUR DATA IS PROCESSING....");
	for (i = 0; i < 200000000; i++) {
		i++;
		i--;
	}

	gotoxy(30, 10);

	printf("ACCOUNT CREATED SUCCESSFULLY....");
	gotoxy(0, 20);
	printf("Press enter to continue");
   
	main();
}

void displayAccount()
{
    system("cls");
    char name[100];
    printf("\nEnter the Name: ");
    scanf("%s",name);
    system("cls");
    struct Account *temp = head;
    while(temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            gotoxy(30, 1);
            printf("WELCOME, %s",temp->name);
            gotoxy(28, 2);
            printf("..........................");
            gotoxy(55, 6);
            printf("==== YOUR ACCOUNT INFO ====");
            gotoxy(55, 8);
            printf("***************************");
            gotoxy(55, 10);
            printf("NAME..%s", temp->name);
            gotoxy(55, 12);
            printf("FATHER's NAME..%s", temp->fathname);
            gotoxy(55, 14);
            printf("MOTHER's NAME..%s",temp->mothname);
            gotoxy(55, 16);
            printf("ADHAR CARD NUMBER..%s",temp->adharnum);
            gotoxy(55, 18);
            printf("MOBILE NUMBER..%s",temp->phno);
            gotoxy(55, 20);
            printf("age... %d",temp->age);
            gotoxy(55, 22);
            printf("ADDRESS..%s", temp->address);
            gotoxy(55, 24);
            printf("ACCOUNT TYPE..%s",temp->typeaccount);
        }
        temp = temp->next;
    }
    

}

void deleteAccount()
{
    system("cls");
    char name[20];
    printf("\nEnter username of Account to be deleted: ");
    scanf("%s", name);
    struct Account *temp = head;
    struct Account *prev = NULL;
    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            if (prev == NULL)
            {
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            printf("\nAccount deleted successfully");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("\nAccount not found");
}