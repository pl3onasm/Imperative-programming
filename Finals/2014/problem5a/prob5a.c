/* file: prob4b.c
   author: David De Potter
   description: IP Final 2014, problem 5a, Recursive algorithms,
   addition
*/

#include <stdio.h>
#include <stdlib.h>

int add(a, b){
  if (b == 0) return a;
  return add(a+1, b-1);
}

int main(int argc, char *argv[]) {
  int a, b;
  scanf("%d %d", &a, &b);
  printf("%d\n", add(a, b));  
  return 0;
}