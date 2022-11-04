/* file: prob4.c
   author: David De Potter
   description: IP Final 2022, problem 4, Intervals
*/

#include <stdio.h>
#include <stdlib.h>

void *safeMalloc (int n) {
  /* allocates n bytes of memory and checks whether the allocation
     was successful */
  void *ptr = malloc(n);
  if (ptr == NULL) {
    printf("Error: malloc(%d) failed. Out of memory?\n", n);
    exit(EXIT_FAILURE);
  }
  return ptr;
}

int *copySubArray(int left, int right, int arr[]) {
  /* copies the subarray arr[left..right] into a new array */
  int i, *copy = safeMalloc((right - left)*sizeof(int));
  for (i=left; i < right; i++) 
    copy[i - left] = arr[i];
  return copy;
}

void mergeSort(int length, int arr[]) {
  /* sorts an array of integers in O(n log n) time */
  int l, r, mid, idx, *left, *right;
  if (length <= 1) {
    return;
  }
  mid = length/2;
  left = copySubArray(0, mid, arr);
  right = copySubArray(mid, length, arr);
  mergeSort(mid, left);
  mergeSort(length - mid, right);
  idx = 0;
  l = 0;
  r = 0;
  while ((l < mid) && (r < length - mid)) {
    if (left[l] < right[r]) {
      arr[idx] = left[l];
      l++;
    } else {
      arr[idx] = right[r];
      r++;
    }
    idx++;
  }
  while (l < mid) {
    arr[idx] = left[l];
    idx++;
    l++;
  }
  while (r < length - mid) {
    arr[idx] = right[r];
    idx++;
    r++;
  }
  free(left);
  free(right);
}

int *createArray (int size) {
  // creates an array of size integers
  int *arr = safeMalloc(size * sizeof(int));
  return arr;
}

void readIntArray(int size, int *arr){
  // reads an array of size integers from stdin
  for (int i=0; i < size; i++) 
    scanf("%d", &arr[i]);
}

void printIntervals(int n, int *arr){
  int i = 0;
  while (i < n) {
    printf("%d", arr[i++]); 
    int interval = 0;
    while (i < n && (arr[i] == arr[i-1] + 1 || arr[i] == arr[i-1])) {
      if (!interval && arr[i] != arr[i-1]) {
        printf("..");
        interval = 1;
      }
      ++i;
    }
    if (interval) { // we encountered an interval and need to close it
      printf("%d", arr[i-1]);
    }
    if (i < n) {  // we have more elements to print
      printf(",");
    }
  }
  printf("\n"); 
}

int main(int argc, char **argv){
  int n; 
  scanf("%d", &n);
  int *arr = createArray(n);
  readIntArray(n, arr);
  mergeSort (n, arr);
  printIntervals(n, arr);
  free(arr);
  return 0; 
}