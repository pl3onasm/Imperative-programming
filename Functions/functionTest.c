/* file: functionTest.c
   author: David De Potter
   Purpose: examples of using functions from the functions library
   Compile with: gcc -O2 -std=c99 -o a.out functions.c functionTest.c -lm
*/

#include "functions.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("\nSome usage examples of the functions\n\n");
  int a = 5, b = -7;
  printf("min(%d, %d) = %d\n", a, b, minimum(a, b));
  printf("max(%d, %d) = %d\n", a, b, maximum(a, b));
  printf("abs(%d) = %d\n\n", b, abs(b));

  int c = 128;
  printf("countDigits(%d) = %d\n", c, countDigits(c));
  printf("reverse(%d) = %d\n", c, reverseInt(c));
  printf("leftRotate(%d) = %d\n", c, leftRotate(c));
  printf("rightRotate(%d) = %d\n", c, rightRotate(c));
  printf("isPrime(%d) = %d\n", c, isPrime(c));
  printf("isPerfSquare(%d) = %d\n\n", c, isPerfSquare(c));

  char *bin = toBinary(c + 200);
  printf("binary representation of %d = %s\n\n", c + 200, bin);
  free(bin);
  
  int year = 2020;
  printf("isLeapYear(%d) = %d\n\n", year, isLeapYear(year));

  int d = 12, e = 18;
  printf("isDivisor(%d, %d) = %d\n", d, e, isDivisor(d, e));
  printf("GCD(%d, %d) = %d\n", d, e, GCD(d, e));
  printf("LCM(%d, %d) = %d\n", d, e, LCM(d, e));
  printf("areCoprime(%d, %d) = %d\n", d, e, areCoprime(d, e));

  int f = 2, g = 3;
  printf("power(%d, %d) = %d\n", f, g, power(f, g));
  printf("modExp(%d, %d, %d) = %d\n\n", f, g, a, modExp(f, g, a));

  int h = 12321;
  printf("isIntPalindrome(%d) = %d\n", h, isIntPalindrome(h));
  char str2[] = "abba";
  printf("isStrPalindrome(%s) = %d\n\n", str2, isStrPalindrome(&str2[0], &str2[3]));
  char str3[] = "hello world!";
  printf("reverseString(%s) = ", str3);
  reverseString(str3);
  printf("%s\n\n", str3);

  int arr[] = {9, 2, 5, 1, 7, 3, 4, 6, 8, 0};
  printf("array: ");
  printIntArray(arr, 10);
  printf("sorted array: ");
  selectionSort(arr, 10);
  printIntArray(arr, 10);

  return 0;
}