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
	int n,i,j;
	printf("enter size of array:");
	scanf("%d",&n);
	int a[n];
	printf("enter elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
				swap(a,j,j+1);
		}
	}
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
