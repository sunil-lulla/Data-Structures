#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<stdlib.h>
#include<dos.h>
struct node
{
int info;
struct node *link;
};




void display(struct node *start)
{
struct node *tmp;
if(start==NULL)
{
printf("List is empty");
return;
}
tmp=start;
while(tmp!=NULL)
{
printf(" %d\t",tmp->info);
tmp=tmp->link;
}





}


















struct node * insert(struct node *start,int data)
{
struct node *tmp,*p;
tmp=(struct node *)malloc(sizeof(struct node));
tmp->info=data;
if(start==NULL)
{
tmp->link=start;
start=tmp;
return start;
}
p=start;
while(p->link!=NULL)
p=p->link;
p->link=tmp;
tmp->link=NULL;
return start;
}






void merge(struct node *p1,struct node *p2)
{
struct node *merged=NULL;

while(p1!=NULL&&p2!=NULL)
{
if(p1->info>p2->info)
{
merged=insert(merged,p2->info);
p2=p2->link;
}
else if(p1->info<p2->info)
{
merged=insert(merged,p1->info);
p1=p1->link;
}
else
{
merged=insert(merged,p1->info);
p1=p1->link;
p2=p2->link;
}

}

while(p1!=NULL)
{
merged=insert(merged,p1->info);
p1=p1->link;
}

while(p2!=NULL)
{
merged=insert(merged,p2->info);
p2=p2->link;
}

printf("The merged List is:  ");
display(merged);






}













struct node * insertSorted(struct node * start)
{
int data;
struct node *tmp,*p;
tmp=(struct node *)malloc(sizeof(struct node));
printf("Enter data");
scanf("%d",&data);
tmp->info=data;
if(start==NULL||start->info>data)
{
tmp->link=start;
start=tmp;
return start;
}
for(p=start;p->link!=NULL && p->link->info<data;p=p->link);
tmp->link=p->link;
p->link=tmp;
return start;
}






struct node * create(struct node *start)
{
int size=0;
struct node *p;
if(start!=NULL)
{
printf("You have already created the list");
return start;
}
printf("Enter the Size of the list");
scanf("%d",&size);
for(;size>0;size--)
start=insertSorted(start);
return start;
}


void concat(struct node *p1,struct node *p2)
{
struct node *p;
if(p1==NULL)
{
display(p2);
getch();
return;
}
else if(p2==NULL)  {
display(p1);
getch();
return;
}
else
 {
    p=p1;
 while(p->link!=NULL)
	p=p->link;
	p->link=p2;

 }
display(p1);









}


int areSame(struct node *p1,struct node *p2)
{

while(1)
{
if(p1==NULL&&p2==NULL)
return 1;
if(p1==NULL||p2==NULL)
return 0;
if(p1->info!=p2->info)
return 0;
p1=p1->link;
p2=p2->link;




}





}





void main()
{
struct node *p1=NULL,*p2=NULL;
int choice=0,i=1,check=0;
clrscr();
while(1)
{
	choice=0;
	printf("\n\t1. Create\n");
	printf("\t2. Display\n");
	printf("\t3. Merge\n");
	printf("\t4. Exit\n");
	printf("\t5. Concatenate\n");
	printf("\t6. Same\n");
	printf("Enter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
	case 6:
		check=areSame(p1,p2);
		if(check==0)
		printf("\nNot equal\n");
		else
		printf("\nBoth the list are equal\n");
		break;


	case 5:
		concat(p1,p2);
		break;
	case 3:
		merge(p1,p2);
		break;

	case 1:
		if(i==1)
		p1=create(p1);
		else if(i==2)
		p2=create(p2);
		else
		printf("You have already created too many list\n");
		++i;
		break;

	case 2:
		if(p1==NULL&&p2==NULL)
		{
		printf("First create the List and then try..\n");
		break;
		}
		else
		{
		if(p1!=NULL)
		printf("1. List one\n");
		if(p2!=NULL)
		printf("2. List two\n");
		}
		printf("Enter your choice");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			if(p1==NULL)
			{
			printf("Invalid\n");
			break;
			}
			display(p1);
			break;
		case 2:
			if(p2==NULL)
			{
			printf("Invalid\n");
			break;
			}
			display(p2);
			break;

		default:
			printf("Invalid Choice\n");
		}
		break;
	case 4:
		clrscr();
		sound(200);
		gotoxy(38,12);
		printf("Good Bye..");
		sleep(2);
		nosound();
		exit(1);

	default:
		printf("Invalid choice..\n");



	}







}










}