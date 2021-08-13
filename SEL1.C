/*SELECTION SORT*/
/*Input different values of n(some large values) to check the change in tame taken*/
/*As the value of n increases the time taken by the program also increases*/

#include<stdio.h>
#include<conio.h>
#include<time.h>

void main()
{
  int array[30000],n,c,d,pos,swap,r;
  clock_t start,end;
  double totaltime;
  clrscr();

  printf("enter no of elements\n");
  scanf("%d",&n);

  //Random number generator
  for(c=0;c<=(n-1);c++)
  {
    r=rand();
    array[c]=r;
  }


 start=clock();
 for(c=0;c<=(n-2);c++)
  {
   pos=c;
    for(d=c+1;d<=(n-1);d++)
    {
      if(array[pos]>array[d])
       pos=d;
    }
   
   if(pos!=c)
   {
     swap=array[c];
     array[c]=array[pos];
     array[pos]=swap;
   }
 }
end=clock();


printf("\nsorted list\n");
for(c=0;c<=(n-1);c++)
printf("%d\n",array[c]);

totaltime=(double)(end-start)/CLOCKS_PER_SEC;
printf("time taken is %e",totaltime);
getch();
}