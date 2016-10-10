#include<stdio.h>
#include<conio.h>

#define MAX 20
char stack[MAX];
int tos=-1;


void push(char);
char pop();
int isValid();
int isBalanced();




void main()
{
char arr[20];
clrscr();
printf("Enter the paretheses\n");
gets(arr);
if(isValid(arr)==1)
printf("K");
else
printf("not k");
getch();
}



int isValid(char str[])
{
int i=0;
char temp;

for(i=0;i<strlen(str);i++)
{
temp=str[i];
if(temp=='('||temp=='{'||temp=='[')
push(temp);
else if(temp==')'||temp==']'||temp=='}')
{
if(tos==-1)
return 0;
else
{
 temp=pop();
 if(!isBalanced(temp,str[i]))
	   return 0;
}

 }








}

if(tos==-1)
return 1;
else
return 0;










}





int isBalanced(char ch1,char ch2)
{
 if(ch1=='('&&ch2==')')
 return 1;
 if(ch1=='['&&ch2==']')
 return 1;
 if(ch1=='{'&&ch2=='}')
 return 1;
 return 0;
}


void push(char ch)
{
if(tos==MAX-1)
{
return;
}
stack[++tos]=ch;
}



char pop()
{
if(tos==-1)
exit(0);

return stack[tos--];
}
