/* file: vocabTest.c
   author: David De Potter
   Purpose: examples of using functions from vocabulary.c
   Compile with: gcc -O2 -std=c99 -o a.out vocabulary.c vocabTest.c -lm
*/

#include "vocab.h"

int main() {
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

  char str[100];
  printf("length of %d in binary = %d\n", c, toBinary(c, str));
  printf("binary representation of %d = %s\n\n", c, str);

  int year = 2020;
  printf("isLeapYear(%d) = %d\n\n", year, isLeapYear(year));

  int d = 12, e = 18;
  printf("isDivisor(%d, %d) = %d\n", d, e, isDivisor(d, e));
  printf("GCD(%d, %d) = %d\n", d, e, GCD(d, e));
  printf("LCM(%d, %d) = %d\n", d, e, LCM(d, e));
  printf("areCoprime(%d, %d) = %d\n", d, e, areCoprime(d, e));
  printf("sumDivisors(%d) = %d\n\n", d, sumDivisors(d));

  int f = 2, g = 3;
  printf("power(%d, %d) = %d\n", f, g, power(f, g));
  printf("modExp(%d, %d, %d) = %d\n\n", f, g, a, modExp(f, g, a));

  int h = 12321;
  printf("isIntPalindrome(%d) = %d\n", h, isIntPalindrome(h, 10));
  char str2[] = "abba";
  printf("isPalindrome(%s) = %d\n\n", str2, isPalindrome(0, 3, str2));
  char str3[] = "hello";
  printf("reverse(%s) = %s\n\n", str3, reverse(str3, 4));

  int arr[] = {9, 2, 5, 1, 7, 3, 4, 6, 8, 0};
  printf("array: ");
  printIntArray(arr, 10);
  printf("sorted array: ");
  selectionSort(arr, 10);
  printIntArray(arr, 10);

  return 0;
}