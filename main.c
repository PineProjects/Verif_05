#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>
#include "room_module.c"
#include "user_module.c"

#define SIZE 32

short int checkValid(char*);
void checkStrength(char*);
void resetspassword();
void login();


short int alphabetCount=0, digitCount=0;
short int length=0;
short int symbolCount=0;
int count_reset=3;

void add();
void list();
void edit();
void delete1();
void search();
void customer();
void bill();
void login()
{

char pwd[SIZE],pd[SIZE],ch;
char option;
int count=3;


FILE *fp;
fp=fopen("abc.txt","r");
fscanf(fp,"%s",pwd);


ENTER_PASSWARD:
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n \t\t\t\t\tPLEASE ENTER THE LOGIN PASSWORD: ");
    int p=0;
    do{
        pd[p]=getch();
        if(pd[p]!='\r')
		    {
            printf("*");
            }
        p++;
      }while(pd[p-1]!='\r');
       pd[p-1]='\0';


// Compare Enter passward with inbuild passward
if(strcmp(pwd,pd)==0)
{
    printf("\n\n \t\t\t\t\tWELCOME........LOGIN IN SUCESSFULLY ");
    printf("\n\n \t\t\t\t\tPLEASE WAIT . . . ");

    Sleep(3000);
    system("cls");


}
else{
	count=count-1;
	if (count!=0)
	{
		printf("\n\n \t\t\t\t\tINCORRECT LOGIN Attemp left : %d",count);
		printf("\n\n \t\t\t\t\tPLEASE WAIT . . . ");
		Sleep(3000);
		system("cls");
	    goto ENTER_PASSWARD;

	}
    else
	   printf("\n\n \t\t\t\t\tINCORRECT LOGIN");
	   exit(0);

    }
fclose(fp);

}


void resetpassword()
{
char pw[SIZE],c,rpw[SIZE];
short int count,error,i=0;
int option;

Enter:
printf("\n****************************** ");
printf("\nENETR NEW PASSWORD: ");
int p=0;
    do{
        pw[p]=getch();
        if(pw[p]!='\r')
		   {
            printf("*");
           }
        p++;
      }while(pw[p-1]!='\r');
     pw[p-1]='\0';

length=strlen(pw);
FILE *fp;
 if( error=checkValid(pw) )
 {
   printf("\n\nIts a valid password");
   checkStrength(pw);

printf("\nRECONFIRM PASSWORD: ");
   while( (c=getch()) !='\r')
      {
        rpw[i]=c;
        putchar('*');
        i++;
      }
 rpw[i]='\0';
 length=strlen(rpw);

//Compair both the Entered and RECONFIRM Passward
   if(strcmp(pw,rpw)==0)
   {
       fp=fopen("abc.txt","w");
       fprintf(fp, "%s", rpw);
       fclose(fp);
       printf("\n\n*******************************");
       printf("\nPASSWORD RESET SUCESSFULLY");
       printf("\n*******************************");
       system("cls");

   }
   else{
    printf("\nERROR: Password does not match");
	count_reset=count_reset-1;
	if (count_reset!=0)
	{
		printf("\n\n INCORRECT LOGIN Attemp left : %d",count_reset);

	    resetpassword();
	}
    else
	   printf("\n\n \t\t\t\t\tMore then 3 attemps Cannot Rest passward");

    }

 }
 else
    goto Enter;
}

short int checkValid(char *x)
{
    alphabetCount=0;
    digitCount=0;

if(length<6)
{
printf("\n Password should be atleast 6 characters wide");
return 0;
 }

  while((*x)!='\0')
    {
     if( isalpha(*x))
      alphabetCount++;
     else if( isdigit(*x) )
      digitCount++;
     else if( isascii(*x) )
      symbolCount++;

     x++;
    }

 if(alphabetCount==length) 
 {                         
  printf("\n ERROR: Password should contain both alphabets and digits");
  return 0;
 }
 else if(digitCount==length) 
 {                           
  printf("\n ERROR: Password should contain both alphabets and digits");
  return 0;
 }
 else
 return 1;
}

