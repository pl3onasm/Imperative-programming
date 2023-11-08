/* file: prob2.c
* author: David De Potter
* description: problem 2, double palindromes, mid2018
*/

#include <stdio.h>
#include <stdlib.h>

int isBinPalin(int n) {
  // check if n is a palindrome in base 2
  int rev = 0, m = n;
  while (m > 0) {
    rev = rev * 2 + m % 2;
    m /= 2;
  }
  return rev == n;
}

int isDecPalin(int n) {
  // check if n is a palindrome in base 10
  int rev = 0, m = n;
  while (m > 0) {
    rev = rev * 10 + m % 10;
    m /= 10;
  }
  return rev == n;
}

int main(int argc, char *argv[]) {
  int a, b, count = 0; 
  (void)! scanf("%d %d", &a, &b);
  
  for (int n = a; n <= b; ++n) {
    if (isDecPalin(n) && isBinPalin(n)) 
      count++;
  }

  printf("%d\n", count);
  return 0;
}