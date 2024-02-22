/* 
  file: prob3-2.c
  author: David De Potter
  description: extra, problem 3, maximum path
  version: 3.2, using functions library and
    while the time complexity is still in O(n²), the
    space complexity is now in O(n) instead of O(n²),
    by using only two rows of size n instead of a
    2D array of size n²
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../Functions/clib/clib.h"

int maxPath (int *row1, int *row2, int n) {
  /* computes the maximum path cost */
  // read the first row
  READ_ARRAY(row1, "%d ", 1);
  
  // calculate the maximum path cost for each cell
  for (int i = 2; i <= n; ++i) {
    // read the next row
    READ_ARRAY(row2, "%d ", i);

    // calculate the maximum path cost for each cell
    for (int j = 0; j < i; ++j) {
      if (j == 0)
        row2[j] += row1[j];
      else if (j == i-1)
        row2[j] += row1[j-1];
      else
        row2[j] += MAX(row1[j-1], row1[j]);
    }
    SWAP(row1, row2);
  }
  
  // take maximum of the last row
  int max = row1[0];
  for (int j = 1; j < n; ++j)
    max = MAX(max, row1[j]);
  
  return max;
}

int main() {
  int n;
  (void)! scanf("%d", &n);
 
  CREATE_ARRAY(int, row1, n);
  CREATE_ARRAY(int, row2, n);

  printf("%d\n", maxPath(row1, row2, n));

  free(row1);
  free(row2);

  return 0;
}
