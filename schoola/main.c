#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "student.c"
#include <conio.h>
#include<windows.h>

//const Table = require('ascii-art-table');

void SetColor(int ForgC)
{
    WORD wColor;
    //We will need this handle to get the current background attribute
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    //We use csbi for the wAttributes word.
    if (GetConsoleScreenBufferInfo(hStdOut, & csbi))
    {
        //Mask out all but the background attribute, and add in the forgournd color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

void delay_print(char *str, unsigned int milliseconds)
{
    for (; *str; str++)
    {
        putchar(*str);
        fflush(stdout);
        milli_sleep(milliseconds);
    }
}

void milli_sleep(unsigned int milliseconds)
{
#ifdef _WIN32
    //use windos Sleep function, sleeps for a number of milliseconds
    Sleep(milliseconds);
#else
    // use posix nanosleep function, sleeps for a number of nanoseconds
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000L;
    nanosleep(&ts, NULL);
#endif
}
//Example -- >     delay_print("Hello world",10) ;





void main()
 {
   system("cls");
   Sleep(300);
   SetColor(11);
    printf("\n\n\n\n\n\n"
"\t                           888                                        888                                 888 \n"
"\t                           888                                        888                                 888 \n"
"\t                           888                                        888                                 888 \n"
"\t.d8888b  888  888 .d8888b  888888  .d88b.  88888b.d88b.      .d8888b  88888b.   .d8888b  .d88b.   .d88b.  888 \n"
"\t88K      888  888 88K      888    d8P  Y8b 888 .888 .88b     88K      888 .88b d88P.    d88  88b d88  88b 888 \n"
"\t.Y8888b. 888  888 .Y8888b. 888    88888888 888  888  888     .Y8888b. 888  888 888      888  888 888  888 888 \n"
"\t     X88 Y88b 888      X88 Y88b.  Y8b.     888  888  888          X88 888  888 Y88b.    Y88..88P Y88..88P 888 \n"
"\t88888P'    Y88888  88888P'   Y888   Y8888  888  888  888      88888P' 888  888   Y8888P   Y88P     Y88P   888 \n"
"\t              888 \n"
"\t         Y8b d88P  \n"
"\t          'Y88P' \n"
);
           // system("cls");
              Sleep(3000);

int n;
while(n!=9)
{
    printf("\n");
        system("cls");
        SetColor(9);
        //system("color 4");
        printf("      =======================\n");
        printf("     |student database system|\n");
        printf("      =======================\n");
        SetColor(45);
        printf("\n   1 > Add Student.\n");
        printf("   2 > Students Records.\n");
        printf("   3 > Search Student.\n");
        printf("   4 > Delete Student.\n");
        printf("   5 > edit Student.\n");
        printf("   6 > Call student parents.\n");
        printf("   7 > View Student.\n");
        printf("   8 > Exit.\n");
        printf("   _____________________\n");
        SetColor(11);
        printf(" >> Enter a number of operation which needed : ");
        SetColor(45);
        scanf("%d",&n);
        SetColor(11);

        switch(n)
        {
        case 1:
            system("cls");
            addstudent();
            system("cls");
            break;
        case 2:
            system("cls");
            studentrecord();
            printf("\t\t\t\t  press any key to exit..... \n");
            getch();
            system("cls");
            break;

        case 3:
            system("cls");
            searchstudent();
            printf("\n\t\t\t\t  Press any key to exit.......\n");

            getch();
            system("cls");
            break;

        case 4:
            system("cls");
            delete();
            printf("\n\t\t\t\tPress any key to exit.......\n");
            getch();
            system("cls");
            break;
        case 5:
            system("cls");
            edit();
            printf("\n\t\t\t\t  Press any key to exit.......\n");
            getch();
            system("cls");
            break;
        case 6:
            system("cls");
            callstudentparents();
            printf("\n\t\t\t\t  Press any key to exit.......\n");
            system("cls");
            break;

            case 7:
            system("cls");
            View();
            printf("\n\t\t\t\t  Press any key to exit.......\n");
            //getch();
            system("cls");
            break;

        case 8:
            system("cls");
            printf("\n\t\t\t\tThank you, for used this software.\n\n");
            exit(1);
            //system("cls");
            getch();
            break;

        default :
            system("cls");
            getch();
            printf("\n\t\t\t\t\tEnter a valid number\n\n");
            printf("\t\t\t\tPress any key to continue.......");
            getch();
            system("cls");
            break;
        }

    }

    getch();
}


