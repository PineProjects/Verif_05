#include <stdio.h> ///for input output functions like printf, scanf
#include <stdlib.h>
#include <string.h>  ///string operations
#include <conio.h>

/** Main function started */

int main(){
    FILE *fp, *ft, *fd, *fdt; /// file pointers
    char another, choice;
    int len, recfound=0;

    /** structure that represent a department*/
    struct dep{
	char depid[4]; // dep id
	char dname[20]; ///dep name
    };
    /** structure that represent a employee */
    struct emp{
	char empid[7]; // employee id
	char did[4]; // dep id
	char fname[40]; ///first name of employee
	char lname[20]; // last name of employee
	int age; /// age of employee
	float bs; /// basic salary of employee
    };

    struct emp e; /// structure variable creation

    struct dep d;

    char empId[7]; /// string to store name of the employee

    char depId[7]; /// string to store name of the department

    long int recsize; /// size of each record of employee

    long int depsize;

    /** open the file in binary read and write mode
    * if the file EMP.DAT already exists then it open that file in read write mode
    * if the file doesn't exit it simply create a new copy
    */
    fd = fopen("DEP.DAT","rb+");
    if(fd == NULL){
	fd = fopen("DEP.DAT","wb+");
	if(fd == NULL){
	    printf("Connot open file");
	    exit(1);
	}
    }

    fp = fopen("EMP.DAT","rb+");
    if(fp == NULL){
	fp = fopen("EMP.DAT","wb+");
	if(fp == NULL){
	    printf("Connot open file");
	    exit(1);
	}
    }

    /// sizeo of each record i.e. size of structure variable e
    recsize = sizeof(e);
    depsize = sizeof(d);
    /// infinite loop continues untile the break statement encounter
    while(1){
	mmenu:
	system("cls"); ///clear the console window
	printf("**************** Employee Management System *************\n");
	printf("*                                                       *\n");
	printf("*1. Department                                         *\n");
	printf("*                                                       *\n");
	printf("* 2. Employee                                           *\n");
	printf("*                                                       *\n");
	printf("* 3. Exit                                               *\n");
	printf("*                                                       *\n");
	printf("*********************************************************\n\n");
	printf("Your Choice: "); /// enter the choice 1, 2, 3
	fflush(stdin); /// flush the input buffer
	choice  = getche(); /// get the input from keyboard
	switch(choice){
	    case '1':  /// if user press 1
		system("cls");

		/// infinite loop continues untile the break statement encounter
		while(1){
		system("cls"); ///clear the console window
		printf("************************ Department *********************\n");
		printf("*                                                       *\n");
		printf("* 1. Add Record                                         *\n"); /// option for add record
		printf("*                                                       *\n");
		printf("* 2. List Records                                       *\n"); /// option for showing existing record
		printf("*                                                       *\n");
		printf("* 3. Modify Records                                     *\n"); /// option for editing record
		printf("*                                                       *\n");
		printf("* 4. Delete Records                                     *\n"); /// option for deleting record
		printf("*                                                       *\n");
		printf("* 5. Main Menu                                          *\n"); /// exit from the program
		printf("*                                                       *\n");
		printf("*********************************************************\n\n");
		printf("Your Choice: "); /// enter the choice 1, 2, 3, 4, 5
		fflush(stdin); /// flush the input buffer
		choice  = getche(); /// get the input from keyboard
		switch(choice){
			case '1':  /// if user press 1
			system("cls");
			fseek(fd,0,SEEK_END); /// search the file and move cursor to end of the file
					/// here 0 indicates moving 0 distance from the end of the file

			another = 'y';
			while(another == 'y'){ /// if user want to add another record
			did:
			printf("\nEnter 3 digits Department ID: ");
			scanf("%s",d.depid);
			if(strlen(d.depid)>3)
			goto did;
			printf("\nEnter Department name: ");
			scanf("%s",d.dname);
			fwrite(&d,depsize,1,fd); /// write the record in the file

			printf("\n\nAdd another record(y/n) ");
			fflush(stdin);
			another = getche();
			}
			break;

			case '2':
			system("cls");
			rewind(fd); ///this moves file cursor to start of the file
			printf("------------------------------------\n");
			printf(" Id     | Department Name\n");
			printf("------------------------------------\n");
			while(fread(&d,depsize,1,fd)==1){ /// read the file and fetch the record one record per fetch
				printf("\n");
				printf("%s\t| %-10s|",d.depid,d.dname); /// print the name, age and basic salary
			}
			getch();
			break;

			case '3':  /// if user press 3 then do editing existing record
			system("cls");
			rewind(fd); ///this moves file cursor to start of the file
			printf("------------------------------------\n");
			printf(" Id     | Department Name\n");
			printf("------------------------------------\n");
			while(fread(&d,depsize,1,fd)==1){ /// read the file and fetch the record one record per fetch
				printf("\n");
				printf("%s\t| %-10s|",d.depid,d.dname); /// print the name, age and basic salary
			}

			another = 'y';
			while(another == 'y'){
			printf("\n\nEnter the department id to modify: ");
			scanf("%s", depId);
			rewind(fd);
			while(fread(&d,depsize,1,fd)==1){ /// fetch all record from file
			if(strcmp(d.depid,depId) == 0){ ///if entered name matches with that in file
			    printf("\n\nEnter new department name: ");
			    scanf("%s",d.dname);
			    fseek(fd,-depsize,SEEK_CUR); /// move the cursor 1 step back from current position
			    fwrite(&d,depsize,1,fd); /// override the record
			    break;
			}
			}
			printf("\nModify another record(y/n)");
			fflush(stdin);
			another = getche();
			}
			break;

			case '4':
			system("cls");
			rewind(fd); ///this moves file cursor to start of the file
			printf("------------------------------------\n");
			printf(" Id     | Department Name\n");
			printf("------------------------------------\n");
			while(fread(&d,depsize,1,fd)==1){ /// read the file and fetch the record one record per fetch
				printf("\n");
				printf("%s\t| %-10s|",d.depid,d.dname); /// print the name, age and basic salary
			}
			another = 'y';
			while(another == 'y'){
			printf("\n\nEnter id of department to delete: ");
			scanf("%s",depId);
			fdt = fopen("Dtemp.DAT","wb");  /// create a intermediate file for temporary storage
			rewind(fd); /// move record to starting of file
			while(fread(&d,depsize,1,fd) == 1){ /// read all records from file
			if(strcmp(d.depid,depId) != 0){ /// if the entered record match
			    fwrite(&d,depsize,1,fdt); /// move all records except the one that is to be deleted to temp file
			}
			}
			fclose(fd);
			fclose(fdt);
			remove("DEP.DAT"); /// remove the orginal file
			rename("Dtemp.DAT","DEP.DAT"); /// rename the temp file to original file name
			fd = fopen("DEP.DAT", "rb+");
			printf("Delete another record(y/n)");
			fflush(stdin);
			another = getche();
			}
			break;

			case '5':
			//fclose(fd);  /// close the file
			goto mmenu; /// go to Main menu
		}
	    }
	    //break;

	case '2':
	    /// infinite loop continues untile the break statement encounter
	while(1){
	system("cls"); ///clear the console window
	printf("************************* Employee ***********************\n");
	printf("*                                                       *\n");
	printf("* 1. Add Record                                         *\n"); /// option for add record
	printf("*                                                       *\n");
	printf("* 2. List Records                                       *\n"); /// option for showing existing record
	printf("*                                                       *\n");
	printf("* 3. Modify Records                                     *\n"); /// option for editing record
	printf("*                                                       *\n");
	printf("* 4. Delete Records                                     *\n"); /// option for deleting record
	printf("*                                                       *\n");
	printf("* 5. Main Menu                                          *\n"); /// exit from the program
	printf("*                                                       *\n");
	printf("*********************************************************\n\n");
	printf("Your Choice: "); /// enter the choice 1, 2, 3, 4, 5
	fflush(stdin); /// flush the input buffer
	choice  = getche(); /// get the input from keyboard
	switch(choice){
	    case '1':  /// if user press 1
		system("cls");
		fseek(fp,0,SEEK_END); /// search the file and move cursor to end of the file
					/// here 0 indicates moving 0 distance from the end of the file

		another = 'y';
		while(another == 'y'){ /// if user want to add another record
		    eid:
		    printf("\nEnter 6 digits Employee ID: ");
		    scanf("%s",e.empid);
		    if(strlen(e.empid)<6)
		    goto eid;
		    fdid:
		    printf("\n\nAssign department id to employee: \n");
		    rewind(fd); ///this moves file cursor to start of the file
			printf("------------------------------------\n");
			printf(" Id     | Department Name\n");
			printf("------------------------------------\n");
			while(fread(&d,depsize,1,fd)==1){ /// read the file and fetch the record one record per fetch
				printf("\n");
				printf("%s\t| %-10s|",d.depid,d.dname); /// print depid and name
			}
		    printf("\n\n");
		    scanf("%s",e.did);
		    rewind(fd);
		    while(fread(&d,depsize,1,fd)==1){ /// fetch all record from file
			if(strcmp(e.did,d.depid) == 0){ ///if entered name matches with that in file
			    recfound = 1;
			    break;
			}
		    }
		    if(recfound == 0)
		    {
			printf("\nInvalid department. Please refer to department records\n");
			goto fdid;
		    }

		    printf("\nEnter First name: ");
		    scanf("%s",e.fname);
		    printf("\nEnter Last name: ");
		    scanf("%s",e.lname);
		    printf("\nEnter age: ");
		    scanf("%d", &e.age);
		    printf("\nEnter basic salary: ");
		    scanf("%f", &e.bs);

		    fwrite(&e,recsize,1,fp); /// write the record in the file

		    printf("\n\nAdd another record(y/n) ");
		    fflush(stdin);
		    another = getche();
		}
		break;
	    case '2':
		system("cls");
		rewind(fp); ///this moves file cursor to start of the file
		    printf("----------------------------------------------------------------------\n");
		    printf(" Id     | DepId | First Name     | Last Name    | Age           |Basic\n");
		    printf("----------------------------------------------------------------------\n");
		while(fread(&e,recsize,1,fp)==1){ /// read the file and fetch the record one record per fetch
		    printf("\n");
		    printf(" %s\t| %s\t| %-15s| %s\t\t| %d\t\t| %.2f",e.empid,e.did,e.fname,e.lname,e.age,e.bs); /// print the name, age and basic salary
		}
		getch();
		break;

	    case '3':  /// if user press 3 then do editing existing record
		system("cls");
		rewind(fp); ///this moves file cursor to start of the file
		    printf("----------------------------------------------------------------------\n");
		    printf(" Id     | DepId | First Name     | Last Name    | Age           |Basic\n");
		    printf("----------------------------------------------------------------------\n");
		while(fread(&e,recsize,1,fp)==1){ /// read the file and fetch the record one record per fetch
		    printf("\n");
		    printf(" %s\t| %s\t| %-15s| %s\t\t| %d\t\t| %.2f",e.empid,e.did,e.fname,e.lname,e.age,e.bs); /// print the name, age and basic salary
		}

		another = 'y';
		while(another == 'y'){
		    printf("\n\nEnter the employee id to modify: ");
		    scanf("%s", empId);
		    rewind(fp);
		    while(fread(&e,recsize,1,fp)==1){ /// fetch all record from file
			if(strcmp(e.empid,empId) == 0){ ///if entered name matches with that in file
			    fndid:
			    printf("\n\nEnter new department: ");
			    scanf("%s",e.did);

			    rewind(fd);
			    while(fread(&d,depsize,1,fd)==1){ /// fetch all record from file
				if(strcmp(e.did,d.depid) == 0){ ///if entered name matches with that in file
				recfound = 1;
				break;
				}
			    }
			if(recfound == 0)
			{
				printf("\nInvalid department. Please refer to department records\n");
				rewind(fd); ///this moves file cursor to start of the file
				printf("------------------------------------\n");
				printf(" Id     | Department Name\n");
				printf("------------------------------------\n");
				while(fread(&d,depsize,1,fd)==1){ /// read the file and fetch the record one record per fetch
					printf("\n");
					printf("%s\t| %-10s|",d.depid,d.dname); /// print depid and name
				}
				printf("\n\n");
				goto fndid;
			}

			    printf("\n\nEnter new first name: ");
			    scanf("%s",e.fname);
			    printf("\nEnter new last name: ");
			    scanf("%s",e.lname);
			    printf("\nEnter new age: ");
			    scanf("%d",&e.age);
			    printf("\nEnter new basic salary: ");
			    scanf("%f",&e.bs);
			    fseek(fp,-recsize,SEEK_CUR); /// move the cursor 1 step back from current position
			    fwrite(&e,recsize,1,fp); /// override the record
			    break;
			}
		    }
		    printf("\nModify another record(y/n)");
		    fflush(stdin);
		    another = getche();
		}
		break;
	    case '4':
		system("cls");
		rewind(fp); ///this moves file cursor to start of the file
		    printf("----------------------------------------------------------------------\n");
		    printf(" Id     | DepId | First Name     | Last Name    | Age           |Basic\n");
		    printf("----------------------------------------------------------------------\n");
		while(fread(&e,recsize,1,fp)==1){ /// read the file and fetch the record one record per fetch
		    printf("\n");
		    printf(" %s\t| %s\t| %-15s| %s\t\t| %d\t\t| %.2f",e.empid,e.did,e.fname,e.lname,e.age,e.bs); /// print the name, age and basic salary
		}
		another = 'y';
		while(another == 'y'){
		    printf("\n\nEnter id of employee to delete: ");
		    scanf("%s",empId);
		    ft = fopen("Temp.DAT","wb");  /// create a intermediate file for temporary storage
		    rewind(fp); /// move record to starting of file
		    while(fread(&e,recsize,1,fp) == 1){ /// read all records from file
			if(strcmp(e.empid,empId) != 0){ /// if the entered record match
			    fwrite(&e,recsize,1,ft); /// move all records except the one that is to be deleted to temp file
			}
		    }
		    fclose(fp);
		    fclose(ft);
		    remove("EMP.DAT"); /// remove the orginal file
		    rename("Temp.DAT","EMP.DAT"); /// rename the temp file to original file name
		    fp = fopen("EMP.DAT", "rb+");
		    printf("Delete another record(y/n)");
		    fflush(stdin);
		    another = getche();
		}
		break;
	    case '5':
		//fclose(fp);  /// close the file
		goto mmenu; /// go to main menu
	}
    }

     case '3':
		fclose(fp);  /// close the file
		fclose(fd);
		exit(0); /// exit from the program
	}
    }
   
}
