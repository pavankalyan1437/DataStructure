#include<stdio.h>
void swap(int a[],int i,int j)
{
	int temp;
	temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
void quicksort(int a[],int start,int end)
{
	int i, j, pivote, temp;
	if(start<end)
	{
		pivote=a[start];
		i=start;
		j=end;
		while(i<j)
		{
			while(a[i]<=pivote && i<end)
				i++;
			while(a[j]>pivote)
				j--;
			if(i<j)
			{
				swap(a,i,j);
			}
		}
	swap(a,start,j);
	quicksort(a,start,j-1);
	quicksort(a,j+1,end);
	}
}
void main()
{
	int i,n;
	printf("enter no.of elements: ");
	scanf("%d",&count);
	int a[count];
	printf("enter elements: ");
	for(i=0;i<count;i++)
		scanf("%d",&a[i]);
	quicksort(a,0,count-1);
	printf("The Sorted Order is: ");
	for(i=0;i<count;i++)
		printf(" %d",a[i]);
}
