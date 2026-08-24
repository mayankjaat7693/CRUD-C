#include<time.h>
#include<stdio.h>
#include<string.h>
#define USER_FILE "user.data"
#define BOOK_FILE "books.data"
#define RECORDS "records.data"
#define ID 231069
#define PASS 588254

void clear_stdin_buffer()
{
while(getchar()!='\n');
}

typedef struct date
{
int day;
int month;
int year;
}date;

typedef struct user
{
int id;
char name[101];
char gender;
}user;

typedef struct books
{
int book_id;
char name[101];
char author[101];
char publisher[101];
char category[101];
int year;
float price;
int quantity;
int avaibility;
}books;

typedef struct records
{
char book_name[101];
int book_id;
int user_id;
int issue_check;
int return_check;
date issuedate;
date returndate;
}records;

void search_book_by_category();
void search_book_by_id();
void search_book_by_name();
void search_book_by_author();
void search_book_by_publisher();
void issue_book();
void return_book();
void display_records();
void list_of_books();
void login_admin();
void register_user();
void lowercase();
void getcurrentdate();

int main()
{
int choice;
do
{
printf("1.Search book by category\n");
printf("2.Search book by id\n");
printf("3.Search book by name\n");
printf("4.Search book by author name\n");
printf("5.Search book by publisher name\n");
printf("6.Issue book\n");
printf("7.Return book\n");
printf("8.Display records\n");
printf("9.List of books\n");
printf("10.Login admin\n");
printf("11.Register User\n");
printf("12.Exit\n");
printf("Enter your choice: ");
scanf("%d",&choice);
clear_stdin_buffer();
if(choice==1)search_book_by_category();
else if(choice==2)search_book_by_id();
else if(choice==3)search_book_by_name();
else if(choice==4)search_book_by_author();
else if(choice==5)search_book_by_publisher();
else if(choice==6)issue_book();
else if(choice==7)return_book();
else if(choice==8)display_records();
else if(choice==9)list_of_books();
else if(choice==10)login_admin();
else if(choice==11)register_user();
else if(choice<=0 || choice>12)
{
printf("Invalid choice!!!!\n");
continue;
}
}while(choice!=12);
printf("!!!!!THANK YOU!!!!!\n");
return 0;
}

void search_book_by_category()
{
books s,t;
FILE *f;
int header;
int sno;
int page_size;
int found;
int i;

printf("-------------------------------------\n");
printf("             BOOKs Category          \n");
printf("-------------------------------------\n");
printf("Enter category: ");
scanf("%[^\n]s",s.category);
clear_stdin_buffer();
lowercase(s.category);
f=fopen(BOOK_FILE,"rb");
if(f==NULL)
{
printf("invailid category!!!!\n");
return;
}
found=0;
sno=0;
page_size=5;
header=1;
while(1)
{
fread(&t,sizeof(books),1,f);
if(feof(f))break;
lowercase(t.category);
for(i=0;s.category[i]!='\0' && t.category[i]!='\0';i++);
if(s.category[i]==t.category[i])
{
found=1;
if(header==1)
{
printf("----------------------------------------------------------------------------\n");
printf("SNO  ID    BOOK NAME      AUTHOR           PUBLISHER       YEAR   AVAIBILITY \n");
printf("----------------------------------------------------------------------------\n");
header=0;
}
sno++;
printf("%-4d %-4d %-15s %-15s  %-15s  %-10d  %-5d\n",sno,t.book_id,t.name,t.author,t.publisher,t.year,t.avaibility);
if(sno%page_size==0)
{
printf("----------------------------------------------------------------------------\n");
header=1;
}
}
}
fclose(f);
if(sno%page_size!=0)
{
printf("----------------------------------------------------------------------------\n");
}
if(found==0)printf("categary does not exist\n");
}

