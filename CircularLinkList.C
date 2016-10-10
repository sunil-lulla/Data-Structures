#include<stdio.h>
#include<CONIO.H>
#include<alloc.h>
struct node
{
int data;
struct node *next;
};





struct node * addAtEnd(struct node *last,int data)
{
struct node *p=NULL;
if(last==NULL)
{
printf("\nFirst create the list and then try..\n");
return last;
}
p=(struct node *)malloc(sizeof(struct node));
p->data=data;
p->next=last->next;
last->next=p;
last=p;
return last;

}
void display(struct node *last)
{
struct node *p=NULL;
if(last==NULL)
{
printf("List is empty..");
return;
}
p=last->next;
do
{
printf("%d ",p->data);
p=p->next;
}
while(p!=last->next);
printf("\n");






}
struct node *createList(struct node *last)
{
int n=0,data=0,i=0;
struct node *p=NULL;
if(last!=NULL)
{
printf("List is already Created\n");
return last;
}
printf("Enter the initial size of list");
scanf("%d",&n);
if(n<=0)
return last;
printf("Enter data");
scanf("%d",&data);
p=(struct node *)malloc(sizeof(struct node));
p->data=data;
p->next=p;
last=p;
for(i=2;i<=n;i++)
{
printf("Enter data");
scanf("%d",&data);
last=addAtEnd(last,data);
}
return last;
}
int getSize(struct node *last)
{
struct node *p;
int size=0;
if(last==NULL)
return size;
p=last->next;
do
{

size++;
p=p->next;
}while(p!=last->next);
return size;
}
int search(struct node *last,int data)
{
int pos=1;
struct node *p;
if(last==NULL)
{
printf("List is empty\n");
return -1;
}
p=last->next;
do
{
  if(p->data==data)
  return pos;
  ++pos;
  p=p->next;



}
while(p!=last->next);
return -1;




}








void main()
{
struct node *last=NULL;
int data,choice,size,pos;
clrscr();
while(1)
{
printf("1. Create\n");
printf("2. Display\n");
printf("3. Size\n");
printf("4. Add at end\n");
printf("5. Search");
printf("10. Exit");
printf("\nEnter your choice");
scanf("%d",&choice);
clrscr();
switch(choice)
{
case 5:
	printf("Enter the data to be searched");
	scanf("%d",&data);
	pos=search(last,data);
	if(pos==-1)
	{
	printf("Not availabl\n");
	break;
	}
	printf("The data %d is avilable at %d position",data,pos);
	break;
case 4:
	printf("Enter data");
	scanf("%d",&data);
	last=addAtEnd(last,data);
	break;
case 3:
	size=getSize(last);
	printf("The size of list is %d\n",size);
	break;
case 1:
	last=createList(last);
	break;
case 2:
	display(last);
	break;

case 10:
	exit(1);
}
}

getch();
}