#include<stdio.h>
#include<conio.h>
#define MAX 100
void Merge_Sort(int A[],int low,int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        Merge_Sort(A,low,mid);
        Merge_Sort(A,mid+1,high);
        Merge(A,low,mid,high);
    }
}
void Merge(int A[],int low,int mid, int high)
{
      int i,j,k,temp[MAX];
      i=low;
      j=mid+1;
      k=low;
      while(i<=mid && j<=high)
      {
	     if(A[i]<=A[j])
            temp[k++]=A[i++];
	     else
            temp[k++]=A[j++];
      }
      while(i<=mid)
            temp[k++]=A[i++];

      while(j<=high)
	  	  temp[k++]=A[j++];

      for(i=low;i<=high;i++)
          A[i]=temp[i];
}
void main()
{
      int i,A[MAX],n;
      printf("\nEnter the Length of Array:=> ");
      scanf("%d",&n);
      printf("\nEnter Elements of Array:\n");
      for(i=0;i<n;i++)
      {
	    printf("\nA[%d]= ",i);
	    scanf("%d",&A[i]);
      }
      Merge_Sort(A,0,n-1);
      printf("\n\n\nSorted List:\n");
      printf("-----------\n");
      for(i=0;i<n;i++)
	    printf("%d  ",A[i]);
      printf("\n");
}
