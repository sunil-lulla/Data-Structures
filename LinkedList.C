#include<stdio.h>
#include<conio.h>
#include<alloc.h>

//the actual link list is created here..
struct node
{
int info;
struct node *link;
};






void display(struct node * start)
{
struct node *p;
if(start==NULL)
{
printf("List is empty\n");
return;
}
p=start;
clrscr();
while(p!=NULL)
{
printf("%d\t",p->info);
p=p->link;
}
getch();
}











void copyReversed(struct node *start)
{
struct node *t,*p,*q;
if(start==NULL)
{
printf("The List is Empty!!...\n");
return;
}
p=start;
q=(struct node *)malloc(sizeof(struct node));
q->link=NULL;
q->info=p->info;
p=p->link;
while(p!=NULL)
{
t=(struct node *)malloc(sizeof(struct node));
t->info=p->info;
t->link=q;
q=t;
p=p->link;
}






display(t);





}








int countOccurences(struct node *start,int data)
{
int i=0;
if(start==NULL)
{
printf("The list is empty\n");
return -1;
}
while(start!=NULL)
{
if(start->info==data)
++i;
start=start->link;
}


return i;






}






//search() function
int search(struct node *start,int data)
{
struct node *p;
int pos=1;
p=start;
do
{
if(p->info==data)
return pos;
++pos;
p=p->link;
}
while(p!=NULL);
return -1;
}

//addAtEnd() function
void addAtEnd(struct node * start,int data)
{
struct node *tmp=NULL,*p;
if(start==NULL)
{
printf("List is not created first create the list and then try\n");
return;
}
tmp=start;
while(tmp->link!=NULL)
tmp=tmp->link;
p=(struct node *)malloc(sizeof(struct node));
p->info=data;
tmp->link=p;
p->link=NULL;
clrscr();
printf("Added successfull press any key to continue");
getch();
}

//display() function

//insertBefore() function
struct node * insertBefore(struct node *start,int data,int item)
{
struct node *p,*temp;
if(start==NULL)
{
printf("List is empty\n");
return NULL;
}
p=start;
temp=(struct node *)malloc(sizeof(struct node));
temp->info=data;
if(p->info==item)
{
temp->link=p;
start=temp;
return start;
}
while(p->link!=NULL)
{
if(p->link->info==item)
{
temp->link=p->link;
p->link=temp;
return start;
}
p=p->link;
}
printf("NOt found");
return start;
}


//insertAt() function
void insertAt(struct node *start,int data,int pos)
{
int i=0;
struct node *tmp,*p;
tmp=start;
p=(struct node *)malloc(sizeof(struct node));
p->info=data;
if(pos==1)
{
p->link=tmp->link;
tmp->link=p;
return ;
}
while(tmp->link!=NULL)
{
++i;
if(i==pos)
break;
tmp=tmp->link;
}
if(i<pos)
{
printf("position not avilable");
return;
}
p->link=tmp->link;
tmp->link=p;
}


//createList() function
struct node * createList(struct node *start)
{
struct node *temp;
int size=0,i=0,data=0;
if(start!=NULL)
{
printf("List is alreday created\n");
return start;
}
printf("Enter the initial size of list");
scanf("%d",&size);
temp=(struct node *)malloc(sizeof(struct node));
printf("Enter data");
scanf("%d",&data);
temp->info=data;
temp->link=NULL;
start=temp;
for(i=2;i<=size;i++)
{
printf("Enter data");
scanf("%d",&data);
addAtEnd(start,data);
}
return start;
}

//deleteLast() function
struct node* deleteLast(struct node *start)
{
struct node *temp;
if(start==NULL)
return NULL;
temp=start;
if(temp->link==NULL)
{
free(temp);
return NULL;
}
while(temp->link->link!=NULL)
temp=temp->link;
free(temp->link);
temp->link=NULL;
return start;
}


//deleteAfter() function
struct node *deleteAfter(struct node *start,int data)
{
struct node *temp,*p;
temp=start;
if(start==NULL)
{
printf("List is empty first create the list and try again");
return NULL;
}
do
{
if(temp->info==data)
{
if(temp->link==NULL)
{
printf("This is the last node");
return start;
}
p=temp->link;
temp->link=p->link;
free(p);
return start;
}
temp=temp->link;
}
while(temp!=NULL);
printf("data is not avilable");
return start;
}

//getSize() function
int getSize(struct node * start)
{
struct node *tmp;
int i=0;
tmp=start;
while(tmp!=NULL)
{
++i;
tmp=tmp->link;
}
return i;
}


/*
*
*
*
*/
//deletebefore() function
struct node * deleteBefore(struct node *start,int data)
{
struct node *tmp,*p;
if(start==NULL)
{
printf("The list is empty");
return NULL;
}
tmp=start;
if(tmp->info==data)
{
printf("This is the first node of the list");
return start;
}
while(tmp->link!=NULL)
{
if(tmp->link->link->info==data)
{
p=tmp->link;
tmp->link=p->link;
free(p);
return start;
}
tmp=tmp->link;
}
printf("data is not avilable");
return start;
}


