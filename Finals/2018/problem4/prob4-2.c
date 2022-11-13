/* file: prob4-2.c
   author: David De Potter
   version: 4.2, in this version we optimize
      the second split from 4.1, which was in O(n²),
      to be in O(n log n) using binary search
   description: IP Final 2018, problem 4, split3
*/

#include <stdio.h>
#include <stdlib.h>

void *safeMalloc (int n) {
  void *ptr = malloc(n);
  if (ptr == NULL) {
    printf("Error: malloc(%d) failed. Out of memory?\n", n);
    exit(EXIT_FAILURE);
  }
  return ptr;
}

int solutionExists (int *arr, int n, int mid){
  /* checks if a solution can be found below mid, i.e. if  
     there exists a 3-way split such that maxsum < mid */
  int sum = 0, split = 0; 
  for (int i = 0; i < n && split <= 2; ++i){
    if (arr[i] > mid) return 0;
    sum += arr[i];
    if (sum > mid){
      sum = arr[i];
      split++;
    }
  }                   // solution exists if didn't have  
  return split <= 2;  // to split more than 2 times                      
}

int binSearch (int *arr, int n, int left, int right) {
  /* Searches through the solution space, consisting  
     of a (virtual) ordered array of increasing maxsums. 
     Returns the lower bound of the solution space */
  if (left > right) return left;
  int mid = left + (right - left) / 2;
  if (solutionExists(arr, n, mid))
    return binSearch(arr, n, left, mid-1);
  return binSearch(arr, n, mid+1, right);
}
    

int main(int argc, char **argv){
  int n, totalSum = 0;
  scanf("%d", &n);
  int *arr = safeMalloc(n*sizeof(int));
  for (int i=0; i < n; i++) {
    scanf("%d", &arr[i]);
    totalSum += arr[i];
  }
  printf("%d\n", binSearch(arr, n, 0, totalSum)); 
  free(arr);
  return 0; 
}