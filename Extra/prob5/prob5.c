/* file: prob3.c
   author: David De Potter
   description: extra, prob5, binary palindromes
*/

#include <stdio.h>
#include <stdlib.h>

int isPalindrome(int n) {
  // checks if n is a palindrome in binary
  int rev = 0, orig = n;
  while (orig) {
    rev = (rev << 1) | (orig & 1);
    orig >>= 1;
  }
  return rev == n;
}

void printBinary(int n) {
  // prints the binary representation of n
  if (!n) {
    printf("0");
    return;
  }
  while (n) {
    printf("%d", n & 1);
    n >>= 1;
  }
}

void generatePalindromes(int a, int b) {
  // generates all binary palindromes in the range [a, b]
  for (int i = a; i <= b; ++i)
    if (isPalindrome(i)) {
      printf("%d: ", i); 
      printBinary(i);
      printf("\n");
    }
}

int main() {
  int a, b;
  (void)! scanf("%d %d", &a, &b);

  generatePalindromes(a, b);
  
  return 0;
}
