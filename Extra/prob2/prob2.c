/* file: prob2.c
   author: David De Potter
   description: extra, prob2, adding large numbers
*/

#include <stdio.h>
#include <stdlib.h>

void *safeMalloc (int n) {
  // checks if memory has been allocated successfully
  void *p = malloc(n);
  if (p == NULL) {
    printf("Error: malloc(%d) failed. Out of memory?\n", n);
    exit(EXIT_FAILURE);
  }
  return p;
}

void *safeRealloc (void *p, int n) {
  // checks if memory has been reallocated successfully
  p = realloc(p, n);
  if (p == NULL) {
    printf("Error: realloc(%d) failed. Out of memory?\n", n);
    exit(EXIT_FAILURE);
  }
  return p;
}

char *readString(int *len) {
  // reads a string from stdin
  int capacity = 50, size = 0;
  char ch;
  char *s = safeMalloc(capacity * sizeof(char));
  while (scanf("%c", &ch) && ch != '\n' && ch != EOF) {
    if (size >= capacity) {
      capacity *= 2;
      s = safeRealloc(s, capacity * sizeof(char));
    }
    s[size++] = ch;
  }
  *len = size;
  return s;
}

void print(char *s, int len) {
  // prints a string of length len
  for (int i = 0; i < len; ++i) 
    printf("%c", s[i]);
  printf("\n");
}

void add(char *a, int lenA, char *b, int lenB) {
  // adds two large numbers
  int len = lenA > lenB ? lenA : lenB;
  char *sum = safeMalloc(len * sizeof(char));
  int carry = 0;
  for (int i = 0; i < len; ++i) {
    int digitA = i < lenA ? a[lenA - i - 1] - '0' : 0;
    int digitB = i < lenB ? b[lenB - i - 1] - '0' : 0;
    int digitSum = digitA + digitB + carry;
    sum[len - i - 1] = digitSum % 10 + '0';
    carry = digitSum / 10;
  }
  
  if (carry) printf("%d", carry);
  
  print(sum, len);
  free(sum);
}
  
int main() {
  int lenA, lenB;

  char *a = readString(&lenA);
  char *b = readString(&lenB);

  add(a, lenA, b, lenB);

  free(a);
  free(b);
 
  return 0;
}