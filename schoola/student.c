#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include <conio.h>
#include <string.h>
//#include "color.c"
#include<windows.h>
#include<MMsystem.h>

void string_scan(char*str,int MaxSize)
{
    int i=0;
    scanf(" %c",&str[i]);
    for(; str[i]!='\n'&&i<MaxSize-1;)
    {
        i++;
        scanf("%c",&str[i]);
    }
    str[i]=0;
}

void addstudent()
{
    char another;
    FILE *file ;
    struct student s;
    do
    {
        system("cls");
        printf("\t\t<<Add Students>>\n\n");
        file=fopen("New Text.txt","a+");
        SetColor(14);
        printf(">> Enter a student name :");
        SetColor(19);
        string_scan(s.name,20);
        SetColor(14);
        printf(">> Enter a student roll_n:");
        SetColor(19);
        scanf(" %d",&(s.roll_n));
        SetColor(14);
        printf(">> Enter a student age :");
        SetColor(19);
        scanf(" %d",&(s.age));
        SetColor(14);
        printf(">> Enter a student phone :");
        SetColor(19);
        scanf(" %s",&(s.phone));
        SetColor(14);
        printf(">> Enter a student grade :");
        SetColor(19);
        scanf(" %c",&(s.grade));
        SetColor(14);
        printf(">> Enter father's name :");
        SetColor(19);
        string_scan(s.father.num,20);
        SetColor(14);
        printf(">> Enter father's age :");
        SetColor(19);
        scanf(" %d",&(s.father.age));
        SetColor(14);
        printf(">> Enter father's phone :");
        SetColor(19);
        scanf(" %s",&(s.father.phone));
        SetColor(14);
        printf(">> Enter mother's name :");
        SetColor(19);
        string_scan(s.mother.num,20);
        SetColor(14);
        printf(">> Enter mother's age :");
        SetColor(19);
        scanf(" %d",&(s.mother.age));
        SetColor(14);
        printf(">> Enter mother's phone :");
        SetColor(19);
        scanf(" %s",&(s.mother.phone));
        SetColor(14);
        printf(">> Enter no. of brothers :");
        SetColor(19);
        scanf("%d",&(s.numberofBrothers));
        /*s.brothers=(person_t*)malloc(s.numberofBrothers*sizeof(person_t));
        for(int i=0; i<s.numberofBrothers; i++)
        {
            SetColor(14);printf("\nenter information student[%d]:\n",i+1);
            SetColor(14);printf(">> Enter a student name :");
            SetColor(19);
            scanf(" %s",&(s.brothers[i].num));
            SetColor(14);printf(">> Enter a student age :");
            SetColor(19);
            scanf(" %d",&(s.brothers[i].age));
            //printf("\n\t______________________________\n");

        }*/
        if(file==NULL)
        {
            fprintf(stderr,"can't open file\n");
            //exit(1);
        }
        else
        {
            printf("\t\tRecord stored successfuly\n");
        }

        fwrite(&s,sizeof(struct student),1,file);
        fclose(file);
        printf("\t\tYou want to add another record?(y/n) : ");
        scanf(" %s",&another);

    }
    while(another=='y'||another=='Y');
    free(s.brothers);
}
void studentrecord()
{
    FILE *file;
    struct student s;
    file=fopen("New Text.txt","r+");
    printf("\n\t\t<<STUDENTS RECORD>>\n\n\n");
    if(file==NULL)
    {
        fprintf(stderr,"can't open file\n");
        //exit(1);
    }
    else
    {
        printf("\t>>RECORDS<< ");
    }
    while(fread(&s,sizeof(struct student),1,file))
    {

        SetColor(3);
        printf("\n  ===========================");
        SetColor(14);
        printf("\n  ---< Student info. >---");
        SetColor(15);
        printf("\n  >> Name : %s",s.name);
        printf("\n  >> Roll_n : %d",s.roll_n);
        printf("\n  >> Age : %d",s.age);
        printf("\n  >> phone : %s",s.phone);
        printf("\n  >> Grade : %c",s.grade);
        SetColor(14);
        printf("\n  ---< Father info. >---");
        SetColor(15);
        printf("\n  >> father's name : %s",s.father.num);
        printf("\n  >> father's age : %d",s.father.age);
        printf("\n  >> father's phone : %s",s.father.phone);
        SetColor(14);
        printf("\n  ---< Mother info. >---");
        SetColor(15);
        printf("\n  >> mother's name : %s",s.mother.num);
        printf("\n  >> mother's age : %d",s.mother.age);
        printf("\n  >> mother's phone : %s",s.mother.phone);
        SetColor(14);
        printf("\n  ---< Brothers info. >---");
        SetColor(15);
        printf("\n  >> Enter no. of brothers : %d",s.numberofBrothers);
        /* for(int i=0; i<s.numberofBrothers; i++)
         {
             printf("\n  >> Enter a student name : %s",s.brothers[i].num);
             printf("\n  >> Enter a student age :  %d",s.brothers[i].age);

         }*/
        SetColor(3);
        printf("\n  ===========================\n");

    }
    fclose(file);
    getch();

}
void searchstudent()
{
    struct student s;
    FILE *file;
    int roll_n,flag=0;
    char Name[20];
    gets(Name);
    file=fopen("New Text.txt","rb+");
    printf("\t\t\t\t\n<<SEARCH STUDENTS RECORD>>\n\n\n");
    printf(">>Enter the roll number<< :");
    scanf(" %d",&roll_n);

    while(fread(&s,sizeof(struct student),1,file)>0)
    {
        if(s.roll_n==roll_n)
        {

            flag=1;
            SetColor(3);
        printf("\n  ===========================");
        SetColor(14);
        printf("\n  ---< Student info. >---");
        SetColor(15);
        printf("\n  >> Name : %s",s.name);
        printf("\n  >> Roll_n : %d",s.roll_n);
        printf("\n  >> Age : %d",s.age);
        printf("\n  >> phone : %s",s.phone);
        printf("\n  >> Grade : %c",s.grade);
        SetColor(14);
        printf("\n  ---< Father info. >---");
        SetColor(15);
        printf("\n  >> father's name : %s",s.father.num);
        printf("\n  >> father's age : %d",s.father.age);
        printf("\n  >> father's phone : %s",s.father.phone);
        SetColor(14);
        printf("\n  ---< Mother info. >---");
        SetColor(15);
        printf("\n  >> mother's name : %s",s.mother.num);
        printf("\n  >> mother's age : %d",s.mother.age);
        printf("\n  >> mother's phone : %s",s.mother.phone);
        SetColor(14);
        printf("\n  ---< Brothers info. >---");
        SetColor(15);
        printf("\n  >> Enter no. of brothers : %d",s.numberofBrothers);
        /* for(int i=0; i<s.numberofBrothers; i++)
         {
             printf("\n  >> Enter a student name : %s",s.brothers[i].num);
             printf("\n  >> Enter a student age :  %d",s.brothers[i].age);

         }*/
        SetColor(3);
        printf("\n  ===========================\n");
        }
    }
    if(flag=0)
    {
        printf("\n\t\t\tRecord not found\n");
    }
    fclose(file);
    getch();

}
void delete()
{
    struct student s;
    FILE *file,*file1;
    int roll_n,flag=0;
    printf("\t\t\t\t<<DELETE STUDENTS RECORD>>\n\n\n");
    file=fopen("New Text.txt","r");
    file1=fopen("temp.txt","w");
    printf("\t\t\tEnter the roll number :");
    scanf(" %d",&roll_n);

    if(file==NULL)
    {
        fprintf(stderr,"can't open file\n");
        //exit(1);
    }
    while(fread(&s,sizeof(struct student),1,file))
    {
        if(s.roll_n == roll_n)
        {

            flag=1;

        }
        else
        {
            fwrite(&s,sizeof(struct student),1,file1);
        }

    }
    fclose(file);
    fclose(file1);

    if(!flag)
    {
        printf("\n\t\t\t\tRecord not flag\n");
    }
    if(flag)
    {
        remove("New Text.txt");
        rename("temp.txt","C:\school system.txt");

        printf("\n\t\t\t\tRecord deleted succesfully\n");
    }

    getch();
}
void callstudentparents()
{
    struct student s;
    FILE *file;
    int roll_n,flag=0;
    file=fopen("New Text.txt","rb+");
    printf("\n\t\t\t\t<<COLL STUDENTS PARENT>>\n\n\n");
    printf(">>Enter the roll number<< :");
    scanf(" %d",&roll_n);
    int n;
    if(file==NULL)
    {
        fprintf(stderr,"can't open file\n");
        //exit(1);
    }
    while(fread(&s,sizeof(struct student),1,file))
    {
        if(s.roll_n == roll_n)
        {
            flag=1;
        }
        else
        {
            flag=0;
        }



        if(flag==1)
        {
            SetColor(3);
            printf("<<Call student parents.>>\n");
            SetColor(15);
            printf("\n 1 > Call fathers.\n");
            printf(" 2 > Call Mothers.\n\n");
            SetColor(3);
            printf(" >> press 1 or 2 :  ");
            SetColor(15);
            scanf("%d",&n);
            if(n==1)
            {
                //system("cls");
                SetColor(3);
                printf("\n  ===========================");
                SetColor(14);
                printf("\n  ---< Student info. >---");
                SetColor(15);
                printf("\n  >> Name : %s",s.name);
                SetColor(14);
                printf("\n  ---< Calling Father . >---");
                SetColor(15);
                printf("\n  >> father's name : %s",s.father.num);
                printf("\n  >> father's phone : %s",s.father.phone);
                SetColor(3);
                printf("\n  ===========================\n\n");

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
                //PlaySound(TEXT("C:\\school system\\sawend\\iphone.wav"),NULL,SND_ASYNC);
                system("pause");
                printf("ringing  ");
                SetColor(9);
                printf("******") ;
                Sleep(1000);
                SetColor(4);
                delay_print("**",300) ;
                Sleep(1000);
                SetColor(5);
                delay_print("**",300) ;
                Sleep(1000);
                SetColor(11);
                delay_print("**",300) ;
                Sleep(1000);
                SetColor(8);
                delay_print("**",300) ;
                Sleep(1000);
                SetColor(12);
                delay_print("**",300) ;
                Sleep(1000);
                SetColor(11);
                delay_print("**",300) ;
                SetColor(4);
                printf("    No answer.\n");

            }


            else if(n==2)
            {
                // system("cls");
                SetColor(3);
                printf("\n  ===========================");
                SetColor(14);
                printf("\n  ---< Student info. >---");
                SetColor(15);
                printf("\n  >> Name : %s",s.name);
                SetColor(14);
                printf("\n  ---< Calling Mother . >---");
                SetColor(15);
                printf("\n  >> mother's name : %s",s.mother.num);
                printf("\n  >> mother's phone : %s",s.mother.phone);
                SetColor(3);
                printf("\n  ===========================\n\n");

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

  // PlaySound(TEXT("C:\\school system\\sawend\\iphone.wav"),NULL,SND_ASYNC);
                system("pause");
                printf("ringing  ");
                SetColor(9);
                printf("******") ;
                Sleep(1000);
                SetColor(4);
                delay_print("**",300) ;
                Sleep(1000);
                SetColor(5);
                delay_print("**",300) ;
                Sleep(1000);
                SetColor(11);
                delay_print("**",300) ;
                Sleep(1000);
                SetColor(8);
                delay_print("**",300) ;
                Sleep(1000);
                SetColor(12);
                delay_print("**",300) ;
                Sleep(1000);
                SetColor(11);
                delay_print("**",300) ;
                SetColor(4);
                printf("    No answer.\n\n\n");

            }
            else
            {
                printf("\n\t\t\t\t Record not flag\n");
            }

        }
    }
    fclose(file);
    SetColor(11);
    printf("\n Press any key to continue.");
    getch();
}





