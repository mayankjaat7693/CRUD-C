#include<stdio.h>
#define CLASS_1 "cls1.data"
#define CLASS_2 "cls2.data"
#define CLASS_3 "cls3.data"
#define TMP "t.tmp"
void clear_stdin_buffer()
{
while(getchar()!='\n');
}

typedef struct student
{
int roll_number;
char name[21];
char gender;
}student;

void add_student();
void edit_student();
void delete_student();
void search_student();
void display_list_of_student();
char* class_file();

int main()
{
int choice;
int class;
do{
printf("----Select class----\n");
printf("1.First class\n");
printf("2.Second class\n");
printf("3.Third class\n");
printf("4.Exit\n");
printf("--------------------\n");
printf("Enter your choice: ");
scanf("%d",&choice);
clear_stdin_buffer();
if(choice==1)class=1;
else if(choice==2)class=2;
else if(choice==3)class=3;
else if(choice==4)return 0;
else{
printf("invalid selection!!!\n");
continue;
}

printf("1.Add student\n");
printf("2.Edit student\n");
printf("3.Delete sudent\n");
printf("4.Search student\n");
printf("5.Display list of student\n");
printf("6.Exit\n");
printf("Enter your choice: ");
scanf("%d",&choice);
clear_stdin_buffer();
if(choice==1)add_student(class);
else if(choice==2)edit_student(class);
else if(choice==3)delete_student(class);
else if(choice==4)search_student(class);
else if(choice==5)display_list_of_student(class);
else if(choice<=0 || choice>6){
printf("Invalid choice!!");
continue;
}
}while(choice!=6);
printf("Exit successfull!!!\n");
return 0;
}

void add_student(int class)
{
FILE *f;
student t,s;

printf("--------------------------------------------\n");
printf("            Student (Add Module)            \n");
printf("--------------------------------------------\n");

printf("Enter Roll number: ");
scanf("%d",&s.roll_number);
clear_stdin_buffer();

f=fopen(class_file(class),"rb");
if(f!=NULL)
{
while(1)
{
fread(&t,sizeof(student),1,f);
if(feof(f))break;
if(s.roll_number==t.roll_number)
{
printf("That roll number alloted to %s\n",t.name);
fclose(f);
return;
}
}
fclose(f);
}
printf("Enter name: ");
scanf("%[^\n]s",s.name);
clear_stdin_buffer(); 

printf("Gender(M/F): ");
scanf("%c",&s.gender);
clear_stdin_buffer();
if(s.gender!='m' && s.gender!='M' && s.gender!='f' && s.gender!='F' )
{
printf("invalid gender\n");
return;
} 
if(s.gender=='m')s.gender='M';
if(s.gender=='f')s.gender='F';
f=fopen(class_file(class),"ab");
fwrite(&s,sizeof(student),1,f);
fclose(f);
printf("Student Added!!!\n");
}

void edit_student(int class)
{
student s,t;
FILE *f,*f2;
int found;
char edit;

printf("-------------------------------\n");
printf("     Student(Edit Module)      \n");
printf("-------------------------------\n");
printf("Enter roll number: ");
scanf("%d",&s.roll_number);
clear_stdin_buffer();

f=fopen(class_file(class),"rb");
if(f==NULL)
{
printf("That roll number does not exist\n");
return;
}
found=0;
while(1)
{
fread(&t,sizeof(student),1,f);
if(feof(f))break;
if(s.roll_number==t.roll_number)
{
found=1;
break;
}
}
fclose(f);
if(found==0)
{
printf("That roll number does not exits\n");
return;
}
printf("Name: %s\nGender: %c\n",t.name,t.gender);
printf("Edit(Y/N): ");
scanf("%c",&edit);
clear_stdin_buffer();
if(edit!='y' && edit!='Y')
{
printf("Student not edit\n");
return;
}

printf("Enter name: ");
scanf("%[^\n]s",s.name);
clear_stdin_buffer();

printf("Gender(M/F): ");
scanf("%c",&s.gender);
clear_stdin_buffer();

printf("Update(Y/N): ");
scanf("%c",&edit);
clear_stdin_buffer();
if(edit!='y' && edit!='Y')
{
printf("Student not edit\n");
return;
}
f=fopen(class_file(class),"rb");
f2=fopen(TMP,"wb");
while(1)
{
fread(&t,sizeof(student),1,f);
if(feof(f))break;
if(s.roll_number!=t.roll_number)
{
fwrite(&t,sizeof(student),1,f2);
}
else
{
fwrite(&s,sizeof(student),1,f2);
}
}
fclose(f);
fclose(f2);
f=fopen(class_file(class),"wb");
f2=fopen(TMP,"rb");
while(1)
{
fread(&t,sizeof(student),1,f2);
if(feof(f2))break;
fwrite(&t,sizeof(student),1,f);
}
fclose(f);
fclose(f2);
f2=fopen(TMP,"wb");
fclose(f2);
printf("Student Edit successfull!!!\n");
}

