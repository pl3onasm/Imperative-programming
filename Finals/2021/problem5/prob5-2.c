/* file: prob5-2.c
   author: David De Potter
   version: 5.2, using an int function, getMaxPal
   description: IP Final 2021, problem 5, longest palindromic sequence
*/

#include <stdio.h>
#include <stdlib.h>

void *safeCalloc (int n, int size) {
  /* allocates n elements of size size, initializing them to 0, and
     checks whether the allocation was successful */
  void *ptr = calloc(n, size);
  if (ptr == NULL) {
    printf("Error: calloc(%d, %d) failed. Out of memory?\n", n, size);
    exit(EXIT_FAILURE);
  }
  return ptr;
}

char *createString(int size){
  char *string = safeCalloc(size, sizeof(char));
  return string;
}

int isPalindrome (int start, int end, char *s) {
  if (start >= end) return 1;
  if (s[start] != s[end]) return 0;
  return isPalindrome(start+1, end-1, s);
}

int getMaxPal (char *s, char *seq, int n, int idx, int subLen) {
  int x = 0;
  if (idx >= n) {
    if (isPalindrome(0, subLen-1, seq)) return subLen;
    return 0;
  }
  if (subLen < n) {    // take char at index idx from s
    seq[subLen] = s[idx];    
    x = getMaxPal(s, seq, n, idx+1, subLen+1);
  }
  // skip current char from s
  int y = getMaxPal(s, seq, n, idx+1, subLen);

  return x > y ? x : y;
}

int main(int argc, char **argv){
  int n; 
  scanf("%d", &n);
  char *s = createString(n+1);
  char *seq = createString(n);
  scanf("%s", s);
  printf("%d\n", getMaxPal(s, seq, n, 0, 0));
  free(s); free(seq);
  return 0; 
}
