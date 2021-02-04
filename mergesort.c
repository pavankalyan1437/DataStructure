#include<stdio.h>
int merge(int a[],int l1,int l2,int h2)
{
	int temp[h2];
	int i,j,k;
	i=l1;
	j=l2;
	k=l1;
	while( i<l2 && j<=h2)
	{
		if(a[i]<a[j])
		{
			temp[k]=a[i];
			k++;
			i++;

		}
		else
		{
			temp[k]=a[j];
			k++;
			j++;
		}
	}
	while(i<l2)
	{
		temp[k]=a[i];
		k++;
		i++;
	}
	while(j<=h2)
	{
		temp[k]=a[j];
		k++;
		j++;
	}
	for(i=l1;i<=h2;i++)
	{
		a[i]=temp[i];
	}
}
int mergesort(int a[],int l,int h)
{
	int m=(l+h)/2;
	if(l==h)
		return 0;
	mergesort(a,l,m);
	mergesort(a,m+1,h);
	merge(a,l,m+1,h);
}

void main()
{
	int size;
	printf("enter size:");
	scanf("%d",&size);
	int l,h,i;
	int a[size];
	printf("enter elements:");
	for(i=0;i<size;i++)
		scanf("%d",&a[i]);
	l=0;
	h=size-1;
	mergesort(a,l,h);
	printf("sorted list is:");
	for(i=0;i<size;i++)
		printf("%d ",a[i]);
}








