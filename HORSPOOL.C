#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 50
int t[MAX];
void shifttable(char p[])
{
int i,j,m;
m=strlen(p);
for(i=0;i<MAX;i++)
t[i]=m;
for(j=0;j<m-1;j++)
t[p[j]]=m-1-j;
}

int horspol(char src[], char p[])
{
int i,j,k,m,n;
n=strlen(src);
m=strlen(p);
printf("\nlength of text=%d",n);
printf("\nlength of pattern=%d",m);
i=m-1;
while(i<n)
{
k=0;
while((k<m)&&(p[m-1-k]==src[i-k]))
k++;
if(k==m)
return(i-m+1);
else
i+=t[src[i]];
}
return -1;
}

void main()
{
char src[100],p[100];
int pos;
clrscr();
printf("enter the text:\n");
gets(src);
printf("enter the pattern:\n");
gets(p);
shifttable(p);
pos=horspol(src,p);
if(pos>=0)
printf("\nthe pattern is found at posn %d\n",pos+1);
else
printf("\nthe pattern is not in the text\n");
getch();
}