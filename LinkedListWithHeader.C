#include<stdio.h>
#include<conio.h>
#include<dos.h>
struct node
{
int info;
struct node *next;
};


struct node *deleteAtPos(struct node *head,int pos)
{
int i=1;
struct node *tmp,*p;
if(head->next==NULL)
{
printf("List is empty\n");
return head;
}
tmp=head->next;
if(pos==1)
{
head->next=tmp->next;
free(tmp);
head->info--;
return head;
}
for(;i<pos-1;i++)
tmp=tmp->next;
p=tmp->next;
tmp->next=p->next;
free(p);
head->info--;
return head;
}





struct node *addAtPos(struct node *head,int pos,int data)
{
int i=0;
struct node *tmp,*p;
if(head->next==NULL)
{
printf("List is empty");
return head;
}
tmp=head->next;
p=(struct node *)malloc(sizeof(struct node));
p->info=data;
head->info++;
if(pos==1)
{
p->next=tmp;
head->next=p;
return head;
}
for(i=1;i<pos-1;i++)
tmp=tmp->next;
p->next=tmp->next;
tmp->next=p;
return head;
}







struct node *deleteLast(struct node *head)
{
struct node *tmp;
if(head->next==NULL)
{
printf("List is empty\n");
return head;
}
tmp=head;
while(tmp->next->next!=NULL)
tmp=tmp->next;
free(tmp->next);
tmp->next=NULL;
head->info--;
printf("Data deleted successfully..\n");
return head;
}





int getPosition(struct node *head,int data)
{
int pos=0;
struct node *tmp;
if(head->next==NULL)
{
return -1;
}

tmp=head->next;
while(tmp!=NULL)
{
pos++;
if(tmp->info==data)
{
return pos;
}
tmp=tmp->next;
}
return 0;









}




void display(struct node *head)
{
struct node *p;
if(head->next==NULL)
{
printf("List is empty\n");
return;
}
p=head->next;
while(p!=NULL)
{
printf("%d  ",p->info);
p=p->next;
}
}



struct node *addAtEnd(struct node *head,int data)
{
struct node *p,*tmp;
if(head->next==NULL)
{
printf("First create the list then try...\n");
return head;
}
p=head;
while(p->next!=NULL)
p=p->next;
tmp=(struct node *)malloc(sizeof(struct node));
tmp->info=data;
tmp->next=NULL;
head->info++;
p->next=tmp;
return head;
}



struct node * createList(struct node *head)
{
int initSize=0,data=0;
struct node *tmp;
if(head->next!=NULL)
{
printf("List is already created\n");
return head;
}
printf("Enter the initial size of the list");
scanf("%d",&initSize);
if(initSize<=0)
{
printf("Invalid size");
return head;
}
tmp=(struct node *)malloc(sizeof(struct node));
printf("Enter data:");
scanf("%d",&data);
tmp->next=NULL;
tmp->info=data;
head->next=tmp;
head->info++;
for(;initSize>1;initSize--)
{
printf("Enter data:");
scanf("%d",&data);
head=addAtEnd(head,data);
}
return head;
}




struct node *replace(struct node *head,int data,int newData)
{
struct node *tmp;
if(head->next==NULL)
{
printf("List is empty\n");
return head;
}
tmp=head->next;
for(;tmp!=NULL;tmp=tmp->next)
{
	if(tmp->info==data)
	{
	    tmp->info=newData;
	    return head;
	}

}
printf("Data not avilable\n");

return head;




}



void main()
{
struct node *head;
int choice=0,data=0,pos=0,i=0,newData=0;
clrscr();
head=(struct node *)malloc(sizeof(struct node));
head->info=0;
head->next=NULL;
while(1)
{       printf("\n\n\t\t1.  Create\n");
	printf("\t\t2.  Add at last\n");
	printf("\t\t3.  Display\n");
	printf("\t\t4.  Count\n");
	printf("\t\t5.  Exit\n");
	printf("\t\t6.  Search\n");
	printf("\t\t7.  Delete last\n");
	printf("\t\t8.  Delete all\n");
	printf("\t\t9.  Add at Position\n");
	printf("\t\t10. Delete at Position\n");
	printf("\t\t11. Add After\n");
	printf("\t\t12. Add Before\n");
	printf("\t\t13. Delete Selected\n");
	printf("\t\t14. Replace\n");
	printf("Enter your choice");
	scanf("%d",&choice);
	switch(choice)
	{

	case 14:
		printf("Enter the data you want to replace");
		scanf("%d",&data);
		printf("Enter the data you want to add");
		scanf("%d",&newData);
		head=replace(head,data,newData);
		break;

	case 13:
		printf("Enter the data you want to delete");
		scanf("%d",&data);
		pos=getPosition(head,data);
		if(pos==0)
		printf("Data is not avilable\n");
		else if(pos==-1)
		printf("List is empty");
		else
		{
		head=deleteAtPos(head,pos);
		}
		break;







	/*case 13:
		printf("Enter the position whose data u want to delete");
		scanf("%d",&pos);
		if(pos<=0||head->info>pos)
		printf("Invalid position");
		else
		head=deleteAtPos(head,pos);
		break;
		*/

	case 12:
		printf("Enter the data whom before u want to add the data");
		scanf("%d",&data);
		pos=getPosition(head,data);
		if(pos==0)
		printf("Data is not avilable\n");
		else if(pos==-1)
		printf("List is empty");
		else
		{
		printf("Enter the data");
		scanf("%d",&data);
		head=addAtPos(head,pos,data);
		}
		break;


	case 11:
		printf("Enter the data whom after u  want to add the data");
		scanf("%d",&data);
		pos=getPosition(head,data);
		if(pos==0)
		printf("Data is not avilable\n");
		else if(pos==-1)
		printf("List is empty");
		else
		{
		printf("Enter the data");
		scanf("%d",&data);
		head=addAtPos(head,pos+1,data);
		}
		break;

	case 10:
		printf("Enter the position on which u want to delete the data");
		scanf("%d",&pos);
		if(pos<=0||pos>head->info)
		printf("Invalid Position");
		else
		head=deleteAtPos(head,pos);
		break;



	case 9:
		printf("Enter the position on which u want to add the data");
		scanf("%d",&pos);
		printf("Enter the data");
		scanf("%d",&data);
		if(pos<=0||pos>head->info)
		printf("Invalid Position");
		else
		head=addAtPos(head,pos,data);
		break;

	case 8:
		i=head->info;
		for(;i>0;i--)
		head=deleteLast(head);
		break;

	case  7:
		head=deleteLast(head);
		break;

	case 6:
		printf("Enter the data to be search");
		scanf("%d",&data);
		pos=getPosition(head,data);
		if(pos==0)
		printf("data is not available\n");
		else if(pos==-1)
		printf("List is empty\n");
		else
		printf("Data is available at position %d\n",pos);

		break;

	case 2:
		printf("Enter the data to be add");
		scanf("%d",&data);
		head=addAtEnd(head,data);
		break;

	case 4:
		printf("The count is: %d",head->info);
		break;

	case 1:
		head=createList(head);
		break;

	case 3:

		display(head);
		break;

	case 5:
		clrscr();
		sound(440);
		gotoxy(35,12);
		printf("Good Bye..");
		sleep(2);
		nosound();
		exit(0);

	default:
		printf("Invalid choice");




	}




}









}