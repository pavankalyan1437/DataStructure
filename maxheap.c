#include<stdio.h>
void swap(int a[],int i,int max)
{
	int b;
	b=a[i];
	a[i]=a[max];
	a[max]=b;
	printf("%d %d\n",a[max],a[i]);
}
void heapify(int a[],int n,int i)
{
	int l,r,max;
	l=2*i+1;
	r=2*i+2;
	max=-1;
	if(r<n)
	{
		if(a[l]>a[r])
			max=l;
		else
			max=r;
	}
	else if(l<n)
	{
		max=l;
	}
	if(max!=-1 && a[i]>a[max])
	{
		swap(a,i,max);
		heapify(a,n,max);
	}
}
void main()
{
	int a[20],n,i;
	printf("enter size:");
	scanf("%d",&n);
	printf("enter elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=n/2;i>=0;i--)
	{
		heapify(a,n,i);
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
