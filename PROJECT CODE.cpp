#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include<windows.h>
using namespace std;
   
   
   
  void start()
     {  
	     
		system("color 06");
		system("cls");
			cout<<"\n\t\t\t---------------------------------------";
			cout<<"\n\t\t\t  EMPLOYEE DATABASE MANAGMENT SYSTEM   ";
			cout<<"\n\t\t\t---------------------------------------";
		Sleep(500);
      		cout<<"\n\n\n\n\t\tMade By:-";
		Sleep(500);
      		cout<<"\tName:- Tejaswini Sonawane";
		Sleep(500);
      		cout<<"\n\t\t\t\tROLL NO:- 63";
		Sleep(500);
     		cout<<"\n\t\t\t\tBatch:- C";
     	Sleep(500);
     		cout<<"\n\t\t\t\tYear:- SE(IT)";
		Sleep(500);
     		cout<<"\n\n\t\tSubmitted To:-  Mr.Kiran Somvanshi\n\t\t\t\tMr.Pratik Kadam";
		Sleep(500);
     		cout<<"\t";
		Sleep(500);
            cout<<"\n\n\n\t\t\tPress any key to continue....!!";
    getch();
}
 void data()
   {
    
    string p1,p2;
    
    
    

    FILE *fp, *ft;
    char another;
    int flag,choice;

   //declaration of structure: structure may contain different data type
   
    struct employee                
    {
        char first_name[50], last_name[50];
        int Age;
        long Salary;
    };

    struct employee e;                            
    char xfirst_name[50], xlast_name[50];
    long int recsize;

    fp=fopen("users.txt","rb+");

    if (fp == NULL)
    {
        fp = fopen("users.txt","wb+");

        if (fp==NULL)
        {
            puts("Cannot open file");
            
        }
        getch();
    }
	


    recsize = sizeof(e);

    while(1)
    {
        system("cls");
        
        cout << "\t\t\t======== SONAWANE DEVELOPERS WELCOMES YOU ========";
        cout << "\n\n\t\t\t\t====== EMPLOYEE RECORDS ======";
        cout << "\n\n";
        cout << "\n \t\t\t\t 1. REGISTER AN EMPLOYEE";
        cout << "\n \t\t\t\t 2. LIST OF EMPLOYEE";
        cout << "\n \t\t\t\t 3. MODIFY DETAILS OF EMPLOYEE";
        cout << "\n \t\t\t\t 4. DELETE RECORDS OF EMPLOYEE";
        cout << "\n \t\t\t\t 5. Exit ";
        cout << "\n\n";
        cout << "\t\t\t\t Select Your Choice :- ";
        fflush(stdin);
		choice = getche();                                   
        switch(choice)
        {
        case '1' :
            fseek(fp,0,SEEK_END);
            another ='Y';
            while(another == 'Y' || another == 'y')
            {
                system("cls");
                cout << "\n\t      Enter the Firt Name:- ";
                cin >> e.first_name;
                cout << "\n\t      Enter the Last Name:- ";
                cin >> e.last_name;
                cout << "\n\t   Enter the Employee Age:- ";
                cin >> e.Age;
                cout << "\n\tEnter the Employee Salary:- ";
                cin >> e.Salary;
                fwrite(&e,recsize,1,fp);
                cout << "\n\tIf you want to add another another record then enter Y else enter N";
                fflush(stdin);
                another = getchar();
            }
            
            break;
        case '2' :
				      system("cls");
                      rewind(fp);                                            
                      cout << "=== View the Records in the Database ===";
                      cout << "\n";
                      while (fread(&e,recsize,1,fp) == 1)
                        {
                           cout << "\nDetails of Employees";
                           cout <<"\n\t\tFirst Name:- " << e.first_name << setw(10);  //<< e.last_name;
                           cout <<"\n\t\t Last Name:- " << e.last_name << setw(10);
                           cout <<"\n\t\t       Age:- " <<e.Age <<  setw(8);
                           cout <<"\n\t\t    Salary:- " << e.Salary <<  setw(8);
                        }
                      cout << "\n\n";
                      system("pause");
                      break;

        case '3' :
            system("cls");
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
                cout << "\n\t\t\t Enter the last name of the Employee:- ";
                cin >> xlast_name;

                rewind(fp);
                while (fread(&e,recsize,1,fp) == 1)
                {
                    if (strcmp(e.last_name,xlast_name) == 0)
                    {
                        cout << "\n\t\t\t Enter new the Fisrt Name:- ";
                        cin >> e.first_name;
                        cout << "\n\t\t\t  Enter new the Last Name:- ";
                        cin >> e.last_name;
                        cout << "\n\t\t\t   Enter new Employee Age:- ";
                        cin >> e.Age;
                        cout << "\n\t\t\tEnter new Employee Salary:- ";
                        cin >> e.Salary;
                        fseek(fp, - recsize, SEEK_CUR);
                        fwrite(&e,recsize,1,fp);
                        break;
                    }
                    else
                        cout<<"Record not found";
                }
                cout << "\n Do You Want To Modify Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;


        case '4' :
            system("cls");
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
                cout << "\n Enter the last name of the Employee to delete:- ";
                cin >> xlast_name;

                ft = fopen("temp.dat", "wb");

                rewind(fp);
                while (fread (&e, recsize,1,fp) == 1)

                    if (strcmp(e.last_name,xlast_name) != 0)
                    {
                        fwrite(&e,recsize,1,ft);
                    }
                    
                fclose(fp);
                fclose(ft);
                remove("users.txt");
                rename("temp.dat","users.txt");

                fp=fopen("users.txt","rb+");
                
                cout << "\n\tIf you want to delete another recoed then enter Y else enter N:- ";
                fflush(stdin);
                another = getchar();
            }

            break;

        case '5' :
            fclose(fp);
            cout << "\n\n";
            cout << "\t\t     THANKS FOR VISITING SONAWANE DEVELOPERS";
            cout << "\n\n";
            exit(0);
        }
    }


    system("pause");
    getch();

   }

    
int main()
  {
  	start();
  	char y;
  	system("cls");
     	string u;
     	cout<<"\n\t\tWelcome to Sonawane Developers.....!!!!!";
     	cout<<"\n\n\t\tWe request you Sir/Mam to continue by registrating yourself and be part of Sonawane Developers.";
     	cout<<"\n\n\t\tPlease enter your username:-";
     	cin>>u;
     	string pass1 ="";
        char ch;
        cout << "\n\t\t\tEnter password:- ";
        ch = _getch();
        while(ch != 13)
		{
	 		 pass1.push_back(ch);
             cout << '*';
             ch = _getch();
        }
        string pass2 ="";
        cout << "\n\t\t\tPlease re-enter password:- ";
        ch = _getch();
        while(ch != 13)
	    {
          pass2.push_back(ch);
          cout << '*';
          ch = _getch();
        }
       	
  	if(pass1==pass2)
  	{
  	   
  	    cout<<"\n\n\t\tSucessfully Logined in....";
  	    cout<<"\n\n\t\tPress y key to continue......";
  	    cin>>y;
		 data(); 	
	}
	else
	{
	   cout<<"\n\t\tSorry for Inconinvence but you entered both Password incorrect";
	   cout<<"\n\t\tPlease try again later"	;
	}
  	
  	return 0;
  }