void checkStrength(char *p)
{
  short int strengthVar=0;

  if( length>8 )
  strengthVar++;
  if( symbolCount >= 1 )
  strengthVar++;
  if( digitCount >= alphabetCount )
  strengthVar++;
  if( length>12 )
  strengthVar++;

  printf("\nPASSWORD STRENGTH : ");
  switch(strengthVar)
  {
  case 0 :printf("low\n");
   break;
  case 1 :printf("medium\n");
   break;
  case 2 :printf("fair\n");
   break;
  case 3 :printf("high\n");
   break;
  case 4 :printf("very high\n");
   break;
  }

}

  void admin()
{   int flag=0;
    system("cls");
    login();
	while(1)
	{
		printf("   ******************************  |MAIN MENU|  ***************************** \n");
	    printf("\n 1. Customer details");
        printf("\n 2.  Room details");
		printf("\n 3.  Reset password");
		printf("\n 4.  Exit");
		printf("\n Please enter your choice : ");

		char cho;
		cho=getche();

		switch(cho)           // SWITCH STATEMENT
		{
			case '1':
				customer();break;
			case '2':
				room();break;
			case '3':
				resetpassword();break;

			case '4':
				system("cls");
				flag=1;
				break;
			default:
				system("cls");
				printf("Incorrect Input");
				printf("\n Press any key to continue");
				getch();
		}
		if(flag==1)
            break;
	}
}



struct CustomerDetails   //STRUCTURE DECLARATION
{
	char roomnumber[10];
	char name[20];
	char address[25];
	char phonenumber[15];
	char nationality[15];
	char email[20];
	int period;
	char arrivaldate[10];
}s;

