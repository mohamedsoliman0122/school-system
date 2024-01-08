#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED


void addstudent();
void studentrecord();
void searchstudent();
void delete();
void callstudentparents();
void edit();
void View();
void delay_print(char *str, unsigned int milliseconds);
void milli_sleep(unsigned int milliseconds);

typedef struct
{
   char num[20];
   char phone[11];
   int age;
}person_t;

struct student
{
  char name[20];
  int roll_n;
  int age;
  int phone[11];
  char grade;
  person_t father;
  person_t mother;
  int numberofBrothers;
  person_t *brothers;
};






#endif // STUDENT_H_INCLUDED