void search_book_by_id()
{
books s,t;
FILE *f;
int header;
int sno;
int page_size;
int found;

printf("-------------------------------------\n");
printf("                 BOOKs ID            \n");
printf("-------------------------------------\n");
printf("Enter ID: ");
scanf("%d",&s.book_id);
clear_stdin_buffer();
f=fopen(BOOK_FILE,"rb");
if(f==NULL)
{
printf("invailid ID!!!!\n");
return;
}
found=0;
sno=0;
page_size=5;
header=1;
while(1)
{
fread(&t,sizeof(books),1,f);
if(feof(f))break;
if(s.book_id==t.book_id)
{
found=1;
if(header==1)
{
printf("----------------------------------------------------------------------------\n");
printf("SNO  ID    BOOK NAME      AUTHOR           PUBLISHER       YEAR   AVAIBILITY \n");
printf("----------------------------------------------------------------------------\n");
header=0;
}
sno++;
printf("%-4d %-4d %-15s %-15s  %-15s  %-10d  %-5d\n",sno,t.book_id,t.name,t.author,t.publisher,t.year,t.avaibility);
if(sno%page_size==0)
{
printf("----------------------------------------------------------------------------\n");
header=1;
}
}
}
fclose(f);
if(sno%page_size!=0)
{
printf("----------------------------------------------------------------------------\n");
}
if(found==0)printf("book id does not exist\n");
}

void search_book_by_name()
{
books s,t;
FILE *f;
int header;
int sno;
int found;
int page_size;
int i;

printf("-------------------------------------\n");
printf("               BOOKs Name            \n");
printf("-------------------------------------\n");
printf("Enter book name: ");
scanf("%[^\n]s",s.name);
clear_stdin_buffer();
lowercase(s.name);
f=fopen(BOOK_FILE,"rb");
if(f==NULL)
{
printf("invailid book name!!!\n");
return;
}
found=0;
sno=0;
page_size=5;
header=1;
while(1)
{
fread(&t,sizeof(books),1,f);
if(feof(f))break;
lowercase(t.name);
for(i=0;s.name[i]!='\0' && t.name[i]!='\0';i++);
if(s.name[i]==t.name[i])
{
found=1;
if(header==1)
{
printf("----------------------------------------------------------------------------\n");
printf("SNO  ID    CATEGORY        AUTHOR           PUBLISHER       YEAR   AVAIBILITY \n");
printf("----------------------------------------------------------------------------\n");
header=0;
}
sno++;
printf("%-4d %-4d %-15s %-15s  %-15s  %-10d  %-5d\n",sno,t.book_id,t.category,t.author,t.publisher,t.year,t.avaibility);
if(sno%page_size==0)
{
printf("----------------------------------------------------------------------------\n");
header=1;
}
}
}
fclose(f);
if(sno%page_size!=0)
{
printf("----------------------------------------------------------------------------\n");
}
if(found==0)printf("book name does not exist\n");
}

void search_book_by_author()
{
books s,t;
FILE *f;
int header;
int sno;
int page_size;
int found;
int i;

printf("-------------------------------------\n");
printf("             BOOKs Author          \n");
printf("-------------------------------------\n");
printf("Enter author: ");
scanf("%[^\n]s",s.author);
clear_stdin_buffer();
lowercase(s.author);
f=fopen(BOOK_FILE,"rb");
if(f==NULL)
{
printf("invailid author!!!!\n");
return;
}
found=0;
sno=0;
page_size=5;
header=1;
while(1)
{
fread(&t,sizeof(books),1,f);
if(feof(f))break;
lowercase(t.author);
for(i=0;s.author[i]!='\0' && t.author[i]!='\0';i++);
if(s.author[i]==t.author[i])
{
found=1;
if(header==1)
{
printf("----------------------------------------------------------------------------\n");
printf("SNO  ID    BOOK NAME      CATEGORY           PUBLISHER       YEAR   AVAIBILITY \n");
printf("----------------------------------------------------------------------------\n");
header=0;
}
sno++;
printf("%-4d %-4d %-15s %-15s  %-15s  %-10d  %-4d\n",sno,t.book_id,t.name,t.category,t.publisher,t.year,t.avaibility);
if(sno%page_size==0)
{
printf("----------------------------------------------------------------------------\n");
header=1;
}
}
}
fclose(f);
if(sno%page_size!=0)
{
printf("----------------------------------------------------------------------------\n");
}
if(found==0)printf("book author does not exist\n");
}

