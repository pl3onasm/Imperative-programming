/* file: prob5-1.c
   author: David De Potter
   version: 5.1, using a void function, string library, and
      an int pointer to keep track of the the maximum
   description: IP Final 2021, problem 5, longest palindromic sequence
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int isPalindrome(char *s, int index) {
  if (index >= strlen(s) / 2) return 1;
  if (s[index] != s[strlen(s) - index - 1]) return 0;
  return isPalindrome(s, index + 1);
}

void checkSequences (char *s, char *seq, int idx, int subidx, int *max) {
  if (idx > strlen(s)) return;
  if (isPalindrome(seq, 0) && subidx > *max) *max = subidx;
  if (subidx < strlen (s)) {
    seq[subidx] = s[idx];     // take char at index idx from s
    seq[subidx + 1] = '\0';
    checkSequences(s, seq, idx+1, subidx+1, max);
  }
  seq[subidx] = '\0';         // skip current char from s
  checkSequences(s, seq, idx+1, subidx, max);
}

int main(int argc, char **argv){
  int n, max=0; 
  scanf("%d", &n);
  char *s = createString(n+1);
  char *seq = createString(n+1);
  scanf("%s", s);
  checkSequences(s, seq, 0, 0, &max);
  printf("%d\n", max);
  free(s); free(seq);
  return 0; 
}