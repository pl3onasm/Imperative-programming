#include "functions.ih"

int countDigits(int n) {
  // returns the number of digits in n
  int count = 0;
  while (n) {
    n /= 10;
    count++;
  }
  return count;
}

int reverseInt(int n) {
  // returns the reverse of a given integer n
  int rev = 0;
  while (n) {
    rev = rev * 10 + n % 10;
    n /= 10;
  }
  return rev;
}

int leftRotate(int x) {
  /* returns the left rotation of a given integer x,
     ignoring leading zeros, e.g. 1234 -> 2341 */
  int pow = power(10, countDigits(x)-1);
  int firstDigit = x / pow;
  return (x % pow)*10 + firstDigit;
}

int rightRotate(int x) {
  /* returns the right rotation of a given integer x,
     ignoring leading zeros, e.g. 1234 -> 4123 */
  int pow = power(10, countDigits(x)-1);
  int lastDigit = x % 10;
  return lastDigit * pow + x / 10;
}

char *toBinary(int n) {
  /* converts n to binary and stores the result in bin;
     returns a pointer to the string bin, which must be
     freed by the caller */
  char *bin = safeMalloc(33 * sizeof(char));  // 32 bits + '\0'
  int len = 0;
  while (n > 0) {
    bin[len++] = n % 2 + '0';
    n >>= 1;
  }
  bin[len] = '\0';
  reverseString(bin);
  return bin; 
}

int isLeapYear(int year) {
  // determines whether the given year is a leap year
  return (year % 4 == 0 && year % 100 != 0) 
          || year % 400 == 0;
}

int isIntPalindrome(int n) {
  // checks whether given integer n is a palindrome
  return n == reverseInt(n);
}
