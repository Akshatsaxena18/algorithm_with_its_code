#include<stdio.h>
void DFS(int[20][20],int,int[20],int);
void main()
{
 int n,a[20][20],i,j,visited[20],source;
 clrscr();

 printf("Enter the no of vertices:");
 scanf("%d",&n);

 printf("\nenter the adjacency matrix:\n");
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
   scanf("%d",&a[i][j]);

 for(i=1;i<=n;i++)
  visited[i]=0;

  printf("\nenter the source code:");
  scanf("%d",&source);

  DFS(a,source,visited,n);

  for(i=1;i<=n;i++)
  {
   if(visited[i]==0)
   {
    printf("\ngraph is nt connected");
    getch();
    exit(0);
   }
  }
   printf("\ngraph is connected\n");
   getch();
}

void DFS(int a[20][20], int u, int visited[20], int n)
{
 int v;
 visited[u]=1;
 for(v=1;v<=n;v++)
 {
  if(a[u][v]==1&&visited[v]==0)
  DFS(a,v,visited,n);
 }
}