void search_book_by_publisher()
{
books s,t;
FILE *f;
int header;
int sno;
int page_size;
int found;
int i;

printf("-------------------------------------\n");
printf("             BOOKs Publisher         \n");
printf("-------------------------------------\n");
printf("Enter publisher: ");
scanf("%[^\n]s",s.publisher);
clear_stdin_buffer();
lowercase(s.publisher);
f=fopen(BOOK_FILE,"rb");
if(f==NULL)
{
printf("invailid publisher!!!!\n");
return;
}
found=0;
sno=0;
page_size=5;
header=1;
while(1)
{
fread(&t,sizeof(books),1,f);
if(feof(f))break;
lowercase(t.publisher);
for(i=0;s.publisher[i]!='\0' && t.publisher[i]!='\0';i++);
if(s.publisher[i]==t.publisher[i])
{
found=1;
if(header==1)
{
printf("----------------------------------------------------------------------------\n");
printf("SNO  ID    BOOK NAME      AUTHOR           CATEGORY        YEAR   AVAIBILITY \n");
printf("----------------------------------------------------------------------------\n");
header=0;
}
sno++;
printf("%-4d %-4d %-15s %-15s  %-15s  %-10d  %-4d\n",sno,t.book_id,t.name,t.author,t.category,t.year,t.avaibility);
if(sno%page_size==0)
{
printf("----------------------------------------------------------------------------\n");
header=1;
}
}
}
fclose(f);
if(sno%page_size!=0)
{
printf("----------------------------------------------------------------------------\n");
}
if(found==0)printf("book publisher does not exist\n");
}

void issue_book()
{
FILE *f,*f2,*f3;
books s,i;
user t,j;
records issue,check;
int found;
char yn;
int k;
int sno,header,pagesize;

printf("Enter your ID: ");
scanf("%d",&t.id);
clear_stdin_buffer();
f=fopen(USER_FILE,"rb");
if(f==NULL)
{
printf("user not exist!!!\nPlease Register First\n");
return;
}
found=0;
while(1)
{
fread(&j,sizeof(user),1,f);
if(feof(f))break;
if(t.id==j.id)
{
found=1;
break;
}
}
fclose(f);
if(found==0)
{
printf("user not exist!!!\nPlease Register First\n");
return;
}
printf("Enter book id: ");
scanf("%d",&s.book_id);
clear_stdin_buffer();
f=fopen(BOOK_FILE,"rb");
if(f==NULL)
{
printf("Book does not avaible!!!\n");
return;
}
found=0;
while(1)
{
fread(&i,sizeof(books),1,f);
if(feof(f))break;
if(s.book_id==i.book_id)
{
for(k=0;s.name[k]!='\0' && i.name[k]!='\0';k++)s.name[k]=i.name[k];
s.name[k]='\0';
found=1;
break;
}
}
fclose(f);
if(found==0)
{
printf("Invalid book id!!!!\nPlease check book ID first\n");
return;
}

f2=fopen(RECORDS,"rb");
if(f2!=NULL)
{
while(1)
{
fread(&issue,sizeof(records),1,f2);
if(feof(f2))break;
if(issue.user_id==t.id && issue.issue_check==1)
{
printf("book name: %s    book id: %d   user id: %d    issue date: %d/%d/%d\n",issue.book_name,issue.book_id,issue.user_id,issue.issuedate.day,issue.issuedate.month,issue.issuedate.year);  
printf("You allready issue one Book!!!!\nreturn previous book first,then issue this book\n");
return;
}
}
fclose(f2);
}
printf("Issue Book(Y/N): ");
scanf("%c",&yn);
clear_stdin_buffer();
if(yn!='y' && yn!='Y')
{
printf("Book not issue!!!\nTHANKYOU!!!\n");
return;
}
f=fopen(BOOK_FILE,"rb");
while(1)
{
fread(&i,sizeof(books),1,f);
if(feof(f))break;
if(s.book_id==i.book_id)
{
if(i.avaibility<=0)
{
printf("Book not in stock know!!!\n");
fclose(f);
return;
}
i.avaibility--;
issue.book_id=i.book_id;
strcpy(issue.book_name,i.name);
break;
}
}
fclose(f);
issue.user_id=t.id;
issue.issue_check=1;
issue.return_check=0;
getcurrentdate(&issue.issuedate);
f2=fopen(RECORDS,"ab");
fwrite(&issue,sizeof(records),1,f2);
fclose(f2);
f=fopen(BOOK_FILE,"rb");
f3=fopen("tmp.tmp","wb");
while(1)
{
fread(&s,sizeof(books),1,f);
if(feof(f))break;
if(s.book_id!=i.book_id)
{
fwrite(&s,sizeof(books),1,f3);
}
else 
{
fwrite(&i,sizeof(books),1,f3);
}
}
fclose(f);
fclose(f3);
f=fopen(BOOK_FILE,"wb");
f3=fopen("tmp.tmp","rb");
while(1)
{
fread(&s,sizeof(books),1,f3);
if(feof(f3))break;
fwrite(&s,sizeof(books),1,f);
}
fclose(f);
fclose(f3);
f=fopen("tmp.tmp","wb");
fclose(f);
header=1;
sno=0;
pagesize=5;
f=fopen(RECORDS,"rb");
while(1)
{
fread(&issue,sizeof(records),1,f);
if(feof(f))break;
if(t.id==issue.user_id)
{
if(header==1)
{
printf("===| same book id and user id enter for return time ===|\n");
printf("------------------------------------------------------------\n");
printf("SNO    Book name     book id    user id    issue date     \n");
printf("------------------------------------------------------------\n");
header=0;
}
sno++;
printf("%-4d  %-15s%-10d %-10d %02d/%02d/%04d\n",sno,issue.book_name,issue.book_id,issue.user_id,issue.issuedate.day,issue.issuedate.month,issue.issuedate.year); 
if(sno%pagesize==0)
{
printf("------------------------------------------------------------\n");
header=1;
}
}
}
fclose(f);
if(sno%pagesize!=0)
{
printf("------------------------------------------------------------\n");
}
}