void main()
{

	int i=0;
	char option;
	char customername;

	system("cls");   // FOR CLEARING SCREEN

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n \t\t\t\t\tWELCOME TO HOTEL Taj ");
	Sleep(3000);
while(1)
{
    User_type:
    system("cls");
    printf("\n");
    printf("   ******************************  |User type|  ***************************** \n");
        printf("\n");
		printf(" \n Enter 1 : Admin");
		printf(" \n Enter 2 : user");
		printf("\n\n\n");
		printf("Please enter your choice for menu: ");

   option = getche();


   switch(option)
		{
			case '1':
				admin();break;
			case '2':
				user();break;

			default:
				system("cls");
				printf("Incorrect Input");
				printf("\n Press any key to continue");
				getch();
				goto User_type;
		}
    }


}




	 void customer()      
	{
	    system ("cls");
	    int check=0;
	    char choice;
		system("cls");

        while(1)
		{
        system ("cls");
		printf("\n");
		printf("   ******************************  |MAIN MENU|  ***************************** \n");


		printf("\n");
		printf(" \n Enter 1 : Book a room");
		printf(" \n Enter 2 : View Customer Record");
		printf(" \n Enter 3 : Delete Customer Record");
		printf(" \n Enter 4 : Search Customer Record");
		printf(" \n Enter 5 : Bill Generate");
		printf(" \n Enter 6 : Exit");
		printf("\n\n\n");
		printf("Please enter your choice for menu: ");



		choice=getche();
		choice=toupper(choice);
		switch(choice)           // SWITCH STATEMENT
		{
			case '1':
				add();break;
			case '2':
				list();break;
			case '3':
				delete1();break;
			case '4':
				search();break;
			case '5':
				bill();break;
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


void add()
{
	FILE *f,*f_room;
	char test;
	f=fopen("add.txt","a+");
	int flag=0;
	if(f==0)
	{   f=fopen("add.txt","w+");
		system("cls");
		printf("Please hold on while we set our database in your computer!!");
		printf("\n Process completed press any key to continue!! ");
		getch();
	}
	char av_check;

	while(1)
	{
        flag=0;
	    f_room=fopen("room.txt","r");
		system("cls");
		printf("\n Enter Customer Details:");
		printf("\n**************************");
		printf("\n Enter Room number:\n");
		scanf("\n%s",s.roomnumber);

		while(fread(&r,sizeof(r),1,f_room)==1)
	  {
		if(strcmp(r.room_number,s.roomnumber)==0 && strcmp(r.av,"av")==0 )
		{   flag=1;
			break;
	    }

	  }

		if (flag==1)
		{
		fflush(stdin);
		printf("Enter Name:\n");
		scanf("%s",s.name);
		printf("Enter Address:\n");
		scanf("%s",s.address);
		printf("Enter Phone Number:\n");
		scanf("%s",s.phonenumber);
		printf("Enter Nationality:\n");
		scanf("%s",s.nationality);
		printf("Enter Email:\n");
		scanf(" %s",s.email);
		printf("Enter Period(\'x\'days):\n");
		scanf("%d",&s.period);
		printf("Enter Arrival date(dd\\mm\\yyyy):\n");
		scanf("%s",&s.arrivaldate);
		fwrite(&s,sizeof(s),1,f);
		fflush(stdin);
		printf("\n\n1 Room is successfully booked!!");
		}
		else
		{
			printf("Room not available\n ");
		}

		fclose(f_room);
		printf("\n Press esc key to exit,  any other key to add another customer detail:");
		test=getche();
		if(test==27)
			break;
	}
	fclose(f);
}

void list()
{
	FILE *f;
	int i;
	if((f=fopen("add.txt","r"))==NULL)
		exit(0);
	system("cls");



	while(fread(&s,sizeof(s),1,f)==1)
	{
	    for(i=0;i<118;i++)
		printf("*");

    printf("\nROOM:%s",s.roomnumber);
	printf("\nNAME:%s",s.name);
	printf("\nADDRESS:%s",s.address);
	printf("\nPHONENUMBER:%s",s.phonenumber);
	printf("\nNATIONALITY:%s",s.nationality);
	printf("\nEMAIL:%s",s.email);
	printf("\nPERIOD:%d",s.period);
	printf("\nARRIVALDATE:%s\n\n",s.arrivaldate);

	}
	printf("\n");
	for(i=0;i<118;i++)
		printf("*");
	fclose(f);
	getch();
}

void delete1()
{
	FILE *f,*t;
	int i=1;
	char roomnumber[20];
	if((t=fopen("temp.txt","w"))==NULL)
	exit(0);
	if((f=fopen("add.txt","r"))==NULL)
	exit(0);
	system("cls");
	printf("Enter the Room Number of the hotel to be deleted from the database: \n");
	fflush(stdin);
	scanf("%s",roomnumber);
	//fflush(stdin);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0)
		{       i=0;
			continue;
		}
		else
			fwrite(&s,sizeof(s),1,t);
	}
	if(i==1)
	{
		printf("\n\n Records of Customer in this  Room number is not found!!");
		
		getch();
		fclose(f);
		fclose(t);

	}
	fclose(f);
	fclose(t);
	remove("add.txt");
	rename("temp.txt","add.txt");
	printf("\n\nThe Customer is successfully removed....");
	fclose(f);
	fclose(t);
	getch();
}

void search()
{
system("cls");
	FILE *f;
	char roomnumber[20];
	int flag=1;
	f=fopen("add.txt","r+");
	if(f==0)
		exit(0);
	fflush(stdin);
	printf("Enter Room number of the customer to search its details: \n");
	scanf("%s", roomnumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0){
			flag=0;
			printf("\n\tRecord Found\n ");
			printf("\nRoom Number:\t%s",s.roomnumber);
			printf("\nName:\t%s",s.name);
			printf("\nAddress:\t%s",s.address);
			printf("\nPhone number:\t%s",s.phonenumber);
			printf("\nNationality:\t%s",s.nationality);
			printf("\nEmail:\t%s",s.email);
			printf("\nPeriod:\t%d",s.period);
			printf("\nArrival date:\t%s",s.arrivaldate);
			flag=0;
			break;
		}
	}
	if(flag==1){
		printf("\n\tRequested Customer could not be found!");
	}
	getch();
	fclose(f);
}
void bill()
{
	FILE *f,*f1;
	int k=1,j=0;
	char number[20];
	long int size=sizeof(s);
	if((f=fopen("add.txt","r+"))==NULL)
		exit(0);
	if((f1=fopen("room.txt","r+"))==NULL)
		exit(0);
	system("cls");
	printf("Enter Room number of the customer to edit:\n\n");
	scanf("%[^\n]",number);
	fflush(stdin);
	while(fread(&s,sizeof(s),1,f)==1)
	{
	   
		if(strcmp(s.roomnumber,number)==0)
		{   k=0;
	        printf("\n\n\n*******************************************************")	;
		    printf("\nRoomnumber  : %s",s.roomnumber);
		    printf("\nName        : %s",s.name);
		    printf("\nAddress     : %s",s.address);
		    printf("\nPhoneno     : %s",s.phonenumber);
		    printf("\nNationality : %s",s.nationality);
		    printf("\nEmail       : %s",s.email);
		    printf("\nPeriod      : %d",s.period);
		    printf("\nArrival     : %s",s.arrivaldate);
			while(fread(&r,sizeof(r),1,f1)==1)
	       {
	           if(strcmp(r.room_number,number)==0)
               {
                printf("\nCost per day: %d",r.price);
		        printf("\nTotal Amount: %d",r.price*s.period);
                printf("\n*******************************************************")	;
               }

		   }

        }

	}
	if(k==1)
    {
		printf("\n\nTHE RECORD DOESN'T EXIST!!!!");
		fclose(f);
		getch();
	}else
	{
	fclose(f);
	fclose(f1);
    getch();
    }
}



