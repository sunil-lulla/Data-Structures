#include<stdio.h>
#include<conio.h>
#include<alloc.h>
struct node
{
int data;
struct node *next;
};
void addAtPos(struct node * start,int pos,int data)
{
int j=1;
struct node *p,*temp;
p=start;
for(;p->next!=NULL&&j<pos;)
{
p=p->next;
j++;
}
if(j<pos)
{
printf("Position naot avilable\n");
return;
}
temp=(struct node *)malloc(sizeof(struct node));
temp->data=data;
temp->next=p->next;
p->next=temp;
}
//search()
int search(struct node *start,int item)
{
int pos=0;
struct node *p;
p=start;
while(p!=NULL)
{
++pos;
if(p->data==item)
  return pos;

p=p->next;
}
return -1;
}
//display()
void display(struct node * start)
{
struct node *temp;
temp=start;
if(temp==NULL)
{
printf("List is empty\n");
return;
}
while(temp!=NULL)
{
printf("%d\n",temp->data);
temp=temp->next;
}
}
//adding data at the last
void addAtEnd(struct node * start,int data)
{
struct node *temp,*p;
p=start;
if(start==NULL)
{
printf("List is not created first create then try...\n");
return;
}
temp=(struct node *)malloc(sizeof(struct node));
temp->data=data;
temp->next=NULL;
while(p->next!=NULL)
p=p->next;
p->next=temp;
}
//creating list
struct node * createList(struct node * start)
{
struct node *temp;
int n=0,data,i=0;
if(start!=NULL)
{
printf("You have already created the list\n");
return start;
}
printf("Enter the no data u want to add\n");
scanf("%d",&n);
if(n<=0)
return NULL;
printf("Enter data");
scanf("%d",&data);
temp=(struct node *)malloc(sizeof(struct node));
temp->data=data;
temp->next=NULL;
start=temp;
for(i=2;i<=n;i++)
{
printf("Enter data");
scanf("%d",&data);
addAtEnd(start,data);
}
return start;
}
void main()
{
struct node *start=NULL;
int choice=0,data=0,i=0;
clrscr();
while(1)
{
printf("1. Create List\n");
printf("2. Insert data\n");
printf("3. Insert after\n");
printf("4. Insert Before\n");
printf("5. Display\n");
printf("6. Exit\n");
printf("7. Search\n");
printf("8. Insert At\n");

printf("enter ur choice");
scanf("%d",&choice);
clrscr();
switch(choice)
{
case 1:
	//create
	start=createList(start);
	break;
case 2:
	printf("Enter Data");
	scanf("%d",&data);
	addAtEnd(start,data);
	break;

case 3:
	//INSERT AFTER CODE GOES HERE
	printf("insert the data whom after u want to add");
	scanf("%d",&data);
	i=search(start,data);
	if(i==-1)
	{
		printf("The Given element is not avilable in the list");
		break;
	}
	printf("insert the data u want to addd");
	scanf("%d",&data);
	addAtPos(start,i,data);
	break;



case 5:
	//display
	display(start);
	break;

case 6:
	exit(0);

case  7:
		//SEARCH CODE GOES HERE
		printf("Enter data to  be search");
		scanf("%d",&data);
		i=search(start,data);
		if(i==-1)
		{
		printf("elemnet not avilable in the list");
		break;
		}
		printf("element found at %d position",i);
		break;

		default:
		printf("Invalid option");
}
getch();
}
}