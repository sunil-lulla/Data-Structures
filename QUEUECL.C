#include<stdio.h>
#include<conio.h>
struct node
{
int info;
struct node *link;
}*rear=NULL;

int siz=0;
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

int isEmpty()
{
if(rear==NULL)
return 1;
return 0;
}



void display()
{
struct node *tmp;
if(isEmpty())
{
printf("Empty");
return;
}

tmp=rear->link;
do
{
printf("%d\t",tmp->info);
tmp=tmp->link;
}
while(tmp!=rear->link);
}


int peek()
{
return rear->link->info;
}










int dequeue()
{
struct node *tmp=NULL;
int item=0;
if(isEmpty())
{
printf("underflow..");
return -1;
}

if(rear->link==rear)
{
tmp=rear;
rear=NULL;
}
else
{
tmp=rear->link;
rear->link=tmp->link;
}
item=tmp->info;
siz--;
return item;
}







void enqueue(int data)
{
struct node *tmp=NULL;
tmp=(struct node *)malloc(sizeof(struct node));
if(tmp==NULL)
{
printf("Memory not available.. ");
return;
}
tmp->info=data;
if(rear==NULL)
{
rear=tmp;
tmp->link=rear;
}
else
{
tmp->link=rear->link;
rear->link=tmp;
rear=tmp;
}

siz++;










}






int size()
{
return siz;
}