void return_book()
{
FILE *f,*f2,*f3;
books s,a,i;
user t,j;
records issue,check,read;
int found;
char yn;
int k;

printf("Enter your ID: ");
scanf("%d",&t.id);
clear_stdin_buffer();
f=fopen(USER_FILE,"rb");
if(f==NULL)
{
printf("user not exist!!!\nPlease Register First\n");
return;
}
found=0;
while(1)
{
fread(&j,sizeof(user),1,f);
if(feof(f))break;
if(t.id==j.id)
{
found=1;
break;
}
}
fclose(f);
if(found==0)
{
printf("user not exist!!!\nPlease Register First\n");
return;
}
printf("Enter book id: ");
scanf("%d",&a.book_id);
clear_stdin_buffer();
f=fopen(BOOK_FILE,"rb");
if(f!=NULL)
{
while(1)
{
fread(&s,sizeof(books),1,f);
if(feof(f))break;
if(s.book_id==a.book_id)break;
}
fclose(f);
}

f2=fopen(RECORDS,"rb");
found=0;
if(f!=NULL)
{
while(1)
{
fread(&issue,sizeof(records),1,f2);
if(feof(f))break;
if(issue.user_id==t.id && issue.book_id==s.book_id && issue.issue_check==1)
{
found=1;
printf("book name: %s    book id: %d   user id: %d    issue date: %d/%d/%d\n",issue.book_name,issue.book_id,issue.user_id,issue.issuedate.day,issue.issuedate.month,issue.issuedate.year);
break;
}
}
fclose(f);
}
if(found==0)
{
printf("invalid Book id!!!!\n");
return;
}
printf("Return Book(Y/N): ");
scanf("%c",&yn);
clear_stdin_buffer();
if(yn!='y' && yn!='Y')
{
printf("Book not Return!!!\nOOOPPPPSSS!!!\n");

return;
}
issue.user_id=t.id;
issue.book_id=s.book_id;
for(k=0;issue.book_name[k]!='\0' && s.name[k]!='\0';k++)issue.book_name[k]=s.name[k];
issue.issue_check=0;
issue.return_check=1;
getcurrentdate(&issue.returndate);
f2=fopen(RECORDS,"ab");
fwrite(&issue,sizeof(records),1,f2);
fclose(f2);
f3=fopen(BOOK_FILE,"rb");
f=fopen("t.tmp","wb");
while(1)
{
fread(&i,sizeof(books),1,f3);
if(feof(f3))break;
if(s.book_id!=i.book_id)
{
fwrite(&i,sizeof(books),1,f);
}
else 
{
i.avaibility++;
fwrite(&i,sizeof(books),1,f);
}
}
fclose(f3);
fclose(f);
f3=fopen(BOOK_FILE,"wb");
f2=fopen("t.tmp","rb");
while(1)
{
fread(&i,sizeof(books),1,f2);
if(feof(f2))break;
fwrite(&i,sizeof(books),1,f3);
}

fclose(f3);
fclose(f2);
f=fopen("t.tmp","wb");
fclose(f);
f=fopen(RECORDS,"rb");
f2=fopen("tt.tmp","ab");
f3=fopen("tmp.tmp","ab");
while(1)
{
fread(&read,sizeof(records),1,f);
if(feof(f))break;
if(read.book_id!=s.book_id && read.user_id!=t.id)
{
fwrite(&read,sizeof(records),1,f2);
}
else
{
read.issue_check=0;
fwrite(&read,sizeof(records),1,f3);
}
}
fclose(f);
fclose(f2);
fclose(f3);
f=fopen(RECORDS,"wb");
f2=fopen("tt.tmp","rb");
f3=fopen("tmp.tmp","rb");
while(1)
{
fread(&read,sizeof(records),1,f2);
if(feof(f2))break;
fwrite(&read,sizeof(records),1,f);
}
while(1)
{
fread(&read,sizeof(records),1,f3);
if(feof(f3))break;
fwrite(&read,sizeof(records),1,f);
}
fclose(f);
fclose(f2);
fclose(f3);
f=fopen("tt.tmp","wb");
fclose(f);
f=fopen("tmp.tmp","wb");

fclose(f);
printf("Book returned!!!\n");
}

