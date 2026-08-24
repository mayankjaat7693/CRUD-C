#include<stdio.h>
#include<str-lib.h>
#include<io-lib.h>
#define CLASS_1 "class_1.data"
#define CLASS_2 "class_2.data"
#define CLASS_3 "class_3.data"
#define TMP "tmp.tmp"

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
choice=accept_int_input("Enter your choice: ");
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
choice=accept_int_input("Enter your choice: ");
if(choice==1)add_student(class);
else if(choice==2)edit_student(class);
else if(choice==3)delete_student(class);
else if(choice==4)search_student(class);
else if(choice==5)display_list_of_student(class);
else if(choice<=0 || choice>6)printf("Invalid choice!!");
}while(choice!=6);
printf("Exit successfull!!!\n");
return 0;
}

void add_student(int class)
{
FILE *f;
int roll_number;
char roll_number_string[21];
char name[21];
char gender;
char save;
char m;
int i;
int namelen;

printf("--------------------------------------------\n");
printf("          Student (Add Module)           \n");
printf("--------------------------------------------\n");

roll_number=accept_int_input("Enter your Roll Number: ");
if(roll_number<1)
{
printf("invalid roll number!!!\n");
return;
}

f=fopen(class_file(class),"r");
if(f!=NULL)
{
while(1)
{
m=fgetc(f);
if(feof(f))break;
roll_number_string[0]=m;
i=1;
while(1)
{
m=fgetc(f);
if(m==',')break;
roll_number_string[i]=m;
i++;
}
roll_number_string[i]='\0';
if(str2int(roll_number_string)==roll_number)
{
fclose(f);
printf("That roll number exist\n");
return;
}
while(1)
{
m=fgetc(f);
if(m==',')break;
}
m=fgetc(f);
m=fgetc(f);
}// end infinite loop
fclose(f);
}
accept_string_input("Enter name: ",name,21);
str_trim(name);
namelen=str_length(name);
if(namelen<=0)
{
printf("Name Required!!\n");
return;
}
gender=accept_char_input("Gender(M/F): ");
if(gender!='m' && gender!='M' && gender!='f' && gender!='F')
{
printf("invalid gender!!!");
return;
}
if(gender=='m')gender='M';
if(gender=='f')gender='F';
save=accept_char_input("Save(Y/N): ");
if(save!='y' && save!='Y')
{
printf("student not added!!!\n");
return;
}
sprintf(roll_number_string,"%d",roll_number);
f=fopen(class_file(class),"a");
for(i=0;roll_number_string[i]!='\0';i++)
{
fputc(roll_number_string[i],f);
}
fputc(',',f);
for(i=0;name[i]!='\0';i++)
{
fputc(name[i],f);
}
fputc(',',f);
fputc(gender,f);
fputc(',',f);
fclose(f);
printf("Student Added!!\n");
}

