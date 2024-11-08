#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	char number[50];
	char mail[40];
	char name[30];
	struct node *next,*prev;
}*head,*last,*ptr;

void menu();
void display();
void create();
void sort();
int update();
void search();
int searchbyname();
int searchbynumber();
int searchbymail();
int deletecontact();

void main()
{
	char name[10],ans;
	int choice;
	printf("**************                                PHONE BOOK                          ********************");
	printf("\n\nWHAT IS YOUR NAME?\n");
	fflush(stdin);
	gets(name);
	printf("\n\n!!!!!!!!!!!!!!!!!!!!!!!   WELCOME %s   !!!!!!!!!!!!!!!!!!!!!",name);
	printf("\n\n\nLET'S CREATE OUR PHONEBOOK %s  \n\n",name);
	sleep(3);
	do
	{
		menu();
		printf("\n\nDO YOU WANT TO GO TO MAIN MENU?[y/n]:");
		fflush(stdin);
		scanf("%c",&ans);
	}while(ans=='y');
}


void menu()
{
	char name[20];
	int choice;
	system("cls");
	printf("**************                                PHONE BOOK                          ********************");
	printf("\n\n\n\n1) DISPLAY YOUR PHONE BOOK\n2) CREATE NEW CONTACT\n3) UPDATE DETAILS ON EXISTING CONTACT\n4) SEARCH\n5) DELETE CONTACT\n");
	printf("\nENTER YOUR CHOICE:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:display();
		       break;
		case 2:create();
		       sort();
			   break;
		case 3:update();
			   break;
		case 4:search();
			   break;
		case 5:deletecontact();
			   break;
		default:printf("\nNO PROPER INPUT GIVEN..\n");
	}
}


void display()
{
	system("cls");
	printf("**************                                PHONE BOOK                          ********************");
	if(head==NULL)
	{
		printf("\n\nNO CONTACTS IN PHONEBOOK!!");
	}
	ptr=head;
	while(ptr!=NULL)
	{
		printf("\n\nNAME  ::\t%s",ptr->name);
		printf("\nNUMBER::\t+91-%s",ptr->number);
		printf("\nE-MAIL::\t%s",ptr->mail);
		ptr=ptr->next;
	}
}


void create()
{
	system("cls");
	struct node *temp,*last;
	char name[30],number[50],mail[40],ans;
	do
	{
		system("cls");
		printf("**************                                CREATE CONTACT                          ********************");
		printf("\n\nENTER NAME      :");
		fflush(stdin);
		gets(name);
		printf("ENTER NUMBER    :");
		fflush(stdin);
		gets(number);
		while(strlen(number)!=10)
		{
			printf("ENTER VALID NUMBER  :");
			fflush(stdin);
			gets(number);
		}
		printf("ENTER E-MAIL    :");
		fflush(stdin);
		gets(mail);
		temp=(struct node *)malloc(sizeof(struct node));
		if(head==NULL)
		{
			head=temp;
			strcpy(temp->name,name);
			strcpy(temp->number,number);
			strcpy(temp->mail,mail);
			head->prev=NULL;
			head->next=NULL;
			last=head;
    	}
		else
		{
			ptr=head;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=temp;
			strcpy(temp->name,name);
			strcpy(temp->number,number);
			strcpy(temp->mail,mail);
			temp->prev=last;
			temp->next=NULL;
			last->next=temp;
			last=temp;
		}
		void sort();
		printf("\nDO YOU WANT TO CONTINUE INSERTING A NEW CONTACT?[y/n]:");
		fflush(stdin);
		scanf("%c",&ans);
	}while(ans=='y');
}


