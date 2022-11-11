/* file: prob5-2.c
   author: David De Potter
   version: 5.2, using an int function to compute
      result during recursive calls
   description: IP Final 2017 Resit, problem 5, 
      sums and products
*/

#include <stdio.h>
#include <stdlib.h>

int countExps(int target, int digit, int prev, int current, int product){
  int result = 0;
  if (digit == 9) return current + 9*product == target; 
  if (prev) { // previous operator was *
    result = countExps (target, digit+1, 0, current + product * digit, 1) 
           + countExps (target, digit+1, 1, current, product * digit);    
  } else {    // previous operator was +
    result = countExps (target, digit+1, 0, current + digit, 1) 
           + countExps (target, digit+1, 1, current, digit);    
  }
  return result;
}

int prodSum(int n){
  return countExps(n, 1, 0, 0, 1);
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  printf("%d\n", prodSum(n)); 
  return 0;
}