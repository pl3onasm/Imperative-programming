/* file: prob5.c
   author: David De Potter
   description: IP mid2022, problem 5, Curzon numbers
   We use modular exponentiation and rewrite the condition as
       (2ⁿ + 1) mod (2*n + 1) = 0
    ⇔ (2ⁿ mod (2*n + 1) + 1 mod (2*n + 1)) mod (2*n + 1) = 0
    ⇔ (2ⁿ mod (2*n + 1) + 1) mod (2*n + 1) = 0
*/

#include <stdio.h>
#include <stdlib.h>

int modExp (int a, int b, int n) {
  // computes a^b mod n using modular exponentiation
  int r = 1;
  while (b > 0) {
    if (b % 2) r = (r * a) % n;
    a = (a * a) % n;
    b /= 2;
  }
  return r;
}

int main(int argc, char *argv[]) {
  int n; 
  scanf("%d", &n);
  printf((modExp(2,n,2*n+1) + 1) % (2*n + 1) ? "NO\n" : "YES\n");
  return 0;
}