#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<stdlib.h>
struct node
{
int info;
struct node *next;
};



struct node *insert(struct node *start,int data)
{
struct node *temp,*p;
temp=(struct node *)malloc(sizeof(struct node));
temp->info=data;
if(start==NULL||start->info>data)
{
temp->next=start;
start=temp;
return start;
}






for(p=start;p->next!=NULL&&p->next->info<data;p=p->next);
temp->next=p->next;
p->next=temp;
return start;
}


void display(struct node *start)
{
struct node *p;
p=start;
if(start==NULL)
{
printf("List is empty");
return;
}
while(p!=NULL)
{
printf("%d ",p->info);
p=p->next;
}
}


int search(struct node *start,int data)
{
int pos;
struct node *p;
if(start==NULL||start->info>data)
return -1;
for(p=start,pos=1;p!=NULL&&p->info<=data;p=p->next,pos++)
{

if(p->info==data)
{
return pos;
}

}
return 0;











}






void main()
{
int choice,data,pos;
struct node *start=NULL;
clrscr();
while(1)
{

	printf("1. Insert\n");
	printf("2. Search\n");
	printf("3. display\n");
	printf("4. exit\n");
	printf("Enter your choice");
	scanf("%d",&choice);
	switch(choice)
	{
	case 3:
		display(start);
		break;

	case 1:
		printf("Enter the data you ant to insert");
		scanf("%d",&data);
		start=insert(start,data);
		break;
	case 2:
		printf("Enter the data you want to search");
		scanf("%d",&data);
		pos=search(start,data);
		if(pos<=0)
		printf("Invalid");
		else
		printf("Data is avilable at pos %d",pos);
		break;
	case 4:
		exit(1);

	}






}





}