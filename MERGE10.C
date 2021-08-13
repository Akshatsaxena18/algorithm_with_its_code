#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<math.h>

void merge(int a[],int low,int mid,int high)
{
  int i,j,k,b[30000];
  i=low;j=mid+1;k=low;

  while(i<=mid && j<=high)
  {
    if(a[i]<=a[j])
      b[k++]=a[i++];
    else
      b[k++]=a[j++];
  }

  while(i<=mid) b[k++]=a[i++];
  while(j<=high)b[k++]=a[j++];


  for(k=low;k<=high;k++)
  a[k]=b[k];
}




void mergesort(int a[],int low,int high)
{
  int mid;
  if(low>=high)
  return;

  mid=floor((low+high)/2);
  mergesort(a,low,mid);
  mergesort(a,mid+1,high);
  merge(a,low,mid,high);
}




void main()
{
  int n,a[30000],k,r;
  clock_t start,end;
  double totaltime;
  clrscr();
  printf("\nenter value of n");
  scanf("%d",&n);
  for(k=1;k<=n;k++)
  {
    r=rand();
    a[k]=r;
  }


  start=clock();
  mergesort(a,1,n);
  end=clock();


  printf("\nsorted numbers\n");
  for(k=1;k<=n;k++)
  printf("%d\n",a[k]);
  totaltime=(double)(end-start)/CLOCKS_PER_SEC;
  printf("time taken is %e",totaltime);
  getch();
}