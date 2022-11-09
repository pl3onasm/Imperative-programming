/* file: prob5-3.c
   author: David De Potter
   version: 5.3, using an int function
   description: IP Final 2016, problem 5, balanced subsequences
*/

#include <stdio.h>
#include <stdlib.h>

int generateSequences(int a[], int idx, int evens, int odds){
  if (idx < 0){  // base case
    return evens && evens == odds;
  }
  // put the current element a[idx] into the sequence or skip it
  return generateSequences(a, idx-1, evens+(!(a[idx]%2)), odds+a[idx]%2)
       + generateSequences(a, idx-1, evens, odds);
}

int numberOfBalancedSubsets(int length, int a[]) {
  return generateSequences(a, length-1, 0, 0); 
}

int main(int argc, char *argv[]) {
  int n, i, seq[20];
  scanf ("%d\n", &n);
  for (i=0; i < n; i++) {
    scanf("%d", &seq[i]);
  }
  printf("%d\n", numberOfBalancedSubsets(n, seq));
  return 0;
}