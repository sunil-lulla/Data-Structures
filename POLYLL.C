#include<stdio.h>
#include<conio.h>
#include<alloc.h>
struct node
{
float coff;
int expo;
struct node *link;
};


void display(struct node * start)
{
if(start==NULL)
{
printf("List is empty");
return;
}
while(start!=NULL)
{
printf("(%.1fx^%d)",start->coff,start->expo);
start=start->link;
if(start!=NULL)
{
printf("+");
}
}
}







struct node *insert(struct node *start,float coff,int expo)
{
struct node *p,*tmp;
p=tmp=NULL;
p=(struct node *)malloc(sizeof(struct node));
p->coff=coff;
p->expo=expo;
if(start==NULL)
{
p->link=start;
start=p;
return start;
}
tmp=start;
while(tmp->link!=NULL)
tmp=tmp->link;
p->link=tmp->link;
tmp->link=p;
return start;
}


struct node *check(struct node *start)
{
struct node *p=NULL,*q=NULL,*tmp=NULL;
if(start==NULL)
return NULL;



for(p=start;p!=NULL;p=p->link)
{
for(q=p->link;q!=NULL;)
{
 if(q->expo<p->expo)
 {
 p=p->link;
 q=q->link;
 }

 else if(p->expo==q->expo)
 {
 p->coff+=q->coff;
 p->link=q->link;
 tmp=q;
 q=q->link;
 free(tmp);
  }

   }

     }










return start;


}









void sum(struct node *p1,struct node *p2)
{    struct node *p3=NULL;

while(p1!=NULL&&p2!=NULL)
{
 if(p1->expo>p2->expo)
 {
 p3=insert(p3,p1->coff,p1->expo);
    p1=p1->link;
 }
 else if(p2->expo>p1->expo)
 {
 p3=insert(p3,p2->coff,p2->expo);
    p2=p2->link;
 }
 else
 {
 p3=insert(p3,p2->coff+p1->coff,p1->expo);
 p1=p1->link;
 p2=p2->link;
 }
 }
 while(p1!=NULL)
 {
 p3=insert(p3,p1->coff,p1->expo);
 p1=p1->link;

 }

 while(p2!=NULL)
 {
 p3=insert(p3,p2->coff,p2->expo);
    p2=p2->link;
 }
 display(p3);
 p3=check(p3);
 printf("\n------------\n");
 display(p3);






}






struct node *insSorted(struct node *start,float coff,int expo)
{
struct node*tmp=NULL,*p;
tmp=(struct node *)malloc(sizeof(struct node));
tmp->coff=coff;
tmp->expo=expo;
if(start==NULL||start->expo<expo)
{
tmp->link=start;
start=tmp;
return start;
}
for(p=start;p->link!=NULL&&p->link->expo>expo;p=p->link);

tmp->link=p->link;
p->link=tmp;
return start;
}










struct node *create(struct node *start)
{
int size=0,expo=0;
float coff=0.0f;
printf("Enter the size of list");
scanf("%d",&size);
if(size<=0)
{
printf("Invalid Size");
return start;
}
for(;size>0;size--)
{
printf("Enter the coefficient");
scanf("%f",&coff);
printf("Enter the exponent");
scanf("%d",&expo);
start=insSorted(start,coff,expo);
printf("\n");
}
return start;
}
void mul(struct node *p1,struct node *p2)
{
struct node *p3=NULL;
struct node *p2Beg=NULL;
if(p1==NULL)
p3=p2;
else if(p2==NULL)
p3=p1;
else
{
p2Beg=p2;
for(;p1!=NULL;p1=p1->link)
{
for(p2=p2Beg;p2!=NULL;p2=p2->link)
{

  p3=insSorted(p3,p1->coff*p2->coff,p1->expo+p2->expo);
}
}





}
display(p3);
p3=check(p3);
printf("\n-----------\n");
display(p3);





}







void main()
{
struct node *p1=NULL,*p2=NULL;
clrscr();
p1=create(p1);
clrscr();
display(p1);
printf("\n----------------Create the Second list----------------------------\n");
p2=create(p2);
display(p2);
printf("\n------------------Sum of Both the list is-------------\n");
sum(p1,p2);
printf("\n----------------------mul of both the list-------------\n");
mul(p1,p2);
getch();

}