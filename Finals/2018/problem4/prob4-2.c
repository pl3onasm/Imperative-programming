/* file: prob4-1.c
   author: David De Potter
   version: 4.2, in this version we optimize
      the second split from 4.1, which was in O(n²),
      to be in O(n log n) using binary search
   description: IP Final 2018, problem 4, split3
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void *safeMalloc (int n) {
  void *ptr = malloc(n);
  if (ptr == NULL) {
    printf("Error: malloc(%d) failed. Out of memory?\n", n);
    exit(EXIT_FAILURE);
  }
  return ptr;
}

int solutionExists (int *arr, int totalSum, int n, int mid){
  /* checks if a solution can be found below mid, i.e. if  
     there exists a 3-way split such that maxsum < mid */
  int i = 0;
  while (arr[i++] < mid);
  while (arr[i++] < 2*mid);
  return totalSum - arr[i-1] < mid;
}


int binSearch (int *arr, int n, int right, int left) {
  /* Searches through the solution space, consisting  
     of a (virtual) ordered array of increasing maxsums. 
     Returns the lower bound of the solution space */
  while (left > right) {
    int mid = left + (right-left)/2;
    if (solutionExists(arr, left, n, mid)) right = mid + 1;
    else left = mid;
  }
  return left;
}

int main(int argc, char **argv){
  int n, min = INT_MAX;
  scanf("%d", &n);
  int *arr = safeMalloc(n*sizeof(int));
  for (int i=0; i < n; i++) {
    scanf("%d", &arr[i]);
    arr[i] += arr[i-1];   // precomputes partial sums
  }
  int totalSum = arr[n-1];
  printf("%d\n", binSearch(arr, n, 0, totalSum)); 
  free(arr);
  return 0; 
}