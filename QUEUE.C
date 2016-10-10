#include<stdio.h>
#include<conio.h>
#include<process.h>
#define MAX 5
int rear=-1,front=-1;
int queuearr[MAX];
void enqueue(int data);
int dequeue();
void display();
int isEmpty();
int peek();
int isFull();
int size();
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
if(isFull())
{
printf("Overflow\n");
return;
}
rear++;
queuearr[rear]=data;
if(front==-1)
front=0;
}



int isFull()
{
if(rear==MAX-1)
return 1;
return 0;
}


int dequeue()
{
int item;
if(isEmpty())
{
printf("Underflow..\n");
return 0;
}
item=queuearr[front];
front++;
return item;
}


int isEmpty()
{
if(front==-1||front==rear+1)
return 1;
return 0;
}


int size()
{
return rear-front+1;

}




void display()
{
int i=0;
if(isEmpty())
{
printf("UnderFlow..");
return;
}

for(i=front;i<=rear;i++)
{
printf("%d\t",queuearr[i]);
}






}



int peek()
{
if(isEmpty())
{
printf("underflow..\n");
return -1;
}

return queuearr[front];



}


