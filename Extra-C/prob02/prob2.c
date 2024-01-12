/* file: prob2.c
   author: David De Potter
   description: extra, prob2, adding large numbers
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

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
  // reads a string of characters and determines its length
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
  s[size] = '\0'; // add null terminator
  return s;
}

void add(char *a, int lenA, char *b, int lenB) {
  // adds two strings of digits
  int sumLen = MAX(lenA, lenB);   
  // allocate extra space for carry and null terminator
  char *sum = safeMalloc((sumLen + 2) * sizeof(char));  
  sum[sumLen] = '\0';
  int digitSum = 0;
  for (int i = 0; i < sumLen; ++i) {
    digitSum += i < lenA ? a[lenA - i - 1] - '0' : 0;
    digitSum += i < lenB ? b[lenB - i - 1] - '0' : 0;
    sum[sumLen - i - 1] = digitSum % 10 + '0';
    digitSum /= 10;   // carry
  }
  if (digitSum) {
    // shift all digits + '\0' one position to the right
    memmove(sum + 1, sum, sumLen + 1);
    sum[0] = digitSum + '0';
  }
  printf("%s\n", sum);
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