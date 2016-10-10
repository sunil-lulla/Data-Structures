#include<stdio.h>
#include<conio.h>
#define MAX 20
char stack[MAX];
void push();
char pop();
int tos=-1;
void main()
{
char str[20];
int i=0;
clrscr();
printf("Enter a string");
gets(str);
for(;i<strlen(str);i++)
push(str[i]);
for(i=0;i<strlen(str);i++)
printf("%c",pop());
getch();
}



char pop()
{
if(tos==-1)
{
printf("Underflow");
getch();
exit(1);
}
return stack[tos--];
}






void push(char ch)
{
if(tos==MAX-1)
{
printf("Stack overflow\n");
return;
}
stack[++tos]=ch;
}

