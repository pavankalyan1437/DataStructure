#include<stdio.h>
#include<stdlib.h>
struct que
{
	int r;
	int f;
	int a[50];
};
void enque(struct que *q,int ele)
{
	q->r++;
	q->a[q->r]=ele;
}
int deque(struct que *q)
{
	q->f++;
	return q->a[q->f];
}
int isempty(struct que *q)
{
	if(q->r==q->f)
		return 1;
	else
		return 0;
}
void main()
{
	int n,i,j,k;
	printf("enter number of nodes:");
	scanf("%d",&n);
	int a[n][n],visit[n];
	for(i=0;i<n;i++)
	{
		visit[i]=0;
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	struct que *q;
	q=(struct que *)malloc(sizeof(struct que));
	q->r=-1;
	q->f=-1;
	q->r++;
	q->a[q->r]=0;
	while(!isempty(q))
	{
		k=deque(q);
		if(visit[k]==0)
		{
			visit[k]=1;
			printf("%d ",k);
			for(i=0;i<n;i++)
			{
				if(a[k][i]==1 && visit[i]==0)
					enque(q,i);
			}
		}
	}
	
}
