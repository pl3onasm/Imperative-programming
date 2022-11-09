/* file: prob5.c
   author: David De Potter
   version: 2.0, this version works with an int function,
   so that the total sums are computed during the recurive calls
   and counted if they are equal to the target sum.
   description: IP Final 2015 resit, problem 5, recursion
*/

#include <stdio.h>
#include <stdlib.h>

int evaluateExps(int length, int n, int a[], int index, int sum) {
  // base case: check computed sum
  if (index == length-1){   
    return sum == n;
  }
  // recursive case: add / subract next term
  return evaluateExps(length, n, a, index+1, sum+a[index+1]) +
  evaluateExps(length, n, a, index+1, sum-a[index+1]);
}

int plusmin(int length, int a[], int n) {
  return evaluateExps(length, n, a, 0, a[0]);
}

int main() {
  int len, n, i, a[100];
  scanf ("%d %d", &len, &n);
  for (i=0; i < len; i++) {
    scanf("%d", &a[i]);
  }
  printf("%d\n", plusmin(len, a, n));
  return 0;
}