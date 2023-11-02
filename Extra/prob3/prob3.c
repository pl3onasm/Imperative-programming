/* file: prob3.c
   author: David De Potter
   description: extra, prob3, pandigital divisibility
*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long llu;

void printArray (int *digits) {
  // prints the digits array
  for (int i = 0; i < 10; ++i) 
    printf("%d", digits[i]);
  printf("\n");
}

llu toLlu(int *digits) {
  // converts the digits array to an unsigned long long
  llu result = 0;
  for (int i = 0; i < 10; ++i) {
    result *= 10;
    result += digits[i];
  }
  return result;
}

void permute(int *digits, int *taken, int start, int end, int d) {
  /* computes all permutations of the digits array and prints, in
     ascending order, those that satisfy the divisibility condition */ 
  if (start == end) {
    if (toLlu(digits) % d == 0)
      printArray(digits);
    return;
  }
  // recursive case
  for (int i = 0; i < end; ++i) {
    if (!taken[i]                     // each digit can only be used once   
        && !(start == 0 && i == 0)) { // first digit cannot be 0
      ++taken[i];
      digits[start] = i;  
      permute(digits, taken, start + 1, end, d);
      --taken[i];                     // backtrack
    }
  }
}

int main() {
  int digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8 ,9};
  int taken[10] = {0};

  int d; 
  scanf("%d", &d);

  permute(digits, taken, 0, 10, d);
  
  return 0;
}
