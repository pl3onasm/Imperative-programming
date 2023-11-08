/* file: prob5-1.c
   author: David De Potter
   version: 5.1, using a void function, partitionGenerator
   description: IP Final 2018 Resit, problem 5,
   minimal palindromic partition
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int isPalindrome(char *s, int start, int end) {
  if (start >= end) return 1;
  if (s[start] != s[end]) return 0;
  return isPalindrome(s, start+1, end-1);
}

void partitionGenerator(int left, int right, char *a, int *min, int *count) {
  if (left > right) {
    *min = *min < *count ? *min : *count;
    return;
  }
  for (int j = left; j <= right; j++) {
    if (isPalindrome(a, left, j)) {
      ++*count;
      partitionGenerator(j+1, right, a, min, count);
      --*count;	  // backtrack
    }
  }
}

int minimalPalPartition(int left, int right, char *a) {
  int min = INT_MAX, count = 0;
  partitionGenerator (left, right, a, &min, &count);
  return min;
}

int main(int argc, char *argv[]) {
  char a[21];
  (void)! scanf("%s", a);
  printf("%d\n", minimalPalPartition(0, strlen(a)-1, a));
  return 0;
}
