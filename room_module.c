#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>


void add_room();
void list_room();
void edit_room();
void delete_room();
void search_room();


struct RoomDetails   //STRUCTURE DECLARATION
{
	char room_number[10];
	char roomtype[20];
	char type[30];
	char av[30];
	int price;

}r;

void room()
{
	char ch;
	int check=0;
	while (1)
	{
		system("cls");

		printf("\n");
		printf("   ******************************  |MAIN MENU|  ***************************** \n");


		printf("\n");
		printf(" \n Enter 1 : Add room");
		printf(" \n Enter 2 : Delete Room");
		printf(" \n Enter 3 : Modify Room");
		printf(" \n Enter 4 : Search Room");
		printf(" \n Enter 5 : Disply list");
		printf(" \n Enter 6 : Exit");
		printf("\n\n\n");
		printf("Please enter your choice for menu: ");



		ch=getche();

		switch(ch)           // SWITCH STATEMENT
		{
			case '1':
				add_room();break;
			case '2':
				delete_room();break;
			case '3':
				edit_room();break;
			case '4':
				search_room();break;
			case '5':
				list_room();break;
			case '6':
				system("cls");
			//	Sleep(2000);
                check=1;
				break;
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

void add_room()
{
	FILE *f;
	char test;
	f=fopen("room.txt","a");

	while(1)
	{
		system("cls");
		printf("\n Enter Room Details:");
		printf("\n**************************");
		printf("\n Enter Room number:\n");
		scanf("\n%s",r.room_number);
		fflush(stdin);
		printf("Enter Room-type(AC/NON-AC):\n");
		scanf("%s",r.roomtype);
		printf("Enter Type of room :\n");
		scanf("%s",r.type);
		printf("Enter status of room :\n");
		scanf("%s",r.av);
		printf("Enter price of room :\n");
		scanf("%d",&r.price);
		fwrite(&r,sizeof(r),1,f);
		fflush(stdin);
	    printf("\n Press esc key to exit,  any other key to add another customer detail:");
		test=getche();
		if(test==27)
			break;

	}
	fclose(f);
}

void list_room()
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
	printf("STATUS\t");
	printf("\tPRICE\t\n");

	for(i=0;i<118;i++)
		printf("-");
	while(fread(&r,sizeof(r),1,f)==1)
	{

		printf("\n\n%s \t%s \t\t%s   \t%s    \t%d\n",r.room_number, r.roomtype , r.type , r.av , r.price);
	}
	printf("\n");
	for(i=0;i<118;i++)
		printf("-");

	fclose(f);
	getch();
}

void delete_room()
{
	FILE *f,*t;
	int i=1;
	char number[20];
	if((t=fopen("temp_room.txt","w"))==NULL)
	exit(0);
	if((f=fopen("room.txt","r"))==NULL)
	exit(0);
	system("cls");
	printf("Enter the Room Number of the hotel to be deleted from the database: \n");
	fflush(stdin);
	scanf("%s",number);
	while(fread(&r,sizeof(r),1,f)==1)
	{
		if(strcmp(r.room_number,number)==0)
		{       i=0;
			continue;
		}
		else
			fwrite(&r,sizeof(r),1,t);
	}
	if(i==1)
	{
		printf("\n\nthis  Room number is not found!!");

		getch();
		fclose(f);
		fclose(t);
			}
	fclose(f);
	fclose(t);
	remove("room.txt");
	rename("temp_room.txt","rooms.txt");
	printf("\n\nThe room is successfully removed....");
	fclose(f);
	fclose(t);
	getch();
}
void search_room()
{
system("cls");
	FILE *f;
	char number[20];
	int flag=1;
	f=fopen("room.txt","r+");
	if(f==0)
		exit(0);
	fflush(stdin);
	printf("Enter Room number to search for details: \n");
	scanf("%s", number);
	while(fread(&r,sizeof(r),1,f)==1)
	{
		if(strcmp(r.room_number,number)==0){
			flag=0;
			printf("\n\tRecord Found\n ");
			printf("\nRoom Number:\t%s",r.room_number);
			printf("\nRoom Type:\t%s",r.roomtype);
			flag=0;
			break;
		}
	}
	if(flag==1){
		printf("\n\tRequested Room could not be found!");
	}
	getch();
	fclose(f);
}

void edit_room()
{
	FILE *f;
	int k=1;
	char number[20];
	long int size=sizeof(r);
	if((f=fopen("room.txt","r+"))==NULL)
		exit(0);
	system("cls");
	printf("Enter Room number to edit:\n\n");
	scanf("%[^\n]",number);
	fflush(stdin);
	while(fread(&r,sizeof(r),1,f)==1)
	{
		if(strcmp(r.room_number,number)==0)
		{
			k=0;
			printf("\nEnter Room Number     :");
			gets(r.room_number);
			printf("\nEnter Room - type   :");
			fflush(stdin);
			scanf("%s",&r.roomtype);
			fseek(f,size,SEEK_CUR);  //to go to desired position in file
			fwrite(&r,sizeof(r),1,f);
			break;
		}
	}
	if(k==1){
		printf("\n\nTHE RECORD DOESN'T EXIST!!!!");
		fclose(f);
		getch();
	}else{
	fclose(f);
	printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
	getch();
}
}
