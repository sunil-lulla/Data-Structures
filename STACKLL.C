#include<stdio.h>
#include<conio.h>
#include<alloc.h>

struct node
{
int info;
struct node *link;
}*tos=NULL;

void push(int data);
int pop();
int peek();
void display();
int size();
void create();
void deleteAll();

void main()
{
int choice=0,data=0;

while(1)
{
	printf("\n1. Create");
	printf("\n2. Push");
	printf("\n3. Pop");
	printf("\n4. Peek");
	printf("\n5. Display");
	printf("\n6. Size");
	printf("\n7. Delete All");
	printf("\n8. Exit");
	printf("\nEnter Choice");
	scanf("%d",&choice);
	switch(choice)
	{
	case 7:
		deleteAll();
		break;
	case 1:
		create();
		printf("Successfully deleted..");
		break;


	case 6:
	       printf("\nThe size of list is %d\n",size());
	       break;

	case 4:
		printf("\nThe data at top of stack is %d",peek());
		break;


	case 3:
		printf("\nThe data %d is popped\n",pop());
		break;


	case 8:
		exit(1);
	case 5:
		display();
		break;

	case 2:
	      printf("Enter data to be pushed");
	      scanf("%d",&data);
	      push(data);
	      break;




	}






}



}


int peek()
{
if(tos==NULL)
{
printf("Stack undreFlow..");
getch();
exit(0);
}
return tos->info;







}



void deleteAll()
{
struct node *tmp=NULL;
tmp=tos;


while(tos!=NULL)
{
tmp=tos;
tos=tos->link;
free(tmp);
}




}


int size()
{
int size=0;
struct node *tmp=NULL;
tmp=tos;
while(tmp!=NULL)
{
size++;
tmp=tmp->link;
}

return size;



}




void create()
{
int size=0;
int data=0;
if(tos!=NULL)
{
printf("The list is already created");
return;
}
printf("Enter the initial size of stack");
scanf("%d",&size);
for(;size>0;size--)
{
printf("Enter the data to be pushed");
scanf("%d",&data);
push(data);
}
}






int pop()
{
int item;
struct node *tmp=NULL;
if(tos==NULL)
{
printf("Stack UnderFlow");
getch();
exit(0);
}
tmp=tos;
item=tos->info;
tos=tos->link;
free(tmp);
return item;






}








void push(int data)
{
struct node *tmp=NULL;
tmp=(struct node *)malloc(sizeof(struct node));
if(tmp==NULL)
{
printf("Stack OverFlow\n");
return;
}
tmp->info=data;
tmp->link=tos;
tos=tmp;
}

void display()
{
struct node *p=NULL;

if(tos==NULL)
{
printf("Stack Underflow..");
return;
}
p=tos;

while(p!=NULL)
{
printf("\t%d",p->info);
p=p->link;
}
}





