#include<stdio.h>
#include<conio.h>
#include<alloc.h>
struct node
{
struct node *prev;
int info;
struct node *next;
};
struct node * addAtEmpty(int data)
{
struct node *tmp;
tmp=(struct node *)malloc(sizeof(struct node));
tmp->info=data;
tmp->next=tmp->prev=NULL;
return tmp;
}
struct node * addAtEnd(struct node *start,int data)
{
struct node *p,*tmp;
if(start==NULL)
{
printf("First create the list and then try\n");
return start;
}
p=(struct node *)malloc(sizeof(struct node));
p->info=data;
tmp=start;
while(tmp->next!=NULL)
tmp=tmp->next;
p->prev=tmp;
p->next=NULL;
tmp->next=p;
return start;
}




struct node * createList(struct node *start)
{
int n=0,data=0,i;
if(start!=NULL)
{
printf("List is already Created\n");
return start;
}
printf("Enter the initial size of list");
scanf("%d",&n);
if(n<=0)
return start;
printf("Enter data");
scanf("%d",&data);
start=addAtEmpty(data);
for(i=2;i<=n;i++)
{
printf("Enter data");
scanf("%d",&data);
start=addAtEnd(start,data);
}
return start;
}
void display(struct node *start)
{
struct node *p;
if(start==NULL)
{
printf("List is empty\n");
return;
}
p=start;
while(p!=NULL)
{
printf("%d\t",p->info);
p=p->next;
}
printf("\n");

}
int getPosition(struct node *start,int data)
{
struct node *p;
int pos=0;
if(start==NULL)
return -1;
p=start;
do
{
++pos;
if(p->info==data)
return pos;
p=p->next;
}
while(p!=NULL);
return -1;
}
struct node *insertAfter(struct node *start,int data,int item)
{
struct node *p,*tmp;
if(start==NULL)
{
printf("List is empty\n");
return start;
}
p=start;
tmp=(struct node *)malloc(sizeof(struct node));
tmp->info=data;
while(p!=NULL)
{
if(p->info==item)
{
tmp->next=p->next;
tmp->prev=p;
if(p->next!=NULL)
p->next->prev=tmp;
p->next=tmp;
return start;
}
p=p->next;
}




printf("Not avilable\n");
return start;
}


struct node *deleteLast(struct node *start)
{
struct node *p;
if(start==NULL)
{
printf("LList is empty");
return start;
}
p=start;
while(p->next!=NULL)
p=p->next;
if(p->prev==NULL)
{
free(p);
return NULL;
}
p->prev->next=NULL;
free(p);
return start;





}


void main()
{
int choice;
int data=0;
int item=0;
int pos=0;
struct node *start=NULL;
clrscr();
while(1)
    {
	printf("\t\tWelcome to the control panel of doubly linked list\n");
	printf("------------------------------------------------------------------------------\n");
	printf("  1.  Create\n");
	printf("  2.  Display\n");
	printf("  3.  Add at end\n");
	printf("  4.  Delete Last\n");
	printf("  5.  insert at position\n");
	printf("  6.  delete all\n");
	printf("  7.  delete at pos\n");
	printf("  8.  delete after\n");
	printf("  9.  Exit\n");
	printf("  10. Search\n");
	printf("  11. Insert After");
	printf("Enter your choice");
	scanf("%d",&choice);
	clrscr();
	switch(choice)
	{
	case 4:
		start=deleteLast(start);
		break;

	case 11:
		printf("Enter data whom after you want to insert data");
		scanf("%d",&item);
		printf("Enter data");
		scanf("%d",&data);
		start=insertAfter(start,data,item);
		break;


	case 10:
		printf("Enter data");
		scanf("%d",&data);
		pos=getPosition(start,data);
		if(pos==-1)
		printf("Element not avilable\n");
		else
		printf("Available at pos %d\n",pos);
		break;

	case 9:
		exit(1);

	case 1:
	       start =	createList(start);
	       break;

	case 2:
		display(start);
		break;
	case 3:
		printf("Enter the data");
		scanf("%d",&data);
		start=addAtEnd(start,data);
		break;

	}




}}