void sort()
{
	struct node *i,*j;
	int temp;
	char n[30],num[50],m[40];
	for(i=head;i->next!=NULL;i=i->next)
	{
		for(j=i->next;j!=NULL;j=j->next)
		{
			temp=strcmp(i->name,j->name);
			if(temp>0)
			{
				strcpy(n,i->name);
				strcpy(i->name,j->name);
				strcpy(j->name,n);
				strcpy(num,i->number);
				strcpy(i->number,j->number);
				strcpy(j->number,num);
				strcpy(m,i->mail);
				strcpy(i->mail,j->mail);
				strcpy(j->mail,m);
            }
        }
    }
}


int update()
{
	char name[30],number[50],mail[40];
	char a[20],ans;
	int c;
	ptr=head;
	system("cls");
	display();
	ptr=head;
	if(ptr==NULL)
	{
		printf("\n\nNO CONTACTS IN PHONEBOOK!!");
		return 0;
	}
	printf("\n\nENTER THE NAME OF PERSON WHOSE DETAILS YOU WANT TO UPDATE:");
	fflush(stdin);
	gets(a);
	while(ptr!=NULL)
	{
		if(strcmp(a,ptr->name)==0)
		{
			do
			{
				printf("\nWHAT DO YOU WANT TO UPDATE?\n1.NAME\n2.PHONE NUMBER\n3.E-MAIL");
				printf("\nENTER YOUR CHOICE:");
				scanf("%d",&c);
				switch(c)
				{
					case 1:printf("\nENTER NEW-NAME:");
					       fflush(stdin);
					       gets(name);
					       strcpy(ptr->name,name);
					       sort();
						   break;
					case 2:printf("\nENTER NEW PHONE-NUMBER:");
					       fflush(stdin);
					       gets(number);
						   strcpy(ptr->number,number);
						   while(strlen(ptr->number)!=10)
						   {
						   	printf("\nENTER VALID NUMBER  :");
							fflush(stdin);
							gets(number);
							strcpy(ptr->number,number);
						   }
						   break;
					case 3:printf("\nENTER NEW E-MAIL:");
					       fflush(stdin);
					       gets(mail);
						   strcpy(ptr->mail,mail);
						   break;
				}
				printf("\nCONTACT UPDATED SUCCESSFULLY.");
				sleep(2);
				printf("\r                             ");
				printf("\nDO YOU WANT TO CONTINUE UPDATING?[y/n]:");
				fflush(stdin);
				scanf("%c",&ans);
				if(ans=='n')
				{
					return 0;
				}
			}while(ans=='y');
        }
		ptr=ptr->next;
	}
	if(ptr==NULL)
	{
		printf("\n\nSEARCHED CONTACT NOT FOUND IN PHONEBOOK!!");
	}
}


void search()
{
	char ans,name[30],number[50],mail[40];
	int a;
	do
	{
		system("cls");
		printf("**************                                SEARCH CONTACT                          ********************");
		printf("\n\n1.SEARCH BY NAME\n2.SEARCH BY NUMBER\n3.SEARCH BY E-MAIL");
		printf("\nENTER YOUR CHOICE:");
		scanf("%d",&a);
		switch(a)
		{
			case 1:searchbyname();
				   break;
			case 2:searchbynumber();
				   break;
			case 3:searchbymail();
				   break;
			default:printf("\nNO PROPER INPUT GIVEN.....\n");
		}
		printf("\n\nDO YOU WANT TO CONTINUE SEARCHING?[y/n]:");
		fflush(stdin);
		scanf("%c",&ans);
	}while(ans=='y');
}


int searchbyname()
{
	char name[30];
	ptr=head;
	if(ptr==NULL)
	{
		printf("\n\nNO CONTACTS IN PHONEBOOK!!");
		return 0;
	}
	printf("\nENTER THE NAME TO BE SEARCHED:");
	fflush(stdin);
	gets(name);
	while(ptr!=NULL)
	{
		if(strcmp(name,ptr->name)==0)
		{
			printf("NAME FOUND");
			sleep(2);
			printf("\r          ");
			printf("\nCONTACT DETAILS ARE BELOW:\n");
			printf("\n\nNAME  ::\t%s",ptr->name);
			printf("\nNUMBER::\t+91-%s",ptr->number);
			printf("\nE-MAIL::\t%s",ptr->mail);
			break;
		}
		ptr=ptr->next;
	}
	if(ptr==NULL)
	{
		printf("\n\nSEARCHED CONTACT NOT FOUND IN PHONEBOOK!!");
	}
}