void display_records()
{
FILE *f,*f2;
int header,sno,pagesize;
records issue;
header=1;
pagesize=5;
sno=0;
f=fopen(RECORDS,"rb");
if(f==NULL)
{
printf("No Records\n");
return;
}
while(1)
{
fread(&issue,sizeof(records),1,f);
if(feof(f))break;
if(header==1)
{
printf("===|         RECORDS OF BOOK ISSUE AND RETURN    |===\n");
printf("--------------------------------------------------------\n");
printf("SNO  Book name   book id   user id   issue date     \n");
printf("--------------------------------------------------------\n");
header=0;
}
sno++;
printf("%-4d  %-10s      %-4d      %-4d        %02d/%02d/%04d\n",sno,issue.book_name,issue.book_id,issue.user_id,issue.issuedate.day,issue.issuedate.month,issue.issuedate.year);
if(sno%pagesize==0)
{
printf("--------------------------------------------------------\n");
header=1;
}
}
fclose(f);
}

void list_of_books()
{
books s,t;
FILE *f;
int header;
int sno;
int page_size;

printf("----------------------------------------------------------------------------------\n");
printf("                                    BOOKS LIST                                    \n");
printf("----------------------------------------------------------------------------------\n");
f=fopen(BOOK_FILE,"rb");
if(f==NULL)
{
printf("NO BOOKS\n");
return;
}
sno=0;
page_size=5;
header=1;
while(1)
{
fread(&t,sizeof(books),1,f);
if(feof(f))break;
if(header==1)
{
printf("-----------------------------------------------------------------------------------------------------\n");
printf("SNO BOOK ID   BOOK NAME       AUTHOR          CATEGORY        PUBLISHER  YEAR  QUANTITY  AVAIBLE     \n");
printf("-----------------------------------------------------------------------------------------------------\n");
header=0;
}
sno++;
printf("%-4d %-8d %-15s %-15s %-15s %-10s %-6d  %-8d %-1d\n",sno,t.book_id,t.name,t.author,t.category,t.publisher,t.year,t.quantity,t.avaibility);
if(sno%page_size==0)
{
printf("-------------------------------------------------------------------------------------------------------\n");
header=1;
}
}
fclose(f);
if(sno%page_size!=0)
{
printf("----------------------------------------------------------------------------------------------------\n");
}
}

