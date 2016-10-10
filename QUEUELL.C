#include<stdio.h>
#include<conio.h>
#include<process.h>

struct node
{
int info;
struct node *link;
}*rear=NULL,*front=NULL;


void enqueue(int data);
int dequeue();
int size();
void display();
int isEmpty();
int peek();





void main()
{
int choice=0,data=0;

while(1)
{
	clrscr();
	printf("\t\t\t\t\tWelcome to my DS world\n");
	printf("1. Enqueue\n");
	printf("2. Dequeue\n");
	printf("3. Size\n");
	printf("4. Display\n");
	printf("5. Peek\n");
	printf("6. Exit\n");
	printf("Enter your choice\n");
	scanf("%d",&choice);
	switch(choice)
	{

	case 1:
		printf("Enter data:");
		scanf("%d",&data);
		enqueue(data);
		break;
	case 2:
		printf("The data is %d is deleted",dequeue());
		break;

	case 3:
		printf("The size of queue is %d  ",size());
		break;
	case 4:
		display();
		break;
	case 5:
	       printf("%d is the first element in queue",peek());
	       break;
	case 6:
		exit(0);
	default:
		printf("Invalid choice\n");

	}



	 getch();


}
}







void enqueue(int data)
{
struct node *p;
p=(struct node *)malloc(sizeof(struct node));
if(p==NULL)
{
printf("Overflow");
return;
}

p->info=data;
p->link=NULL;
if(front==NULL)
front=p;
else
rear->link=p;
rear=p;
}


int isEmpty()
{
if(front==NULL)
return 1;
return 0;
}




int dequeue()
{
int item=0;
struct node *tmp=NULL;
if(isEmpty())
{
printf("Underflow");
return -1;
}
tmp=front;
front=front->link;
item=tmp->info;
free(tmp);
return item;
}


void display()
{
struct node *p;
if(isEmpty())
{
printf("Underflow");
return;
}
p=front;
while(p!=NULL)
{
printf("%d\t",p->info);
p=p->link;
}
}

int peek()
{
if(isEmpty())
{
printf("Underflow");
return -1;
}
return front->info;



}

int size()
{
int size=0;
struct node *p;
p=front;
while(p!=NULL)
     {
     size++;
     p=p->link;
     }
     return size;


}






