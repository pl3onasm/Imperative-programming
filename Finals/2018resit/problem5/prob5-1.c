/* file: prob5.c
   author: David De Potter
   version: 5.1, using a void function
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

void partitionGenerator(int idx, char *a, int size, int *min, int *count) {
  if (idx > size) {
    *min = *min < *count ? *min : *count;
    return;
  }
  for (int j = idx; j <= size; j++) {
    if (isPalindrome(a, idx, j)) {
      ++*count;
      partitionGenerator(j+1, a, size, min, count);
      --*count;	  // backtrack
    }
  }
}

int minimalPalPartition(int i, int size, char *a) {
  int min = INT_MAX, count = 0;
  partitionGenerator (i, a, size, &min, &count);
  return min;
}

int main(int argc, char *argv[]) {
  char a[21];
  scanf("%s", a);
  printf("%d\n", minimalPalPartition(0, strlen(a)-1, a));
  return 0;
}
