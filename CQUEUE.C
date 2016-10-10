#include<stdio.h>
#include<conio.h>
#include<process.h>
#define MAX 5
int size=0;
int front=-1,rear=-1;
int cqueue[MAX];
int dequeue();
void enqueue(int data);
int isEmpty();
int isFull();
int peek();
void display();
int sizeFun();



void main()
{
int choice=0,data=0;


while(1)
{
	printf("1. Enqueue\n");
	printf("2. Dequeue\n");
	printf("3. Display\n");
	printf("4. SizeVal\n");
	printf("5. SizeFunc\n");
	printf("6. Peek\n");
	printf("7. Exit\n");
	printf("Enter your choice\n");
	scanf("%d",&choice);
	switch(choice)
	{
	 case 1:
		printf("Enter data");
		scanf("%d",&data);
		enqueue(data);
		break;

	 case 2:
		printf("The %d is deleted successfully",dequeue());
		break;
	 case 3:
		display();
		break;
	 case 4:
		printf("The size of list is %d",size);
		break;
	 case 5:
		printf("The size of list is %d",sizeFun());
		break;
	 case 6:
		printf("The %d is available at front of the circular queue",peek());
		break;


	 case 7:
		exit(1);








	}



}


}




int isFull()
{
if((front==0&&rear==MAX-1)||(front==rear+1))
return 1;
return 0;
}



int isEmpty()
{
if(front==-1)
return 1;
return 0;
}




void display()
{
int i=0;
if(isEmpty())
{
printf("Queue is empty\n");
return;
}
i=front;
if(front<=rear)
{
 while(i<=rear)
 {
 printf("\t%d",cqueue[i]);
 i++;
 }
}
else
{       i=front;
	while(i<=MAX-1)
	{
	printf("%d\t",cqueue[i]);
	++i;
	}
	i=0;
	while(i<=rear)
	{
	printf("%d\t",cqueue[i]);
	i++;
	}





}

















}




int sizeFun()
{
 if(front<=rear)
 {
 return rear-front+1;
 }
 else
 {
 return (MAX-front)+(rear+1);
 }







}















int dequeue()
{
int item=0;
if(isEmpty())
{
printf("Overflow\n");
getch();
exit(0);
}
item=cqueue[front];
size--;
if(front==rear)
{
front=-1;
rear=-1;
}
else if(front==MAX-1)
front=0;
else
front+=1;
return item;
}




int peek()
{
if(isEmpty())
{
printf("Underflow\n");
exit(0);
}
return cqueue[front];
}











void enqueue(int data)
{
if(isFull())
{
printf("Overflow\n");
return;
}
size++;
if(front==-1)
front=0;
if(rear==MAX-1)
rear=0;
else
rear+=1;
cqueue[rear]=data;
}