void edit()
{
    char stname[20];
    FILE *file;
    struct student s;
    system("cls");
    printf("<--:MODIFY RECORD:-->\n");
    printf("Enter name of student to modify: ");
    fflush(stdin);
    gets(stname);
    //scanf(" %S",&stname);
    file = fopen("New Text.txt","rb+");
    if(file == NULL)
    {
        printf("Error opening file\n");
        //exit(1);
    }
    rewind(file);
    fflush(stdin);
    while(fread(&s,sizeof(s),1,file) == 1)
    {
        if(strcmp(stname,s.name) == 0)
        {

            SetColor(14); printf(">> Enter a student name :");
            SetColor(19); string_scan(s.name,20);
            SetColor(14); printf(">> Enter a student roll_n:");
            SetColor(19); scanf(" %d",&(s.roll_n));
            SetColor(14); printf(">> Enter a student age :");
            SetColor(19); scanf(" %d",&(s.age));
            SetColor(14); printf(">> Enter a student phone :");
            SetColor(19); scanf(" %s",&(s.phone));
            SetColor(14); printf(">> Enter a student grade :");
            SetColor(19); scanf(" %c",&(s.grade));
            SetColor(14); printf(">> Enter father's name :");
            SetColor(19); string_scan(s.father.num,20);
            SetColor(14); printf(">> Enter father's age :");
            SetColor(19); scanf(" %d",&(s.father.age));
            SetColor(14); printf(">> Enter father's phone :");
            SetColor(19); scanf(" %s",&(s.father.phone));
            SetColor(14); printf(">> Enter mother's name :");
            SetColor(19); string_scan(s.mother.num,20);
            SetColor(14); printf(">> Enter mother's age :");
            SetColor(19); scanf(" %d",&(s.mother.age));
            SetColor(14); printf(">> Enter mother's phone :");
            SetColor(19); scanf(" %s",&(s.mother.phone));
            SetColor(14); printf(">> Enter no. of brothers :");
            SetColor(19); scanf(" %d",&(s.numberofBrothers));
            /*s.brothers=(person_t*)malloc(s.numberofBrothers*sizeof(person_t));

            for(int i=0; i<s.numberofBrothers; i++)
            {
                printf("\nenter information student[%d]:\n",i+1);
                printf(">> Enter a student name :");
                string_scan(s.brothers[i].num,20);
                printf(">> Enter a student age :");
                scanf(" %d",&(s.brothers[i].age));
            }*/
            fseek(file,-sizeof(s),SEEK_CUR);
            fwrite(&s,sizeof(s),1,file);
            break;
        }
    }
    fclose(file);
    printf("Press any key to continue.");
    getch();
}
void View()
{
    FILE *file;
    int i=1;
    struct student s;
    SetColor(14);
    printf("<--:VIEW RECORD:-->\n\n\n");


    SetColor(44);
    printf("   == ++ ==================== + === + === + === + ============ ++ =================== + === + =========== ++ =================== + === + ===========\n");
    SetColor(47);
    printf("   ID ||     student name     | age |roll |Grade|    phone     ||     Father name     | Age |    Phone    ||     Mother name     | Age |   Phone\n");
    SetColor(44);
    printf("   == ++ ==================== + === + === + === + ============ ++ =================== + === + =========== ++ =================== + === + ===========\n");
    file = fopen("New Text.txt","r+");
    if(file == NULL)
    {
        printf("Error opening file.");
        //exit(1);
    }

    while(fread(&s,sizeof(struct student),1,file))
    {

        SetColor(47);
        printf("   %-6d%-24s%-6d%-6d%-5c%-16s%-23s%-5d%-15s%-23s%-5d%-20s\n",i,s.name,s.age,s.roll_n,s.grade,s.phone,s.father.num,s.father.age,s.father.phone,s.mother.num,s.mother.age,s.mother.phone);
        i++;
        SetColor(44);
        printf("      ||                      |     |     |     |              ||                     |     |             ||                     |     |            \n");
    }
    SetColor(44);
    printf("   == ++ ==================== + === + === + === + ============ ++ =================== + === + =========== ++ =================== + === + ===========\n\n\n");
    fclose(file);
    SetColor(11);
    printf("Press any key to continue.\n");
    getch();

}
