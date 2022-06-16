#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include <windows.h>

#define Student struct Stud

void add(FILE * fp);
void modify(FILE * fp);
void display(FILE * fp);
FILE * del(FILE * fp);
void printChar(char ch,int n);
void title();
FILE *tp;

void gotoxy(int x,int y)
{
  COORD CRD;
    CRD.X = x;
    CRD.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CRD);
}

struct pass
{
  char pass[25];
}pa;

struct Stud
{
    char name[100];
    char dept[50];
    int roll;
    float sgpa[12];
    float cgpa;
};


int main()
{
    int ch,id,k,i;
    char c,pas[50];
    SetConsoleTitle("Student Management System | DIU");
    FILE * fp;
    Student s;
    int option;
    char another;

    if((fp=fopen("db.txt","rb+"))==NULL)
    {
        if((fp=fopen("db.txt","wb+"))==NULL)
        {
            printf("Can't create or open Database.");
            return 0;
        }
    }
    system("color 9f");
  gotoxy(42,8);
  printf("LOGIN(If 1st login press ENTER)");
  gotoxy(42,10);
  printf("____________________________________");
  gotoxy(42,11);
  printf("|\tEnter password :             |");
  gotoxy(42,12);
  printf("|__________________________________|");
  //printf("\n\t\t\t\t\t");
  gotoxy(65,11);
  while( k<10)
  {
      pas[k]=getch();
      char s=pas[k];
      if(s==13)
     break;
      else printf("*");
      k++;
  }
  pas[k]='\0';
  tp=fopen("F:/Password.txt","r+");
    fgets(pa.pass,25,tp);
    if(strcmp(pas,pa.pass)==0)
  {
    system("cls");
    gotoxy(10,3);
    printf("<<<< Loading Please Wait >>>>");
    for(i=0; i<5; i++)
        {
            printf("\t(*_*)");
            Sleep(500);
        }
        printf(" \n\n\n\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *");
    printf("\n\n\t\t\t\t\t     *                    *");
    printf("\n\n\t\t\t\t\t     *       Welcome      *");
    printf("\n\n\t\t\t\t\t     *                    *");
    printf("\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *");
    printf("\n\n\n\n\n\t\t\t\t\tPress any key to continue...... ");
    getch();

    title();
    printf("\n\n\t\t\t\tLab Final Spring 2017");
    printf("\n\n\t\t\t\t     The A Team");
    printf("\n\n\t\t\t  Daffodil International University\n\t\t\t");
    printChar('=',38);
    printf("\n\n\n\t\t\t       press any key to Enter");
    getch();

    while(1)
    {
        title();
        printf("\n\t");
        printChar('*',64);

        printf("\n\n\t\t\t\t1. Add Student");
        printf("\n\n\t\t\t\t2. Modify Student");
        printf("\n\n\t\t\t\t3. Show All Student");
        printf("\n\n\t\t\t\t4. Remove Student");
        printf("\n\n\t\t\t\t5. Logout\n\t");
        printChar('*',64);
        printf("\n\n\t\t\t\tEnter Your Option :--> ");
        scanf("%d",&option);

        switch(option)
        {
            case 1:
                add(fp);
                break;
            case 2:
                modify(fp);
                break;
            case 3:
                display(fp);
                break;
            case 4:
                fp=del(fp);
                break;
            case 5:
                return 1;
                break;
            default:
                printf("\n\t\tNo Action Detected");
                printf("\n\t\tPress Any Key\n\n\n");
                getch();
                system("pause");
        }
    }
    }
    else
    {
        printf("Wrong Password . Get Out");
        getch();
    }
    return 1;

}


void printChar(char ch,int n)
{
    while(n--)
    {
        putchar(ch);
    }
}

void title()
{
    system("cls");
    system("COLOR 03");
    printf("\n\n\t");
    printChar('=',19);
    printf(" Student Management System ");
    printChar('=',19);
    printf("\n");
}


//Insert at end

 void add(FILE * fp)
{
    title();

    char another='y';
    Student s;
    int i;
    float cgpa;

    fseek(fp,0,SEEK_END);
    while(another=='y'||another=='Y')
    {
