/* file: prob4b.c
   author: David De Potter
   description: IP Final 2014, problem 5b, 
   Recursive algorithms, kth smallest element
*/

#include <stdio.h>
#include <stdlib.h>

void swap(int i, int j, int *a){
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}

int partition(int *arr, int len) {
  int idx=0, pivot = arr[0];
  swap(0, len-1, arr);
  for (int i = 0; i < len-1; i++)
    if (arr[i] < pivot){
      swap(i, idx, arr);
      idx++;
    }
  swap(idx, len-1, arr);
  return idx;
}

int kthSmallest(int k, int len, int *arr) {
  if (len == 1) 
    return arr[0];
  int p = partition(arr, len);
  if (p == k) return arr[p];
  if (p < k) return kthSmallest(k-p-1, len-p-1, arr+p+1);
  return kthSmallest(k, p, arr);
}

int main(int argc, char *argv[]) {
  int n, k, arr[100], len=0;
  scanf("%d", &k);
  while (scanf("%d", &n) == 1) 
    arr[len++] = n;
  printf("%d\n", kthSmallest(k, len, arr));
  return 0;
}