int searchbynumber()
{
	char number[50];
	ptr=head;
	if(ptr==NULL)
	{
		printf("\n\nNO CONTACTS IN PHONEBOOK!!");
		return 0;
	}
	printf("\nENTER THE NUMBER TO BE SEARCHED:");
	fflush(stdin);
	gets(number);
	while(ptr!=NULL)
	{
		if(strcmp(number,ptr->number)==0)
		{
			printf("NUMBER FOUND\n");
			printf("CONTACT DETAILS ARE BELOW:\n");
			printf("\n\nNAME  ::\t%s",ptr->name);
			printf("\nNUMBER::\t+91-%s",ptr->number);
			printf("\nE-MAIL::\t%s",ptr->mail);
			break;
		}
		ptr=ptr->next;
	}
	if(ptr==NULL)
	{
		printf("\n\nSEARCHED CONTACT NOT FOUND IN PHONEBOOK!!");
	}
}


int searchbymail()
{
	char mail[40];
	ptr=head;
	if(ptr==NULL)
	{
		printf("\n\nNO CONTACTS IN PHONEBOOK!!");
		return 0;
	}
	printf("\nENTER THE E-MAIL TO BE SEARCHED\n");
	fflush(stdin);
	gets(mail);
	while(ptr!=NULL)
	{
		if(strcmp(mail,ptr->mail)==0)
		{
			printf("MAIL FOUND\n");
			printf("CONTACT DETAILS ARE BELOW:\n");
			printf("\n\nNAME  ::\t%s",ptr->name);
			printf("\nNUMBER::\t+91-%s",ptr->number);
			printf("\nE-MAIL::\t%s",ptr->mail);
			break;
		}
		ptr=ptr->next;
	}
	if(ptr==NULL)
	{
		printf("\n\nSEARCHED CONTACT NOT FOUND IN PHONEBOOK!!");
	}
}


int deletecontact()
{
	char name[30];
	int c=0;
	ptr=head;
	system("cls");
	printf("**************                                DELETE CONTACT                          ********************");
	if(ptr==NULL)
	{
		printf("\n\nNO CONTACTS IN PHONEBOOK!!");
		return 0;
	}
	printf("\n\nENTER THE NAME OF CONTACT WHICH YOU WANT TO DELETE:");
	fflush(stdin);
	gets(name);
	while(ptr!=NULL)
	{
		if(strcmp(name,ptr->name)==0)
		{
			c=1;
			break;
		}
		else
		{
			c=2;
		}
		ptr=ptr->next;
	}
	if(c==1 && ptr!=head && ptr->next!=NULL)
	{
		ptr->prev->next=ptr->next;
		ptr->next->prev=ptr->prev;
		free(ptr);
		printf("\nYOUR CONTACT IS SUCCESSFULLY DELETED.");
		sleep(2);
		printf("\r                                     ");
	}
	else if(ptr==head)
	{
		if(head->next==NULL)
		{
			head=NULL;
		}
		else
		{
			head=head->next;
			head->prev=NULL;
		}
		free(ptr);
		printf("\nYOUR CONTACT IS SUCCESSFULLY DELETED.");
		sleep(2);
		printf("\r                                     ");
	}
	else if(ptr->next==NULL)
	{
		ptr->prev->next=NULL;
		ptr->prev=NULL;
		free(ptr);
		printf("\nYOUR CONTACT IS SUCCESSFULLY DELETED.");
		sleep(2);
		printf("\r                                     ");
	}
	else if(c==2)
	{
		printf("\nTHE NAME YOU ENTERED IS NOT IN THE PHONEBOOK!!");
	}
}