//deletePos() function
struct node *deleteAtPos(struct node *start,int pos)
{
int i=0;
struct node *tmp,*p;
if(start==NULL)
{
printf("The list is empty");
return start;
}
tmp=start;
if(pos==1)
{
start=tmp->link;
free(tmp);
return start;
}
do
{
++i;
if(pos-1==i)
break;
tmp=tmp->link;
}
while(tmp->link!=NULL);
if(pos>i)
{
printf("Position is not avilable");
return start;
}
p=tmp->link;
tmp->link=p->link;
free(p);
return start;
}


//reverse() function
struct node *reverse(struct node *start)
{
struct node *current,*previous,*next;
current=start;
previous=next=NULL;
while(current!=NULL)
{
next=current->link;
current->link=previous;
previous=current;
current=next;
}
start=previous;
return start;
}


//insertion Sort function which actually exchange the data part of the link list
struct node *insSortByDataEx(struct node *start)
{
struct node *p,*q;
if(start==NULL)
{
printf("List is empty\n");
return start;
}
for(p=start;p->link!=NULL;p=p->link)
	for(q=p->link;q!=NULL;q=q->link)
		if(p->info>q->info)
		{
		q->info=p->info+q->info;
		p->info=q->info-p->info;
		q->info=q->info-p->info;
		}









		return start;






}



//bubbleSort() function which exchanges the data part for sorting the list
struct node *bubbleSort(struct node *start)
{

struct node *p,*q,*last;
if(start==NULL)
{
printf("List is empty");
return start;
}
for(last=NULL;start->link!=last;last=q)
{
for(p=start;p->link!=last;p=p->link)
{
q=p->link;
if(p->info>q->info)
{
q->info=p->info+q->info;
p->info=q->info-p->info;
q->info=q->info-p->info;
}


}


}






  return start;
}



//insertion sort coding using rearranging links technique


struct node * insSortByRerrLink(struct node *start)
{
struct node *p,*r;// r contains the address of the previous node of p
struct node *q,*s;// s contains the address of the previous node of q
struct node *tmp;
p=q=r=s=tmp=NULL;
if(start==NULL)
{
printf("List is empty\n");
return start;
}
for(p=r=start;p->link!=NULL;r=p,p=p->link)
{
for(q=s=p->link;q!=NULL;s=q,q=q->link)
{
	if(p->info>q->info)
	{
	    tmp=p->link;
	    p->link=q->link;
	    q->link=tmp;
	    if(p!=start)
	    r->link=q;
	    s->link=p;
	    if(p==start)
	    start=q;
	    tmp=p;
	    p=q;
	    q=tmp;
	   }
}
}






return start;

}


//the below is the code for sorting using Bubble sort algorithm by rearranging the links of the nodes


struct node * bubbleSortByLink(struct node * start)
{

struct node *p,*q,*r,*last,*temp;
if(start==NULL)
{
printf("List is empty\n");
return start;
}

for(last=NULL;start->link!=last;last=q)
{
for(p=r=start;p->link!=last;r=p,p=p->link)
{

q=p->link;
if(p->info>q->info)
{
p->link=q->link;
q->link=p;
if(p!=start)
r->link=q;
else
start=q;
temp=p;
p=q;
q=temp;
}
}
}
return start;



}




void largest(struct node *start)
{
int max=0;
if(start==NULL)
{
printf("\nList is empty\n");
return;
}
max=start->info;
while(start!=NULL)
{
if(start->info>max)
max=start->info;
start=start->link;
}
printf("\nThe largest element is %d\n",max);





}



void smallest(struct node *start)
{
int small=0;
if(start==NULL)
{
printf("\n the list is empty\n");
return;

}
small=start->info;
while(start!=NULL)
{
if(start->info<small)
small=start->info;

start=start->link;
}

printf("\ndThe smallest element is: %d\n",small);







}





struct node *copy(struct node *start)
{
struct node *start2,*p,*tmp;
if(start==NULL)
{
return start;
}
start2=NULL;
start2=(struct node *)malloc(sizeof(struct node));
start2->info=start->info;
start2->link=NULL;
p=start2;

start=start->link;
while(start!=NULL)
{
tmp=(struct node *)malloc(sizeof(struct node));
tmp->info=start->info;
tmp->link=NULL;
p->link=tmp;
start=start->link;
p=p->link;
}
return start2;







}








