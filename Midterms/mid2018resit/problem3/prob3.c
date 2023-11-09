/* file: prob3.c
* author: David De Potter
* description: problem 3, takuzu numbers, resit mid2018
*/

#include <stdio.h>
#include <stdlib.h>

int toBinary (int n, int bin[50]) {
  /* computes the binary representation of n and 
     returns its length */
  int i = 0;
  while (n > 0) {
    bin[i++] = n % 2; 
    n >>= 1;
  }
  return i; 
}

int checkIfTakuzu (int len, int bin[50]) {
  /* checks the binary representation stored in the
     array bin to see if it meets the Takuzu criteria */
  int count0 = 0, count1 = 0, countAdj1 = 0, countAdj0 = 0;

  for (int i = 0; i < len; ++i) {
    if (bin[i] == 0) {
      count0++;
      countAdj1 = 0;
      countAdj0++;
    } else {
      count1++;
      countAdj1++;
      countAdj0 = 0;
    }
    if (countAdj1 > 2 || countAdj0 > 2) return 0;
  }
  return count1 == count0;
}

int main(int argc, char *argv[]) {
  int n, index = 0, number = 1, bin[50];

  (void)! scanf("%d", &n);
  
  while (index != n) {
    number++;
    int len = toBinary(number, bin);
    if (checkIfTakuzu(len, bin)) index++;
  }

  printf("%d\n", number);
  return 0;
}
