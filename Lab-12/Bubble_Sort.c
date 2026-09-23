#include<stdio.h>

void bubble_sort(int arr[], int n) {
  int i, j, temp;
  for (i=0;i<n-1;i++)
    {
    for (j=0;j<n-i-1;j++)
    {
      if (arr[j]>arr[j+1])
      {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}


int main() {
  int array[100], search, i, n;

  printf("\nEnter the Length of Array:=> ");
  scanf("%d",&n);
  printf("\nEnter Elements of Array:\n");
      for(i=0;i<n;i++)
      {
	    printf("\nA[%d]= ",i);
	    scanf("%d",&array[i]);
      }

  bubble_sort(array, n);

  printf("\nSorted Array: ");
  for(i=0;i<n;i++)
        printf("%d  ",array[i]);
}