void edit_student(int class)
{
FILE *f,*f2;
int roll_number;
char roll_number_string[21];
char name[21];
char v_roll_number[21];
char v_name[21];
char v_gender;
char gender;
char edit;
char update;
char m;
int i;
int namelen;
int found;

printf("--------------------------------------------\n");
printf("           Student (Edit Module)            \n");
printf("--------------------------------------------\n");

roll_number=accept_int_input("Enter your Roll Number: ");
if(roll_number<1)
{
printf("invalid roll number!!!\n");
return;
}
found=0;
f=fopen(class_file(class),"r");
if(f==NULL)
{
printf("That roll number does not exist\n");
return;
}
while(1)
{
m=fgetc(f);
if(feof(f))break;
roll_number_string[0]=m;
i=1;
while(1)
{
m=fgetc(f);
if(m==',')break;
roll_number_string[i]=m;
i++;
}
roll_number_string[i]='\0';
i=0;
while(1)
{
m=fgetc(f);
if(m==',')break;
name[i]=m;
i++;
}
name[i]='\0';
gender=fgetc(f);
m=fgetc(f);
if(str2int(roll_number_string)==roll_number)
{
found=1;
break;
}
}// end infinite loop
fclose(f);
if(found==0)
{
printf("That roll number does not exist\n");
return;
}
printf("------------------------------\n");
printf("Name : %s \nGender: %c\n",name,gender);
printf("------------------------------\n");
edit=accept_char_input("Edit(Y/N): ");
if(edit!='y' && edit!='Y')
{
printf("Student not update\n");
return;
}
accept_string_input("Enter New Name: ",name,21);
str_trim(name);
namelen=str_length(name);
if(namelen<1)
{
printf("Name Required!!!!\n");
return;
}
gender=accept_char_input("Gender(M/F): ");
if(gender!='f' && gender!='F' && gender!='M' && gender!='m')
{
printf("invalid gender!!!\n");
return;
}
if(gender=='m')gender='M';
if(gender=='f')gender='f';
update=accept_char_input("Updete(Y/N):  ");
if(update!='y' && update!='Y')
{
printf("Student not update\n");
return;
}
sprintf(roll_number_string,"%d",roll_number);
f=fopen(class_file(class),"r");
f2=fopen(TMP,"w");
while(1)
{
m=fgetc(f);
if(feof(f))break;
v_roll_number[0]=m;
i=0;
}
i=0;
while(1)
{
m=fgetc(f);
if(m==',')break;
v_roll_number[i]=m;
i++;
}
v_roll_number[i]='\0';
i=0;
while(1)
{
m=fgetc(f);
if(m==',')break;
v_name[i]=m;
i++;
}
v_name[i]='\0';
v_gender=fgetc(f);
m=fgetc(f);
if(str2int(v_roll_number)!=roll_number)
{
for(i=0;v_roll_number[i]!='\0';i++)fputc(v_roll_number[i],f);
fputc(',',f);
for(i=0;v_name[i]!='\0';i++)fputc(v_name[i],f);
fputc(',',f);
fputc(v_gender,f);
fputc(',',f);
}
else
{
for(i=0;roll_number_string[i]!='\0';i++)fputc(roll_number_string[i],f);
fputc(',',f);
for(i=0;name[i]!='\0';i++)fputc(name[i],f);
fputc(',',f);
fputc(gender,f);
fputc(',',f);
}
fclose(f);
fclose(f2);
f=fopen(class_file(class),"w");
f2=fopen(TMP,"r");
while(1)
{
m=fgetc(f2);
if(feof(f))break;
fputc(m,f);
}
fclose(f);
fclose(f2);
f2=fopen(TMP,"w");
fclose(f2);
printf("strudent updated!!\n");
}

void delete_student(int class)
{
FILE *f,*f2;
int roll_number;
char roll_number_string[21];
char name[21];
char v_roll_number[21];
char v_name[21];
char v_gender;
char gender;
char edit;
char update;
char m;
int i;
int namelen;
int found;

printf("--------------------------------------------\n");
printf("           Student (Delete Module)            \n");
printf("--------------------------------------------\n");

roll_number=accept_int_input("Enter your Roll Number: ");
if(roll_number<1)
{
printf("invalid roll number!!!\n");
return;
}
found=0;
f=fopen(class_file(class),"r");
if(f==NULL)
{
printf("That roll number does not exist\n");
return;
}
while(1)
{
m=fgetc(f);
if(feof(f))break;
roll_number_string[0]=m;
i=1;
while(1)
{
m=fgetc(f);
if(m==',')break;
roll_number_string[i]=m;
i++;
}
roll_number_string[i]='\0';
i=0;
while(1)
{
m=fgetc(f);
if(m==',')break;
name[i]=m;
i++;
}
name[i]='\0';
gender=fgetc(f);
m=fgetc(f);
if(str2int(roll_number_string)==roll_number)
{
found=1;
break;
}
}// end infinite loop
fclose(f);
if(found==0)
{
printf("That roll number does not exist\n");
return;
}
printf("------------------------------\n");
printf("Name : %s \nGender: %c\n",name,gender);
printf("------------------------------\n");
update=accept_char_input("Delete(Y/N):  ");
if(update!='y' && update!='Y')
{
printf("Student not Delete\n");
return;
}
sprintf(roll_number_string,"%d",roll_number);
f=fopen(class_file(class),"r");
f2=fopen(TMP,"w");
while(1)
{
m=fgetc(f);
if(feof(f))break;
v_roll_number[0]=m;
i=1;
while(1)
{
m=fgetc(f);
if(m==',')break;
v_roll_number[i]=m;
i++;
}
v_roll_number[i]='\0';
i=0;
while(1)
{
m=fgetc(f);
if(m==',')break;
v_name[i]=m;
i++;
}
v_name[i]='\0';
v_gender=fgetc(f);
m=fgetc(f);

if(str2int(v_roll_number)!=roll_number)
{
for(i=0;v_roll_number[i]!='\0';i++)fputc(v_roll_number[i],f2);
fputc(',',f2);
for(i=0;v_name[i]!='\0';i++)fputc(v_name[i],f2);
fputc(',',f2);
fputc(v_gender,f2);
fputc(',',f2);
}
}
fclose(f);
fclose(f2);
f=fopen(class_file(class),"w");
f2=fopen(TMP,"r");
while(1)
{
m=fgetc(f2);
if(feof(f2))break;
fputc(m,f);
}
fclose(f);
fclose(f2);
f2=fopen(TMP,"w");
fclose(f2);
printf("Student deleted!!!\n");
}

