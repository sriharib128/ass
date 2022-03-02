#include <stdio.h>
#include <stdlib.h>

int comp(const void* p1, const void* p2) {
  int* arr1 = (int*)p1;
  int* arr2 = (int*)p2;
  int diff1 = arr1[0] - arr2[0];
  if (diff1) return diff1;
  return arr1[1] - arr2[1];
}

int main()
{
  int arr[5][2] = {{5, 10},{2, 2}, {1, 5}, {5, 4}, {5, 20}};
  qsort(arr, 5, 2*sizeof(int), comp);
  for(int i=0;i<5;i++)
  {
    for(int j=0;j<2;j++)
      printf("%d ",arr[i][j]);
    printf("\n");
  }
  return 0;
}