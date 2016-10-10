#include<stdio.h>
#include<conio.h>

struct node
{
int a[15880];
struct node *link;
};

void main()
{
      int i=0;
 struct node *p=NULL,*tmp;

 clrscr();

 tmp=(struct node *)malloc(sizeof(struct node));

 for(i=0;i<=3000;i++)
 {
  p=(struct node *)malloc(sizeof(struct node));





 if(p==NULL)
 {

 printf("Overflow %d",i);
 getch();
 break;
 }

 tmp->link=p;
 p->link=NULL;

 printf("%d\t",i);


 }





 printf("Done");
 getch();


}