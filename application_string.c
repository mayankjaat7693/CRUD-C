#include<stdio.h>
#include<str-lib.h>
#include<io-lib.h>
#define CLASS_1 "class1.data"
#define CLASS_2 "class2.data"
#define CLASS_3 "class3.data"
#define TMP "tp.tmp"

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
char m_roll_number_string[21];
char roll_number_string[22];
char name[22];
char m_name[21];
char m_gender[7];
char gender[8];
char save;
char m;
int i;
int namelen;
int choice;

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
fgets(roll_number_string,22,f);
if(feof(f))break;
roll_number_string[str_length(roll_number_string)-1]='\0';
fgets(name,22,f);
fgets(gender,8,f);
if(str2int(roll_number_string)==roll_number)
{
fclose(f);
printf("That roll number exist\n");
return;
}
}// end infinite loop
fclose(f);
}
accept_string_input("Enter name: ",m_name,21);
str_trim(m_name);
namelen=str_length(m_name);
if(namelen<=0)
{
printf("Name Required!!\n");
return;
}
choice=accept_int_input("1.Male\n 2.Female\n");
if(choice!=1 && choice!=2)
{
printf("invalid gender!!\n");
return;
}
else if(choice==1)str_copy(gender,"Male");
else if(choice==2)str_copy(gender,"Female");

save=accept_char_input("Save(Y/N): ");
if(save!='Y' && save!='y'){
printf("student not added!!!\n");
return;
}
sprintf(m_roll_number_string,"%d",roll_number);
f=fopen(class_file(class),"a");
fputs(m_roll_number_string,f);
fputc('\n',f);
fputs(m_name,f);
fputc('\n',f);
fputs(gender,f);
fputc('\n',f);
fclose(f);
printf("Student Added!!\n");
}

void edit_student(int class)
{
FILE *f,*f2;
int roll_number;
char roll_number_string[21];
char name[21];
char v_roll_number_string[22];
char v_name[22];
char v_gender[8];
char gender[7];
char edit;
char update;
char m;
int i;
int namelen;
int found;
int choice;

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
fgets(v_roll_number_string,22,f);
if(feof(f))break;
v_roll_number_string[str_length(v_roll_number_string)-1]='\0';
fgets(v_name,22,f);
v_roll_number_string[str_length(v_name)-1]='\0';
fgets(v_gender,8,f);
v_gender[str_length(v_gender)-1]='\0';
if(str2int(v_roll_number_string)==roll_number)
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
printf("Name : %s \nGender: %s\n",v_name,v_gender);
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
choice=accept_int_input("1.Male\n2.Female\n");
if(choice!=1 && choice!=2)
{
printf("invalid gender\n");
return;
}
else if(choice==1)str_copy(gender,"Male");
else if(choice==2)str_copy(gender,"Female");
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
fgets(v_roll_number_string,22,f);
if(feof(f))break;
v_roll_number_string[str_length(v_roll_number_string)-1]='\0';
fgets(v_name,22,f);
v_name[str_length(v_name)-1]='\0';
fgets(v_gender,8,f);
v_gender[str_length(v_gender)-1]='\0';
if(str2int(v_roll_number_string)!=roll_number)
{
fputs(v_roll_number_string,f2);
fputc('\n',f2);
fputs(v_name,f2);
fputc('\n',f2);
fputs(v_gender,f2);
fputc('\n',f2);
}
else
{
fputs(roll_number_string,f2);
fputc('\n',f2);
fputs(name,f2);
fputc('\n',f2);
fputs(gender,f2);
fputc('\n',f2);
}
}
fclose(f);
fclose(f2);
f=fopen(class_file(class),"w");
f2=fopen(TMP,"r");
while(1)
{
fgets(v_roll_number_string,22,f2);
if(feof(f2))break;
fgets(v_name,22,f2);
fgets(v_gender,8,f2);
fputs(v_roll_number_string,f);
fputs(v_name,f);
fputs(v_gender,f);
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
char v_roll_number_string[22];
char v_name[22];
char v_gender[8];
char gender[7];
char edit;
char update;
char m;
int i;
int namelen;
int found;
int choice;

printf("--------------------------------------------\n");
printf("           Student (delete Module)            \n");
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
fgets(v_roll_number_string,22,f);
if(feof(f))break;
v_roll_number_string[str_length(v_roll_number_string)-1]='\0';
fgets(v_name,22,f);
v_roll_number_string[str_length(v_name)-1]='\0';
fgets(v_gender,8,f);
v_gender[str_length(v_gender)-1]='\0';
if(str2int(v_roll_number_string)==roll_number)
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
printf("Name : %s \nGender: %s\n",v_name,v_gender);
printf("------------------------------\n");
update=accept_char_input("Delete(Y/N):  ");
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
fgets(v_roll_number_string,22,f);
if(feof(f))break;
v_roll_number_string[str_length(v_roll_number_string)-1]='\0';
fgets(v_name,22,f);
v_name[str_length(v_name)-1]='\0';
fgets(v_gender,8,f);
v_gender[str_length(v_gender)-1]='\0';
if(str2int(v_roll_number_string)!=roll_number)
{
fputs(v_roll_number_string,f2);
fputc('\n',f2);
fputs(v_name,f2);
fputc('\n',f2);
fputs(v_gender,f2);
fputc('\n',f2);
}
}
fclose(f);
fclose(f2);
f=fopen(class_file(class),"w");
f2=fopen(TMP,"r");
while(1)
{
fgets(v_roll_number_string,22,f2);
if(feof(f2))break;
fgets(v_name,22,f2);
fgets(v_gender,8,f2);
fputs(v_roll_number_string,f);
fputs(v_name,f);
fputs(v_gender,f);
}
fclose(f);
fclose(f2);
f2=fopen(TMP,"w");
fclose(f2);
printf("strudent Delete!!\n");
}