void delete_student(int class)
{
student s,t;
FILE *f,*f2;
int found;
char edit;

printf("-------------------------------\n");
printf("     Student(Delete Module)      \n");
printf("-------------------------------\n");
printf("Enter roll number: ");
scanf("%d",&s.roll_number);
clear_stdin_buffer();

f=fopen(class_file(class),"rb");
if(f==NULL)
{
printf("That roll number does not exist\n");
return;
}
found=0;
while(1)
{
fread(&t,sizeof(student),1,f);
if(feof(f))break;
if(s.roll_number==t.roll_number)
{
found=1;
break;
}
}
fclose(f);
if(found==0)
{
printf("That roll number does not exits\n");
return;
}

printf("Name: %s\nGender: %c\n",t.name,t.gender);
printf("Delete(Y/N): ");
scanf("%c",&edit);
clear_stdin_buffer();
if(edit!='y' && edit!='Y')
{
printf("Student not delete\n");
return;
}
f=fopen(class_file(class),"rb");
f2=fopen(TMP,"wb");
while(1)
{
fread(&t,sizeof(student),1,f);
if(feof(f))break;
if(s.roll_number!=t.roll_number)
{
fwrite(&t,sizeof(student),1,f2);
}
}
fclose(f);
fclose(f2);
f=fopen(class_file(class),"wb");
f2=fopen(TMP,"rb");
while(1)
{
fread(&t,sizeof(student),1,f2);
if(feof(f2))break;
fwrite(&t,sizeof(student),1,f);
}
fclose(f);
fclose(f2);
f2=fopen(TMP,"wb");
fclose(f2);
printf("Student delete successfull!!!\n");
}
void search_student(int class)
{
student s,t;
FILE *f;
int found;

printf("-------------------------------\n");
printf("     Student(search Module)      \n");
printf("-------------------------------\n");
printf("Enter roll number: ");
scanf("%d",&s.roll_number);
clear_stdin_buffer();

f=fopen(class_file(class),"rb");
if(f==NULL)
{
printf("That roll number does not exist\n");
return;
}
found=0;
while(1)
{
fread(&t,sizeof(student),1,f);
if(feof(f))break;
if(s.roll_number==t.roll_number)
{
found=1;
break;
}
}
fclose(f);
if(found==0)
{
printf("That roll number does not exits\n");
return;
}
printf("Name: %s\nGender: %c\n",t.name,t.gender);
return;
}

void display_list_of_student(int class)
{
student s,t;
FILE *f;
int header;
int sno;
int page_size;

printf("-------------------------------\n");
printf("     Student(List Module)      \n");
printf("-------------------------------\n");
f=fopen(class_file(class),"rb");
if(f==NULL)
{
printf("That roll number does not exist\n");
return;
}
sno=0;
page_size=3;
header=1;
while(1)
{
fread(&t,sizeof(student),1,f);
if(feof(f))break;
if(header==1)
{
printf("------------------------------------\n");
printf("SNO  Roll No.      Name       gender\n");
printf("------------------------------------\n");
header=0;
}
sno++;
printf("%-4d  %-4d    %-15s    %-2c\n",sno,t.roll_number,t.name,t.gender);
if(sno%page_size==0)
{
printf("------------------------------------\n");
header=1;
}
}
fclose(f);
if(sno%page_size!=0)
{
printf("------------------------------------\n");
}
}

char* class_file(int choice)
{
if(choice==1)return CLASS_1;
else if(choice==2)return CLASS_2;
else if(choice==3)return CLASS_3;
}











