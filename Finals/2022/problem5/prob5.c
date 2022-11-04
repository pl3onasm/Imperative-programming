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

int checkSum(int idx, int taken, int rem, int k, int n, int *arr){
  if (taken == k) return rem == 0;
  if (idx == n) return 0;
  return checkSum(idx+1, taken, rem, k, n, arr) 
         || checkSum(idx+1, taken+1, rem-arr[idx], k, n, arr);
}

int main(int argc, char **argv){
  int target, k, n, solved = 0;
  scanf("%d %d %d", &target, &k, &n);
  int *arr = createArray(n);
  readIntArray(n, arr);
  printf(checkSum(0, 0, target, k, n, arr) ? "YES\n" : "NO\n");
  free(arr);
  return 0; 
}