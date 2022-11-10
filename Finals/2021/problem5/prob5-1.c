/* file: prob5-1.c
   author: David De Potter
   version: 5.1, using a void function, checkSequences,
      and an int pointer to keep track of the maximum
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

void checkSequences (char *s, char *seq, int n, int idx, int subLen, int *max) {
  if (idx >= n) {
    if (isPalindrome(0, subLen-1, seq) && subLen > *max) *max = subLen;
    return;
  }
  if (subLen < n) {    // take char at index idx from s
    seq[subLen] = s[idx];    
    checkSequences(s, seq, n, idx+1, subLen+1, max);
  }
  // skip current char from s
  checkSequences(s, seq, n, idx+1, subLen, max);
}

int main(int argc, char **argv){
  int n, max=0; 
  scanf("%d", &n);
  char *s = createString(n+1);
  char *seq = createString(n);
  scanf("%s", s);
  checkSequences(s, seq, n, 0, 0, &max);
  printf("%d\n", max);
  free(s); free(seq);
  return 0; 
}