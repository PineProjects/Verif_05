#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct{
    char username[50];
    char password[10];
}add,check,edit;

void set()
{
    FILE *ptr;
    ptr = fopen("Pass.txt","a+");
    set_username:
    //system("cls");
    printf("Enter your unique username:  ");
    scanf("%s",check.username);
    while(fscanf(ptr,"%s %s",add.username,add.password)!=EOF)
    {
        if(strcmp(add.username,check.username)==0)
        {
            printf("Username already in use\n");
            fseek(ptr, 0, SEEK_SET);
            goto set_username;
        }

    }

    strcpy(add.username,check.username);
    printf("Enter your password : ");
    scanf("%s",add.password);
    fprintf(ptr,"%s %s\n",add.username,add.password);
    fclose(ptr);
    //main();
}

void edit_pass()
{
    int test = 0;
    FILE *old,*new_rec;
    old = fopen("Pass.txt","r");
    new_rec = fopen("New.txt","w");
    printf("\nEnter the username for which you want to change the password: ");
    scanf("%s",edit.username);
    while(fscanf(old,"%s %s",add.username,add.password)!=EOF)
    {
        if(strcmp(add.username,edit.username)==0)
        {
            test = 1;
            printf("\nEnter the new password: ");
            scanf("%s",edit.password);
            fprintf(new_rec,"%s %s\n",add.username,edit.password);
            printf("\nChanges saved");
        }
        else
            fprintf(new_rec,"%s %s\n",add.username,add.password);
    }
    fclose(old);
    fclose(new_rec);
    remove("Pass.txt");
    rename("New.txt","Pass.txt");
    if(test==0)
    {
        printf("\nRecord not found\n");
    }
}


int main(void)
{
    int choice;
    printf("\t\t\t\t\tThis is password manager\n");
    printf("1.Set Username and password\n2.Reset your password\n3.Exit");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        set();
        break;
    case 2:
        edit_pass();
        break;
    case 3:
        exit(1);
        break;
    }
    return 0;
}
