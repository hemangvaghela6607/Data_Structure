#include<stdio.h>
void Quick_sort(int[],int,int);
void main()
{
	int i,a[50],n;
	printf("Enter a num in list:");
	scanf("%d",&n);
	printf("Enter a number:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	Quick_sort(a,0,n-1);
	printf("sorrted array is :");
	for(i=0;i<n;i++)
	{
		printf("\t%d",a[i]);
	}

}
void Quick_sort(int a[],int lb,int ub)
{
	int pivot,i,j,temp;
	if(lb<ub){
		pivot=lb;
		i=lb+1;
		j=ub;
		while(i<=j){
		while(a[i]<=a[pivot] && i<=ub)
			i++;
		while(a[j]>a[pivot] && j>lb)
			j--;
		if(i<j){
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		 }	
		}
	temp=a[pivot];
	a[pivot]=a[j];
	a[j]=temp;
	Quick_sort(a,lb,j-1);
	Quick_sort(a,j+1,ub);
	}

}
