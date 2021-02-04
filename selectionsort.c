#include<stdio.h>
void swap(int a[],int i,int j)
{
	int temp;
	temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
void main()
{
	int n,i,j,min,loc;
	printf("enter size of array:");
	scanf("%d",&n);
	int a[n];
	printf("enter elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		min=a[i];
		loc=i;
		for(j=i;j<n;j++)
		{
			if(a[j]<min)
			{
				min=a[j];
				loc=j;
			}
		}
		swap(a,i,loc);
	}
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
