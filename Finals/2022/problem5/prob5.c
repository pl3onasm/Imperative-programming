/* file: prob5.c
   author: David De Potter
   description: IP Final 2022, problem 5, sum with k elements
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

int checkSum(int taken, int remaining, int k, int n, int *arr){
  if (taken == k) return remaining == 0;
  if (n == 0) return 0;
  return checkSum(taken, remaining, k, n-1, arr) 
      || checkSum(taken+1, remaining - arr[n-1], k, n-1, arr);
}

int main(int argc, char **argv){
  int target, k, n;
  scanf("%d %d %d", &target, &k, &n);
  int *arr = createArray(n);
  readIntArray(n, arr);
  printf(checkSum(0, target, k, n, arr) ? "YES\n" : "NO\n");
  free(arr);
  return 0; 
}