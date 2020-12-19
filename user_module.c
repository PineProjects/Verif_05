#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>


struct userDetails
{
	char snonumber[10];
	char name[50];
	char service[50];
	char phonenumber[50];

}u;


struct RoomDetails_1
{
	char room_number[10];
	char roomtype[20];
	char type[30];
	char av[30];
	int price;

}r1;



void user()
	{

	    system ("cls");
	    int check=0;
	    char choice;
		system("cls");

        while(1)
		{
        system ("cls");
		printf("\n");
		printf("   ******************************  | MENU|  ***************************** \n");


		printf("\n");
		printf(" \n Enter 1 : Staff and Admin moblie no.");
		printf(" \n Enter 2 : Availability of Rooms");
		printf(" \n Enter 3 : Exit");
		printf("\n\n\n");
		printf("Please enter your choice for menu: ");



		choice=getche();
		choice=toupper(choice);
		switch(choice)           // SWITCH STATEMENT
		{
			case '1':
				staff();break;
			case '2':
				room_status_check();break;
			case '3':
				system("cls");
			//	Sleep(2000);
			     check=1;
				break;
			case '9':
                add_staff();break;
			default:
				system("cls");
				printf("Incorrect Input");
				printf("\n Press any key to continue");
				getch();
		  }

		  if (check==1)
            break;

		}
	}


void staff()
	{
    FILE *f;
	int i;
	if((f=fopen("staff.txt","r"))==NULL)
		exit(0);
	system("cls");
	for(i=0;i<118;i++)
		printf("-");
	printf("\nSNO   ");
	printf("\tNAME\t ");
	printf("\tSERVICE\t\t");
	printf("PHONE NO\t\n");

	for(i=0;i<118;i++)
		printf("-");
	while(fread(&u,sizeof(u),1,f)==1)
	{

		printf("\n\n%s \t%s \t\t%s   \t%s\n",u.snonumber,u.name ,u.service , u.phonenumber);
	}
	printf("\n");
	for(i=0;i<118;i++)
		printf("-");

	fclose(f);
	getch();

	}

void room_status_check()
{
	FILE *f;
	int i;
	if((f=fopen("room.txt","r"))==NULL)
		exit(0);
	system("cls");
	for(i=0;i<118;i++)
		printf("-");
	printf("\nROOM    ");
	printf("AC/NON AC\t ");
	printf("TYPE\t\t");
	printf("STATUS\t\n");

	for(i=0;i<118;i++)
		printf("-");
	while(fread(&r1,sizeof(r1),1,f)==1)
	{

		printf("\n\n%s \t%s \t\t%s   \t%s\n",r1.room_number, r1.roomtype , r1.type , r1.av);
	}
	printf("\n");
	for(i=0;i<118;i++)
		printf("-");

	fclose(f);
	getch();
}

void add_staff()
{
	FILE *f;
	char test;
	f=fopen("staff.txt","a");

	while(1)
	{
		system("cls");
		printf("\n Enter sno number:\n");
		scanf("\n%s",u.snonumber);
		fflush(stdin);
		printf("Enter name:\n");
		scanf("%s",u.name);
		printf("Enter service :\n");
		scanf("%s",u.service);
		printf("Enter phone :\n");
		scanf("%s",u.phonenumber);
        fwrite(&u,sizeof(u),1,f);
		fflush(stdin);
	    printf("\n Press esc key to exit,  any other key to add another customer detail:");
		test=getche();
		if(test==27)
			break;

	}
	fclose(f);
}

















