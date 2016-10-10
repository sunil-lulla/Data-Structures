#include<stdio.h>
#include<conio.h>
#include<process.h>

#define MAX 10
int stack[MAX];
int tos=-1;

void push(int data);
int pop();
int peek();
int isEmpty();
int isFull();
int size();
void display();
int deleteAll();
void create();

void main()
{
int data=0,choice=0,isDeleted=0;



while(1)
{
	clrscr();
	printf("\n1. Create");
	printf("\n2. Push");
	printf("\n3. Pop");
	printf("\n4. Peek");
	printf("\n5. Display");
	printf("\n6. Delete All");
	printf("\n7. Exit");
	printf("\n8. size");
	printf("\nEnter your choice..");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		create();
		break;
	case 6:
		isDeleted=deleteAll();
		if(isDeleted)
		printf("\n Successfully Deleted...");
		else
		printf("\n Deletion Aborted..");
		break;

	case 8:
		printf("The size of list is %d",size());
		break;
	default:
		printf("Invalid choice..");
		break;
	case 5:
		display();
		break;


	case 2:
		printf("Enter the data");
		scanf("%d",&data);
		push(data);
		break;
	case 7:
		exit(1);
	case 3:
		data=pop();
		printf("The %d is deleted from stack",data);
		break;

	case 4:
		data=peek();
		printf("The %d is on top of stack",data);
		break;







	}

	 printf("\nContinue...");
	getch();
}













}

int deleteAll()
{
tos=-1;
return 1;
}


void create()
{
int size=0,data=0;
if(tos!=-1)
{
printf("The stack is already created..");
return;
}
printf("Enter the initial size o f stack");
scanf("%d",&size);
if(size>MAX||size<1)
{
printf("Invalid Size");
return;
}

for(;size>0;size--)
{
printf("Enter the data");
scanf("%d",&data);
push(data);
}








}






int size()
{

return tos+1;
}


void push(int item)
{
if(isFull())
{
printf("Stack Overflow\n");
getch();
exit(1);
}
tos++;
stack[tos]=item;
}

int isFull()
{
if(tos==MAX-1)
return 1;
return 0;
}


int pop()
{
int item;
if(isEmpty())
{
printf("Stack UnderFlow");
getch();
exit(1);
}
item=stack[tos];
tos--;
return item;


}


int isEmpty()
{
 if(tos==-1)
 return 1;
 return 0;

}

int peek()
{
 if(isEmpty())
 {
 printf("Stack OverFlow");
 getch();
 exit(1);
 }
 return stack[tos];
}

void display()
{

int i=0;
if(isEmpty())
{
printf("Stack is empty");
return;
}
for(i=tos;i>=0;i--)
{
printf("\t%d",stack[i]);
}


}




