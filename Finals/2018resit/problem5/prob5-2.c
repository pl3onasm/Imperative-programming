/* file: prob5-2.c
   author: David De Potter
   version: 5.2, using an int function
   description: IP Final 2018 Resit, problem 5,
   minimal palindromic partition
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(char *s, int start, int end) {
  if (start >= end) return 1;
  if (s[start] != s[end]) return 0;
  return isPalindrome(s, start+1, end-1);
}

int countPartitions(int start, int end, char *a) {
  int x, y = 10000;
  if (start > end) return 0;
  for (int j = start; j <= end; j++) {
    if (isPalindrome(a, start, j)) {
      x = countPartitions(j+1, end, a);
      y = x < y ? x : y;
    }
  }
  return 1 + y;
}

int minimalPalPartition(int start, int end, char *a) {
  return countPartitions (start, end, a); 
}

int main(int argc, char *argv[]) {
  char a[21];
  scanf("%s", a);
  printf("%d\n", minimalPalPartition(0, strlen(a)-1, a));
  return 0;
}