void search_student(int class)
{
FILE *f;
int roll_number;
char roll_number_string[21];
char name[21];
char v_roll_number_string[22];
char v_name[22];
char v_gender[8];
char gender[7];
char edit;
char update;
char m;
int i;
int namelen;
int found;
int choice;

printf("--------------------------------------------\n");
printf("           Student (Search Module)            \n");
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
fgets(v_roll_number_string,22,f);
if(feof(f))break;
v_roll_number_string[str_length(v_roll_number_string)-1]='\0';
fgets(v_name,22,f);
v_roll_number_string[str_length(v_name)-1]='\0';
fgets(v_gender,8,f);
v_gender[str_length(v_gender)-1]='\0';
if(str2int(v_roll_number_string)==roll_number)
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
printf("Name : %s \nGender: %s\n",v_name,v_gender);
printf("------------------------------\n");
}

void display_list_of_student(int class)
{
FILE *f;
int roll_number;
char roll_number_string[21];
char name[21];
char v_roll_number_string[22];
char v_name[22];
char v_gender[8];
char gender[7];
char edit;
char update;
char m;
int i;
int namelen;
int page_size;
int header;
int sno; 

printf("--------------------------------------------\n");
printf("           Student (LIst Module)            \n");
printf("--------------------------------------------\n");

f=fopen(class_file(class),"r");
if(f==NULL)
{
printf("That roll number does not exist\n");
return;
}
sno=0;
page_size=5;
header=TRUE;
while(1)
{
fgets(v_roll_number_string,22,f);
if(feof(f))break;
v_roll_number_string[str_length(v_roll_number_string)-1]='\0';
fgets(v_name,22,f);
v_name[str_length(v_name)-1]='\0';
fgets(v_gender,8,f);
v_gender[str_length(v_gender)-1]='\0';
if(header==TRUE)
{
printf("----------------------------------------------\n");
printf(" SNO    Roll No.       Name             Gender\n");
printf("----------------------------------------------\n");
header=FALSE;
}
sno++;
printf(" %-5d   %-10s    %-15s      %-2s   \n",sno,v_roll_number_string,v_name,v_gender);
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











