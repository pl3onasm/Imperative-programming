/* file: prob7.c
* author: David De Potter
* description: extra, problem 7, dividing large numbers
*/

#include <stdio.h>
#include <stdlib.h>

void *safeCalloc (int n, int size) {
  /* allocates memory and checks if it was successful */
  void *ptr = calloc(n, size);
  if (ptr == NULL) {
    printf("Error: calloc(%d, %d) failed. Out of memory?\n", n, size);
    exit(EXIT_FAILURE);
  }
  return ptr;
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
  char *s = safeCalloc(capacity, sizeof(char));
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

int compare(char *a, char *b, int lenDiff) {
  // compares two strings of characters
  if (lenDiff > 0) return 1;
  if (lenDiff < 0) return -1;
  // if a and b are of equal length, 
  // compare them digit by digit
  while (*a && *b) {
    if (*a > *b) return 1;
    if (*a < *b) return -1;
    a++;
    b++;
  }
  return 0; // a and b are equal
}

void subtract(char **a, char *b, int *lenA, int lenB) {
  // subtracts two strings of characters: a - b

  for (int i = *lenA - 1, j = lenB - 1; j > -1; j--, i--) {
    if ((*a)[i] < b[j]) {
      (*a)[i - 1]--;               // borrow from preceding digit
      (*a)[i] += 10;               // add 10 to current digit
    }
    (*a)[i] += '0' - b[j];         // subtract digits
  }

  while ((*a)[0] == '0' && *lenA > 1) {
    (*a)++;                        // remove leading zeroes
    (*lenA)--;
  }

  if ((*a)[0] == '0')       
    *lenA = 0;                     // may be overwritten
}

int main(int argc, char *argv[]) {
  int lenA = 0, lenB = 0, lenR = 0, lenQ = 0;

  char *a = readString(&lenA);
  char *b = readString(&lenB);
  
  char *rem = safeCalloc(lenA+1, sizeof(char));
  char *quot = safeCalloc(lenA+1, sizeof(char));

  char *remc = rem, *quotc = quot; // pointer copies for freeing memory
  int idx = 0;

  while (a[idx]) {
    
    rem[lenR++] = a[idx++];        // add next digit 
    quot[lenQ++] = '0';            // initialize quotient's next digit
    
    while (compare(rem, b, lenR - lenB) >= 0) {
      subtract(&rem, b, &lenR, lenB);
      quot[lenQ - 1]++;            // increment quotient's last digit
    }

    if (lenR == 1 && rem[0] == '0') 
      lenR--;                      // may be overwritten
  }

  while (*quot == '0' && lenQ > 1) {
    quot++;                        // remove leading zeroes
    lenQ--;
  }

  printf("%s\n%s\n", quot, rem);

  free(remc); free(quotc);         // free memory using pointer copies
  free(a); free(b);  
  return 0;
}