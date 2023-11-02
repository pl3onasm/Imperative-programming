/* file: prob3.c
   author: David De Potter
   description: extra, prob3, pandigital divisibility
*/

#include <stdio.h>
#include <stdlib.h>

int isDivisible(int *digits) {
  /* tests if the consecutive subnumbers of length 3
     are divisible by the consecutive primes below 20 */
  int primes[] = {2, 3, 5, 7, 11, 13, 17};
  for (int i = 1; i < 8; ++i) {
    if ((100 * digits[i] + 10 * digits[i + 1] 
         + digits[i + 2]) % primes[i - 1] != 0) 
      return 0;
  }
  return 1;
}

void printArray (int *digits) {
  // prints the digits array
  for (int i = 0; i < 10; ++i) 
    printf("%d", digits[i]);
  printf("\n");
}

void permute(int *digits, int *taken, int start, int end) {
  /* computes all permutations of the digits array and prints, in
     ascending order, those that satisfy the divisibility condition */ 
  if (start == end) {
    if (isDivisible(digits))
      printArray(digits);
    return;
  }
  // recursive case
  for (int i = 0; i < end; ++i) {
    if (!taken[i] && (start != 0 || i != 0)) {
      ++taken[i];
      digits[start] = i;  
      permute(digits, taken, start + 1, end);
      --taken[i];         // backtrack
    }
  }
}

  
int main() {
  int digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int taken[10] = {0};

  permute(digits, taken, 0, 10);
  
  return 0;
}