// the main() function
void main()
{
struct node *start=NULL,*start2=NULL;
int choice=0,data=0,pos=0,_data=0,i=0;
char ch='\0';
clrscr();
while(1)
{
while(1)
    {

	printf("%c",201);
	for(i=1;i<=77;i++)
	{
	printf("%c",205);
	if(i==26)
	printf("%c",203);
	}
	printf("%c",187);


	printf("\n   1.  Create Link list\n");
	printf("   2.  Insert at last\n");
	printf("   3.  Insert after\n");
	printf("   4.  Insert before\n");
	printf("   5.  Insert at position\n");
	printf("   6.  Delete all\n");
	printf("   7.  Delete at pos\n");
	printf("   8.  Delete after\n");
	printf("   9.  Delete last\n");
	printf("  10.  Display\n");
	printf("  11.  Exit\n");
	for(i=1;i<=11;i++)
	{
	gotoxy(28,i+1);
	printf("%c",186);

	}
	gotoxy(35,2);
	printf(" 12.  Search\n");
	gotoxy(35,3);
	printf(" 13.  Size\n");
	gotoxy(35,4);
	printf(" 14.  Reverse\n");
	gotoxy(35,5);
	printf(" 15.  Sort using Insertion Sort\n");
	gotoxy(35,6);
	printf(" 16.  Sort using Bubble Sort\n");
	gotoxy(35,7);
	printf(" 17.  Delete before\n");
	gotoxy(35,8);
	printf(" 18.  Sort using insertion sort\n");
	gotoxy(35,9);
	printf(" 19.  Sort using Bubble sort by links\n");
	gotoxy(35,10);
	printf(" 20.  Count the no of occurences of an element\n");
	gotoxy(35,11);
	printf(" 21.  Find smallest element\n");
	gotoxy(35,12);
	printf(" 22.  Find largest element\n");
	gotoxy(35,13);
	printf(" 23.  Copy\n");
	printf("24 .Copy Reversed");

	printf("Enter your choice");
	scanf("%d",&choice);
	clrscr();
	switch(choice)
	{
	case 24:
		copyReversed(start);
		break;


	case 23:
		start2=copy(start);
		printf("\n----------copied lis is-----------\n");
		display(start2);
		start2=NULL;
		break;


	case 22:
		largest(start);
		break;

	case 21:
		smallest(start);
		break;

	case 20:
		printf("Enter the data");
		scanf("%d",&data);
		pos=countOccurences(start,data);
		if(pos==0)
		printf("No available");
		else if(pos>0)
		printf("The element %d is avilable %d no of times",data,pos);
		break;


	case 19:
		start=bubbleSortByLink(start);
		break;

	case 18:
		start=insSortByRerrLink(start);
		break;


	case 16:

		start=bubbleSort(start);
		break;


	case 15:

		start=insSortByDataEx(start);
		break;


	case 14:

		start=reverse(start);
		break;


	case 17:

		printf("Enter data whom before you want to delete nodes");
		scanf("%d",&data);
		start=deleteBefore(start,data);
		break;


	case 13:

		printf("the size of list is %d",getSize(start));
		break;


	case 7:

		printf("Enter the position u want to delete");
		scanf("%d",&pos);
		start=deleteAtPos(start,pos);
		break;


	case 8:
		printf("Enter data whom after you want to delete nodes");
		scanf("%d",&data);
		start=deleteAfter(start,data);
		break;


	case 9:
		start = deleteLast(start);
		break;


	case 4:
		printf("Enter data whom before u want to add data");
		scanf("%d",&_data);
		printf("Enter data");
		scanf("%d",&data);
		start=insertBefore(start,data,_data);
		break;


	case 1:
		start=createList(start);
		break;

	case 2:
		printf("Enter data");
		scanf("%d",&data);
		addAtEnd(start,data);
		break;

	case 10:
		display(start);
		break;

	case 11:
		fflush(stdin);
		printf("Are you sure want to quit y/n");
		scanf("%c",&ch);
		if(ch=='y')
		{
		clrscr();
		gotoxy(35,13);
		cprintf("Good bye..");
		sound(440);
		sleep(3);
		nosound();
		exit(0);
		}
		clrscr();
		break;


	case 12:

		printf("Enter data to be search");
		scanf("%d",&data);
		pos=search(start,data);
		if(pos==-1)
		{
		printf("not avilable");
		continue;
		}
		printf("%d is avilable at %d pos\n",data,pos);
		break;


	 case 3:

		printf("Enter data whom after you want to add the data");
		scanf("%d",&data);
		pos=search(start,data);
		if(pos==-1)
		{
		 printf("Not avilable");
		 continue;
		}
		printf("Enter new data");
		scanf("%d",&data);
		insertAt(start,data,pos);
		break;

	case 5:
		printf("Enter position");
		scanf("%d",&pos);
		if(pos<1)
		{
		printf("Invalid position");
		continue;
		}
		printf("Enter data");
		scanf("%d",&data);
		insertAt(start,data,pos-1);
		break;

	}
	}





































}}