void login_admin()
{
FILE *f,*f2;
books s,t;
int id_user;
int pass;
int choice;
int change;
char save;
int found;

printf("Enter a user id: ");
scanf("%d",&id_user);
clear_stdin_buffer();
if(ID!=id_user)
{
printf("Invailid user id!!!!\n");
return;
}
printf("Enter a password: ");
scanf("%d",&pass);
clear_stdin_buffer();
if(PASS!=pass)
{
printf("Invalid user pass!!!!\n");
return;
}

while(1)
{
printf("1.Add Book in library\n");
printf("2.Detele book\n");
printf("3.Exit\n");
printf("Enter your choice: ");
scanf("%d",&choice);
clear_stdin_buffer();
if(choice==1)
{
change=1;
break;
}else if(choice==2){
change=2;
break;
}else if(choice==3)return;
else printf("invalid choice!!!!\n");
}

if(change==1){
printf("Enter book id: ");
scanf("%d",&s.book_id);
clear_stdin_buffer();
printf("Enter book name: ");
scanf("%[^\n]s",s.name);
clear_stdin_buffer();
printf("Enter author: ");
scanf("%[^\n]s",s.author);
clear_stdin_buffer();
printf("Enter publisher: ");
scanf("%[^\n]s",s.publisher);
clear_stdin_buffer();
printf("Enter category: ");
scanf("%[^\n]s",s.category);
clear_stdin_buffer();
printf("Enter year: ");
scanf("%d",&s.year);
clear_stdin_buffer();
printf("Enter price: ");
scanf("%f",&s.price);
clear_stdin_buffer();
printf("Enter quantity: ");
scanf("%d",&s.quantity);
clear_stdin_buffer();
printf("Enter avaibility: ");
scanf("%d",&s.avaibility);
clear_stdin_buffer();

printf("Save(Y/N): ");
scanf("%c",&save);
clear_stdin_buffer();
if(save!='y' && save!='Y')
{
printf("Book not save!!\n");
return;
}
f=fopen(BOOK_FILE,"ab");

fwrite(&s,sizeof(books),1,f);
fclose(f);
printf("Book added successfull\n");
}
if(change==2)
{
printf("Enter book id: ");
scanf("%d",&s.book_id);
clear_stdin_buffer();

f=fopen(BOOK_FILE,"rb");
if(f==NULL)
{
printf("No books\n");
return;
}
found=0;
while(1)
{
fread(&t,sizeof(books),1,f);
if(feof(f))break;
if(t.book_id==s.book_id)
{
found=1;
break;
}
}
fclose(f);
if(found==0)
{
printf("book not found!!!\nInvalid book ID\n");
return;
}
printf("Delete book(Y/N): ");
scanf("%c",&save);
clear_stdin_buffer();
if(save!='y' && save!='Y')
{
printf("Book not deleted!!\n");
return;
}

f=fopen(BOOK_FILE,"rb");
f2=fopen("tt.tmp","wb");
while(1)
{
fread(&t,sizeof(books),1,f);
if(feof(f))break;
if(s.book_id!=t.book_id)
{
fwrite(&t,sizeof(books),1,f2);
}
}
fclose(f);
fclose(f2);
f=fopen(BOOK_FILE,"wb");
f2=fopen("tt.tmp","rb");
while(1)
{
fread(&t,sizeof(books),1,f2);
if(feof(f2))break;
fwrite(&t,sizeof(books),1,f);
}
fclose(f);
fclose(f2);
f=fopen("tt.tmp","wb");
fclose(f);
printf("Book Deleted!!!\n");
}
}


void register_user()
{
user t,s;
FILE *f;
int len;
char edit;

printf("---------------------------------------------\n");
printf("           Student Registration              \n");
printf("---------------------------------------------\n");

printf("Enter NEW ID: ");
scanf("%d",&s.id);
clear_stdin_buffer();
f=fopen(USER_FILE,"rb");
if(f!=NULL)
{
while(1)
{
fread(&t,sizeof(user),1,f);
if(feof(f))break;
if(t.id==s.id)
{
printf("This ID allocated to %s\n",t.name);
return;
}
}
fclose(f);
}
printf("Enter your name: ");
scanf("%[^\n]s",s.name);
clear_stdin_buffer();
printf("Enter gender(M/F): ");
scanf("%c",&s.gender);
clear_stdin_buffer();
len=strlen(s.name);
if(len<=1)
{
printf("name required\n");
return;
}
if(s.gender!='m' && s.gender!='M' && s.gender!='F' && s.gender!='f')
{
printf("invalid gender!!\n");
return;
}
if(s.gender=='m')s.gender='M';
if(s.gender=='f')s.gender='f';

printf("Save(Y/N): ");
scanf("%c",&edit);
clear_stdin_buffer();
if(edit!='y' && edit!='Y')
{
printf("User not register!!\n");
return;
}
f=fopen(USER_FILE,"ab");
fwrite(&s,sizeof(user),1,f);
fclose(f);
printf("Register Successfull!!!\nNow you go to for issue books\n");
}

void lowercase(char *ptr)
{
if(*ptr=='\0')return;
while(*ptr!='\0')
{
if(*ptr>=65 && *ptr<=90)*ptr=*ptr+32;
++ptr;
}
}

void getcurrentdate(struct date *d)
{
time_t t=time(NULL);
struct tm *today =localtime(&t);
d->day=today->tm_mday;
d->month=today->tm_mon+1;
d->year=today->tm_year+1900;
}

