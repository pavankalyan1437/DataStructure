#include<stdio.h>
void swap(int a[],int i,int min)
{
	int b;
	b=a[i];
	a[i]=a[min];
	a[min]=b;
	//printf("%d %d",a[min],a[i]);
	printf("\n");
}
void heapify(int a[],int n,int i)
{
	int l,r,min;
	l=2*i+1;
	r=2*i+2;
	min=-1;
	if(r<n)
	{
		if(a[l]<a[r])
			min=l;
		else
			min=r;
	}
	else if(l<n)
	{
		min=l;
	}
	if(min!=-1 && a[i]>a[min])
	{
		swap(a,i,min);
		heapify(a,n,min);
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
