#include<stdio.h>
#include<conio.h>


#define MAX 10
int rear=-1;
int front=-1;
int deckarr[MAX];
int size=0;

void push(int data);
int pop();
void inject(int data);
int eject();
int isEmpty();
int isFull();
void display();


void main()
{
	int choice=0,data=0;
	while(1)
	{
	clrscr();
	printf("\n1. Push insert at front end");
	printf("\n2. Pop  Delete at front end");
	printf("\n3. Inject insert at rear end");
	printf("\n4. Eject insert at rear end");
	printf("\n5. Exit");
	printf("\n6. Display");
	printf("Enter choice");
	scanf("%d",&choice);
	switch(choice)
	{
		case 6:
			display();
			break;
		case 1:
			printf("Enter data");
			scanf("%d",&data);
			push(data);
			break;
		case 2:
			printf("The %d is deleted from front end",pop(data));
			break;
		case 3:
			printf("Enter data");
			scanf("%d",&data);
			inject(data);
			break;
		case 4:
			printf("The %d is deleted from rear end",eject(data));
			break;
		case 5:
			printf("Good bye!!..");
			getch();
			exit(1);








	}

	getch();







	}







}


int eject()
{
int data=0;
if(isEmpty())
{
printf("List is empty\n");
getch();
exit(0);
}
 data=deckarr[rear];
if(rear==front)
{
rear=-1,front=-1;
}
else if(rear==0)
rear=MAX-1;
else
rear-=1;
return data;




}








void inject(int data)
{

if(isFull())
{
printf("Deck is full\n");
return;
}

if(front==-1)
{
front=0;
rear=0;
}
else if(rear==MAX-1)
rear=0;
else
rear+=1;
deckarr[rear]=data;
}











int isFull()
{
if(front==-1&&rear==MAX-1||front==rear+1)
return 1;
return 0;
}


int isEmpty()
{
if(front==-1)
return 1;
return 0;
}

int pop()
{
int data=0;
if(isEmpty())
{
printf("List is empty\n");
getch();
exit(1);
}
data=deckarr[front];

if(front==rear)
front=-1,rear=-1;
else if(front==MAX-1)
front=0;
else
front+=1;
return data;




















}









void push(int data)
{
if(isFull())
{
printf("List is full\n");
return;
}

if(front==-1)
front=0,rear=0;
else if(front==0)
front=MAX-1;
else
front=front-1;
deckarr[front]=data;
}







void display()
{
int i=0;
if(isEmpty())
{
printf("Empty\n");
return;
}
i=front;
if(i<=rear)
{
while(i<=rear)
{
printf("%d\t",deckarr[i++]);
}
}
else
{
i=front;

while(i<=MAX-1)
{
printf("%d\t",deckarr[i++]);

}
i=0;
while(i<=rear)
printf("%d\t",deckarr[i++]);


}














}













