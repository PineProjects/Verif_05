#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

void display();
void user_display();
void admin_display();

int main()
{
    display();
    user_display();
    display();
    admin_display();
    return 0;
}

void display()
{
    system("cls");
    printf("\n\t\t\t------------------------");
    printf("\n\t\t\t|BANK MANAGEMENT SYSTEM|");
    printf("\n\t\t\t------------------------");
}


void user_display()
{
    int op;
    A:
        printf("\n\n\t\t USER OPTIONS");
        printf("\n\n\t1.View Account Details");
        printf("\n\n\t2.Edit Personal Details");
        printf("\n\n\t3.View transaction");
        printf("\n\nEnter Valid Option");
        scanf("%d",&op);

    switch(op)
    {
    case 1:
        //display();user_account();
        break;
    case 2:
        //display();update_user();
        break;
    case 3:
        //display();view_transaction();
        break;
    default:
        printf("\n\t\tInvalid Option!!");
        Sleep(350);
        display();
        goto A;
        break;
    }

}

void admin_display()
{
    int op;
    B:
        printf("\n\n\t\t ADMIN OPTIONS");
        printf("\n\n\t1.View Details of All Customers");
        printf("\n\n\t2.View Details of Particular Customer");
        printf("\n\n\t3.Add Account");
        printf("\n\n\t4.Delete Account");
        printf("\n\n\t5.Reset Password");
        printf("\n\nEnter Valid Option");
        scanf("%d",&op);

    switch(op)
    {
    case 1:
        //display();user_account();
        break;
    case 2:
        //display();view_users();
        break;
    case 3:
        //display();add_account();
        break;
    case 4:
        //display();delete_account();
        break;
    case 5:
        //display();reset_password();
    default:
        printf("\n\t\tInvalid Option!!");
        Sleep(350);
        display();
        goto B;
        break;
    }
}
