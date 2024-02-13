/* 
  file: libtest.c
  author: David De Potter
  description: example program using functions from Functions library
    Program asks for a pos. integer and prints some of its properties
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Functions/functions.h"

int isValidInt(char *str, int *n) {
  // check if the input is a valid positive integer
  char *end;
  if (str[strlen(str) - 1] != '\n') {  
    // if the input is too long, clear stdin buffer
    while (getchar() != '\n');         
    return 0;
  }
  // try to convert the input to an int
  *n = (int) strtol(str, &end, 10);
  // return 1 if the input was fully converted to a pos int
  return *end == '\n' && *n > 0;      
}

int main() {
  char input[11];
  int n;

  while (1) {
    printf("\nGive a positive integer of at most 9 digits (q to quit): ");
    if (! fgets(input, 11, stdin) || input[0] == 'q')
      break;
    // check if the input is valid
    if (! isValidInt(input, &n)) {
      printf("Invalid input\n");
      continue;
    }
    
    // print some properties of the input number
    printf("The input has %d digit%s.\n", countDigits(n), 
      countDigits(n) == 1 ? "" : "s");
    printf("The number is %sa prime.\n", isPrime(n) ? "" : "not ");
    printf("It is %sa perfect square.\n", isPerfSquare(n) ? "" : "not ");
    printf("Its reverse is %d.\n", reverseInt(n));
    char *bin = toBinary(n);
    printf("Its binary representation is %s, which is %sa palindrome.\n",
       bin, isStrPalindrome(bin, bin + strlen(bin) - 1) ? "" : "not ");
    free(bin);
  }
  return 0;
}