void search_student(int class)
{
FILE *f;
int roll_number;
char roll_number_string[21];
char name[21];
char gender;
char save;
char m;
int i;
int namelen;
int found;

printf("--------------------------------------------\n");
printf("          Student (Search Module)           \n");
printf("--------------------------------------------\n");
roll_number=accept_int_input("Enter roll number: ");
if(roll_number<1)
{
printf("invalid roll number\n");
return;
}
f=fopen(class_file(class),"r");
if(f==NULL)
{
printf("That roll number not exist\n");
return;
}
found=0;
while(1)
{
m=fgetc(f);
if(feof(f))break;
roll_number_string[0]=m;
i=1;
while(1)
{
m=fgetc(f);
if(m==',')break;
roll_number_string[i]=m;
i++;
}
roll_number_string[i]='\0';
i=0;
while(1)
{
m=fgetc(f);
if(m==',')break;
name[i]=m;
i++;
}
name[i]='\0';
gender=fgetc(f);
m=fgetc(f);

if(str2int(roll_number_string)==roll_number)
{
found=1;
break;
}
}
fclose(f);
if(found==0)
{
printf("That roll number does not exist\n");
return;
}
printf("Name: %s\nGender: %c\n",name,gender);
}

void display_list_of_student(int class)
{
FILE *f;
int roll_number;
char roll_number_string[21];
char name[21];
char gender;
char save;
char m;
int i;
int namelen;
int sno;
int page_size;
int header;

printf("--------------------------------------------\n");
printf("          Student (List Module)           \n");
printf("--------------------------------------------\n");
sno=0;
page_size=4;
header=TRUE;
f=fopen(class_file(class),"r");
if(f==NULL)
{
printf("That roll number not exist\n");
return;
}
while(1)
{
m=fgetc(f);
if(feof(f))break;
roll_number_string[0]=m;
i=1;
while(1)
{
m=fgetc(f);
if(m==',')break;
roll_number_string[i]=m;
i++;
}
roll_number_string[i]='\0';
i=0;
while(1)
{
m=fgetc(f);
if(m==',')break;
name[i]=m;
i++;
}
name[i]='\0';
gender=fgetc(f);
m=fgetc(f);
if(header==TRUE)
{
printf("----------------------------------------------\n");
printf(" SNO    Roll No.       Name             Gender\n");
printf("----------------------------------------------\n");
header=FALSE;
}
sno++;
printf(" %-5d   %-10s    %-15s     %-2c   \n",sno,roll_number_string,name,gender);
if(sno%page_size==0)
{
printf("----------------------------------------------\n");
header=TRUE;
}
}// end infinite loop
fclose(f);
}

char* class_file(int choice)
{
if(choice==1)return CLASS_1;
else if(choice==2)return CLASS_2;
else if(choice==3)return CLASS_3;
}











