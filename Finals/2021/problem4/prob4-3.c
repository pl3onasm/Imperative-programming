/* file: prob4-3.c
   author: David De Potter
   version: 4.3, same as 4.2, but using an explicit 
      function to get maximum of two integers
   description: IP Final 2021, problem 4, maximum sum
*/

#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
  return a > b ? a : b;
}

int getMaxSum(int arr[], int idx, int sum, int len) {
  // get maximum sum of subsequences with len >= 2
  if (idx < 0) return len >= 2 ? sum : 0;
  return max(getMaxSum(arr, idx-2, sum + arr[idx], len+1),
             getMaxSum(arr, idx-1, sum, len));
}

int main(int argc, char **argv){
  int arr[35], n; 
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d ", &arr[i]);
  printf("%d\n", getMaxSum(arr, n-1, 0, 0));
  return 0; 
}